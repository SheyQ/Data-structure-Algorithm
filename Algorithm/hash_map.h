#include<algorithm>
#define bucket_num 1543
using namespace std;

/*
hash_map可以用hash_table构建键值对直接实现
重写一遍为了能单独拿来参考
 */
template<class Key, class Value>
class hash_map
{
	//冲突以开链法解决
	struct node
	{
		node* next;
		pair<Key, Value> value;
		node(): next(nullptr) {};
		node(pair<Key, Value> val): next(nullptr), value(val) {}
	};
private:
	node* buckets;
public:
	//桶的大小通常根据需求选择某个质数
	hash_map(): buckets(new node[bucket_num]) {};
	~hash_map()
	{
		destroy(buckets);
		delete[] buckets;
	}

	//不能有重复值
	bool insert(const pair<Key, Value> value)
	{
		int hashcode = value.first % bucket_num;
		node* head = &buckets[hashcode];
		while (head->next != nullptr && head->next->value.first != value.first) head = head->next;
		if (head->next == nullptr)
			head->next = new node(value);
		else
			return false;
		return true;
	}

	bool remove(const Key key)
	{
		int hashcode = key % bucket_num;
		node* head = &buckets[hashcode];
		while (head->next != nullptr && head->next->value.first != key) head = head->next;
		if (head->next == nullptr) return false;
		else
		{
			node* temp = head->next;
			head->next = head->next->next;
			delete temp;
		}
		return true;
	}


	pair<bool, Value> find(const Key key)
	{
		int hashcode = key % bucket_num;
		node* head = &buckets[hashcode];
		while (head->next != nullptr && head->next->value.first != key) head = head->next;
		if (head->next == nullptr) return make_pair(false, head->value.second);
		else return make_pair(true, head->next->value.second);
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

//在cpp文件里测试
// #include"hash_map.h"
// #include<iostream>
// int main(int argc, char const *argv[])
// {
// 	hash_map<int, string> m;
// 	m.insert(make_pair(1, "hello"));
// 	m.insert(make_pair(2, "world"));
// 	m.insert(make_pair(3, "this"));
// 	m.insert(make_pair(4, "is"));
// 	m.insert(make_pair(5, "Shey's"));
// 	m.insert(make_pair(6, "map"));
// 	m.remove(2);
// 	if (m.find(1).first) cout << m.find(1).second << endl;
// 	if (m.find(2).first) cout << m.find(2).second << endl;
// 	if (m.find(3).first) cout << m.find(3).second << endl;
// 	if (m.find(4).first) cout << m.find(4).second << endl;
// 	if (m.find(5).first) cout << m.find(5).second << endl;
// 	if (m.find(6).first) cout << m.find(6).second << endl;
// 	return 0;
// }
// hello
// this
// is
// Shey's
// map