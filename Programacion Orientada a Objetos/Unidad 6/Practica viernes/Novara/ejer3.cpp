#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Archivo {
	fstream f;
public:
	Archivo(string nom) : f(nom,ios::binary|ios::in|ios::out) { }
	int leer(int p) {
		f.seekg(p*sizeof(int));
		int i; 
		f.read(reinterpret_cast<char*>(&i),sizeof(int));
		return i;
	}
	int operator[](int i) { return leer(i); }
	void escribir(int p, int x) {
		f.seekp(p*sizeof(int));
		f.write(reinterpret_cast<char*>(&x),sizeof(int));
	}
	int size() {
		f.seekg(0,ios::end);
		return f.tellg()/sizeof(int);
	}
};

int main() {
	
	Archivo v("lista.dat");
	
	int d; cin >> d;
	
	// determinar la pos
	int p = 0, n = v.size();
	while(p<n and d>v.leer(p)) ++p;
	
	// insertar
	for(int i=n; i>p ; --i)
		v.escribir(i, v.leer(i-1)); // v[i] = v[i-1]
	v.escribir(p, d); // v[p] = d
	
	// mostrar como queda
	for(int i=0;i<v.size();++i) { 
		cout << v[i] << " ";
	}
	
	return 0;
}

