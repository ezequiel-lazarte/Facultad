#include <iostream>
using namespace std;
struct vector_int_dinamico{
	int *p;
	int size;
};
vector_int_dinamico redimensionar(vector_int_dinamico arreglo, int c);
int main() {
///	Se tiene un arreglo dinámico de n enteros, y se quiere insertar al final c ceros.
///	Implemente una función redimensionar() que reserve dinámicamente un nuevo
///	arreglo que contenga lugar para guardar los n datos anteriores y los c ceros que
///	serán insertados, luego copie en la nueva memoria los datos del vector viejo y
///	agregue los ceros al final. La memoria del primer arreglo debe ser liberada y la
///	dirección del arreglo nuevo será retornada para que el programa cliente actualice
///	su puntero. La función debería poder invocarse de la siguiente manera:
///	vector_int_dinamico arreglo; (Teoría Pág. 10)
///	arreglo = redimensionar( arreglo, c );
///	Finalmente, implemente un programa cliente que muestre el arreglo resultante.
	vector_int_dinamico arreglo;
	int n, c;
	cout << "Ingrese el tamaño del arreglo: "; cin >> n;
	arreglo.size = n;
	arreglo.p = new int[arreglo.size];
	cout << "Ingrese el numero de ceros a insertar en el arreglo: "; cin >> c;
	//Leo
	for(int i=0;i<arreglo.size;++i) {
		*(arreglo.p+i) = rand()%101+10;
	}
	arreglo = redimensionar(arreglo, c);
	
	//Muestro
	cout << "Arreglo modificado: " << endl;
	for(int i=0;i<arreglo.size;++i) {
		cout << " " << *(arreglo.p+i);
	}
	//Borro el espacio de memoria
	delete []arreglo.p;
	return 0;
}

vector_int_dinamico redimensionar(vector_int_dinamico arreglo, int c) {
	vector_int_dinamico aux;
	aux.size=arreglo.size+c;
	aux.p = new int[aux.size];
	for(int i=0;i<aux.size;++i) {
		*(aux.p+i) = *(arreglo.p+i);
	}
	for(int i=arreglo.size;i<aux.size;++i) {
		*(aux.p+i) = 0;
	}
	delete []arreglo.p;
	return aux;
}
