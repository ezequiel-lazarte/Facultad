#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class ConfigFile {
	struct Par { string clave, valor; };
	vector<Par> m_v;
	string m_nombre;
public:
	ConfigFile(string nombre) : m_nombre(nombre) {
		ifstream fin(nombre);
		if (!archi_in.is_open()) {
			cerr << "No se pudo abrir el archivo " << nombre << endl;
			return 1;
		}
		string linea;
		while(getline(fin,linea)) {
			if (linea.empty()) continue;
			if (linea[0]=='#') continue;
			size_t pos_igual = linea.find('=');
			if (pos_igual==string::npos) {
				cerr<<"Error leyendo " << nombre <<endl;
				return;
			}
			Par p;
			p.clave = linea.substr(0,pos_igual);
			p.valor = linea.substr(pos_igual+1);
			m_v.push_back(p);
		}
	}
	string Ver(string clave) const {
		for(Par p:m_v)
			if (p.clave==clave) return p.valor;
		return "";
	}
	void Modificar(string clave, string nuevo_valor) {
		for(Par &p:m_v) {
			if (p.clave==clave) {
				p.valor = nuevo_valor;
				return;
			}
		}
		m_v.push_back({clave,nuevo_valor});
	}
	void Guardar() const {
		ofstream fout(m_nombre,ios::trunc);
		for(Par p:m_v)
			fout << p.clave << "=" << p.valor << endl;
	}
};


