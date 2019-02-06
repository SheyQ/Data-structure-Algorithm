#include <string.h>
#include <assert.h>
#include<iostream>
template<class T>
class stack
{
public:
	stack(int defalut = 8): sequence(new T[defalut]), top(0), capacity(defalut)
	{}
	~stack()
	{
		delete[] sequence;
	}

	void push(const T value)
	{
		if (top == capacity) //stack is full,allocate larger capacity
		{
			capacity <<= 1;
			T* temp = new T[capacity];
			memcpy(temp, sequence, sizeof(T)*top);
			delete[] sequence;
			sequence = temp;
		}
		sequence[top++] = value;
	}

	T pop()
	{
		assert(top != 0);
		return sequence[top--];
	}

	T operator[](int n)
	{
		return *(this->sequence + n);
	}

	int size() const
	{
		return top;
	}
private:
	T* sequence;
	int top;
	int capacity;
};

/*
for test
 */
// int main(int argc, char const *argv[])
// {
// 	stack<int> s;
// 	int i=0;
// 	while(s.size()<100)
// 	{
// 		s.push(i);
// 		cout<<s[i++];
// 	}
// 	while(s.size()>0)
// 		s.pop();
// 	return 0;
// }