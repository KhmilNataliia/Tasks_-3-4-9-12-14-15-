#include<iostream>
#include"skiplist.h"
#include <omp.h>

using namespace std;

int main()
{
	int i;
	char input[11]="1229608374";
	skiplist list;
#pragma omp parallel num_threads(3)
	{
#pragma omp for
		for (i=0; i < 10; i++)  
			list.insert(input[i] - '0');
	};
	list.output();
#pragma omp parallel sections
	{
#pragma omp section
		list.insert(5);
#pragma omp section 
		list.delitem(6);
#pragma omp section
		list.delitem(4);
	}
	list.output();
	cout << list.is_in_list(7) << endl;
	cout << list.is_in_list(3) << endl;
	cout << list.is_in_list(5) << endl;
	cout << "enter the number of elements, which you want to delete: ";
	int n;
	cin >> n;
	cout << "enter elements: ";
	int* mtx = new int[n];
	for (int i(0); i < n; i++) cin >> mtx[i];
#pragma omp parallel num_threads(3)
	{
#pragma omp for
		for ( i=0; i < n; i++)
			list.delitem(mtx[i]);
	}

	list.output();
	system("pause");
}