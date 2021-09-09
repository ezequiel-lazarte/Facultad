#include <iostream>
#include <list>
using namespace std;

	/*Concatena. Escriba procedimientos para concatenar: a) dos listas L1 y L2 usando insert; b) una
	lista LL de n sublistas usando insert; c) una lista LL de n sublistas usando splice. Cada
	procedimiento debe retornar el resultado en una lista nueva.*/

list<int> concatenar(list<int> L1, list<int> L2) { //a
	list<int> L = L1;
	L.insert(L.end(),L2.begin(), L2.end());
	return L;
}

list<int> concatenar(list<list<int>> &LL) { //b
	list<int> L, aux;
	for(list<list<int>>::iterator it = LL.begin(); it != LL.end(); it++) {
		aux = *it; // asigna una lista a aux 
		L.insert(L.end(), aux.begin(), aux.end());
	}
	return L;
}

list<int> concatenar_list(list<list<int>> LL) { //c
	list<int> L, aux;
	for(list<list<int>>::iterator it = LL.begin(); it != LL.end(); it++) {
		aux = *it;
		L.splice(L.end(), aux);
	}
	return L;
}

void print_list(const list<int> &L) {
	cout << "[ ";
	for(int x:L) {
		cout << x << " ";
	}
	cout << "]";
}

int main() {
	list<list<int>> L;
	list<int> a = {1,2,3,4,5,6}, b = {7,8,9,10};
	L.push_back(a);
	L.push_back(b);
	L.push_back(a);
	L.push_back(b);
	list<int> resultado = concatenar_list(L);
	print_list(resultado);
	return 0;
}







