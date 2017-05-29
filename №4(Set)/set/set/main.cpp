#include<iostream>
#include<conio.h>
#include "wide_set.h"

using namespace std;

Set<char>* s_char;
Set<int>* s_int;
Set<double>* s_double;

void page1();
void page2(int type);
void page3(int type);
void page4(int type,int key);

int main()
{
	page1();
	system("pause");
}

void page1()
{
	int cod = 0;
	int key = 1;
	while (cod != 13)
	{
		if (key == 1)
		{
			system("cls");
			cout << "-->type 'char'" << std::endl;
			cout << "   type 'int'" << std::endl;
			cout << "   type 'double'" << std::endl;
		}
		if (key == 2)
		{
			system("cls");
			cout << "   type 'char'" << std::endl;
			cout << "-->type 'int'" << std::endl;
			cout << "   type 'double'" << std::endl;
		}
		if (key == 3)
		{
			system("cls");
			cout << "   type 'char'" << std::endl;
			cout << "   type 'int'" << std::endl;
			cout << "-->type 'double'" << std::endl;
		}
		cod = _getch();
		if (cod == 224)
		{
			cod = _getch();
			if (cod == 72)
			{
				if (key == 1) { key = 3; }
				else { key--; }
			}
			if (cod == 80)
			{
				if (key == 3) { key = 1; }
				else { key++; }
			}
		}
	}
	page2(key);
}

void page2(int type)
{
	int cod = 0;
	int key = 1;
	while (cod != 13 && cod!=8)
	{
		if (key == 1)
		{
			system("cls");
			cout << "-->vector-based" << std::endl;
			cout << "   list-based" << std::endl;
		}
		if (key == 2)
		{
			system("cls");
			cout << "   vector-based" << std::endl;
			cout << "-->list-based" << std::endl;
		}
		cod = _getch();
		if (cod == 224)
		{
			cod = _getch();
			if (cod == 72)
			{
				if (key == 1) { key = 2; }
				else { key--; }
			}
			if (cod == 80)
			{
				if (key == 2) { key = 1; }
				else { key++; }
			}
		}
	}
	if (cod == 13)
	{
		if (type == 1) 
		{
			if (key ==1) { s_char = new Set<char>(new set_vector_adapter<char>); }
			if (key == 2) { s_char = new Set<char>(new set_list_adapter<char>); }
		}
		if (type == 2)
		{
			if (key == 1) { s_int = new Set<int>(new set_vector_adapter<int>); }
			if (key == 2) { s_int = new Set<int>(new set_list_adapter<int>); }
		}
		if (type == 3)
		{
			if (key == 1) { s_double = new Set<double>(new set_vector_adapter<double>); }
			if (key == 2) { s_double = new Set<double>(new set_list_adapter<double>); }
		}
		page3(type);
	}
	if (cod == 8) page1();
}

void page3(int type)
{
	int cod = 0;
	int key = 1;
	while (cod != 13)
	{
		if (key == 1)
		{
			system("cls");
			cout << "-->add" << std::endl;
			cout << "   delete" << std::endl;
			cout << "   check whether is in set" << std::endl;
		}
		if (key == 2)
		{
			system("cls");
			cout << "   add" << std::endl;
			cout << "-->delete" << std::endl;
			cout << "   check whether is in set" << std::endl;
		}
		if (key == 3)
		{
			system("cls");
			cout << "   add" << std::endl;
			cout << "   delete" << std::endl;
			cout << "-->check whether is in set" << std::endl;
		}
		cod = _getch();
		if (cod == 224)
		{
			cod = _getch();
			if (cod == 72)
			{
				if (key == 1) { key = 3; }
				else { key--; }
			}
			if (cod == 80)
			{
				if (key == 3) { key = 1; }
				else { key++; }
			}
		}
	}
	if (cod == 13) page4(type, key);
	if (cod == 8) page2(type);
}

void page4(int type, int key)
{
	system("cls");
	switch (key)
	{
	case 1:
	{
		cout << "enter value, which you want to add" << endl;
		if (type == 1)
		{
			char val; cin >> val;
			s_char->add(val);
		}
		if (type == 2)
		{
			int val; cin >> val;
			s_int->add(val);
		}
		if (type == 3)
		{
			double val; cin >> val;
			s_double->add(val);
		}
		break;
	}
	case 2:
	{
		cout << "enter value, which you want to delete" << endl;
		if (type == 1)
		{
			char val; cin >> val;
			if (!s_char->del(val)) cout << "no such value";
		}
		if (type == 2)
		{
			int val; cin >> val;
			if (!s_int->del(val)) cout << "no such value";
		}
		if (type == 3)
		{
			double val; cin >> val;
			if (!s_double->del(val)) cout << "no such value";
		}
		break;
	}
	case 3:
	{
		cout << "enter value, which you want to chek" << endl;
		if (type == 1)
		{
			char val; cin >> val;
			if (s_char->in_set(val))
				cout << "value is in set";
			else  cout << "no such value in set";
		}
		if (type == 2)
		{
			int val; cin >> val;
			if (s_int->in_set(val))
				cout << "value is in set";
			else  cout << "no such value in set";
		}
		if (type == 3)
		{
			double val; cin >> val;
			if (s_double->in_set(val))
				cout << "value is in set";
			else  cout << "no such value in set";
		}
		break;
	}
	}
	int cod = _getch();
	if (cod == 8) page3(type);
}