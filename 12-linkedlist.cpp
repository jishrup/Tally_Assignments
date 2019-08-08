#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int l = 0;
int p = 0;
int k = 0;
char* create()
{
	char *ptr, c;
	int a = 0;
	ptr = (char*)malloc(1);
	while (cin.get(c))
	{
		if ('\n' == c )
		{
			ptr = (char*)realloc(ptr, a + 1);
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
class employe {
public:
	int id;
	int age;
	char* name ;
	employe* link;
	bool comp(employe* t, int opt)
	{
		if (opt == 1)
		{
			if (strlen(name) < strlen(t->name))
			{
				return 1;
			}
			else if (strlen(name) > strlen(t->name))
			{
				return 0;
			}
			else
			{
				int i = 0;
				while (name[i])
				{
					if (name[i] < t->name[i])
						return 1;
					else if (name[i] > t->name[i])
						return 0;
					else
						i++;
				}
			}
		}
		if (opt == 2)
		{
			return id < t->id;
		}
		if (opt == 3)
		{
			return age < t->age;
		}
	}
};
void insert(employe* &head, employe* node, int ind)
{
	if (ind == 0)
	{
		node->link = head;
		head = node;
		return;
	}
	if (!head)
	{
		head = node;
		return;
	}
	employe* temp = head;
	employe* prev = head;
	for (int j = 0; j < ind; j++)
	{
		prev = temp;
		temp = temp->link;
	}
	prev->link = node;
	node->link = temp;
}

void print(employe* head)
{
	employe* temp = head;
	int i = 1;
	while (temp)
	{
		cout << "Information of employee" << i++ << endl;
		cout <<"ID-No: "<< temp->id<<endl << "Age: " << temp->age<<endl << "Name: " << temp->name << endl;
		temp = temp->link;
	}
}
bool name_find(char* s1, char* s2)
{
	if (strlen(s1) != strlen(s2))
	{
		return 0;
	}
	int i = 0;
	while (s1[i] and s2[i])
	{
		if (s1[i] != s2[i])
		{
			return 0;
		}
		i++;
	}
	return 1;
}
void insert_name(employe* &head, employe* node, char* name)
{
	employe* temp = head->link;
	employe *cur = head;
	while (cur->link)
	{
		if (strcmp(cur->name, name) != 0)
		{
			cur = temp;
			temp = temp->link;
		}
		else
			break;
	}
	if (!cur)
	{
		if (strcmp(cur->name, name)==0)
		{
			cur->link = node;
			node->link = temp;
			return;
		}
		else
		{
			cout << "Name not found in this list" << endl;
			return;
		}
	}
	cur->link = node;
	node->link = temp;
	return;
}
employe* insert_employe()
{
	l++;
	employe* temp = new employe;
	cout << "enter the following details" << endl;
	cout << "Id-No: ";
	cin >> temp->id;
	cout << "Age: ";
	cin >> temp->age;
	cout << "Name: ";
	cin.ignore();
	temp->name=create();
	return temp;
}
void delete_at_start(employe*& head)
{
	l--;
	if (!head)
	{
		l++;
		return;
	}
	employe* temp = head;
	head = head->link;
	delete temp;
}
void delete_at_end(employe*& head)
{
	l--;
	employe* temp = head;
	employe* prev = head;
	if (!head)
	{
		l++;
		return;
	}
	if (!head->link)
	{
		head = NULL;
		delete temp;
	}
	while (temp->link)
	{
		prev = temp;
		temp = temp->link;
	}
	prev->link = NULL;
	delete temp;
}
void delete_at_position(employe*& head, int ind)
{
	l--;
	if (!head)
	{
		l++;
		return;
	}
	employe* cur = head;
	employe* prev = head;
	if (ind == 1)
	{
		head = head->link;
		delete cur;
		return;
	}
	int i = 1;
	while (cur->link && i < ind)
	{
		prev = cur;
		cur = cur->link;
		i++;
	}
	prev->link = cur->link;
	delete cur;
}
void delete_id(employe*& head, int id)
{
	l--;
	employe* temp = head;
	employe* prev = head;
	if (head->id == id)
	{
		head = head->link;
		delete temp;
		return;
	}
	if (!head)
	{
		l++;
		return;
	}
	while (temp and temp->id != id)
	{
		prev = temp;
		temp = temp->link;
	}
	if (!temp)
	{
		cout << "Id not found: " << endl;
		l++;
		return;
	}
	prev->link = temp->link;
	delete temp;
}
void delete_all(employe*& head)
{
	employe* temp = head;
	while (temp)
	{
		l--;
		delete_at_start(temp);
		temp = temp->link;
	}
	head = temp;
}
void Search_By_Position(employe* head, int ind)
{
	while (head and ind--)
	{
		head = head->link;
	}
	if (head)
	{
		cout << head->id << " " << head->age << " " << head->name << endl;
	}
	else
	{
		cout << "Search not found!" << endl;
	}
}
void Search_By_Id(employe* head, int id)
{
	p = 0;
	int flag = 0;
	while (head)
	{
		if (head->id == id)
		{
			flag = 1;
			if(k==0)
			cout << head->id << " " << head->age << " " << head->name << endl;
			break;
		}
		head = head->link;
		p++;
	}
	if (flag==0)
	{
		cout << "requested id not found!" << endl;
		p = -1;
	}
	k = 0;
}
void Search_By_Name(employe* head, char* name)
{
	p = 0;
	int flag = 0;
	while (head)
	{
		if (name_find(head->name, name))
		{
			flag = 1;
			if(k==0)
			cout << head->id << " " << head->age << " " << head->name << endl;
			break;
		}
		head = head->link;
		p++;
	}
	if (flag==0)
	{
		cout << "requested name not found!" << endl;
		p = -1;
	}
	k = 0;
}
void Search_By_Age(employe* head, int age)
{
	p = 0;
	int flag = 0;
	while (head)
	{
		if (head->age == age)
		{
			flag = 1;
			if(k==0)
			cout << head->id << " " << head->age << " " << head->name << endl;
			break;
		}
		head = head->link;
		p++;
	}
	if (flag==0)
	{
		cout << "requested age not found!" << endl;
		p = -1;
	}
	k = 0;
}
employe* Merge(employe* first, employe* second, int opt)
{
	employe* head = NULL;
	employe* temp1 = first;
	employe* temp2 = second;
	employe* tail = NULL;
	while (temp1 and temp2)
	{
		bool flag = temp1->comp(temp2, opt);
		if (flag)
		{
			if (head == NULL)
			{
				head = temp1;
				tail = head;
				temp1 = temp1->link;
				tail->link = NULL;
			}
			else
			{
				tail->link = temp1;
				temp1 = temp1->link;
				tail = tail->link;
				tail->link = NULL;
			}
		}
		else
		{
			if (!head)
			{
				head = temp2;
				tail = head;
				temp2 = temp2->link;
				tail->link = NULL;
			}
			else
			{
				tail->link = temp2;
				temp2 = temp2->link;
				tail = tail->link;
				tail->link = NULL;
			}
		}
	}
	while (temp1)
	{
		tail->link = temp1;
		temp1 = temp1->link;
		tail = tail->link;
	}
	while (temp2)
	{
		tail->link = temp2;
		temp2 = temp2->link;
		tail = tail->link;
	}
	return head;
}
void Partition(employe*& head, int opt)
{
	if (!head or !head->link)
	{
		return;
	}
	employe* slow = head;
	employe* fast = head->link;
	while (slow and fast and fast->link)
	{
		slow = slow->link;
		fast = fast->link->link;
	}
	employe* first = head;
	employe* second = slow->link;
	slow->link = NULL;
	Partition(first, opt);
	Partition(second, opt);
	head = Merge(first, second, opt);
}
char* char_co(string ty)
{
	int n, j;
	char* arr{ nullptr };
	n = ty.length();
	for (j = 0; j < n; j++)
	{
		arr = (char*)realloc(arr, (j + 1));
		arr[j] = ty[j];

	}
	arr = (char*)realloc(arr, (j + 1));
	arr[j] = '\0';



	return arr;
}
void file_c(vector <string> result, employe * head, int p)
{
	int n;
	employe * temp = new employe;
	l++;
	stringstream s(result[3]);
	s >> n;
	temp->id = n;
	temp->name = char_co(result[4]);
	stringstream m(result[5]);
	m >> n;
	temp->age = n;
	insert(head, temp, p + 1);
}
int main()
{
	employe* head = NULL;
	while (1)
	{
		char i;
		int ind,opt;
		employe* temp2;
		int n = 0, a;
		ifstream myfile;
		cout << "linked list implementation\n";
		cout << "1. Insert\n2. Delete\n3. Search\n4. Sort\n5. Print\n6. Read From File\n7.Exit\n";
		cin >> i;
		employe* temp;
		switch (i)
		{
		case '1':
			cout << "1. insert at the  begining\n2. insert at the end\n3. insert at a position\n4. insert after an existing node\n5. Main Menu\n";
			cin >> i;
			if (i == '1')
			{
				temp = insert_employe();
				insert(head, temp,0);
			}
			if (i == '2')
			{
				temp = insert_employe();
				temp2 = head;
				int i = 0;
				while (temp2)
				{
					temp2 = temp2->link;
					i++;
				}
				insert(head, temp, i);
			}
			if (i == '3')
			{
				cout << "Enter the Index" << endl;
				cin >> ind;
				temp = insert_employe();
				insert(head, temp, ind-1);
			}
			if (i == '4')
			{
				cout << "Enter the name after the node need to be inserted" << endl;
				cin.ignore();
				char * name = create();
				cout << name << endl;
				temp = insert_employe();
				insert_name(head, temp, name);
			}
			if (i == '5')
			{
				break;
			}
			break;
		
		case '3':
			
				cout << "1. By position\n2. By name\n3. By id\n4. By age\n5. Main Menu\n";
				cin >> opt;
				if (opt == 1)
				{
					cout << "Enter position: ";
					int temp_ind;
					cin >> temp_ind;
					Search_By_Position(head, temp_ind);
				}
				if (opt == 2)
				{
					cout << "Enter name: ";
					cin.ignore();
					char* name = create();
					Search_By_Name(head, name);
				}
				if (opt == 3)
				{
					cout << "Enter id: ";
					int temp_id;
					cin >> temp_id;
					Search_By_Id(head, temp_id);
				}
				if (opt == 4)
				{
					cout << "Enter age: ";
					int temp_age;
					cin >> temp_age;
					Search_By_Age(head, temp_age);
				}
				if (opt == 5)
				{
					continue;
				}
				break;
		case '5':
			
				print(head);
				break;
		
		case '6': 
			myfile.open("data.txt", ios::in);
			if (myfile.is_open())
			{
				int j;
				string str;
				char* arr;
				while (!myfile.eof())
				{
					while (getline(myfile, str, '\n'))
					{
						stringstream s(str);
						vector<string> result;
						while (s.good())
						{
							string substr;
							getline(s, substr, ',');
							result.push_back(substr);
						}
						if (result[0].compare("idx")==0)
						{
						    stringstream s(result[1]);
							s >> n;
							if (n>( l + 1))
								cout << "insertion not possible" << endl;
							else
							{
								temp = new employe;
								l++;
								stringstream s(result[2]);
								s >> a;
								temp->id = a;
								temp->name = char_co(result[3]);
								stringstream m(result[4]);
								m >> a;
								temp->age = a;
								insert(head, temp, n-1);
							}

						}
						else if (result[0].compare("after")==0)
						{
							if (result[1].compare("id")==0)
							{
								stringstream s(result[2]);
								s >> n;
								k = 1;
								Search_By_Id(head, n);
								if (p >= 0)
								{
									file_c(result, head, p );
								}

							}
							else if (result[1].compare("name") == 0)
							{
								char* name = char_co(result[2]);
								k = 1;
								 Search_By_Name(head, name);
								 if (p >= 0)
								 {
									 file_c(result, head, p );
								 }
							}
							else if (result[1].compare("age") == 0)
							{
								stringstream s(result[2]);
								s >> n;
								k = 1;
								 Search_By_Age(head, n);
								 if (p >= 0)
								 {
									 file_c(result, head, p );
								 }
							}
						}
						else if (result[0].compare("before") == 0)
						{
							if (result[1].compare("id") == 0)
							{
								stringstream s(result[2]);
								s >> n;
								k = 1;
								Search_By_Id(head, n);
								if (p > 0)
								{
									file_c(result, head, p - 1);
								}
								else if (p == 0)
									file_c(result, head, p);

							}
							else if (result[1].compare("name") == 0)
							{
								char* name = char_co(result[2]);
								k = 1;
								Search_By_Name(head, name);
								if (p > 0)
								{
									file_c(result, head, p - 1);
								}
								else if (p == 0)
									file_c(result, head, p);
							}
							else if (result[1].compare("age") == 0)
							{
								stringstream s(result[2]);
								s >> n;
								k = 1;
								Search_By_Age(head, n);
								if (p > 0)
								{
									file_c(result, head, p-1);
								}
								else if(p==0)
									file_c(result, head, p );
							}
						}
					}
				}
				myfile.close();
			}
			break;
		case '7':exit(0);
		default: break;
		}
	}
}