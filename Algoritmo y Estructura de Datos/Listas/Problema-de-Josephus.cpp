#include <iostream>
#include <list>
using namespace std;

	/* Problema de Josephus. Un grupo de soldados se haya rodeado por una fuerza enemiga. No hay
	esperanzas de victoria si no llegan refuerzos y existe solamente un caballo disponible para el
	escape. Los soldados se ponen de acuerdo en un pacto para determinar cual de ellos debe escapar y
	solicitar ayuda. Forman un circulo y se escoge un numero n al azar. Igualmente se escoge el
	nombre de un soldado. Comenzando por el soldado cuyo nombre se ha seleccionado, comienzan a
	contar en la direccion del reloj alrededor del circulo. Cuando la cuenta alcanza el valor n, este
	soldado es retirado del circulo y la cuenta comienza de nuevo, con el soldado siguiente. El proceso
	continua de tal manera que cada vez que se llega al valor de n se retira un soldado. El ultimo
	soldado que queda es el que debe tomar el caballo y escapar. Entonces, dados un numero n y una
	lista de nombres, que es el ordenamiento en el sentido de las agujas del reloj de los soldados en el
	circulo (comenzando por aquel a partir del cual se inicia la cuenta), escribir un procedimiento
	list<string> josephus(list<string>& nombres, int n) que retorna una lista con los
	nombres de los soldados en el orden que han de ser eliminados y en ultimo lugar el nombre del
	soldado que escapa.*/
	
list<string> josephus(list<string>& nombres, int n) {
	list<string> L = {};
	list<string>::iterator it = nombres.begin();
	int c = 1;
	while(nombres.size() > 0) {
		if(c == n) {
			L.push_back(*it);
			it = nombres.erase(it);
			it--;
			c=0;
		}
		it++;
		if(it == nombres.end()--) it = nombres.begin();
		c++;
	}
	return L;
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
	list<string> nombres = {"Ezequiel", "Jenifer", "Pepe", "Carlos", "Mario", "Anonimus"};
	int n=3;
	list<string> orden = josephus(nombres, n);
	print_list(orden);
	return 0;
}







