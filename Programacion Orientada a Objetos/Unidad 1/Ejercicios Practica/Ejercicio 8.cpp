#include <iostream>
using namespace std;

int main() {
	/// Respuestas a ejercicio 8.
	
	// a) para llamar a la funci�n func se utilizan 3 par�metros, el 1ero es una variable que reserva 6 espacios en el stack 
	// �sea es un vector que no puede incrementarse es est�tico, el 2do par�metro es la posici�n en donde empieza el vector 
	// mas 6 posiciones lo cual es la ultima posici�n y el 3er argumento es la direcci�n de suma la cual se envia con un &suma.
	
	// b) en func se definen 3 par�metros de tipo puntero, el 1ero toma la primer posicion del vector, la 2da toma la ultima posicion
	// del vector que es x+6 y el 3ero es la direcci�n de memoria de suma.
	
	// c) la funci�n func no devuelve informaci�n por eso es de tipo void y lo que realiza es acumular la suma de los datos de un 
	// vector y los acumula en suma

	// d) La salida del programa es la variable suma la cual es un acumulador ya que sumo todos los valores que conten�a el vector
	// en si el resultado ser� 309.
	return 0;
}

