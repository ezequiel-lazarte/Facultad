#include <iostream>
using namespace std;

int main() {
///	A continuación se declara un arreglo a de 10 elementos enteros: int x[10]={110,
///	120, 130, 140, 150, 160, 170, 180, 190, 200};. El elemento inicial x[0] se ubica en la
///	dirección de memoria 0x00011E4. Determine lo que que representan las siguientes
///	expresiones:
	int x[10]={110,120, 130, 140, 150, 160, 170, 180, 190, 200};
	cout << *x+3 <<endl;
///	a) x;
	// x representa el valor de memoria de la primera posicion del vector x[]
///	b) *x;
	// *x representa el valor del contenido de la primera posicion de del vector x que seria 110
///	c) (x+4);
	// x+4 muestra el espacio de memoria en la posicion 4 del vector x, este avanza 4 lugares o 4 packs de bits
///	d) *(x+4);
	// muestra el valor del contenido de la posicion 4 del vector que seria 150
///	e) *x+3;
	// muestra la suma del contenido de la primer posicion de x + 3 que da 113
///	f) (*x)+3;
	// muestra lo mismo que antes
	
	return 0;
}

