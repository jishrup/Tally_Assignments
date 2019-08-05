#include <iostream> 
#include<process.h>
using namespace std;
void Decimal_To_Binary(int n, int b)
{
	int num[32], t;
	char hexa[100];
	int i = 0;
	while (n > 0) {
		if (b == 16)
		{
			t = n % b;
			if (t < 10)
			{
				hexa[i] = t + 48;
			}
			else
			{
				hexa[i] = t + 55;
			}
		}
		else
			num[i] = n % b;
		n = n / b;
		i++;
	}


	for (int j = i - 1; j >= 0; j--)
	{
		if (b != 16)
			cout << num[j];
		else
			cout << hexa[j];
	}

}
void todecimal(char *n, int b)
{
	int t, number, len;
	len = strlen(n);
	number = 0;
	for (int i = 0; i<len; i++)
	{
		if (n[i] >= 48 && n[i] <= 57)
		{
			t = n[i] - 48;
		}
		else
		{
			t = n[i] - 55;
		}
		number += t * pow(b, len - 1 - i);
	}
	cout << number;
}
int main()
{
	int n, b;
	char hexn[100];
	cout << "Enter the number to convert : ";
	cin >> n;
	cout << "Binary Equivalent: "<<endl;
	Decimal_To_Binary(n, 2);
	cout << "Octal Equivalent: " << endl;
	Decimal_To_Binary(n, 8);
	cout << "Hexadecimal Equivalent: " << endl;
	Decimal_To_Binary(n, 16);
	cout << "Enter the number to convert to decimal : " << endl;
	cin >> hexn;
	cout << "Enter the base  of the number (2,8,16) : " << endl;
	cin >> b;
	todecimal(hexn, b);
	system("pause");

	return 0;
}
