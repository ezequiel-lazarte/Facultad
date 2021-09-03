#include <iostream>
#include <fstream>
using namespace std;

struct Par {
	int x;
	float y;
};

int main() {
	
	Par par;
	cout << "Ingrese el nuevo par: ";
	cin >> par.x >> par.y;
	int pos; 
	cout << "Ingrese la posicion: ";
	cin >> pos;
	
	fstream f("datos.dat",ios::binary|ios::in|ios::out|ios::ate);
	int tamanio = f.tellg();
	int n = tamanio / sizeof(Par);
	
	f.seekp( pos*sizeof(Par) );
	f.write(reinterpret_cast<char*>(&par),sizeof(par));
	
	f.seekg(0);
	for(int i=0;i<n;++i) { 
		f.read(reinterpret_cast<char*>(&par),sizeof(par));
		cout << "Par " << i << ": " << par.x << ", " << par.y << endl;
	}
	
	return 0;
}

