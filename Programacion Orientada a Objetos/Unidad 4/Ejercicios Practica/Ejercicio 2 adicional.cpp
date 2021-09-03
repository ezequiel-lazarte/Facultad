#include <iostream>
using namespace std;
class VectorDinamico{
public:
	VectorDinamico() { }
	VectorDinamico(int tamanio) : m_tamanio(tamanio) {
		m_p = new int[m_tamanio];
		for(int i=0;i<m_tamanio;i++) {
			*(m_p+i) = rand()%101+10;
		}
	}
	int VerElemento(int pos) { return *(m_p+pos); }
	int VerTamanio() { return m_tamanio; }
	~VectorDinamico() {
		delete m_p;
	}
	VectorDinamico operator=(VectorDinamico &v2) {
		for(int i=0;i<m_tamanio;i++) {
			*(m_p+i) = *(v2+i);
		}
		return *this;
	}
private:
	int *m_p;
	int m_tamanio;
};

void operator*(VectorDinamico &v1, const int &entero) {
	int *aux = new int(v1.VerTamanio());
	*aux = *v1;
	for(int i=0;i<v1.VerTamanio();i++) {
		*(aux+i) = *(aux+i) * entero; 
	}
}
int main() {
/**	Para la clase VectorDinamico desarrollada en la guía 2 implemente una
	sobrecarga del operador * que permita multiplicar por un entero a todos los
	elementos del arreglo. Implemente, además, una sobrecarga del operador = que
	permita asignar un objeto de tipo V ectorDinamico a otro objeto del mismo tipo,
	copiando los elementos. Pruebe los operadores sobrecargados en un programa
	cliente, luego, comente la sobrecarga del operador = para que no sea compilada y
	explique lo que sucede.
	Implemente una sobrecarga del operador [ ] para ver y modificar los elementos del
	vector, que además verifique si el índice que recibe es correcto, y muestre un
	mensaje de error en caso contrario. **/
	
	return 0;
}

