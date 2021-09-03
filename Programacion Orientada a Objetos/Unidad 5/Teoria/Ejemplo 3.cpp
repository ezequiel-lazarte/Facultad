#include <iostream>
#include <fstream>
using namespace std;

int main() {
	/** Escriba un programa para leer una lista de nombres
	y notas de 3 parciales de un curso de POO de un archivo 
	de texto como el siguiente
	**/
	string nombre;
	int n1, n2, n3;
	ifstream archi("nombres.txt");
	if(!archi.is_open()) {
		cerr << "Error no se pudo abrir el archivo" << endl;
		return 1;
	}
	
	while(getline(archi, nombre)) {
		archi >> n1 >> n2 >> n3;
		archi.ignore(); /// va despues del cin y antes de que se repita el getline
		float prom = (n1+n2+n3)/3;
		cout << "El promedio de " << nombre << " es " << prom << endl;
	}
	
	archi.close();
	return 0;
}
