#include <iostream>
#include <list>
using namespace std;

	/*Compacta. Escribir una funcion void compacta(list<int> &L,list<int> &S) que toma un elemento 
	entero n de S y, si es positivo, saca n elementos de L y los reemplaza por su suma. Esto ocurre 
	con todos los elementos de S hasta que se acaben, o bien se acaben los elementos de L.
	[2,5,1,4,2,4,6,7,4,56,1,-3,3,12] y [3,1,3,5] -> [8,4,12,65,3,12]
	*/

template<typename T>
void print_list(const list<T> &L) {
	cout << "[ ";
	for(T x:L) {
		cout << x << " ";
	}
	cout << "]";
}

void compacta(list<int> &L,list<int> &S) {
	list<int>::iterator it = L.begin(), it2 = S.begin();
	int n = 1, acum = 0;
	while(it != L.end()) {
		if(it == S.end() or it2 == S.end()) break;
		if(L.size() == 0 or L.size() == 1) return;
		if(n == *it2 and it2 != S.end()) {
			acum += *it;
			*it = acum;
			++it2, acum=0, n=1, ++it;
		} else {
			acum += *it;
			it = L.erase(it);
			++n;
		}
		if(it == --L.end() and it2 != S.end()) {
			acum += *it;
			*it = acum;
			break;
		}
	}
}

int main() {
	list<int> L = {2,5,1,4,2,4,6,7,4,56,1,-3,3,12}, S = {3,1,3,5}; // [13,7,11,5]
	compacta(L,S);
	print_list(L);
	return 0;
}
