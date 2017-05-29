#include <memory>
#include <atomic>

using namespace std;

class LF_queue
{
public:
	struct Node
	{
		int dat;
		atomic<Node*> next;
		Node(int val): dat(val), next(NULL){}
	};

	LF_queue()
	{
		Head = new Node(0);
		Tail = Head.load(memory_order_relaxed);
	};

	~LF_queue()
	{
		while (Head.load(memory_order_relaxed) != Tail.load(memory_order_relaxed))
			del();
	};

	void add(int data)
	{
		Node* newNode(new Node(data));
		Node* tail_copy;
		while (true)
		{
			tail_copy = Tail;
			auto next = tail_copy->next.load(memory_order_relaxed);
			if (tail_copy == Tail)
			{
				if (next == nullptr)
				{
					if (atomic_compare_exchange_weak(&tail_copy->next, &next, newNode))
						break;
				}
				else
				{
					atomic_compare_exchange_weak(&Tail, &tail_copy, next);
				}
			}
		}
		atomic_compare_exchange_weak(&Tail, &tail_copy, newNode);
	};

	int del()
	{
		Node* head_copy = Head;
		int res;
		while (true)
		{
			auto head_copy = Head.load(memory_order_relaxed);
			auto next = head_copy->next.load(memory_order_relaxed);
			auto tail_copy = Tail.load(memory_order_relaxed);

			if (head_copy == Head)
			{
				if (head_copy == tail_copy)
				{
					if (next == nullptr)
						return INFINITY;
					atomic_compare_exchange_weak(&Tail, &tail_copy, next);
				}
				else
				{
					res = next->dat;
					if (atomic_compare_exchange_weak(&Head, &head_copy, next))
						break;
				}
			}
		}
		return res;
	};

	atomic<Node*> Head;
	atomic<Node*> Tail;
};
