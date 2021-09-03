#include <iostream>
using namespace std;

int main() {
	/// ofstream es salida o escritura y ifstream es lectura o entrada
	///dos formas de abrir un archivo de texto uno es por medio del constructor y otro por un metodo "Open" de ifstream
	ifstream archi("texto.txt");
	archi.open("texto.txt");
	/// para cerrar el archivo se usa
	archi.close();
	///operadores de alcance o banderitas que se pueden usar en los archivos de texto
	ios::app /// abro el archivo y con app agrego datos al final
	ios::trunc /// abro el archivo pero borra todo el contenido antes de abrirlo 
	/// para verificar si se abrio correctamente
	if(!archi.is_open()) {  /// is_open() es el metodo que me da verdadero si se abrio bien el archivo
		cerr << "Error no se pudo abrir el archivo" << endl;
		return 1;
	}
	/// para escribir << o leer >> con archivos de texto
	/// escribo <<
	archi << nombre << endl;
	archi << set_precision(2) << prom << endl;
	///leo >>
	getline(archi, nombre);
	archi >> nota;
	///siempre como nombre de los archivos no poner nombres absolutos como c":\\zza\\user\\dato.txt"
	
	
	///manipuladores de texto
	setw(3)  /// este manipulador setea el ancho osea le da 3 espacios "1   2"
	set_precision(3) /// este le da n decimales a los numeros flotantes
	left ///derecha
	right /// izquierda
	fixed /// sirve para mostrar el resultado en decimales y no en notacion cientifica
	
	
	
	/// string operadores
	
	/// el = copia/asigna
	string s1 = "gta", s2 = "juego";
	s1 = s2;
	
	/// el + concatena
	string s3 = s1 + " es un " + s2;
	cout << s3 << endl; /// muestra "gta es un juego"
	
	/// los operadores ==, <, <=, >, >=, != comparan lexicograficamente (segun el codigo ASCII)
	/// Extraer sub-cadenas con el metodo substr()
	string s1 = "Gta 5 es un videojuego!";
	
	string s2 = s1.substr(0,5);
	cout << s2 << endl; /// muestra "Gta 5"
	
	string s3 = s1.substr(12);
	cout << s3 << endl; /// muestra "videojuego!"
	
	cout << s1 << endl; /// muestra "Gta 5 es un videojuego!"
	/// el 1ero argumento del metodo es la pos inicial y el 2do es la longitud
	/// si solo se indica la pos inicial, va hasta el final de la cadena la longitud
	to_string() ///convierte un entero o float en cadena
	return 0;
}
