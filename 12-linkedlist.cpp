#include <iostream>
#include <cstring>
using namespace std;

struct node {
	long int id;
	char name[50];
	int age;
	node* link;
};

class Linked_list {
private:
	node * head, *tail;
public:
	Linked_list() {
		head = nullptr;
		tail = nullptr;
	}
	void insertion();
	void insertAtBeginning(long int id, char name[], int age);
	void insertAtEnd(long int id, char name[], int age);
	void insertAtPosition(long int id, char name[], int age, int pos);
	void insertAfterName(long int id, char name[], int age, char search_name[]);

	void deletion();
	void deleteAtBeginning();
	void deleteAtEnd();
	void deleteAtPosition(int pos);
	void deleteById(long int id);
	void deleteAll();

	void finding();
	void findByName(char name[]);
	void findById(long int id);
	void findByAge(int age);
	void findByPosition(int pos);

	void sort();

	void print();

	void bubbleSort(char param[]);
	void swap(node* n1, node* n2);
};

int main() {
	Linked_list l;
	int ch = 0;
	while (ch != 10) {
		cout << "Linked List Implemetation" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Find" << endl;
		cout << "4. Sort" << endl;
		cout << "5. Print" << endl;
		cout << "Enter your choice: ";
		cin >> ch;
		cout << endl;
		switch (ch) {
		case 1: {
			l.insertion();
			break;
		}
		case 2: {
			l.deletion();
			break;
		}
		case 3: {
			l.finding();
			break;
		}
		case 4: {
			l.sort();
			break;
		}
		case 5: {
			l.print();
			break;
		}
		case 10: {
			cout << "Exiting." << endl;
			break;
		}
		default: {
			cout << "Invalid choice" << endl;
			break;
		}
		}
	}
	return 0;
}

void Linked_list::insertion() {
	int ch;
	long int id;
	char name[50];
	int age;
	cout << "Enter the id: ";
	cin >> id;
	cout << endl;
	cout << "Enter the name: ";
	cin >> name;
	cout << endl;
	cout << "Enter the age: ";
	cin >> age;
	cout << endl;
	cout << "\t" << "1. Insert at beginning" << endl;
	cout << "\t" << "2. Insert at end" << endl;
	cout << "\t" << "3. Insert at position" << endl;
	cout << "\t" << "4. Insert after name" << endl;
	cout << "\t" << "Enter your choice: ";
	cin >> ch;
	cout << endl;
	switch (ch) {
	case 1: {
		insertAtBeginning(id, name, age);
		break;
	}
	case 2: {
		insertAtEnd(id, name, age);
		break;
	}
	case 3: {
		int pos;
		cout << "Enter the position: ";
		cin >> pos;
		cout << endl;
		insertAtPosition(id, name, age, pos);
		break;
	}
	case 4: {
		char search_name[50];
		cout << "Enter the search name: ";
		cin >> search_name;
		cout << endl;
		insertAfterName(id, name, age, search_name);
		break;
	}
	default: {
		cout << "Invalid choice" << endl;
		break;
	}
	}
}

void Linked_list::insertAtBeginning(long int id, char name[], int age) {
	node* temp = new node;
	temp->id = id;
	strcpy(temp->name, name);
	temp->age = age;
	if (head == nullptr) {
		head = temp;
		tail = temp;
		temp->link = nullptr;
		print();
		cout << endl;
		cout << "Head: " << head->id << endl;
		cout << "Tail: " << tail->id << endl;
		return;
	}
	temp->link = head;
	head = temp;
	print();
	cout << endl;
	cout << "Head: " << head->id << endl;
	cout << "Tail: " << tail->id << endl;
}

void Linked_list::insertAtEnd(long int id, char name[], int age) {
	node* temp = new node;
	temp->id = id;
	strcpy(temp->name, name);
	temp->age = age;
	if (head == nullptr) {
		head = temp;
		tail = temp;
		temp->link = nullptr;
		return;
	}
	tail->link = temp;
	temp->link = nullptr;
	tail = temp;
	print();
	cout << endl;
	cout << "Head: " << head->id << endl;
	cout << "Tail: " << tail->id << endl;
}

void Linked_list::insertAtPosition(long int id, char name[], int age, int pos) {
	if (pos <= 0) {
		cout << "Invalid positon" << endl;
		return;
	}
	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	node* temp = new node;
	//    node* prev = new node;
	node* cur = head;
	//    for(int i = 1; i < pos; i++){
	//        prev = cur;
	//        cur = cur->link;
	//    }
	//    temp->id = id;
	//    strcpy(temp->name,name);
	//    temp->age = age;
	//    prev->link = temp;
	//    temp->link = cur;
	if (pos == 1) {
		temp->id = id;
		strcpy(temp->name, name);
		temp->age = age;
		temp->link = head;
		head = temp;
		print();
		cout << endl;
		cout << "Head: " << head->id << endl;
		cout << "Tail: " << tail->id << endl;
		return;
	}
	while (--pos > 1) {
		cur = cur->link;
	}
	temp->id = id;
	strcpy(temp->name, name);
	temp->age = age;
	temp->link = cur->link;
	cur->link = temp;
	if (temp->link == nullptr)
		tail = temp;
	print();
	cout << endl;
	cout << "Head: " << head->id << endl;
	cout << "Tail: " << tail->id << endl;
}

void Linked_list::insertAfterName(long int id, char name[], int age, char search_name[]) {
	node* cur = head;
	while (cur != nullptr) {
		if (strcmp(cur->name, search_name) == 0) {
			node* temp = new node;
			temp->id = id;
			strcpy(temp->name, name);
			temp->age = age;
			temp->link = cur->link;
			cur->link = temp;
			if (temp->link == nullptr)
				tail = temp;
			return;
		}
		cur = cur->link;
	}
	cout << "Name not found" << endl;
	print();
	cout << endl;
	cout << "Head: " << head->id << endl;
	cout << "Tail: " << tail->id << endl;
}

void Linked_list::deletion() {
	int ch;
	cout << "\t" << "1. Delete at beginning" << endl;
	cout << "\t" << "2. Delete at end" << endl;
	cout << "\t" << "3. Delete at position" << endl;
	cout << "\t" << "4. Delete by Id" << endl;
	cout << "\t" << "5. Delete all" << endl;
	cout << "\t" << "Enter your choice: ";
	cin >> ch;
	cout << endl;
	switch (ch) {
	case 1: {
		deleteAtBeginning();
		break;
	}
	case 2: {
		deleteAtEnd();
		break;
	}
	case 3: {
		int pos;
		cout << "Enter the position:";
		cin >> pos;
		cout << endl;
		deleteAtPosition(pos);
		break;
	}
	case 4: {
		int id;
		cout << "Enter the Id: ";
		cin >> id;
		cout << endl;
		deleteById(id);
		break;
	}
	case 5: {
		deleteAll();
		break;
	}
	default: {
		cout << "Invalid choice" << endl;
		break;
	}
	}
}

void Linked_list::deleteAtBeginning() {
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return;
	}
	node* temp = new node;
	temp = head;
	if (head == tail) {
		tail = nullptr;
	}
	head = head->link;
	delete temp;
}

void Linked_list::deleteAtEnd() {
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return;
	}
	node* cur = head;
	while (cur->link != tail) {
		cur = cur->link;
	}
	node* temp = new node;
	temp = tail;
	cur->link = nullptr;
	tail = cur;
	delete temp;
}

void Linked_list::deleteAtPosition(int pos) {
	if (pos <= 0) {
		cout << "Invalid positon" << endl;
		return;
	}
	if (head->link == nullptr) {
		node* temp = new node;
		temp = head;
		head = nullptr;
		tail = nullptr;
		delete temp;
		return;
	}
	node* cur = head;
	while (--pos > 1)
		cur = cur->link;
	node* temp = new node;
	temp = cur->link;
	cur->link = temp->link;
	if (temp == tail)
		tail = cur;
	delete temp;
}

void Linked_list::deleteById(long int id) {
	node* cur = new node;
	cur = head;
	node* prev;
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return;
	}
	if (head == tail) {
		if (cur->id == id) {
			head = nullptr;
			tail = nullptr;
			delete cur;
			return;
		}
		cout << "Id not found" << endl;
		return;
	}
	if (cur->id == id) {
		head = cur->link;
		delete cur;
		return;
	}
	else {
		prev = cur;
		cur = cur->link;
	}
	while (cur->link != nullptr) {
		if (cur->id == id) {
			prev->link = cur->link;
			delete cur;
			return;
		}
		prev = cur;
		cur = cur->link;
	}
	if (cur->id == id) {
		cout << cur->id << endl;
		cout << prev->id << endl;
		prev->link = nullptr;
		tail = prev;
		delete cur;
		return;
	}
	cout << "Id not found" << endl;
}

void Linked_list::deleteAll() {
	node* cur = new node;
	cur = head;
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return;
	}
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
		delete cur;
		return;
	}
	while (cur != nullptr) {
		node* temp = new node;
		temp = cur;
		cur = cur->link;
		delete temp;
	}
	head = nullptr;
	tail = nullptr;
}

void Linked_list::finding() {
	int ch;
	cout << "\t" << "1. Find by name" << endl;
	cout << "\t" << "2. Find by Id" << endl;
	cout << "\t" << "3. Find by age" << endl;
	cout << "\t" << "4. Find by position" << endl;
	cout << "\t" << "Enter your choice: ";
	cin >> ch;
	cout << endl;
	switch (ch) {
	case 1: {
		char name[50];
		cout << "Enter the name: ";
		cin >> name;
		cout << endl;
		findByName(name);
		break;
	}
	case 2: {
		int id;
		cout << "Enter the Id:";
		cin >> id;
		cout << endl;
		findById(id);
		break;
	}
	case 3: {
		int age;
		cout << "Enter the age: ";
		cin >> age;
		cout << endl;
		findByAge(age);
		break;
	}
	case 4: {
		int pos;
		cout << "Enter the positon";
		cin >> pos;
		cout << endl;
		findByPosition(pos);
		break;
	}
	default: {
		cout << "Invalid choice" << endl;
		break;
	}
	}
}

void Linked_list::findByName(char name[]) {
	node* temp = head;
	while (temp != nullptr) {
		if (strcmp(temp->name, name) == 0) {
			cout << "Id: " << temp->id << endl;
			cout << "Name: " << temp->name << endl;
			cout << "Age: " << temp->age << endl;
			return;
		}
		temp = temp->link;
	}
	cout << "Name not found" << endl;
}

void Linked_list::findById(long int id) {
	node* temp = head;
	while (temp != nullptr) {
		if (temp->id == id) {
			cout << "Id: " << temp->id << endl;
			cout << "Name: " << temp->name << endl;
			cout << "Age: " << temp->age << endl;
			return;
		}
		temp = temp->link;
	}
	cout << "Id not found" << endl;
}

void Linked_list::findByAge(int age) {
	node* temp = head;
	while (temp != nullptr) {
		if (temp->age == age) {
			cout << "Id: " << temp->id << endl;
			cout << "Name: " << temp->name << endl;
			cout << "Age: " << temp->age << endl;
			return;
		}
		temp = temp->link;
	}
	cout << "Age not found" << endl;
}

void Linked_list::findByPosition(int pos) {
	if (pos <= 0) {
		cout << "Invalid position" << endl;
		return;
	}
	node* cur = head;
	while (--pos > 0) {
		cur = cur->link;
		if (cur == nullptr) {
			cout << "Out of range" << endl;
			return;
		}
	}
	cout << "Id: " << cur->id << endl;
	cout << "Name: " << cur->name << endl;
	cout << "Age: " << cur->age << endl;
}

void Linked_list::print() {
	node* temp = head;
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return;
	}
	while (temp != nullptr) {
		cout << temp->id << " " << temp->name << " " << temp->age << ", ";
		temp = temp->link;
	}
}

void Linked_list::sort() {
	int ch;
	cout << "\t" << "1. Sort by Id" << endl;
	cout << "\t" << "2. Sort by name" << endl;
	cout << "\t" << "3. Sort by age" << endl;
	cout << "\t" << "Enter your choice: ";
	cin >> ch;
	cout << endl;
	switch (ch) {
	case 1: {
		bubbleSort("id");
		break;
	}
	case 2: {
		bubbleSort("name");
		break;
	}
	case 3: {
		bubbleSort("age");
		break;
	}
	default: {
		cout << "Invalid choice" << endl;
		break;
	}
	}
}

void Linked_list::bubbleSort(char param[]) {
	int len = 0;
	node* temp = head;
	while (temp != nullptr) {
		len++;
		temp = temp->link;
	}
	node* cur = head;
	node* prev = cur;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (strcmp(param, "id") == 0) {
				if (cur->id > cur->link->id) {
					//                    swap(prev, cur, cur->link);
					swap(cur, cur->link);
				}
			}
			if (strcmp(param, "name") == 0) {
				if (strcmp(cur->name, cur->link->name) > 0)
					//                    swap(prev, cur, cur->link);
					swap(cur, cur->link);
			}
			if (strcmp(param, "age") == 0) {
				if (cur->age > cur->link->age)
					//                    swap(prev, cur, cur->link);
					swap(cur, cur->link);
			}
			prev = cur;
			cur = cur->link;
		}
		cur = head;
	}
}

void Linked_list::swap(node* n1, node* n2) {
	long int id = n1->id;
	n1->id = n2->id;
	n2->id = id;
	char name[50];
	strcpy(name, n1->name);
	strcpy(n1->name, n2->name);
	strcpy(n2->name, name);
	int age = n1->age;
	n1->age = n2->age;
	n2->age = age;
}