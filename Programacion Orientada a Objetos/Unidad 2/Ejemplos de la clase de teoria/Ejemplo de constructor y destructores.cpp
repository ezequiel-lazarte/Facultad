#include <iostream>
#include <vector>
using namespace std;
class Foo {
public:
	Foo() {
		cout << "Constructor por defecto" << endl;
	}
	Foo(int x) {
		cout << "Constructor para int" << endl;
	}
	Foo(double x) {
		cout << "Constructor para double" << endl;
	}
	Foo(const Foo &copia) {
		cout << "Constructor de copia" << endl;
	}
	~Foo() {
		cout << "Destructor" << endl;
	}
};
int main() {
	vector<Foo> f(5);
//	Foo f(5);
//	Foo f2(f);
//	Foo f3(5.5);
	return 0;
}

