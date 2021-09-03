#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	/**Luego escriba
	otro programa que permita insertar (no reemplazar) un nuevo dato de tipo entero,
	ingresado por el usuario, en el archivo manteniendo el orden creciente. Evite utilizar
	vectores auxiliares.
	**/
	fstream archi("ejercicio3.dat", ios::binary|ios::in|ios::out|ios::ate);
	
	if(!archi.is_open()) {
		cout << "Error al abrir el archivo" << endl;
		return 1;
	}
	int tamanio = archi.tellg()/sizeof(int);
	archi.seekg(0);
	vector<int> v;
	for(int i=0;i<tamanio;i++) {
		int nro=0;
		archi.read(reinterpret_cast<char*>(&nro), sizeof(nro));
		v.push_back(nro);
	}
	int nuevo_dato=0;
	cout << "ingrese el nuevo dato de tipo entero a insertar: "; cin >> nuevo_dato;
	v.push_back(nuevo_dato);
	sort(v.begin(),v.end());
	archi.close();
	
	archi.open("ejercicio3.dat", ios::trunc);
	for(size_t i=0;i<v.size();i++) { 
		archi.write(reinterpret_cast<char*>(&v[i]), sizeof(v[i]));
		cout << "dato " << i+1 << ": " << v[i] << endl;
	}
	archi.close();
	return 0;
}
