#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<string> LeeDatosArchivo() {
	vector<string> aux;
	ofstream archi("Inscriptos.txt");
	string x;
	while(archi >> x) {
		aux.push_back(x);
	}
	archi.close();
	return aux;
}
int CalculaTamanioComisiones(int n) {
	
}
int main() {
	/**Se tiene un archivo “inscriptos.txt” con una lista de nombres de alumnos inscriptos
	al cursado de Fundamentos de Programación. Se desea distribuir los estudiantes
	en comisiones de práctica de no más de 30 alumnos. Escriba un programa que
	determine cuantas comisiones deberían formarse de acuerdo a la cantidad de
	inscriptos y reparta los alumnos en comisiones de igual tamaño, guardando la lista
	de alumnos de cada comisión en archivo de texto “comision1.txt”, “comision2.txt”, …
	“comisionN.txt”.
	Ayuda: puede utilizar la clase stringstream como auxiliar para concatenar en un
	string texto y números para formar los nombres de los archivos.
	**/
	fstream archivo("inscriptos.txt");
	if(!archivo.is_open()) {
		cout << "Error el alchivo no se encontro" << endl;
		return 1;
	}
	vector<string> nombres = LeeDatosArchivo();
	int nro_comis = CalculaTamanioComisiones(nombres.size());
	return 0;
}

