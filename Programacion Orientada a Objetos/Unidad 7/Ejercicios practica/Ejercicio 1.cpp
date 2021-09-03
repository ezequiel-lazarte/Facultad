#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;
struct Persona{
	string nombre;
	string apellido;
	int dni;
};
template<typename T>
T Mayor(T &valor1, T &valor2) {
	if(valor1>valor2)
		return valor1;
	else 
		return valor2;
}
template<typename T>
T Mayor(vector<T> v) {
	T may = v[0];
	for(size_t i=1;i<v.size();i++) { 
		if(may<v[i]) 
			may = v[i];
	}
	return may;
}
bool operator>(Persona x1, Persona x2) {
	return (x1.dni>x2.dni);
}
ostream &operator<<(ostream &o, Persona &x) {
	o << x.nombre;
	return o;
}
int main() {
	/**Implemente una función templatizada llamada Mayor(...) que reciba dos valores y
	devuelva el mayor. Compruebe el correcto funcionamiento de la rutina probándola
	desde un programa cliente con valores de tipo int , float y string .
	a. Programe una sobrecarga de la función Mayor(...) que reciba un vector y
	retorne el mayor elemento del mismo. Pruebe la función sobrecargada
	desde un programa cliente con diversos tipos de datos.
	b. Responda: ¿Servirán las funciones anteriores con datos del tipo mostrado
	en el recuadro? Justifique su respuesta.
	c. Implemente los cambios necesarios, utilizando su propio criterio, para que
	las funciones desarrolladas funcionen con el tipo de dato del recuadro.
	**/
	int e1, e2;
	cout << "Ingrese los valores de tipo entero de e1 y e2: "; cin >> e1 >> e2;
	
	float f1, f2;
	cout << "Ingrese los valores de tipo flotante de f1 y f2: "; cin >> f1 >> f2;
	
	string s1, s2;
	cout << "Ingrese los valores de tipo string de s1 y s2: "; cin >> s1 >> s2;
	
	cout << "Los mayores son: " << endl << "De tipo entero: " << Mayor<int>(e1, e2) << endl;
	cout << "De tipo flotante: " << Mayor<float>(f1, f2) << endl << "De tipo string: " << Mayor<string>(s1, s2) << endl;
	
	vector<int> v(10,0);
	cout << "vector int" << endl;
	for(int i=0;i<10;i++) {
		v[i] = rand()%100+1;
		cout << "Dato " << i+1 << ": " << v[i] << endl;
	}
	vector<float> f(10,0);
	cout << "vector float" << endl;
	for(int i=0;i<10;i++) {
		f[i] = (rand()%1000)+1.0;
		cout << "Dato " << i+1 << ": " << fixed << setprecision(2) << f[i] << endl;
	}
	vector<char> c(10,0);
	cout << "vector char" << endl;
	for(int i=0;i<10;i++) {
		c[i] = rand()%100+1;
		cout << "Dato " << i+1 << ": " << c[i] << endl;
	}
	cout << "El mayor valor de int es: " << Mayor(v) << endl;
	cout << "El mayor valor de float es: " << fixed << setprecision(2)<< Mayor(f) << endl;
	cout << "El mayor valor de char es: " << Mayor(c) << endl;
	
	///b) rta: Si, si comparamos dni
	
	Persona p1, p2;
	
	p1.nombre = "Ezequiel"; p1.apellido = "Lazarte"; p1.dni = 43000999;
	p2.nombre = "Rodrigo"; p2.apellido = "Lazarte"; p2.dni = 43090999;
	
	Persona may = Mayor(p1, p2);
	cout << "El mayor entre " << p1.nombre << " y " << p2.nombre << " es: " << may << endl;
	
	return 0;
}

