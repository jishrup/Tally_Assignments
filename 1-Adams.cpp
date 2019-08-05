#include<iostream>
using namespace std;
int main()
{
	long long int a, num;
	cout << "enter the number";
	cin >> a;
	if (sqr(a) == reverse(sqr(reverse(a))))
		cout << "the entered number is an Adam number";
	else
		cout << "the entered number is not an Adam number";
	
}
long long int reverse(long long int a)
{
	long long int num = 0;
	while (a > 0)
	{
		num = num * 10 + a % 10;
		a = a / 10;
	}
	return num;
}
long long int sqr(long long int  num)
{
	return num * num;
}
