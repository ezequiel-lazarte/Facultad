#include <iostream>
using namespace std;

int main() {
	ifstream archi(nombre, ios::binary|ios::ate);
	///metodos para modificar o consultar la posicion en lectura
	archi.tellg(); //para consultar la posicion en bytes
	archi.seekg(0); //para cambiar la posicion en bytes
	archi.close();
	ofstream archivo(nombre, ios::binary|ios::ate);
	///metodos para modificar o consultar la posicion en escritura
	archi.tellp(); // para consultar la posicion en bytes
	archi.seekp(4); //para cambiar la posicion en bytes
	return 0;
}

