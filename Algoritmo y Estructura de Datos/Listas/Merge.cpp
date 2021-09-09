#include <iostream>
#include <list>
using namespace std;

	/*Merge. Escribir una funcion void merge(list<int> &L1, list<int> &L2, list<int>& L) la
	cual recibe dos listas ordenadas (que pueden ser de distinto tama˜no) de forma ascendente L1 y L2
	y retorna una lista L, pasada como parametro, con los elementos de ambas ordenados tambien en
	forma ascendente. Por ejemplo si L1=[1, 3, 6, 11] y L2=[2, 4, 6, 10], la lista L debe quedar
	como L=[1, 2, 3, 4, 6, 6, 10, 11].*/

void merge(list<int> &L1, list<int> &L2, list<int> &L) {
	L.clear();
	list<int>::iterator it1 = L1.begin(), it2 = L2.begin();
	while(it1 != L1.end() || it2 != L2.end()) {
		if(it1 != L1.end() && it2 != L2.end()) {
			if(*it1 < *it2){
				L.push_back(*it1);
				it1++;
			} else {
				L.push_back(*it2);
				it2++;
			}
		} else if(it1 != L1.end()) {
			L.push_back(*it1);
			it1++;
		} else if(it2 != L2.end()) {
			L.push_back(*it2);
			it2++;
		} else break;
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
	list<int> L1 = {1,3,5,8,14}, L2 = {2,4,7,11,21,122,1000}, L = {};
	merge(L1,L2,L);
	print_list(L);
	return 0;
}







