#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Persona {
	string nombre;
	unsigned int telefono;
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
	void AgregarContacto(string nombre, unsigned int nro_telefono) {
		Persona nuevo;
		nuevo.nombre = nombre;
		nuevo.telefono = nro_telefono;
		m_v.push_back(nuevo);
		Guardar();
	}
private:
	vector<Persona> m_v;
	string m_nombre_archivo;
	void Guardar() {
		ofstream archi(m_nombre_archivo, ios::trunc);
		for(size_t i=0;i<m_v.size();i++) { 
			archi << m_v[i].nombre << endl;
			archi << m_v[i].telefono << endl;
		}
	}
};
int main() {
	/**Agregue a la clase desarrollada en el ejercicio anterior un método
	AgregarContacto(...) que reciba los datos de un nuevo contacto, y lo agregue al
	arreglo; y agregue un método Guardar que actualice el archivo. Utilice la función
	desde un programa cliente para agregar un nuevo contacto y abra nuevamente el
	archivo desde un editor de texto para comprobar que los datos fueron agregados
	correctamente.
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
	
	string nom_per_nueva;
	unsigned int nro_tel = 0;
	cout << "Ingrese el nombre de la persona que quiere agregar a sus contactos: "; getline(cin, nom_per_nueva);
	cout << "Ingrese el numero de telefono de la persona a agregar: "; cin >> nro_tel;
	cin.ignore();
	vecinos.AgregarContacto(nom_per_nueva, nro_tel);
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
