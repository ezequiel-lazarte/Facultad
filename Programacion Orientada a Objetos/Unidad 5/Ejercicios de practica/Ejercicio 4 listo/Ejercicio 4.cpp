#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Clave {
	string campo, valor;
};
class ConfigFile {
public:
	ConfigFile(string nombre_archi) : m_nombre_archivo(nombre_archi) {
		ifstream archi(m_nombre_archivo);
		if(!archi.is_open()) {
			cerr << "Error al abrir el archivo " << m_nombre_archivo << endl;
			return;
		}
		string linea;
		Clave aux;
		while(getline(archi,linea)) {
			if(linea[0]=='#') continue;
			if(linea.empty()) continue;
			if(linea.find("=") == string::npos ) continue;
			aux.campo = linea.substr(0,linea.find("="));
			aux.valor = linea.substr(linea.find("=")+1);
			v.push_back(aux);
		}
		archi.close();
	}
	string VerCampo(string campo) {
		for(size_t i=0;i<v.size();i++) { 
			if(v[i].campo == campo) {
				return v[i].campo;
			}
		}
		return "";
	}
	void ModificarValorDeCampo(string campo, string nuevo_valor) {
		for(size_t i=0;i<v.size();i++) { 
			if(v[i].campo == campo) {
				v[i].valor = nuevo_valor;
				return;
			}
		}
	}
	int VerCantidadDeClaves() { return v.size(); }
	Clave VerCampo(int pos) { return v[pos]; }
	Clave VerClave(int pos) { return v[pos]; }
	string VerClaveATravezDelCampo(string campo) {
		for(size_t i=0;i<v.size();i++) { 
			if(v[i].campo == campo) {
				return v[i].valor;
			}
		}
		return "";
	}
	void ActualizarArchivo() {
		ofstream archi(m_nombre_archivo, ios::trunc);
		for(size_t i=0;i<v.size();i++) 
			archi << v[i].campo << "=" << v[i].valor << endl;
		archi.close();
	}
private:
	string m_nombre_archivo;
	vector<Clave> v;
};
int main() {
	/** Un conjunto de archivos de texto contiene información guardada en el formato que
	se muestra en el recuadro, donde cada línea contiene el nombre de un campo y su
	respectivo valor separados por el signo igual (=). Las líneas que comienzan con el
	carácter '#' deben ser ignoradas.
	Escriba una clase llamada ConfigFile que permita interpretar el contenido de estos
	archivos. La clase debe poseer:
	a) un constructor que reciba el nombre del archivo y cargue sus datos en un
	vector de structs (cada elemento es struct con dos strings: campo y valor).
	b) un método para consultar el valor asociado a un campo
	c) un método para modificar el valor asociado a un campo
	d) un método para guardar el archivo con los datos actualizados
	**/
	string nombre;
	cout << "Ingrese el nombre del archivo a abrir: "; getline(cin,nombre);
	ConfigFile archi(nombre);
	cout << endl << "Claves leidas: " << endl;
	/// veo los campos y claves
	for(int i=0;i<archi.VerCantidadDeClaves();i++) { 
		cout << archi.VerClave(i).campo << "=" << archi.VerClave(i).valor <<endl;
	}
	///Veo un valor de cualquier campo
	string a, campo, nuevo_valor;
	cout << "Ingrese el nombre del campo para ver su valor: "; getline(cin,a);
	cout << "El valor del campo es: " << archi.VerClaveATravezDelCampo(a) << endl;
	
	///modifico el campo
	cout << "Ingrese el nombre del campo a modificar su valor: "; getline(cin,campo);
	cout << "Ingrese el nuevo valor del campo eleguido: "; getline(cin,nuevo_valor);
	archi.ModificarValorDeCampo(campo, nuevo_valor);
	///actualizo el archivo
	archi.ActualizarArchivo();
	
	///Veo un valor de cualquier campo
	string b;
	cout << "Ingrese el nombre del campo para ver su valor: "; getline(cin,b);
	cout << "El valor del campo es: " << archi.VerClaveATravezDelCampo(b) << endl;
	
	return 0;
}

/// remplazar esto en el txt para volver a probar
/**
#ejemplo de archivo de configuracion
materia=Programacion Orientada a Objetos
carrera=Ingenieria en Informatica
facultad=Facultad de Ingeniería y Ciencias Hídricas
universidad=Universidad Nacional del Litoral
#esta linea hay que ignorarla, igual que las 3 ultimas
nro_unidad=5
nombre_unidad=Flujos de entrada/salida
otro_campo=otro_valor
otro_campo_mas=otro_valor_mas
#campo_que_no_se_lee_1=basura
#campo_que_no_se_lee_2=basura
#campo_que_no_se_lee_3=basura
**/
