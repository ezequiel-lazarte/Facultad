#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	/**Escriba un programa que genere un archivo binario con una lista de 100 enteros
	ordenados de forma creciente (por ejemplo: 0, 5, 10, 15, 20, 25...). Luego escriba
	otro programa que permita insertar (no reemplazar) un nuevo dato de tipo entero,
	ingresado por el usuario, en el archivo manteniendo el orden creciente. Evite utilizar
	vectores auxiliares.
	**/
	
	fstream archi("ejercicio3.dat", ios::trunc|ios::binary|ios::out);
	vector<int> v;
	int entero;
	for(int i=0;i<10;i++) {
		entero = rand()%101+2;
		v.push_back(entero);
		cout << "Nro Nº" << i+1 << ": " << v[i] << endl;
	}
	sort(v.begin(), v.end());

	cout << "Vector ordenado: " << endl;
	for(size_t i=0;i<v.size();i++) {
		archi.write(reinterpret_cast<char*>(&v[i]),sizeof(v[i]));
		cout << "Nro Nº" << i+1 << ": " << v[i] << endl;
	}
	archi.close();

	return 0;
}

