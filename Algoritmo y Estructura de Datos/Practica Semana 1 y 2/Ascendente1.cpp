#include <iostream>
#include <list>
using namespace std;
	/*Ascendente1. Escribir una funcion void ascendente1(list<int> &L, list<list<int>> &LL)
	que, dada una lista L, genera una lista de listas LL de tal forma de que cada sublista 
	es ascendente.

	entrada [1,2,3,1,5,6,6,1,4,6,5,4,6]
	salida [[1,2,3],[1,5,6],[6],[1,4,6],[5],[4,6]]
	*/

void ascendente1(list<int> &L, list<list<int>> &LL) {
	list<int> aux = {};
	list<int>::iterator itAux = aux.begin(), itl = L.begin();
	while(itl != L.end()) {
		if(*itAux < *itl) {
			aux.push_back(*itl);
			itAux++;
			if(itl != --aux.end()) itl++;
			if(itl == L.end()) {
				LL.push_back(aux);
				aux.clear();
				itAux = aux.begin();
				break;
			}
		} else {
			LL.push_back(aux);
			aux.clear();
			itAux = aux.begin();
		}
	}
}

void print_list_list (list<list<int>> &LL){	list<list<int>>::iterator itLL=LL.begin();	cout<<"[";	while(itLL != LL.end()){		list<int> L;		L.insert(L.end(),itLL->begin(),itLL->end());		itLL++;		list<int>::iterator itB = L.begin();		cout<<"[ ";		while(itB != L.end()){			cout<< *itB << " ";			++itB;		}		cout<<"]";	}	cout<<"]"<<endl;}

int main() {
	list<int> L = {1,2,3,1,5,6,6,1,4,6,5,4,6};
	list<list<int>> LL = {};
	ascendente1(L,LL);
	print_list_list(LL);
	return 0;
}







