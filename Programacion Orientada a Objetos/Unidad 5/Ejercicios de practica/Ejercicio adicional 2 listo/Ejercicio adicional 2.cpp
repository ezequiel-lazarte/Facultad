#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Persona {
	string nombre;
	int telefono;
};
class Agenda {
public:
	Agenda() {		}
	bool Cargar(string nombre_archivo) {
		m_nombre_archivo = nombre_archivo;
		fstream archi(nombre_archivo, ios::out|ios::in);
		if(!archi.is_open()) {
			return false;
		}
		Persona aux;
		while(getline(archi,aux.nombre)) {
			archi >> aux.telefono;
			m_v.push_back(aux);
			archi.ignore();
		}
		return true;
	}
	Persona Buscar(string nombre_apellido) {
		for(size_t i=0;i<m_v.size();i++) { 
			if(m_v[i].nombre == nombre_apellido) {
				return m_v[i];
			}
		}
		Persona vacia;
		vacia.nombre = "Sin nombre";
		vacia.telefono = 0;
		return vacia;
	}
private:
	vector<Persona> m_v;
	string m_nombre_archivo;
};
int main() {
	/**
	Escriba un archivo de texto desde un editor de textos
	cualquiera (por ejemplo: el Bloc de Notas de Windows).
	Dicho archivo debe contener los nombres y números
	telefónicos de N personas con el formato mostrado en
	el recuadro. Guarde el archivo con el nombre agenda.txt
	u otro nombre de su elección.
	
	a) Diseñe una clase llamada Agenda con un arreglo de structs que permita almacenar
	nombres y números telefónicos de un conjunto de personas.
	b) Implemente un método Cargar que reciba un objeto de tipo std::string con el
	nombre del archivo que contiene los datos. El mismo debe abrir el archivo y
	cargar los datos de las personas en retornando un bool que indique si la
	lectura se realizó con éxito (true) o si ocurrieron errores durante la apertura
	del archivo (false).
	c) Implemente un método Buscar que debe recibir un std::string con parte del
	nombre o del apellido de un contacto y devuelva los datos de la primer
	ocurrencia que coincida con dicha cadena.
	d) Codifique un programa cliente que cargue los datos del archivo,
	**/
	Agenda vecinos;
	
	if(vecinos.Cargar("Mi agenda.txt")) { 
		cout << "Se ha leido con exito" << endl;
	} else {
		cout << "Error el archivo no se pudo abrir" << endl;
		return 1;
	}
	
	Persona desconocido = vecinos.Buscar("Garcia Ana");
	
	cout << "La persona que buscaba es " << desconocido.nombre << " y su telefono es " << desconocido.telefono << endl;
	return 0;
}
/**
Lopez Javier
342569085
Garcia Ana
342778180
Farias Daniel
342606234
**/
