#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int *busca_pos_mayor(int *p,int N);
int main() {
///	Utilizando notación de punteros, generar un arreglo dinámico y lineal de N
///	elementos numéricos enteros, con valores aleatorios entre 1000 y 1500, y muestre
///	en pantalla la dirección de memoria del mayor elemento. N es un dato ingresado
///	por el usuario.
	int N;
	cout << "Ingrese el valor de N: "; cin >> N;
	int *p = new int[N]; //Creo el vector con un puntero
	for(int i=0;i<N;++i) {
		*(p+i) = rand()%501+1000; //p[i] == *(p+i)  son equivalentes &p[5] == (p+5)
	}
	for(int i=0;i<N;++i) {
		cout << p+i << " " << *(p+i) << endl; //Muestra la direcion con p+i y muestra el contenido con el *
	}
	cout << endl;
	int *mayor = busca_pos_mayor(p,N);
	cout << "El Numero mayor es: " << mayor << " y el Nº era " << *mayor << endl;
	delete []p; //Siempre al finalizar hay que liberar la memoria
	return 0;
}
int *busca_pos_mayor(int *p,int N) {
	int m = numeric_limits<int>::min(), *nro_mayor = nullptr;
	for(int i=0;i<N;i++) {
		if(*(p+i)>m) {
			m=*(p+i);
			nro_mayor=(p+i);
		}
	}
	return nro_mayor;
}
