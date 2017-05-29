#include "lists.h"

int main()
{
	List* list = new List('I');
	list->cons('N');
	list->cons('a');
	list->cons('t');
	list->cons('a');
	list->show();
	list->pop();
	list->show();

	List* list1 = new List('a');
	list1->cons('b');
	list1->cons('c');
	list1->iterate().begin(list1);
	list1->iterate().next();
	list1->iterate().next();
	char r = list1->iterate().get();
	system("Pause");

}