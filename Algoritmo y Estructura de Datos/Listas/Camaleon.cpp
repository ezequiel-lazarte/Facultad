#include <iostream>
#include <cmath>
#include <list>
using namespace std;

	/*Camaleon. Implemente los predicados bool menor(int x, int y), bool mayor(int x, int y) y 
	bool dist(int x, int y) que retornen verdadero si x es menor, mayor o menor en valor absoluto 
	que y respectivamente. Luego implemente una funcion void ordena(list<int> &L, bool (*f)(int,int)) 
	que ordene la lista L dependiendo de la funcion f pasada como parametro.*/

bool menor(int x, int y) {return x < y ? true : false;}
bool mayor(int x, int y) {return x > y ? true : false;}
bool dist(int x, int y) {return abs(x)<abs(y) ? true : false;}

void ordena(list<int> &L, bool (*f)(int,int)) {
	list<int>::iterator itB = L.begin(), itE = L.end();
	--itE;
	for(;itB != itE; itB++) {
		list<int>::iterator itB_Next = itB;
		++itB_Next;
		for(; itB_Next != L.end(); itB_Next++) {
			if(f(*itB_Next, *itB)) {
				swap(*itB,*itB_Next);
			}
		}
	}
	
}

template<typename T>
void print_list(const list<T> &L) {
	cout << "[ ";
	for(auto x:L) {
		cout << x << " ";
	}
	cout << "]";
}

int main() {
	list<int> L = {3,2,6,8,3,44,-1,9,1};
	ordena(L,menor);
	cout << "Menor: ";
	print_list(L);
	
	ordena(L,mayor);
	cout << endl << "Mayor: ";
	print_list(L);
	
	ordena(L,dist);
	cout << endl << "Dist: ";
	print_list(L);
	
	return 0;
}







