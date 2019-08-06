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
		arr = new T[8];
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
			cout << "the element poped" << arr[pos] << endl;
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
			cout << "the element poped" << arr[pos] << endl;
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
	int ch=1;
	stack<int> s;
	queue<int> q;
	cout << "stack implementation" << endl;
	int n;
	while (ch)
	{
		cout << <<"enter your choice" << endl << "1.push" << endl << "2.pop" << endl << "3.exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "enter the data to be pushed" << endl;
			cin >> n;
			s.push(n);
			break;
		case 2:
			s.pop();
			break;
		default:
			cout << "wrong choice" << endl;
			break;

		}
	}
	cout << "queue implementation" << endl;
	while (ch)
	{
		cout << <<"enter your choice" << endl << "1.enter" << endl << "2.delete" << endl << "3.exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "enter the data to be entered" << endl;
			cin >> n;
			q.qe(n);
			break;
		case 2:
			q.dq();
			break;
		default:
			cout << "wrong choice" << endl;
			break;

		}
	}
	system("pause");
	return 0;
}