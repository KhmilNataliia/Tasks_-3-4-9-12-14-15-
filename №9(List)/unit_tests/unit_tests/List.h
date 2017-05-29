#include <iostream>
#include <exception>

using namespace std;

class List 
{

	friend class ListIterator;

public:
	struct Node 
	{
		char _elem;		
		Node * _next;		

		Node(const char &nElem) 
		{
			_elem = nElem;
			_next = NULL;
		}
	};

protected:
	Node* head;

public:

	class ListIterator 
	{
		bool start;
		List::Node * _first;	
		List::Node * _current;		

	public:
		void begin(List* src) 
		{
			_first = src->head;
			_current = src->head;
			start = true;
		}

		char get() 
		{
			return _current->_elem;
		}

		void next() 
		{
			if (!end()) 
			{
				_current = _current->_next;
				start = false;
			}
		}

		bool end() 
		{
			return !(_current);
		}
	};

	List(char elem) 
	{
		head = new Node(elem);
	}

	virtual char head_()
	{
		if (!head)
		{
			throw BadListException();
		}
		else
		{
			return head->_elem;
		}
	}
	virtual void cons(char elem) 
	{
		Node *add_el = new Node(elem);
		Node *h = head;
		while (h->_next) h = h->_next;
		h->_next = add_el;
	}

	virtual void pop() 
	{
		if (!head) { throw BadListException(); }
		Node *to_delete = head;
		head = head->_next;
		delete to_delete;
	}

	virtual ListIterator iterate() 
	{
		ListIterator *res = new ListIterator();
		res->begin(this);
		return *res;
	}

	virtual void show() 
	{
		if (!head)
		{
			cout << "the list is empty!" << endl;
			return;
		}
		Node *temp = head;
		while (temp!=NULL) 
		{
			cout << temp->_elem << ", ";
			temp = temp->_next;
		}
		cout << endl;
	}

	class BadListException :public exception
	{
	public:
		const char* what() 
		{
			return "Bad List Exception!";
		}
		void message() 
		{
			cout << what();
		}
	};
};

