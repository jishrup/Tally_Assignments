#include<iostream>
#include<process.h>
using namespace std;
int main()
{
	int n,k=0,c=0;
	cout << "enter the number" << endl;
	cin >> n;
	int * a;
	a = (int*)malloc((k+1)* sizeof(int));
	a[k] = 1;
	for (int j = 2; j <= n; j++)
	{
		for (int i = 0; i <= k; i++)
		{
			int sum = 0;
			if (c > 0)
			{
				sum = (a[i] * j)+c;
				c = 0;
			}
			else
				 sum = a[i] * j;
			if (sum >= 10)
			{
				k+=1;
				a = (int*)realloc(a, (k + 1) * sizeof(int));
				a[k] = 0;
				a[i] = sum % 10;
				c = sum / 10;
			}
			else
			{
				a[i] = sum;
			}
		}
		
	}
	int o = 0;
	for (int b = k; b >= 0; b--)
	{
		if (a[b] == 0&&o==0)
			continue;
		else
		{
			o = 1;
			cout << a[b];
		}
		cout << endl;
	}
	system("pause");
	


}