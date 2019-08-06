#include <iostream>
#include<process.h>
using namespace std;
template <class T> class Dynamic
{
private:
	T * b;
	int size = 0;
public:
	Dynamic()
	{
		b = (T *)malloc(sizeof(T));
	}
	void insert(T a)
	{
		b = (T*)realloc(b, (size + 1) * sizeof(T));
		b[size] = a;
		size++;
	}
	void operator [] (int n)
	{
		if (n < size)
		{
			cout << b[n] << endl;
		}
		else
		{
			cout << "wrong access" << endl;
		}
	}
};
int main() {
	Dynamic<int> x;
	int ch = 1;
	while (ch)
	{
		cout << "enter the numbers" << endl;
		int a;
		cin >> a;
		x.insert(a);
		cout << "do you want to continue" << endl << "1.yes 0.No" << endl;
		cin >> ch;
	}
	cout << "enter the position to be accessed" << endl;
	cin >> ch;
	x[ch];
	system("pause");
}