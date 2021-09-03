#include <iostream>
#include "C:\Librerias C++\Librerias C++.h"
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	/**Escriba un programa que cargue en un vector de strings una lista de palabras
	desde un archivo de texto (que contendrá una palabra por línea), muestre en
	pantalla la cantidad de palabras leídas, las ordene en el vector alfabéticamente, y
	reescriba el archivo original con la lista ordenada.
	Ayuda: para ordenar un vector v de principio a fin puede utilizar la sentencia
	“ sort(v.begin(),v.end()); ”.
	**/
	vector<string> v;
	string x;
	int pal_leidas=0;
	ifstream archi("Salida.txt");
	if(!archi.is_open()) {
		cout << "No se pudo abrir el archivo" << endl;
		return 1;
	}
	while(archi>>x) {
		v.push_back(x);
		pal_leidas++;
	}
	cout << "El total de palabras leidas es " << pal_leidas << endl;
	sort(v.begin(),v.end());
	archi.close();
	
	ofstream archivo("Salida.txt");
	for(int i=0;i<pal_leidas;i++) {
		archivo << v[i] << endl;
	}
	archivo.close();
	return 0;
}





