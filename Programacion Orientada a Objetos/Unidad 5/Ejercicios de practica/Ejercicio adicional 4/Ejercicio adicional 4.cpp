#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class AnalizaTexto {
public:
	AnalizaTexto(string nombre_archivo) : m_nombre_archivo(nombre_archivo) {
		ifstream archi(m_nombre_archivo);
		string aux;
		/// guardo el texto en un vector
		while(getline(archi, aux)) {
			m_linea.push_back(aux);
		}
	}
	int LongitudDelTexto() { ///a)
		int acum=0;
		for(size_t i=0;i<m_linea.size();i++) { 
			acum += m_linea[i].length();
		}
		return acum;
	}
	int CantidadDeParrafos() { ///b)
		int cantparafos=1;
		for(size_t i=0;i<m_linea.size();i++) { 
			if(m_linea[i].empty()) {
				cantparafos++;
			}
		}
		return cantparafos;
	}
	int CantidadDeLetras() {
		
		int cantletras=0, pos=0;
		for(size_t i=0;i<m_linea.size();i++) { 
			
		}
		
		return cantletras;
	}
private:
	string m_nombre_archivo;
	vector<string> m_linea;
};
int main() {
	/**Escriba una clase AnalizaTexto con métodos para analizar un archivo de texto (que
	contendrá varios párrafos) y obtener los siguientes resultados:
	A. cantidad de caracteres en el texto (longitud del mismo)
	B. cantidad párrafos (nota: recuerde ignorar líneas en blanco)
	C. cantidad de letras, cantidad de espacios en blanco, y de otros caracteres
	(como signos depuntuación) por separado.
	Proponga un programa cliente que la utilice.
	**/
	AnalizaTexto archi("Texto.txt");
	
	cout << "La longitud del texto es de " << archi.LongitudDelTexto() << " de caracteres" << endl;
	cout << "La cantidad de parrafos del texto es de " << archi.CantidadDeParrafos() << endl;
	return 0;
}
