#include "skiplist.h"
#include <math.h>
#include<stdio.h>

skiplist::skiplist()
{
	node* dummy = new node(0);
	dummy->next = nullptr;
	dummy->up = nullptr;
	dummy->down = nullptr;
	dummy->tower = dummy;
	head = dummy;
	node* dummy2 = new node(0);
	dummy2 = dummy;
	tail =dummy2 ;
	node* temp = head.load(memory_order_relaxed);
	head.load(memory_order_relaxed)->next = tail.load(memory_order_relaxed);
	for (int i = 0; i < maxtow; i++)
	{
		node* dummy = new node(0);
		dummy->down = temp;
		dummy->up = nullptr;
		dummy->next = tail.load(memory_order_relaxed);
		temp->up = dummy;
		temp = temp->up;
		head.load(memory_order_relaxed)->tower = temp;
	}
	head.load(memory_order_relaxed)->tower.load(memory_order_relaxed)->next = tail.load(memory_order_relaxed);
}

bool skiplist::is_in_list(int item)
{
	node* temp = head.load(memory_order_relaxed)->tower.load(memory_order_relaxed);
	node* next;
	while ((temp != nullptr))
	{
		next = temp->next.load(memory_order_relaxed);
		if ((next->val > item) || (next == tail.load(memory_order_relaxed)))
		{
			temp = temp->down.load(memory_order_relaxed);
		}
		else
		{
			if (next->val == item) return true;
			else temp = temp->next.load(memory_order_relaxed);
		}
	}
	return false;
}


void skiplist::insert(int elem)
{
	node* temp = head.load(memory_order_relaxed)->tower.load(memory_order_relaxed);
	node* prev[8];
	node* next;
	int pos=0;
	next = temp->next.load(memory_order_relaxed);
	while (temp->down.load(memory_order_relaxed) != nullptr)//going down from the top to the first level (1)
	{
		next = temp->next.load(memory_order_relaxed);
		if ((next->val > elem) || (next == tail.load(memory_order_relaxed)))
		{
			prev[pos] = temp;
			pos++;
			temp = temp->down.load(memory_order_relaxed);
		}
		else { temp = next; }
	}// end of (1)
	next = temp->next.load(memory_order_relaxed);
	while ((next->val < elem) && (next != tail.load(memory_order_relaxed))) // searching the position of insert on the first level (2)
	{
		temp = next;
		next = temp->next.load(memory_order_relaxed);
	}//end of (2)
	node* newel = new node(elem); // insert of item (3)
	newel->down = nullptr;
	newel->up = nullptr;
	newel->next = next;
	{atomic_compare_exchange_weak(&temp->next, &next, newel); }
	while (false);
	int coin=1;
	int tow = 1;
	newel->tower = newel;//end of (3) 
	temp = newel; pos--;
	while ((coin == 1) && (tow < maxtow))  //building tower (4)
	{
		coin = rand() % 2;
		if (coin == 1)
		{
			next = prev[pos]->next.load(memory_order_relaxed);
			node* up = new node(elem);
			up->down = temp;
			up->next = next;
			{atomic_compare_exchange_weak(&prev[pos]->next, &next, up); }
			 while (false);
			pos--; tow++;
			temp->up = up;
			temp = temp->up;
			newel->tower = up;
		}
	}// end of (4)
}

bool skiplist::delitem(int item)
{
	node* temp = head.load(memory_order_relaxed)->tower.load(memory_order_relaxed);
	node* next = temp->next.load(memory_order_relaxed);
	node* prev[8]; int pos = 0;
	while (temp->down.load(memory_order_relaxed) != nullptr)//searching item and marking the tower (1)
	{
		next = temp->next.load(memory_order_relaxed);
		if ((next->val > item) || (next == tail.load(memory_order_relaxed)))
		{
			temp = temp->down.load(memory_order_relaxed);
		}
		else
		{
			if (next->val == item)
			{
				prev[pos] = temp;
				pos++;
				next = next->down.load(memory_order_relaxed);
				temp = temp->down.load(memory_order_relaxed);
				node* nextcopy = temp->next.load(memory_order_relaxed);
				while (nextcopy != next)
				{
					temp = temp->next.load(memory_order_relaxed);
					nextcopy = temp->next.load(memory_order_relaxed);
				}
			}
			else
			{
				temp = temp->next.load(memory_order_relaxed);
			}
		}
	} 
	next = temp->next.load(memory_order_relaxed);
	while ((next->val!=item)&&(next!=tail.load(memory_order_relaxed)))
	{
		temp = temp->next.load(memory_order_relaxed);
		next = temp->next.load(memory_order_relaxed);
	}
	prev[pos] = temp;
	// end of (1)
	temp = next;
	if (temp->val != item) return false; // deleting the item and the tower (2)
	else
	{
		while ((temp != nullptr))
		{
			next = temp->next.load(memory_order_relaxed);
			atomic_compare_exchange_weak(&prev[pos]->next, &temp, next);
			temp = temp->up.load(memory_order_relaxed);
			pos--;
		}
	}//end of (2)
	return true;
}

void skiplist::output()
{
	node* head2 = head.load(memory_order_relaxed);
	for (int i(0); i < 8; i++)
	{
		node* temp = head2->next.load(memory_order_relaxed);
		while (temp != tail.load(memory_order_relaxed))
		{
			cout << temp->val;
			temp = temp->next.load(memory_order_relaxed);
			if (temp != tail.load(memory_order_relaxed))
				cout << "-->";
		}
		cout << endl;
		head2 = head2->up.load(memory_order_relaxed);
	}
}

void skiplist::help_()
{
	help = head.load(memory_order_relaxed)->next.load(memory_order_relaxed);
}

int skiplist::get_help()
{
	int r = help->val;
	if (help != tail.load(memory_order_relaxed))
		help = help->next.load(memory_order_relaxed);
	return r;
}

