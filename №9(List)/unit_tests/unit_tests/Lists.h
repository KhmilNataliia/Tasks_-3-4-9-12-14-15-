#ifndef LISTS_H
#define LISTS_H

#include "List.h"

using namespace std;

class CyclicList : virtual public List 
{
public:
	CyclicList(char elem) :List(elem) 
	{
		head->_next = head;
	}

	virtual void cons(char elem) 
	{
		Node *add_el = new Node(elem);
		add_el->_next = head;

		Node *last_el = head->_next;
		while (last_el->_next != head) 
		{
			last_el = last_el->_next;
		}

		last_el->_next = add_el;
	}

	virtual void pop() 
	{
		if (!head) throw BadListException();
		Node *to_delete = head; 	
		Node *last_el = head->_next;
		while (last_el->_next != head) 
		{
			last_el = last_el->_next;
		}
		last_el->_next = head->_next;
		head = head->_next;
		if (to_delete == head) head = NULL;
		delete to_delete;
	}

	virtual void show() 
	{
		Node *temp = head;
		do 
		{
			cout << temp->_elem << ", ";
			temp = temp->_next;
		} while (temp != head);
		cout << endl;
	}
};

class DoubleSidedList : virtual public List 
{
protected:
	Node* tail;
public:
	DoubleSidedList(char elem) :List(elem)
	{
		tail = new Node(elem);
	};

	virtual char head_()
	{
		return List::head_();
	}

	virtual void cons(char elem) 
	{
		List::cons(elem);
		swap(tail, head);
		List::cons(elem);
		swap(tail, head);
	}

	virtual void pop() 
	{
		List::pop();
		Node *last_el = tail;
		if (!last_el->_next) 
		{
			tail = NULL;
			delete last_el;
			return;
		}
		Node *to_delete = last_el->_next;
		while (to_delete->_next)
		{
			to_delete = to_delete->_next;
			last_el = last_el->_next;
		}
		delete to_delete;
		last_el->_next = NULL;
	}
};

class CyclicDoubleSidedList : public DoubleSidedList, public CyclicList
{
public:
	CyclicDoubleSidedList(char elem) : DoubleSidedList(elem), CyclicList(elem), List(elem)
	{
		tail->_next = tail;
	};

	virtual char head_() 
	{
		return List::head_();
	};

	virtual void cons(char elem) throw(List::BadListException)
	{
		CyclicList::cons(elem);
		Node *last_tail = tail;
		while (last_tail->_next != tail)
		{
			last_tail = last_tail->_next;
		}
		Node *add_el = new Node(elem);
		add_el->_next = tail; last_tail->_next = add_el;
		tail = add_el;
	}

	virtual void pop() 
	{
		CyclicList::pop();
		Node *last_tail = tail;
		if (last_tail->_next == last_tail) 
		{
			tail = NULL;
			delete last_tail;
			return;
		}
		Node *to_delete = last_tail->_next;
		while (to_delete->_next != tail) 
		{
			to_delete = to_delete->_next;
			last_tail = last_tail->_next;
		}
		last_tail->_next = tail;
		delete to_delete;
	}
};


#endif

