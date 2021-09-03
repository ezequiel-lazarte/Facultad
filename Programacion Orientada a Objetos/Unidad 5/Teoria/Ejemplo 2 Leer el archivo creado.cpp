#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int x = 0, c = 0;
	ifstream archi("texto.txt");
	if(!archi.is_open()) {
		cerr << "Error al abrir el archivo" << endl;
		return 1;
	}
	while(archi>>x) { /// siempre al leer un archivo hago esto para asegurarme que se lee completo
		cout << x << " ";
		c++; /// para contar cuantos datos hemos leido
	}
	
	cout << endl << "Hay " << c << " en el archivo" << endl;
	
	archi.close();
	return 0;
}

