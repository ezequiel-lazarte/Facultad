#include <iostream>
#include <list>
using namespace std;

	/*Junta. Escribir una funcion void junta(list<int> &L, int c) que, dada una lista L, agrupa de
	a c elementos, dejando su suma in place. Por ejemplo, si se le pasa como argumento la lista
	L=(1,3,2,4,5,2,2,3,5,7,4,3,2,2), despues de aplicar el algoritmo junta(L,3) debe quedar
	L=(6,11,10,14,4) (notar que se agrupan los ultimos elementos, pese a no completar los tres
	requeridos). El algoritmo debe tener un tiempo de ejecucion O(n).*/

template<typename T>
void print_list(const list<T> &L) {
	cout << "[ ";
	for(T x:L) {
		cout << x << " ";
	}
	cout << "]";
}

void junta_(list<int> &L, int c) {
	if(c <= 0) return L.clear();	int resto = L.size()%c;	auto itS = L.begin();	auto itI = L.begin();	int suma;	for(int i = 0; i < (int(L.size())/c); i++){		suma = 0;		for(int j = 0; j < c; j++){			suma += *itS;			itS++;		}		*itI = suma;		itI++;	}	if(resto != 0){		suma = 0;		for(int i = 0; i < resto; i++){			suma += *itS;						itS++;		}		*itI = suma;		itI++;	}	L.erase(itI, L.end());}

int main() {
	list<int> L = {2,2,2,2,2,5,5,5,5,5,3};
	junta_(L,5);
	print_list(L);
	return 0;
}







