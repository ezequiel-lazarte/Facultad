#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int rand10() {
	int c = -10+rand()%+20;
	cout << c << endl;
	return c;
}
bool es_par(int x) {
	if(x%2==0) return true;
	else return false;
}
bool menor_abs(int a, int b) {
	if(abs(a)<abs(b)) return true;
	else return false;
}
int main() {
	/*Ejercicio 8.4
	Declare un arreglo estático de 20 elementos enteros ( int v[20]; ) y luego:
	a. Implemente una función int rand10() que genere un entero aleatorio entre
	-10 y 10, y utilícela como argumento para generate para inicializar el arreglo
	con valores aleatorios.
	b. Implemente una función bool es_par(int x) que retorne true si el entero que
	recibe es par; y utilícela en combinación con count_if para contar cuantos
	elementos pares hay en el contenedor generado.
	c. Implemente una función bool menor_abs(int a, int b) que reciba dos enteros
	y retorne verdadero cuando el valor absoluto del primero sea menor que el
	valor absoluto del segundo; y utilice esta función como argumento de
	sort para ordenar el vector por valor absoluto.
	d. Elimine los elementos repetidos utilizando los algoritmos genéricos de la
	STL, y luego muestre el arreglo resultante.
	*/
	int v[20];
	// a)
	cout << "El vector es: " << endl;
	generate(v, v+20, rand10);
	// b)
	cout << endl << "La cantidad de numeros pares es: " << count_if(v, v+20, es_par) << endl;
	// c)
	sort(v, v+20);
	sort(v, v+20, menor_abs);
	cout << "El nuevo vector ordenado por valor absoluto es: " << endl;
	for(int &x : v)  cout << x << endl;
	// d)
	auto it = unique(v, v+20); /// este me devuelve la pos del ultimo elemento
	cout << "El nuevo vector ordenado por valor absoluto y eliminando los repetidos es: " << endl;
	for(auto i=v;i<it ; i++) cout << *i << endl;
	return 0;
}
