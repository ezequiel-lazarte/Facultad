#include <iostream>
#include <list>
using namespace std;

	/*SelectionSort. Escribir una funcion void selection_sort(list<int> &L), que ordena los
	elementos de L de menor a mayor. Para ello debe tomarse el menor elemento de L e intercambiarlo
	(swap) con el primer elemento de la lista. Luego intercambiar el menor elemento de la lista
	restante, con el segundo elemento, y asi sucesivamente. Esta funcion debe ser IN PLACE*/

void selection_sort(list<int> &L) {
	list<int>::iterator it = L.begin(), it2 = L.end(), it3;
	int min;
	--it2;
	for(; it != it2; it++) {
		it3 = it;
		++it3;
		for(; it3 != L.end(); it3++) {
			if(*it > *it3) {
				min = *it3;
				*it3 = *it;
				*it = min;
			}
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
	list<int> L = {2,3,7,-5,1,4,-4,6,11,-22};
	selection_sort(L);
	print_list(L);
	return 0;
}
