#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int CuentaFrase(vector<string> v1);
int main() {
	/**Escriba un programa que abra un archivo con el texto de Don Quijote de Miguel de
	Cervantes (puede obtener el archivo desde la dirección:
	http://www.gutenberg.org/files/2000/old/2donq10.txt ) y cuente cuantas veces
	aparece en todo el texto la cadena “molinos de viento” (sin distinguir entre
	mayúsculas y minúsculas).
	**/
	ifstream archi("Don Quijote.txt");
	if(!archi.is_open()) {
		cout << "Error al abrir archivo" << endl;
		return 1;
	}
	vector<string> v;
	string aux;
	while(getline(archi,aux)) {
		v.push_back(aux);
	}
	int cant = CuentaFrase(v);
	cout << "La frase \"molinos de viento\" aparece un total de " << cant << " veces" << endl;
	return 0;
}
int CuentaFrase(vector<string> v1) {
	int pos=0, cant=0;
	for(size_t i=0;i<v1.size();i++) { 
		if(v1[i].find("molinos de viento", pos)) {
			pos = v1[i].find("molinos de viento", pos);
			++cant;
		}
	}
	return cant;
}
