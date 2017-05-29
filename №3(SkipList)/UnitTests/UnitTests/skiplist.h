#include <iostream>
#include <thread>
#include <atomic>
#include<omp.h>
#include <bitset>


using namespace std;

class skiplist
{
public:
	struct node
	{
		int val;
		atomic<node*> next;
		atomic<node*> up;
		atomic<node*> down;
		atomic<node*> tower;
		node(int dat) { val = dat; next = nullptr; up = nullptr; down = nullptr; }
	};
	const int maxtow = 8;
	skiplist();
	void insert(int elem);
	bool delitem(int item);
	bool is_in_list(int item);
	void output();
	int get_help();
	void help_();
	atomic<node*> head;
	atomic<node*> tail;
	node* help;
};