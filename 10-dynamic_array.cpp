#include <iostream>
using namespace std;
template <class T> class Dynamic
{
private:
	T * begin;
	T *end;
	size_t d_size = 10;
	size_t c_index = 0;
	size_t c_size;

public:
	Dynamic()
	{
		begin = new T[d_size];
		end = begin;
		c_size = 10;
	}
	Dynamic(size_t size)
	{
		begin = new T[size];
		end = begin;
		c_size = size;
	}
	T operator[](size_t index)
	{
		try {
			if (index >= c_index)
				throw runtime_error("Array index out of bounds");
		}
		catch (runtime_error e) {
			cerr << "handle this error : " << e.what() << endl;
			return EXIT_FAILURE;
		}
		return *(begin + index);
	}
	void insert(T a)
	{
		if (c_index == c_size) {
			T *temp = new T[c_size + d_size];
			c_size += d_size;
			T *curr = begin;
			T *next = temp;
			while (curr) {
				*temp = *curr;
				temp++;
				curr++;
			}
			end = temp;
			delete[] begin;
			begin = next;
		}
		*end = a;
		end++;
		c_size++;
		c_index++;
	}
};
int main() {
	Dynamic<int> x;
	x.insert(2);
	x.insert(2);
	x.insert(4);
	x.insert(2);
	x.insert(5);
	cout << x[5] << endl;
}