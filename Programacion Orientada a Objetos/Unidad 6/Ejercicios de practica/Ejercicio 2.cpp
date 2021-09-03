#include <iostream>
#include <fstream>
using namespace std;
struct Par{
	int i;
	float f;
};
int main() {
	/**Escriba un programa que abra el archivo generado en el ejercicio anterior y solicite al
	usuario que ingrese un entero, un flotante y una posición. El programa debe
	sobrescribir el par en la posición ingresada por el usuario por el nuevo par. Luego
	muestre la lista de datos en consola mostrando un par por línea.
	**/
	fstream archi("grupo.dat", ios::binary|ios::in|ios::out|ios::ate);
	if(!archi.is_open()) {
		cout << "Error al abrir el archivo" << endl;
		return 1;
	}
	int n = archi.tellg()/sizeof(Par);
	int pos;
	Par nuevo;
	cout << "Ingrese la posicion en la cual quiere insertar el nuevo par: "; cin >> pos;
	cout << "Ingrese el par, primero el entero luego el flotannte: "; cin >> nuevo.i >> nuevo.f;
	
	archi.seekp(pos*sizeof(Par), ios::beg);
	archi.write(reinterpret_cast<char*>(&nuevo), sizeof(nuevo));
	
	
	archi.seekg(0);
	for(int i=0;i<n;i++) {
		archi.read(reinterpret_cast<char*>(&nuevo), sizeof(nuevo)); 
		cout << "Par " << i << ": " << nuevo.i << " " << nuevo.f << endl;
	}
	
	
	return 0;
}

