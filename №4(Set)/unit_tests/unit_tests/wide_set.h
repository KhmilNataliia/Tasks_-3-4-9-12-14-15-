#include<vector>
#include<list>

using namespace std;

template<typename T>
class wide_set
{
public:
	virtual void add(T) = 0;
	virtual void del(T) = 0;
	virtual bool in_set(T) = 0;
	virtual size_t size() = 0;
};


template <typename T>
class set_list_adapter : public wide_set<T>
{
	list<T> lst;
public:
	void add(T data)
	{
		lst.push_back(data);
	}
	void del(T data)
	{
		lst.erase(find(lst.begin(), lst.end(), data));
	}
	bool in_set(T data)
	{
		if (find(lst.begin(), lst.end(), data) != lst.end())
			return true;
		else return false;
	}
	size_t size()
	{
		return lst.size();
	}
};

template <typename T>
class set_vector_adapter : public wide_set<T>
{
	vector<T> vec;
public:
	void add(T data)
	{
		vec.push_back(data);
	}
	void del(T data)
	{
		vec.erase(find(vec.begin(), vec.end(), data));
	}
	bool in_set(T data)
	{
		if (find(vec.begin(), vec.end(), data) != vec.end())
			return true;
		else return false;
	}
	size_t size()
	{
		return vec.size();
	}
};

template <typename T>
class Set
{
	wide_set<T>* set;
public:
	Set(wide_set<T>* source) : set(source) {}
	virtual bool in_set(T data)
	{
		return set->in_set(data);
	}
	virtual bool add(T data)
	{
		if (!in_set(data))
		{
			set->add(data);
			return true;
		}
		else return false;
	}
	virtual bool del(T data)
	{
		if (in_set(data))
		{
			set->del(data);
			return true;
		}
		else return false;
	}
	virtual size_t size()
	{
		return set->size();
	}
};