#include<algorithm>
#define bucket_num 1543
using namespace std;

//哈希函数为取余法,因此只适用于整形
template<class Value>
class hash_table
{
	//冲突以开链法解决,STL和JDK都是以这种方法实现
	struct node
	{
		node* next;
		Value value;
		node(Value val = 0): next(nullptr), value(val) {}
	};
private:
	node* buckets;
public:
	//桶的大小通常根据需求选择某个质数
	hash_table(): buckets(new node[bucket_num]) {};
	~hash_table()
	{
		destroy(buckets);
		delete[] buckets;
	}

	//可以有重复值
	// void insert(const Value value)
	// {
	// 	int hashcode = value % bucket_num;
	// 	node* head = &buckets[hashcode];
	// 	while (head->next != nullptr) head = head->next;
	// 	head->next = new node(value);
	// }

	//不能有重复值
	bool insert(const Value value)
	{
		int hashcode = value % bucket_num;
		node* head = &buckets[hashcode];
		while (head->next != nullptr && head->next->value != value) head = head->next;
		if (head->next == nullptr)
			head->next = new node(value);
		else
			return false;
		return true;
	}

	bool remove(const Value value)
	{
		int hashcode = value % bucket_num;
		node* head = &buckets[hashcode];
		while (head->next != nullptr && head->next->value != value) head = head->next;
		if (head->next == nullptr) return false;
		else
		{
			node* temp = head->next;
			head->next = head->next->next;
			delete temp;
		}
		return true;
	}

	bool find(const Value value)
	{
		int hashcode = value % bucket_num;
		node* head = &buckets[hashcode];
		while (head->next != nullptr && head->next->value != value) head = head->next;
		if (head->next == nullptr) return false;
		else return true;
	}

private:
	void destroy(node* buckets)
	{
		for (int i = 0; i < bucket_num; ++i)
		{
			node* head = &buckets[i];
			head = head->next;
			while (head != nullptr)
			{
				node* temp = head;
				head = head->next;
				delete temp;
			}
		}
	}
};