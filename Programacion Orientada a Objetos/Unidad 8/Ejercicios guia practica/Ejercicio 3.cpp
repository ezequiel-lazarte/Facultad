#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
using namespace std;
void GuardarEnArchivo(list<float> l, string archivo);
int main() {
	/*Cree un programa que lea valores flotantes por teclado y los inserte en una lista.
	Luego:
	a. Muestre dicha lista.
	b. Inserte en medio de cada par de elementos contiguos el promedio de
	dichos elementos y guarde la lista resultante en un archivo de texto llamado
	“listafloat.txt” .
	c. Responda: ¿es posible ordenar solamente una porción de la lista de la
	misma manera que se hizo con el vector en el ejercicio 8.2?
	*/
	list<float> l;
	float valor;
	cout << "Ingrese un valor (para terminar ingrese npos): ";
	while(cin >> valor) {
		l.push_back(valor);
		cout << "Ingrese un valor (para terminar ingrese npos): ";
	}
	// a)
	cout << "La lista es: " << endl;
	for(float &x : l) {
		cout << x << endl;
	}
	// b)
	string archivo = "listafloat.txt";
	for(auto it = next(l.begin()); it!=l.end(); advance(it,2)) {
		float prom = (*prev(it)+*it)/2;
		it = l.insert(it,prom);
	}
	GuardarEnArchivo(l, archivo);
	// c) si es posible.
	l.sort();
	cout << "vector ordenado: " << endl;
	for(float &x : l) {
		cout << x << endl;
	}
	return 0;
}
void GuardarEnArchivo(list<float> l, string archivo) {
	ofstream archi(archivo, ios::trunc);
	for(list<float>::iterator it=l.begin();it!=l.end();it++) {
		archi << *it << endl;
	}
}
