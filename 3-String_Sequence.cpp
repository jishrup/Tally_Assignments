#include<iostream>
#include<process.h>
using namespace std;
char* create()
{
	char *ptr, c;
	int a = 0;
	ptr = (char*)malloc(1);
	while (cin.get(c))
	{
		if ('\n' == c || '\r' == c)
		{
			ptr[a] = '\0';
			break;
		}
		else
		{
			ptr = (char*)realloc(ptr, a + 1);
			ptr[a] = c;
			a++;
		}
	}
	return ptr;
}
int check(char c,char* cm)
{
	int i = 0;
	while (cm[i] != '\0')
	{
		if (cm[i] == c)
		{
			return i;
		}
		i++;
	}
	return -1;
}
int main()
{
	char* ptr;
	char* cmp;
	int a = -1,b = 0,i=0;
	cout << "enter the first string"<<endl;
	ptr = create();
	cout << "enter the second string" << endl;
	cmp = create();
	while(ptr[i]!='\0')
	{
		b = check(ptr[i], cmp);
		if (b > a)
		{
			a = b;
		
			b = 0;
		}
		else
		{
			cout << "sequence mismatch" << endl;
			system("pause");
			exit(0);
		}
		i++;
	}
	cout << "pattern found" << endl;
	system("pause");
}