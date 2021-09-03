#include <iostream>
using namespace std;
class VectorDinamico{
public:
	VectorDinamico() { }
	VectorDinamico(const VectorDinamico &otro_vector) { // este contructor se copia de l vector usado
		this-> m_tamanio = otro_vector.m_tamanio;
		this-> m_p = new int[m_tamanio];
		for(int i=0;i<m_tamanio;++i) {
			m_p[i] = otro_vector.m_p[i]; //copio cada elemento al nuevo vector
		}
	}	/// estos dos constructores de copia vienen de regalo siempre por mas que no los escriba estan aca
	VectorDinamico(int tamanio) : m_tamanio(tamanio);	// a)
	void Duplicar();
	int VerElemento(int pos);
	int Tamanio() { return m_tamanio; }
	~VectorDinamico() {
		delete m_p;
	}
private:
	int *m_p;
	int m_tamanio;
};

VectorDinamico::VectorDinamico(int tamanio) {
	m_tamanio = tamanio;
	m_p = new int[m_tamanio];
	for(int i=0;i<m_tamanio;i++) {
		*(m_p+i) = rand()%101+10;
	}
}
void VectorDinamico::Duplicar() {
	m_tamanio = m_tamanio*2;
	int *aux = new int[m_tamanio*2];
	for(int i=0;i<m_tamanio;i++) {
		*(aux+i) = *(m_p+i);
	}
	for(int i=m_tamanio;i<m_tamanio*2;i++) {
		*(aux+i) = rand()%500+100;
	}
	delete [] m_p;
	m_p=aux;
	delete [] aux;
}
int VectorDinamico::VerElemento(int pos) {
	return *(m_p+pos);
}
VectorDinamico::~VectorDinamico() { // c)
	delete[] m_p;
}
int main() {
///		Implemente una clase VectorDinamico que posea como atributo un puntero a
///		entero que apunte a la memoria donde se almacenan los datos. Dicha clase debe
///		poseer:
///		a. Un constructor que reciba el tamaño inicial del vector, reserve la memoria
///		necesaria e inicialice los valores del vector de manera aleatoria.
///		b. Un destructor que se encargue de liberar la memoria reservada.
///		c. Un método Duplicar(...) que duplique la cantidad de memoria reservada
///		manteniendo los datos que ya estaban en el vector e inicializando al azar
///		los nuevos valores.
///		d. Un método VerElemento(...) que reciba el número de elemento y devuelva
///		su valor.
///		e. Cree un programa cliente que muestre la utilización de todas las funciones
///		implementadas.
	int n;
	cout << "Ingrese el tamaño inicial del vector: "; cin >> n;
	VectorDinamico vector(n);
	
	cout << "vector: " << endl; 
	for(int i=0;i<n*2;i++) 
		cout<<vector.VerElemento(i)<<"   ";
	cout << endl;
	
	VectorDinamico v2(vector); // este vector se copia de v y usa el constructor por defecto que es de copia
	return 0;
}

