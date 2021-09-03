#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct Alumno{
	string nombre;
	int nota1, nota2;
};
void modificar(string nomb, int n1, int n2);
vector<Alumno> CargarDatosArchivo();
void GeneraOtroArchivo() {
	vector<Alumno> aux = CargarDatosArchivo();
	ofstream archi("promedio.txt"); /// Escritura: Me crea un archivo nuevo llamado promedio.txt
	for(size_t i=0;i<aux.size();i++) {
		float prom = (aux[i].nota1+aux[i].nota2)/2.0;
		archi << setw(20) << left << aux[i].nombre << setw(10) << setprecision(1) << fixed << prom;
		if(prom>=70.0) {
			archi << setw(10) << right << "Promociono" << endl;
		} else {
			if(prom>=40 or prom<70) {
				archi << setw(10) << right << "Regular" << endl;
			} else {
				archi << setw(10) << right << "Libre" << endl;
			}
		}
		
	}
	archi.close();
}
int main() {
	/**En un archivo de texto llamado lista.txt , como el que se
	muestra a la derecha, se encuentran los nombres y notas
	de los alumnos de una comisión de Programación
	Orientada a Objetos.
	a) Escriba una función modificar que reciba el nombre
	de un alumno y dos notas, y modifique el archivo
	reemplazando las dos notas de ese alumno.
	b) Escriba una función que lea la lista del archivo y genere otro archivo de texto
	promedios.txt con una tabla donde cada línea posea el nombre, el promedio,
	y la condición final de cada uno de los alumnos.
	Ayuda: utilice manipuladores de flujo ( setw , right , left , fixed , setprecision ) para dar
	formato a la tabla del archivo que se genera en b).
	**/
	
	fstream archi("lista.txt");
	if(!archi.is_open()) {
		cout << "No se pudo abrir" << endl;
		return 1;
	}
	modificar("Garcia Ana", 91, 35);
	
	GeneraOtroArchivo();
	
	archi.close();
	
	return 0;
}
void modificar(string nomb, int n1, int n2) {
	vector<Alumno> alumnos = CargarDatosArchivo();
	for(size_t i=0;i<alumnos.size();i++) {
		if(alumnos[i].nombre==nomb) {
			alumnos[i].nota1 = n1;
			alumnos[i].nota2 = n2;
			break;
		}
	}
	ofstream arch("lista.txt",ios::trunc);
	for(size_t i=0;i<alumnos.size();i++) {
		arch << alumnos[i].nombre << endl;
		arch << alumnos[i].nota1 << " " << alumnos[i].nota2 << endl;
	}
	arch.close();
}
vector<Alumno> CargarDatosArchivo() {
	vector<Alumno> aux;
	ifstream archi("lista.txt");
	Alumno a;
	while(getline(archi, a.nombre)) {
		archi >> a.nota1 >> a.nota2;
		aux.push_back(a);
		archi.ignore();
	}
	archi.close();
	return aux;
}	
