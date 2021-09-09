#include <iostream>
#include <list>
using namespace std;

	/*ReemplazaSecuencia. Dada una lista de enteros L y dos listas SEQ y REEMP, posiblemente de
	distintas longitudes, escribir una funcion void reemplaza(list<int> &L, list<int>& SEQ,
	list<int> &REEMP), que busca todas las secuencias de SEQ en L y las reemplaza por REEMP. Por
	ejemplo, si L=(1,2,3,4,5,1,2,3,4,5,1,2,3,4,5), SEQ=(4,5,1) y REEMP=(9,7,3), entonces
	despues de llamar a reemplaza(L,SEQ,REEMP), debe quedar
	L=(1,2,3,9,7,3,2,3,9,7,3,2,3,4,5). Para implementar este algoritmo primero buscar desde el
	principio la secuencia SEQ, al encontrarla, reemplazar por REEMP, luego seguir buscando a partir
	del siguiente elemento al ultimo de REEMP.*/

void reemplaza(list<int> &L, list<int> &SEQ,const list<int> &REEMP) {
	int contador=0;
	list<int>::iterator aux, it, it2;
	if(SEQ.size() == 0 or L.size() == 0) return;
	for(it=L.begin(), it2=SEQ.begin(); it != L.end() and it2 != SEQ.end(); it++, it2++) {
		if(contador == 0) it2 = SEQ.begin();
		if(*it == *SEQ.begin()) aux = it;
		if(*it != *it2) {
			contador = 0;
			it2 = SEQ.begin();
		}
		if(*it == *it2) {
			contador++;
			if(contador == int(SEQ.size())) {
				aux = L.erase(aux, it++);
				aux = L.erase(aux);
				L.insert(aux, REEMP.begin(), REEMP.end());
				contador=0;
			}
		} else {
			contador = 0;
		}
		if(*it2 == *SEQ.end()--) it2 = SEQ.begin();
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
	list<int> L = {1,2,3,111,1,2,3,1,2}, SEQ = {1,2,3}, REEMP = {22,22,22,22};
	reemplaza(L, SEQ, REEMP);
	print_list(L);
	return 0;
}







