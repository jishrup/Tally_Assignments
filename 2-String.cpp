#include<iostream>
#include<process.h>
using namespace std;
class String
{
public:
	int strlen(char* ptr)
	{
		int a = 0;
		while (ptr[a] != '\0')
			a += sizeof(ptr[a]);
		return a;
	}
	char* strcpy(char* cpy, char* ptr)
	{
		int a = 0;
		cpy = (char*)malloc(sizeof(char));
		while (ptr != '\0')
		{
			cpy[a] = ptr[a];
			a++;
			cpy = (char*)realloc(cpy, sizeof(char) + a);
		}
		cpy[a] = '\0';
		return cpy;
	}
	int strcmp(char* cmp, char* ptr)
	{
		int a = 0;
		int i = 0;
		while (cmp[i] != '\0' || ptr[i] != '\0' || a == 0)
		{
			a = (int)cmp[i] - (int)ptr[i];
			i++;
		}
		return a;
	}
	char toupper(char ptr)
	{
		if ((int)ptr > 90)
			ptr = (char)((int)ptr - 32);
		return ptr;

	}
	char tolower(char ptr)
	{
		if ((int)ptr > 90)
			ptr = (char)((int)ptr + 32);
		return ptr;
	}
	char* strupr(char* ptr)
	{

		int i = 0;
		while (ptr[i] != '\0')
		{
			if ((int)ptr[i] <= 90)
				ptr[i] = (char)((int)ptr[i] + 32);
		}
		return ptr;
	}
	char* strlwr(char* ptr)
	{
		int i = 0;
		while (ptr[i] != '\0')
		{
			if ((int)ptr[i] > 90)
				ptr[i] = (char)((int)ptr[i] - 32);
		}
		return ptr;

	}
	int strcmpi(char* cmp, char* ptr)
	{
		int a = strlen(cmp) - strlen(ptr);
		if (a > 0)return 1;
		else if (a < 0)return -1;
		else return 0;
	}
	int strncmp(char* cmp, char* ptr, int n)
	{
		int a = 0;
		int i = 0;
		while (cmp[i] != '\0' || ptr[i] != '\0' || a == 0 || i<n)
		{
			if (cmp[i] == ptr[i])
				continue;
			else if ((int)cmp[i] < (int)ptr[i])
				return -1;
			else
				return 1;
		}
		return a;
	}
	char* strcat(char* cmp, char* ptr)
	{
		while (*cmp)
		{
			cmp++;
		}
		while (*ptr)
		{
			*cmp = *ptr;
			ptr++;
			cmp++;
		}
		return ptr;
	}

	char* strncat(char* cmp, char* ptr, int n)
	{
		int i = 0;
		while (*cmp)
		{
			cmp++;
		}
		while (*ptr || i<n)
		{
			*cmp = *ptr;
			ptr++;
			cmp++;
			i++;
		}
		if (i == n)
			cmp[i] = '\0';
		return ptr;
	}
	char* strstr(char* cmp, char* ptr)
	{
		int i = 0, j = 0;
		while (cmp[i] != '\0')
		{
			if (cmp[i] == ptr[j])
			{
				int k = i;
				while (ptr[j] != '\0' && cmp[k] != '\0'&&ptr[j] == cmp[k])
				{
					k++; j++;
				}
				if (ptr[j] == '\0')
					return cmp;
				else
				{
					i = k;
					j = 0;
				}
			}
			else
				i++;
		}
		char * m=nullptr ;
		return m;
	}
	char * strchr(char* cmp, int c)
	{
		
		int i = 0;
		while (cmp[i] != '\0')
		{
			if (cmp[i] == (char)c)
				return cmp;
			i++;
		}
		char * m = nullptr;
		return m;
	}
	char* strrev(char * cmp)
	{
		int i = 0;
		int j = 0;
		char c;
		while (*cmp)
		{
			cmp++;
			i++;
		}
		while (j < i)
		{
			c = cmp[j];
			cmp[j] = cmp[i];
			cmp[i] = c;
			i--;
			j++;
		}
		return cmp;
	}
	char * strset(char* cmp, int c)
	{
		int i = 0;
		while (cmp[i] != '\0')
		{
			cmp[i] = char(c);
			i++;
		}
		return cmp;
	}
	char * strnset(char* cmp, char c, int n)
	{
		int i = 0;
		while (cmp[i]!= '\0' || i < n)
		{
			cmp[i] = c;
			i++;
		}
		return cmp;
	}
};
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
int main()
{
	char *ptr, c;
	int ch = 1;
	ptr = create();
	String d;
	while (ch)
	{
		cout << "string operstion on c++" << endl << "select a following operation to be performed" << endl;
		cout << "0.exit" << "1.strlen" << endl << "2.strcpy" << endl << "3.strcmp" << endl << "4.toupper" << endl << "5.tolower" << endl << "6.strlwr" << endl << "7.strupr" << endl << "8.strcmpi" << endl << "9.strncmp" << endl << "10.strcat" << endl << "11.strncat" << endl << "12.strstr" << endl << "13.strchr" << endl << "14.strrev" << endl << "15.strset" << endl << "16.strnset" << endl;
		cout << "enter your choice";
		cin >> ch;
		char *cp;
		char* cpy;
		char *cmp;
		int n = 0;
		char c;
		switch (ch)
		{
		case 1:
			cout << d.strlen(ptr) << endl;
			break;
		case 2:
			 cpy;
			cout << d.strcpy(cpy, ptr) << endl;
			break;
		case 3:
			cmp = create();
			cout << d.strcmp(cmp, ptr) << endl;
			break;
		case 4:
			cout << "the conversion of characters to upper case from string :" << ptr << endl;
			cout << d.toupper(*ptr) << endl;
			break;
		case 5:
			cout << "the conversion of characters to lower case from string :" << ptr << endl;
			cout << d.tolower(*ptr) << endl;
			break;
		case 6:
			cp = d.strcpy(cpy, ptr);
			cout << d.strlwr(cp) << endl;
			break;
		case 7:
			cp = d.strcpy(cpy, ptr);
			cout << d.strupr(cp) << endl;
			break;
		case 8:
			cmp = create();
			cout << d.strcmpi(cmp, ptr) << endl;
			break;
		case 9:
			cout << "enter first strng" << endl;
			 cmp = create();
			cout << "enter second strng" << endl;
			ptr = create();
			cout << "enter the number of characters to be compared" << endl;
			n = 0;
			cin >> n;
			cout << strncmp(cmp, ptr, n) << endl;
			break;
		case 10:
			cout << "enter the two strings for concatanatin" << endl;
			 cmp = create();
			ptr = create();
			cout << "concatanated string is" << endl;
			cp = strcat(cmp, ptr);
			cout << cp << endl;
			break;
		case 11:
			cout << "enter the two strings for concatanatin" << endl;
			 cmp = create();
			ptr = create();
			cout << "enter the position till concatanation should happen" << endl;
			 n = 0;
			cin >> n;
			cout << "concatanated string is" << endl;
			cout << strncat(cmp, ptr,n) << endl;
			break;
		case 12:
			cout << "enter one main string and a pattern string to be found" << endl;
			 cmp = create();
			ptr = create();
			cout << strstr(cmp, ptr) << endl;
			break;
		case 13:
			cout << "enter the string" << endl;
			 cmp = create();
			 c;
			cout << "enter the character to be found" << endl;
			cin >> c;
			cout << "found at position " << endl;
			cout << strchr(cmp, c);
			break;
		case 14:
			cout << "enter the string " << endl;
			 cmp = create();
			cout << "reverse of the string" << endl;
			cout << strrev(cmp) << endl;
			break;
		case 15:
			cout << "enter the string and character to be set" << endl;
			 cmp = create();
			 c;
			cin >> c;
			cout << strset(cmp, c) << endl;
			break;
		case 16:
			cout << "enter the string and character to be set and position " << endl;
			 cmp = create();
			c;
			cin >> c;
			n;
			cin >> n;
			cout << strnset(cmp, c, n) << endl;
			break;

		}
	}
	system("pause");
}