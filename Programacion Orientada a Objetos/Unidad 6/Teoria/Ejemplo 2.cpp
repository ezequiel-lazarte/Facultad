#include <iostream>
#include <fstream>
using namespace std;
struct Par {
	int i;
	double d;
};
int main() {
	string nombre;
	getline(cin, nombre);
	ifstream archi(nombre, ios::binary|ios::ate); // se abre el archivo y estoy al final, y en esta posicion puedo saber el tamaño del archivo
	if(!archi.is_open()) {
		cout <<"Error el nombre del archivo es incorrecto" << endl;
		return 1;
	}
	int n = archi.tellg()/sizeof(Par);  //Tamanio del archivo / tamanio del objeto struct
	// tellg() me sirve para saber en donde estoy parado en el archivoy ese valor es el tamaño del archivo
	// archi.seekg() le pido que se valla al principio archi.seekg(0) me deja en el principio del archivo
	archi.seekg(0);
	for(int i=0;i<n;i++) {
		Par p;
		archi.read(reinterpret_cast<char*>(&p), sizeof(p));
		cout << p.i << " " << p.d << endl;
	}
	
	return 0;
}
