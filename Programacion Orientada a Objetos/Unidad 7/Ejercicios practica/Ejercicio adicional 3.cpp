#include <iostream>
using namespace std;
template<typename T>
class VectorEstatico {
public:
	VectorEstatico() : m_tamanio(sizeof(T)) {
		for(int i=0;i<m_tamanio;i++) { 
			m_v[i] = 0;
		}
	}
	void AgregarDatos(int pos, T dato) {
		m_v[pos] = dato;
	}
	int VerTamanioVector() { return m_tamanio; }
private:
	T m_v[sizeof(T)];
	int m_tamanio;
};
int main() {
	/**Implemente una clase genérica vector estático similar a la del ejercicio 2, pero
	utilizando un vector estático, cuya longitud será el argumento de la plantilla. ¿Que
	ventajas tendría el uso de dicha clase sobre el uso de un arreglo estático común?
	**/
	VectorEstatico <double>v1;
	double dato=0;
	cout << "El tamanio del vector es: " << v1.VerTamanioVector() << endl;
	for(int i=0;i<v1.VerTamanioVector();i++) { 
		cout << "Ingrese dato Nº" << i+1 << ": "; cin >> dato;
		v1.AgregarDatos(i, dato);
	}
	v1.AgregarDatos(0,3);
	
	
	
	return 0;
}
