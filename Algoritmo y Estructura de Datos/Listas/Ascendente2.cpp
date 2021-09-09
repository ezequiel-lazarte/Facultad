#include <iostream>
#include <vector>
#include <list>
using namespace std;
	/*Ascendente2. Escribir una funci´on void ascendente2(list<int> &L, vector<list<int>> &VL)
	que, dada una lista L, genera un vector de listas VL de tal forma de que cada sublista es 
	ascendente.
	entrada [1,2,3,1,5,6,6,1,4,6,5,4,6]
	salida [[1,2,3],[1,5,6],[6],[1,4,6],[5],[4,6]]
	*/

void ascendente2(list<int> &L, vector<list<int>> &VL) {
	list<int> aux = {};
	list<int>::iterator itAux = aux.begin(), itl = L.begin();
	while(itl != L.end()) {
		if(*itAux < *itl) {
			aux.push_back(*itl);
			itAux++;
			if(itl != --aux.end()) itl++;
			if(itl == L.end()) {
				VL.push_back(aux);
				aux.clear();
				itAux = aux.begin();
				break;
			}
		} else {
			VL.push_back(aux);
			aux.clear();
			itAux = aux.begin();
		}
	}
}

void print_vector_list (vector<list<int>> &LL) {	vector<list<int>>::iterator itLL=LL.begin();	cout<<"[";	while(itLL != LL.end()){		list<int> L;		L.insert(L.end(),itLL->begin(),itLL->end());		itLL++;		list<int>::iterator itB = L.begin();		cout<<"[ ";		while(itB != L.end()){			cout<< *itB << " ";			++itB;		}		cout<<"]";	}	cout<<"]"<<endl;}
	
int main() {
	list<int> L = {1,2,3,1,5,6,6,1,4,6,5,4,6};
	vector<list<int>> LL = {};
	ascendente2(L,LL);
	print_vector_list(LL);
	return 0;
}





