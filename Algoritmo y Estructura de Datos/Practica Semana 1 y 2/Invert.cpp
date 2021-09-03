#include <iostream>
#include <list>
using namespace std;

	/*Invierte. Escribir una funcion void invert(list<int> &L), que invierte el orden de la lista L.
	Este algoritmo debe implementarse in place y debe ser O(n). Restriccion: no utilizar el metodo
	size().*/
void invert(list<int> &L) {
	int item1;
	list<int>::iterator it = L.begin(), it2 = L.end(), it3 = L.begin()++;
	for(; it != L.end(); it++) {
		it3--;
		it2--;
		item1 = *it;
		*it = *it2;
		*it2 = item1;
		if(*it == *it2 or it3 == it) {
			break;
		}
	}
}

void print_list(const list<int> &L) {
	cout << "[ ";
	for(int x:L) {
		cout << x << " ";
	}
	cout << "]";
}

int main() {
	list<int> L = {1,2,3,4,5,6,7,8};
	invert(L);
	print_list(L);
	return 0;
}







