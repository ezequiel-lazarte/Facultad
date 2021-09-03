#include <iostream>
#include <iomanip>
using namespace std;
template<typename T>
class VectorDinamico {

public:
	VectorDinamico(int tamanio) : m_tamanio(tamanio) {	
		m_p = new T[m_tamanio];
		for(int i=0;i<tamanio;i++) {
			*(m_p+i) = (rand()%1000)+10.0;
		}
	}
	T operator[] (int pos) {
		return *(m_p+pos);
	}
	T VerArreglo(int i){ return *(m_p+i); }
	~VectorDinamico() {
		delete m_p;
	}
private:
	T *m_p;
	int m_tamanio;
};

int main() {
	/**Programe una clase templatizada llamada VectorDinamico (similar a la de la guía
	2). La clase debe poseer:
	a. Un constructor que reciba el tamaño inicial del vector, y reserve la memoria
	necesaria.
	b. Un destructor que se encargue de liberar la memoria reservada.
	c. Una sobrecarga del operador[] que reciba el número de elemento, devuelva
	su valor, y permita modificarlo.
	d. Modifique o sobrecargue el constructor para que permita generar valores
	aleatorios con los cuales inicializar las posiciones del arreglo que reserva.
	Utilice la clase desde un programa cliente creando vectores aleatorios con
	diversos tipos de datos (int,double,string, etc).
	**/
	VectorDinamico <int>v1(4);
	cout << "El arreglo es" << endl;
	for(int i=0;i<4;i++) {
		cout << "dato " << i+1 << ": " << v1.VerArreglo(i) << endl;
	}
	VectorDinamico <double>v3(5);
	cout << "El arreglo es" << endl;
	for(int i=0;i<5;i++) {
		cout << "dato " << i+1 << ": " << v3.VerArreglo(i) << endl;
	}
	VectorDinamico <float>v2(5);
	cout << "El arreglo es" << endl;
	for(int i=0;i<5;i++) {
		cout << "dato " << i+1 << ": " << fixed << setprecision(2) << v2.VerArreglo(i) << endl;
	}
	VectorDinamico <string>v4(5);
	cout << "El arreglo es" << endl;
	for(int i=0;i<5;i++) {
		cout << "dato " << i+1 << ": " << v4.VerArreglo(i) << endl;
	}
	return 0;
}

