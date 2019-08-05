#include<iostream>
#include<process.h>
using namespace std;
char* c;
int i, o=0;
void numbers(int n,int j)
{
	switch (c[n])
	{
	case '0':
		break;
	case '1':
		if (j == 2)
		{
			if (c[n + 1] == '0')
				cout << "ten ";
			else if (c[n + 1] == '1')
				cout << "eleven ";
			else if (c[n + 1] == '1')
				cout << "twelve ";
			else if (c[n + 1] == '1')
				cout << "thirteen ";
			else if (c[n + 1] == '1')
				cout << "fourteen ";
			else if (c[n + 1] == '1')
				cout << "fifteen ";
			else if (c[n + 1] == '1')
				cout << "sixteen ";
			else if (c[n + 1] == '1')
				cout << "seventeen ";
			else if (c[n + 1] == '1')
				cout << "eighteen ";
			else if (c[n + 1] == '1')
				cout << "nineteen ";
		}
		else if(j>2)
		cout << "one";
		break;
	case '2':
		if (j == 2)
			cout << "twen";
		else
			cout << "two";
		break;
	case '3':
		if (j == 2)
			cout << "thir";
		else
		cout << "three";
		break;
	case '4':
		cout << "four";
		break;
	case '5':
		if (j == 2)
			cout << "fif";
		else
		cout << "five";
		break;
	case '6':
		cout << "six";
		break;
	case '7':
		cout << "seven";
		break;
	case '8':
		if (j == 2)
			cout << "eigh";
		else
		cout << "eight";
		break;
	case '9':
		cout << "nine";
		break;
	}
}
void pre(int n)
{
	switch (n)
	{
	case 1:break;
	case 2:
		cout << "ty ";
		break;
	case 3:
		cout << " hundred ";
		break;
	case 4:
		cout << " thousand ";
		break;
	case 6:
		cout << " lakh ";
		break;
	case 8:
		cout << " crore ";
		break;
	}
}
void print(int j,int l)
{
	int k = j;
	int m = 0;
	while (m <j)
	{
		if(c[o]=='1'&& j<=2)
			numbers(l, k);
		else
		{
			numbers(l, k);
			pre(k);
		}
		k--;
		l++;
		m++; o++;
	}
}
void out(int o,int l)
{
	int j = 0;
	while (j < l)
	{
		if (l > 5 && l<8)
		{
			j = (l - 5);
			print(j, o);
			pre(6);
			l = 5;
			o += j;
			continue;
		}
		else if (l > 3 && l<6)
		{
			j = (l - 3);
			print(j, o);
			pre(4);
			l = 3;
			o += j;
			continue;
		}
		else
		{
			j = l;
			print(j, o);
			break;
		}
	}
}
int main()
{
	char m;
	c = (char*)malloc((i + 1) * sizeof(char));
	cout << "enter the number" << endl;
	while (cin.get(m))
	{
		if (m == '\n')
		{
			c[i] = '\0';
			break;
		}
		else
		{
			c = (char*)realloc(c, (i + 1) * sizeof(char));
			c[i] = m;
			i++;
		}
	}
	int k = i / 7;
	if (k > 0)
	{
		while (k > 0 && o <= (i - (k * 7)))
		{
			out(o, (i - (k * 7)));
			if (k > 0)
				pre(8);
			if (i > 7)
			{
				i = k * 7;
			}
			k--;
			
		}
	}
	if(k==0)
	{
		out(o, i);
	}

	cout << endl;
	system("pause");
}


