#include <iostream>
#include <cstring>
using namespace std;

int main() {
	/// un cstring es un arreglo de char[N] que contiene una cadena con el caracter '\0' para indicar donde termina
	char str[10] = "Hola"; ///escribo el vector de char implicitamente con los " "
	
	// para pasar de string a vector de char:
	
	///strcpy copia de un cstring a otro
	/// c es una cadena de char
	strcpy(c /* adonde copio*/, s.c_str() /*Y que copio*/); /// me devuelve un vector char
	
	
	/// string::c_str() es un metodo de string que retorna su contenido
	/// como un cstring(con el '\0' incluido
	
	
	//para pasar de vector de char a string
	
	string s1(c), s2; /// aca estoy creando el string s1 con cada char utilizando el constructor de la clase string
	s2 = c; /// el vector de char se copio al dato de tipo string porque en la clase string
	/// ahy una sobrecarga del operador "=" de asignacion
	
	//Ejemplo escribir
	string str = "hola mundo!";
	char aux[256];
	strcpy(aux, str.c_str());
	ofstream archi("archi.dat", ios::binary);
	archi.write(aux, sizeof(aux));
	
	//ejemplo leer
	char aux[256];
	ifstream arch("archi.dat", ios::binary);
	arch.read(aux, sizeof(aux));
	string str = aux;
	cout << str;
	return 0;
}

