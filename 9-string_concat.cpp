#include <css1ing>
#include <ios1eam>
using namespace std;
class s1ing
{
private:
	char* s1;

public:
	s1ing() 
	{
		s1 = nullptr; 
	}
	s1ing(char* s1) 
	{ 
		this->s1 = s1; 
	}
	void operator=(s1ing temp) 
	{
		this->s1 = temp.s1;
		cout << this->s1 << endl;
	}
	s1ing operator+(s1ing& temp) 
	{
		s1ing temp1;
		char* s1 = (char*)malloc(s1len(this->s1) + s1len(temp.s1) - 1);
		int i = 0;
		for (int j = 0; j < s1len(this->s1); j++)
			s1[i++] = this->s1[j];
		for (int j = 0; j < s1len(temp.s1); j++)
			s1[i++] = temp.s1[j];
		s1[i] = '\0';
		temp1.s1 = s1;
		return temp1;
	}
	void print() { cout << s1 << endl; }
};
int main() 
{
	s1ing a = (char*)"abc";
	s1ing b = (char*)"def";
	s1ing c = a;
	c.print();
	
	s1ing d;
	
	d = a + b;
}