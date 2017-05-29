#include<iostream>
#include <omp.h>

#include "queue.h"

using namespace std;

int main()
{
	LF_queue *LFQ = new LF_queue();
#pragma omp parallel num_threads(3)
	{
		for (int i = 1; i <= 10; i++)
		{
			LFQ->add(i);
		}
		for (int j = 0; j < 5; j++)
		{
			LFQ->del();
		}
	} 
	for (int j = 0; j < 5; j++)
	{
		cout << LFQ->del() << ";" << endl;
	}
	system("pause");
}