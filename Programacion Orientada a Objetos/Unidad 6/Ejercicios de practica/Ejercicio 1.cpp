#include <iostream>
#include <fstream>
using namespace std;
struct Par{
	int i;
	float f;
};
int main() {
	/**
	Escriba a través de un programa C++ un archivo binario llamado grupo.dat , formado
	por un conjunto de 200 pares de números generados aleatoriamente. Cada par de
	datos se conforma por un entero y un flotante.**/
	fstream archi("grupo.dat", ios::binary|ios::out|ios::trunc);
	Par dato; 
	for(int i=0;i<10;i++) {
		dato.i = rand()%100-1;
		dato.f=(rand()%100)/10.0;
		archi.write(reinterpret_cast<char*>(&dato), sizeof(dato));
		cout << dato.i << " " << dato.f << endl;
	}
	archi.close();
	return 0;
}

