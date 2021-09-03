#include <iostream>
#include <fstream>
using namespace std;
struct Par {
	int i;
	double d;
};
int main() {
	/** 
	Escriba un programa para abrir el archivo generado en el primer ejemplo, buscar el
	par de datos cuyo double sea mayor, informar su posicion, y poner su entero en 0
	**/
	string nombre;
	cin >> nombre;
	fstream archi(nombre, ios::binary|ios::in|ios::out|ios::ate);
	if(!archi.is_open()) {
		cout << "Error el archivo no se encontro" << endl;
		return 1;
	}
	int n= archi.tellg()/sizeof(Par);
	archi.seekg(0);
	Par mayor = {0, 0};
	int pos_mayor=0;
	for(int i=0;i<n;i++) {
		Par p;
		archi.read(reinterpret_cast<char*>(&p), sizeof(p));
		if(p.d>mayor.d) {
			mayor = p;
			pos_mayor = i;
		}
	}
	archi.seekp(pos_mayor*sizeof(Par));
	mayor.i = 0;
	archi.write(reinterpret_cast<char*>(&mayor), sizeof(mayor));
	return 0;
}

