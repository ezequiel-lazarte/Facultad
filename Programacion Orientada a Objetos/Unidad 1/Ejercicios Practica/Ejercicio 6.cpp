#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int *busca_pos_mayor(int *p,int N);
void insertar(int *p, int N, int valor_insertar, int pos);
int main() {
///	Amplíe el programa anterior para que, luego de generar el arreglo aleatoriamente,
///	permita ingresar un valor M que debe ser insertado en la posición P de dicho
///	arreglo y muestre el vector modificado. Para la inserción, implemente una función
///	insertar() utilizando notación de punteros.
	int N;
	cout << "Ingrese el valor de N: "; cin >> N;
	int *p = new int[N+1]; //Creo el vector con un puntero
	for(int i=0;i<N;++i) {
		*(p+i) = rand()%501+1000; //p[i] == *(p+i)  son equivalentes &p[5] == (p+5)
	}
	for(int i=0;i<N;++i) {
		cout << i << ": " << p+i << " " << *(p+i) << endl; //Muestra la direcion con p+i y muestra el contenido con el *
	}
	cout << endl;
	int *mayor = busca_pos_mayor(p,N);
	cout << "El Numero mayor es: " << mayor << " y el Nº era " << *mayor << endl;
	//Inicio del Ejercicio 6
	int M, P;
	cout << "Ingrese el valor a insertar: "; cin >> M;
	cout << "Ingrese la posicion a la cual insertara el nuevo valor: "; cin >> P;
	P=P-1; // -1 por que es en base 0
	insertar(p,N,M,P);
	for(int i=0;i<N;++i) {
		cout << i << ": " << p+i << " " << *(p+i) << endl;
	}
	
	delete []p; //Siempre al finalizar hay que liberar la memoria
	return 0;
}
int *busca_pos_mayor(int *p,int N) {
	int m = -1;
	int *nro_mayor = nullptr;
	for(int i=0;i<N;i++) {
		if(*(p+i)>m) {
			m = *(p+i);
			nro_mayor = (p+i);
		}
	}
	return nro_mayor;
}
void insertar(int *p,int N, int valor_insertar, int pos) {
	for(int i=N;i>pos;--i) {
		*(p+i) = *(p+i-1);
	}
	*(p+pos) = valor_insertar;
}
