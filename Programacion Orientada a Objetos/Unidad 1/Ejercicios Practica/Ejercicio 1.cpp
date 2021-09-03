#include <iostream>
using namespace std;

int main() {
///	Declare una variable entera estática y otra variable entera dinámica almacenando
///	su dirección de memoria en un puntero. Asigne a la primera variable el valor 10 y a
///	la segunda variable un valor ingresado por el usuario. Muestre luego las posiciones
///	de memoria de ambas variables. Luego corra el programa varias veces y responda:
///	¿las direcciones de las variables son siempre las mismas cada vez que el
///	programa corre? IMPORTANTE: No olvide liberar la memoria de la segunda
///	variable antes de salir.
	
	int v; // Variable estatica ubicada en el stack
	int *z = new int; // Variable dinamica es un puntero de nombre z ubicada en el heap
	
	v = 10;
	cout << "Ingrese un valor para z: "; cin >> *z; //asigno un valor en el heap a travez del puntero
	
	cout << "La pos de v es: " << &v << endl;
	cout << "La pos de z es: " << z << endl;
	
	// La posicion de v en el stack es la misma pero la posicion de z en el heap van cambiando con cada ejecucion
	
	return 0;
}

