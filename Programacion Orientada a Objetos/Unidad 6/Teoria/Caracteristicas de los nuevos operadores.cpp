#include <iostream>
using namespace std;

int main() {
	ofstream archivo("grupo.dat",ios::binary); // indico que voy a trabajar en binario
	
	int x=3;
	archivo.write(reinterpret_cast<char*>(&x), sizeof(x));  // reinterpret_cast<char*> me convierte la variable en un arreglo de char
	// escribo en un archivo con write osea lo que este es esa memoria lo escribe en el archivo, el 1er argumento 
	// es la direccion de memoria del dato (si no es de tipo char ponemos reinterpret_cast<char*> y si si es char lo indico 
	// como const) y el 2do es el tamanio en bytes
	ifstream archivo("grupo.dat",ios::binary);
	archivo.read(reinterpret_cast<char*>(&x),sizeof(x));
	
	ios::app // para escribir al final
	ios::trunc // para borrar el contenido y escribir por encima
	ios::binary //indico que el archivo es binario
	// si uso fstream in y out me sirve para decir si escribo o solo leo
	ios::in // Abrilo para escribir pero si ya existe no lo borro puedo modificarlo
	ios::out // se habre para lectura, y no borra los datos
	ios::ate //al empezar el cursor se ubica al final y solo puedo agregar osea escribir nomas y puedo volver para atras
	ios::beg //
	
	int x;
	sizeof(x); //me devuelve el tamaño de x en bytes en este caso 4 bytes
	return 0;
}

