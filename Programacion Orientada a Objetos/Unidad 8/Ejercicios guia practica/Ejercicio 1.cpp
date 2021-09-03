#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <algorithm>
using namespace std;

int main() {
	/**Escriba un programa que permita al usuario ingresar 15 valores por teclado, los
	almacene en un vector y luego:
	a. Muestre el vector generado utilizando 3 mecanismos de iteración diferentes.
	1. utilizando el operador []
	2. utilizando iteradores
	3. utilizando el for basado en rangos
	4. ¿en qué caso es conveniente utilizar cada mecanismo?
	b. Calcule y muestre
	1. los valores de los elementos máximo y mínimo
	2. la suma de todos los elementos del arreglo
	3. el promedio y la mediana de los elementos del arreglo
	c. Permita al usuario ingresar un valor, e informe si se encuentra en el vector,
	y en caso afirmativo, en qué posición.
	**/
	vector<int> v(15,0);
	for(int i=0;i<15;i++) {
		cout << "Ingrese un dato " << i+1 << ": "; cin >> v[i];
	}
	// a)
	for(int i=0;i<15;i++) { // 1)
		cout << "Dato " << i+1 << ": " << v[i] << endl;
	}
	int i = 0;
	for(vector<int>::iterator it=v.begin();it!=v.end();++it) { // 2)
		cout << "Dato " << i+1 << ": " << *it << endl;
		++i;
	}
	i=0;
	for(auto it=v.begin();it!=v.end();++it) { // 2) con auto
		cout << "Dato " << i+1 << ": " << *it << endl;
		++i;
	}
	i=0;
	for(int &x : v) { // 3)
		cout << "Dato " << i+1 << ": " << x << endl;
		++i;
	}
	/**4) el mecanismo 1 conviene utilizarlo solo para vectores, el 2do es el mas recomendable ya que contenedores como list, map, etc
	trabajan solo con contenderores, el tercero es recomendable solo para mostrar todo de forma rapida
	**/
	// b)
	// 1)
	list<int> v1(15,0); 
	int c=0;
	for(auto it=v1.begin();it!=v1.end();++it) {
		cout << "Ingrese un dato " << c+1 << ": "; cin >> *it;
		++c;
	}
	cout << "El numero mayor es " << *max_element(v1.begin(), v1.end()) << endl;
	cout << "El numero menor es " << *min_element(v1.begin(), v1.end()) << endl;
	cout << "La suma: " << accumulate(v1.begin(), v1.end(), 0) << endl;
	// 2)
	int acumula=0;
	for(auto it=v1.begin();it!=v1.end();++it) {
		acumula += *it;
	}
	cout << "La suma de todos los elementos es: " << acumula << endl;
	// 3)
	float prom = acumula/15;
	cout << "El promedio es de " << prom << endl;

	// c)
	int valor=0, pos=0; bool e=false;
	cout << "Ingrese un valor: "; cin >> valor;
	for(auto it=v1.begin();it!=v1.end();++it) {
		++pos;
		if(*it==valor) {
			e = true;
			break;
		}
	}
	if(e) 
		cout << "El valor " << valor << " Si se encuentra y esta en la posicion " << pos << endl;
	else 
		cout << "El valor " << valor << " No estaba" << endl;
	return 0;
}

