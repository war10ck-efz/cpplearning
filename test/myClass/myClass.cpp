#include <iostream>

using namespace std;

class MyClass { 
	public:
		void print() {
			cout << a << endl;
		}
	private:
		int a = 1;
};

int main()
{
	auto* a = new MyClass();
	a->print();
	return 0;
}
