#include <iostream>
#include <queue>
#include <list>
using namespace std;

	/*SortQueue. Escribir una funcion void sort(list<int> &L), que ordena los elementos de L de
	menor a mayor. Para ello utilizar el siguiente algoritmo simple, utilizando una cola auxiliar C: ir
	tomando el menor elemento de L, eliminarlo de L e insertarlo en C hasta que L este vacia. Luego
	insertar los elementos de C en L.*/

void sort(list<int> &L) {
	queue<int> C;
	list<int>::iterator  it, it_min;
	while(!L.empty()) {
		it = L.begin();
		it_min = it;
		while(it != L.end()) {
			if(*it_min > *it) it_min = it;
			it++;
		}
		C.push(*it_min);
		it_min = L.erase(it_min);
	}
	while(!C.empty()) {
		L.push_back(C.front());
		C.pop();
	}
}

template<typename T>
	void print_list(const list<T> &L) {
	cout << "[ ";
	for(T x:L) {
		cout << x << " ";
	}
	cout << "]";
}

int main() {
	list<int> L = {-100,4,5,12,4,5,1,3,7,8,-1,44,-55};
	sort(L);
	print_list(L);
	return 0;
}







