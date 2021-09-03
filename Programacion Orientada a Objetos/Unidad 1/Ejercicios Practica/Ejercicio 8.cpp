#include <iostream>
using namespace std;

int main() {
	/// Respuestas a ejercicio 8.
	
	// a) para llamar a la función func se utilizan 3 parámetros, el 1ero es una variable que reserva 6 espacios en el stack 
	// ásea es un vector que no puede incrementarse es estático, el 2do parámetro es la posición en donde empieza el vector 
	// mas 6 posiciones lo cual es la ultima posición y el 3er argumento es la dirección de suma la cual se envia con un &suma.
	
	// b) en func se definen 3 parámetros de tipo puntero, el 1ero toma la primer posicion del vector, la 2da toma la ultima posicion
	// del vector que es x+6 y el 3ero es la dirección de memoria de suma.
	
	// c) la función func no devuelve información por eso es de tipo void y lo que realiza es acumular la suma de los datos de un 
	// vector y los acumula en suma

	// d) La salida del programa es la variable suma la cual es un acumulador ya que sumo todos los valores que contenía el vector
	// en si el resultado será 309.
	return 0;
}

