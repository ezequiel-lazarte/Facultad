#include <iostream>
#include <iomanip>
using namespace std;
template<typename T>
class Rect {
public:
	Rect(T altura=0, T largo=0) : m_altura(altura), m_largo(largo) {		}
	T VerAltura() { return m_altura; }
	T VerLargo() { return m_largo; }
	T ModificarAltura(T altura) { m_altura = altura; } 
	T ModificarLargo(T largo) { m_largo = largo; } 
	T VerArea() { return m_largo*m_altura; }
private:
	T m_altura, m_largo;
};
int main() {
	/**Dise�e e implemente una clase templatizada llamada Rect que permita representar
	un rect�ngulo. La clase debe poseer m�todos para obtener el alto y ancho del
	rect�ngulo. Implemente los m�todos que considere necesarios para la inicializaci�n
	o carga de datos. Cree un programa cliente que instancie un rect�ngulo cuyas
	coordenadas sean enteros y otro cuyas coordenadas sean de tipo double.
	**/
	int altura=rand()%100, largo=rand()%100;
	Rect <int>r1(altura, largo);
	
	cout << "La altura de rec1 es: " << r1.VerAltura() << endl;
	cout << "El largo de rec1 es: " << r1.VerLargo() << endl;
	cout << "El area de rec1 es: " << r1.VerArea() << endl;
	
//	cout << "La altura de rec1 es: " << fixed << setprecision(2) << r1.VerAltura() << endl;
//	cout << "El largo de rec1 es: " << fixed << setprecision(2) << r1.VerLargo() << endl;
//	cout << "El area de rec1 es: " << fixed << setprecision(2) << r1.VerArea() << endl;
	
	return 0;
}

