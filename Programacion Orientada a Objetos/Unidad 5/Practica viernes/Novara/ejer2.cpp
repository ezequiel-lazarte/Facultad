#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

struct Alumno {
	string nombre;
	int n1, n2;
};

vector<Alumno> cargarDatos() {
	vector<Alumno> v;
	ifstream fin("lista.txt");
	if (!fin.is_open()) {
		cerr << "No se pudo abrir el archivo lista.txt" << endl;
		return v;
	}
	Alumno a;
	while( getline(fin,a.nombre) && fin >> a.n1 >> a.n2 ) {
		fin.ignore();
		v.push_back(a);
	}
	return v;
}

int buscar(const vector<Alumno> &v, string nom) {
	for(size_t i=0;i<v.size();++i)
		if (v[i].nombre == nom) return i;
	return -1;
}

void guardarDatos(const vector<Alumno> &v) {
	ofstream fout("lista.txt",ios::trunc);
	for(Alumno a : v)
		fout << a.nombre << endl << a.n1 << " " << a.n2 << endl;
}

bool modificarNota(string nom, int i1, int i2) {
	vector<Alumno> v = cargarDatos();
	int pos = buscar(v,nom);
	if (pos==-1) return false;
	v[pos].n1 = i1; v[pos].n2 = i2;
	guardarDatos(v);
	return true;
}

void generarPromedios() {
	ofstream fout("promedios.txt",ios::trunc);
	vector<Alumno> v = cargarDatos();
	fout << setw(25) << left << "Nombre"
		<< setw(7) << right << fixed << setprecision(2) << "Prom."
		<< setw(14) << right << "Condicion" << endl;
	for(Alumno a : v) {
		float prom = (a.n1+a.n2)/2.0;
		string cond = "libre";
		if (prom>=70 and a.n1>=60 and a.n2>=60) cond = "promocionado";
		else if (a.n1>=40 and a.n2>=40) cond = "regular";
		
		fout << setw(25) << left << a.nombre 
			 << setw(7) << right << fixed << setprecision(2) << prom 
			 << setw(14) << right << cond << endl;
	}
}

int main() {
	
	if ( modificarNota("Lopez Javier",100,100) )
		cout << "Notas modificadas" << endl;
	else
		cout << "No se encontró el alumno" << endl;
	
	generarPromedios();
	
	return 0;
}

