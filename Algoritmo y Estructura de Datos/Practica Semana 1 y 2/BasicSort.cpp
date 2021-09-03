#include <iostream>
#include <list>
using namespace std;

	/*BasicSort. Escribir una funcion void basic_sort(list<int> &L), que ordena los elementos de L
	de menor a mayor. Para ello emplear el siguiente algoritmo simple: utilizando una lista auxiliar L2,
	tomar el menor elemento de L, eliminarlo de L e insertarlo al final de L2 hasta que L este vacia.
	Luego insertar los elementos de L2 en L.*/

void basic_sort_mio(list<int> &L) {
	list<int> L2;
	while (!L.empty()){
		list<int>::iterator itB = L.begin();
		list<int>::iterator it = itB;
		int min = *itB;
		++itB;
		while (itB != L.end()) {
			int tmp = *itB;
			if (min > tmp) {
				min = tmp;
				it = itB;
			}
			++itB;
		}
		L.erase(it);
		L2.push_back(min);
	}
	L.swap(L2);
}

void print_list(const list<int> &L) {
	cout << "[ ";
	for(int x:L) {
		cout << x << " ";
	}
	cout << "]";
}

int main() {
	list<int> L = {2,3,7,-5,1,4,-4,6,11,-22};
	basic_sort_mio(L);
	print_list(L);
	return 0;
}







