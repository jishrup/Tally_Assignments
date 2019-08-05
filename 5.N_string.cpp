#include<iostream>
#include<process.h>
using namespace std;
void print(int n)
{
	if (n >26)
	{

		if (n % 26 == 0)
		{
				print(n / 26 - 1);
				print(n - 26 * ((n / 26)-1));
		
		}
		else
		{
			print(n / 26);
			print(n - 26 * (n / 26));
		}
	}
	else
	{
			cout << char(65 + n - 1);
	}
}
int main()
{
	int m;
	cout << "enter the number of strings to be produced" << endl;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		print(i);
		cout << ",";
	}
	system("pause");
}