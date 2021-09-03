#include <iostream>
#include <matrix>
using namespace std;
int *busca_posicion_de_dato(int *vector, int tamanio, int dato_buscar);
int main() {
///	Escriba una función que utilice punteros para buscar e informar la dirección de un
///	entero dentro de un arreglo. Se pasan como parámetros el arreglo, su tamaño y el
///	entero a buscar. Si el dato no se encuentra, devolver la dirección de memoria nula
///	( nullptr o NULL). ¿Desde un programa cliente, cómo se obtiene el índice del
///	elemento encontrado cuando la función no devuelve nullptr ?
	int n;
	cout << "Ingrese el Nº de tamaño para el arreglo: "; cin >> n;
	
	int *arreglo = new int[n];
	
	for(int i=0;i<n;i++) {
		cout << "Ingrese valor entero: "; cin >> *(arreglo+i);
	}
	int dato_buscar;
	cout << "Ingrese el dato a buscar: "; cin >> dato_buscar;
	int *pos_dato = busca_posicion_de_dato(arreglo, n, dato_buscar);
	if(pos_dato==nullptr) {
		cout << "El dato no se encuentra en el vector" << endl;
	} else {
		cout << "La posicion del dato a buscar en el vector es " << pos_dato << " y el dato era " << *pos_dato << endl;
	}
	
	return 0;
}
int *busca_posicion_de_dato(int *vector, int tamanio, int dato_buscar) {
	int *posicion_de_dato = nullptr;
	for(int i=0;i<tamanio;i++) {
		if(dato_buscar==*(vector+i)) {
			posicion_de_dato = (vector+i);
		}
	}
	return posicion_de_dato;
}
