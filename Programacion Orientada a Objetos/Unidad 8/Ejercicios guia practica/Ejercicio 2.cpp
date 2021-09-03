#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	/**Escriba un programa que defina un vector dinámico de 30 enteros aleatorios
	menores que 25. Luego:
	a. Ordene en forma descendente los elementos ubicados entre las posiciones
	10 y 20 inclusive, y muestre el vector.
	b. Inserte en un nuevo vector los elementos que fueron ordenados en el
	apartado anterior, y quítelos del vector original.
	c. Permita ingresar un valor por teclado, y muestre cuántas veces aparece
	dicho valor en el vector.
	d. Elimine todas las ocurrencias del valor ingresado en el punto c, utilizando la
	función remove. Responda: ¿Pueden las funciones globales de la STL
	eliminar realmente los elementos (liberando la memoria de un contenedor)?
	**/
	
	int* v = new int[30];
	int n=30;
	for(int i=0;i<n;i++) { 
		*(v+i) = rand()%-25;
	}
	for(int i=0;i<n;i++) { 
		cout << "Pos " << i+1 << ": " << *(v+i) << endl;
	}
	// a)
	auto it = v;
	sort(next(it,9),next(it,20)); /// lo unico que se me ocurrio fue remplazarlos por 0
	//for(int i=0;i<n;i++) { 
	//	cout << "Poscicion " << i+1 << ": " << *(v+i) << endl;
	//}
	// b)
	int* v2 = new int[11];
	copy(next(it,9), next(it,20), v2);
//	for(int i=0;i<11;i++) { 
//		cout << "Poscicion " << i+1 << ": " << *(v2+i) << endl;
//	}
	
	fill(v+9, v+ 20, 0);
	// c)
	int valor=0;
	cout << "Ingrese un valor: "; cin >> valor;
	int cant = count(v,next(v,30),valor);
	cout << "Aparece un total de " << cant << " veces" << endl;
	// d) no borran los elementos solo los lanzan a la parte tracera de la list o vector eso quiere decir que no liberan la memoria
	remove(it,next(it,n),valor);
	n = n-cant;
	for(int i=0;i<n;i++) {
		cout << "pos " << i+1 << ": " << *(v+i) << endl;
	}
	delete []v;
	delete []v2;
	return 0;
}

