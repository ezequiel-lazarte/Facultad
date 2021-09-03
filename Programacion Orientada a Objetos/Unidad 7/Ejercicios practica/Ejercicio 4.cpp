#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
template<typename T>
class ManejadorArchivo {
public:
	ManejadorArchivo(string nombre_archivo) : m_nom_arch(nombre_archivo) {		}
	void AgregarRegistro(T registro) { m_registros.push_back(registro); }
	T VerRegistro(int pos) { return m_registros[pos]; }
	void ModificarRegistro(int pos, T nuevo_registro) { m_registros[pos] = nuevo_registro; }
	void ActualizarRegistros() {
		fstream archi(m_nom_arch, ios::binary|ios::in|ios::ate);
		for(int i=0;i<m_registros.size();i++) {
			archi.write(reinterpret_cast<char*>(&m_registros[i]), sizeof(m_registros[i]));
		}
		archi.close();
	}
private:
	string m_nom_arch;
	vector<T> m_registros;
};
int main() {
	/**Desarrolle una clase templatizada llamada ManejadorArchivo que posea métodos
	y atributos para manipular un archivo binario que contenga registros del tipo de
	dato especificado por el parámetro. La clase debe poseer métodos para:
	a. Abrir un archivo binario y cargar los registros en memoria.
	b. Obtener el registro en una posición especificada por el usuario.
	c. Modificar el registro en una posición determinada.
	d. Actualizar la información del archivo con los cambios.
	e. Utilice la clase desde un programa cliente para leer los registros escritos en
	el archivo binario generado en el ejercicio 6.5.
	**/
	int nro_de_registros=0;
	float puntaje=0;
	ManejadorArchivo <float>archivo1("Registros.dat");
	cout << "Ingrese puntaje: "; cin >> puntaje;
	while(puntaje!=-1) {
		archivo1.AgregarRegistro(puntaje);
		cout << "Ingrese puntaje: "; cin >> puntaje;
		nro_de_registros++;
	}
	for(int i=0;i<nro_de_registros;i++) {
		cout << "Registro Nº" << i+1 << ": " << archivo1.VerRegistro(i) << endl;
	}
	return 0;
}

