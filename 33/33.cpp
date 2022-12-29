

#include <iostream>
using namespace std;
const int max_size = 100;
template <class t>
class array_stack
{
private:
	t item[max_size];
	int top;
	int countr;
public:
	array_stack()
	{
		top = -1;
		countr = 0;

	}
	array_stack(array_stack& a)
	{
		top = a.top;
		countr = a.countr;
	}
	void push(t element)
	{
		if (is_full())
			cout << "stack is full" << endl;
		else
		{
			top++;
			item[top] = element;
			countr++;
		}
	}
	void pop()
	{
		if (is_empty())
			cout << "stack is empty" << endl;
		else
		{
			top--;
			countr--;
		}
	}
	void pop(t& deleted_element)
	{
		if (is_empty())
			cout << "stack is empty" << endl;
		else
		{
			deleted_element = item[top];
			top--;
			countr--;
		}
	}
	bool is_empty()
	{
		return top == -1;
	}
	void get_top(t& top_element)
	{
		if (is_empty())
			cout << "stack is empty" << endl;
		else
		{
			top_element = item[top];
		}
	}
	bool is_full()
	{
		return top == (max_size - 1);
	}
	int size()
	{
		return countr;
	}
	void print()
	{
		if (is_empty())
			cout << "stack is empty" << endl;
		else
		{
			cout << "[ ";
			for (int i = top; i >= 0; i--)
			{
				cout << item[i] << " ";
			}
			cout << "]" << endl;
		}
	}
};
int main()
{
	int x, y;
	array_stack<int>as;
	as.push(5);
	as.get_top(x);
	cout << x << endl;
	as.print();
	as.push(6);
	as.push(7);
	cout << "the size =" << as.size() << endl;
	as.pop(y);
	cout << y << endl;
	as.print();
	as.pop();
	as.print();
	cout << "the size =" << as.size();
	return 0;
}
