#include<iostream>
using namespace std;

template <class T> class stack
{
private:
	int pos;
	T* arr;
public:
	stack()
	{
		arr = new T[10];
		pos = -1;
	}
	void push(T a)
	{
		if (pos == 8)
		{
			cout << "Stack Full" << endl;
		}
		else
		{
			arr[++pos] = a;
		}
	}
	void pop()
	{
		if (pos == -1)
		{
			cout << "Stack Empty" << endl;
		}
		else
		{
			pos--;
		}
	}

	void print()
	{
		for (int i = 0; i <= pos; i++)
		{
			cout << arr[i] << ",";
		}
	}

};



template <class T> class queue
{
private:
	int fr, re;
	T* arr;
public:
	queue()
	{
		arr = new T[10];
		fr = 0;
		re = -1;
	}
	void qe(T a)
	{
		if (re == 10)
		{
			cout << "Queue full" << endl;
		}
		else
		{
			arr[++re] = a;
		}
	}
	void dq()
	{
		if (re < fr)
		{
			cout << "Queue Empty" << endl;
		}
		else
		{
			fr++;
		}
	}

	void print()
	{
		for (int i = fr; i <= re; i++)
		{
			cout << arr[i] << ",";
		}
	}

};

int main()
{
	stack<int> s;
	queue<int> q;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.pop();
	s.pop();
	s.pop();
	s.print();

	cout << endl;

	q.qe(1);
	q.qe(2);
	q.qe(3);
	q.qe(4);
	q.qe(5);
	q.qe(6);
	q.dq();
	q.dq();
	q.dq();
	q.print();

	return 0;
}