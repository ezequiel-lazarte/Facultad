#include <iostream>
using namespace std;
class Vector2D {
public:
	Vector2D() {	}
	Vector2D(int x, int y) : m_x(x), m_y(y) { 	}
	int VerX() { return m_x; }
	int VerY() { return m_y; }
	int operator*(Vector2D &v1) {	//Producto escalar osea retorna un escalar al multiplicar dos vectores
		return (m_x*v1.VerX())+(m_y*v1.VerY()); //(x1*x2 + y1*y2)
	}
	Vector2D operator%(int escalar) {
		return Vector2D(m_x*escalar, m_y*escalar);
	}
private:
	int m_x, m_y;
};
Vector2D operator*=(Vector2D &v1, Vector2D &v2) {	//Producto vectorial osea retorna un vector al multiplicar dos vectores
	return Vector2D((v2.VerY()-v1.VerY()),(v1.VerX()-v2.VerX())); //(y2-y1)x + (x1-x2)y
}

ostream & operator<<(ostream &o, Vector2D &v1) {
	o << v1.VerX() << "i + " << v1.VerY() << "j";
	return o;
}
int main() {
	/** Implemente una clase llamada Vector2D con dos números reales como atributos
	para representar un vector en el plano. Implemente operadores para los productos
	escalar y vectorial y el producto del vector por un real. Para elegir los operadores a
	sobrecargar en cada caso, analice la tabla de jerarquía de operadores y seleccione
	los operadores cuya jerarquía coincida con la que tienen dichos productos en el
	álgebra de vectores convencional.
	**/
	Vector2D v1(3, 4), v2(2, 1), v3;
	cout << "v1 es " << v1 << endl << "v2 es " << v2 << endl;
	int escalar = v1*v2;
	cout << "El producto escalar entre v1 y v2 es " << escalar << endl;
	
	v3 = v1*=v2; //multiplicacion de vectores
	cout << "El producto vectorial entre v1 y v2 es " << v3 << endl;
	
	Vector2D v4;
	v4= v1%4;
	cout << "El producto entre un vector y escalar es " << v4 << endl;
	return 0;
}

