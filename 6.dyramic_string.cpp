#include<iostream>
#include<process.h>
using namespace std;
int main()
{
	char* ptr;
	char c;
	int a = 0;
	ptr = (char*)malloc(sizeof(char));
	while (cin.get(c))
	{
		if (c == '\n')
		{
			ptr[a] = '\0';
			break;
		}
		else
		{
			ptr = (char*)realloc(ptr, (a + 1) * sizeof(char));
			ptr[a] = c;
			a++;
		}
	}
	cout << ptr<<endl;
	system("pause");
}