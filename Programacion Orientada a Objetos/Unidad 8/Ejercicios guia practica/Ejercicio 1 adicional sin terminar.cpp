#include <iostream>
#include <map>
using namespace std;
class Config {
public :
	// constructores
	Config();
	Config(string filename);
	// cargar y guardar en archivo de texto
	int Load(string filename);
	int Save(string filename);
	// pedir un valor
	bool GetValue(string option, float &value, float def_val=0);
	bool GetValue(string option, int &value, int def_val=0);
	bool GetValue(string option, string &value, string def_val="");
	// agregar o modificar un valor
	bool SetValue(string option, float newValue);
	bool SetValue(string option, int newValue);
	bool SetValue(string option, string newValue);
private :
	map<string,string> entries;
};
int main() {
	/*Ejercicio 1 adicional
	Diseñe una clase que permita manejar un archivo de configuración con el formato
	que se muestra en el recuadro. Las opciones deberán ser almacenadas en un
	mapeo de tipo string a string, y los valores de las opciones serán convertidos a
	otros formatos (int, float, etc) cuando el usuario lo solicite.
	unaopcion=5
	otraopcion=hola
	fuerzagravedad=9.8v
	La clase debe proveer funcionalidades para:
	a. Leer un archivo de texto dado por el usuario y poblar el mapa con las
	opciones encontradas.
	b. Agregar una opción con su respectivo valor, si dicha opción ya existe su
	valor debe actualizarse. Se recomienda que esta función tenga varias
	sobrecargas para soportar distintos tipos de datos (int, float, etc) y los
	convierta a string para poder almacenarlos en el mapa.
	c. Devolver por referencia el valor asociado a una determinada opción y un
	booleano indicando si dicho valor se encontró o no en el mapa. Se
	recomienda que esta función tenga varias sobrecargas para soportar los
	diversos tipos de datos (int, float, etc).
	d. Guardar la configuración modificada en un archivo de texto.
	Se propone el siguiente prototipo para la clase:
	...
	Analice: ¿Podría reemplazar las sobrecargas de GetValue y SetValue por funciones
	genéricas?
	*/
	return 0;
}

