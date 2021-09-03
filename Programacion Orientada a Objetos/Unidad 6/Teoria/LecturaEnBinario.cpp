#include <iostream>
#include <fstream>
using namespace std;
struct Par {
	int i;
	double d;
};
int main() {
	// aca voy a leer el archivo que cree antes o uno que cree a mano. OJO si lo cree con un struct lo debo leer con un struct 
	// y ademas el struct tiene que definir los datos igual como se definio en el preograma que lo creo y los tipos de
	// datos tienen que ser los mismos
	ifstream archi("datos.eze", ios::binary);
	for(int i=0;i<10;i++) {
		Par p;
		archi.read(reinterpret_cast<char*>(&p), sizeof(p));
		cout << p.i << " " << p.d << endl;
	}
	
	return 0;
}

