#include <iostream>
#include <list>
#include <stack>
using namespace std;

	/*SortStack. Escribir una funcion void sort(list<int> &L), que ordena los elementos de L de
	mayor a menor. Para ello emplear el siguiente algoritmo simple, utilizando una pila auxiliar P: ir
	tomando el menor elemento de L, eliminarlo de L e insertarlo en P hasta que L este vac´ia. Luego
	insertar los elementos de P en L.*/

void sort(list<int> &L) {
	stack<int> P;
	list<int>::iterator it = L.begin(), it_min = L.begin();
	while(!L.empty()) {
		it_min = L.begin();
		it = L.begin();
		while(it != L.end()) {
			if(*it_min >*it) it_min = it;
			it++;
		}
		P.push(*it_min);
		it_min = L.erase(it_min);
	}
	while(!P.empty()) {
		L.push_front(P.top());
		P.pop();
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







