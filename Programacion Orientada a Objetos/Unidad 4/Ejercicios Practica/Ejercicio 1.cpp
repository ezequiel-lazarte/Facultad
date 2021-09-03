#include <iostream>
using namespace std;
class Racional {
public:
	Racional(int n, int d) : num(n), den(d) {}
	int VerNum() { return num; }
	int VerDen() { return den; }
	Racional operator++(int);
	Racional & operator++();
	Racional & operator=(Racional &r1);
private:
	int num, den;
};
Racional Racional::operator++ (int) { //posincremento
	Racional aux=*this;
	num=num+den;
	return aux;
}
Racional & Racional::operator++ () { //preincremento
	num = num+den;
	return *this;
}
Racional & Racional::operator=(Racional &r1) {
	num = r1.num;
	den = r1.den;
	return *this;
}

/// Funciones Globales

Racional operator+(Racional r1, Racional r2) {
	return Racional(r1.VerNum()*r2.VerDen()+r2.VerNum()*r1.VerDen(), r1.VerDen()*r2.VerDen());
}
Racional operator*(Racional r1, Racional r2) {
	return Racional(r1.VerNum()*r2.VerNum(), r1.VerDen()*r2.VerDen());
}

int main() {
///	Dada la clase Racional mostrada en el recuadro:
///	Implemente sobrecargas para los siguiente operadores:
///	-Å El operador + para sumar dos objetos de la clase Racional .
///	Å- El operador * para multiplicar un objeto de tipo Racional por un entero.
///	-Å El operador ++ que permita incrementar en una unidad un numero racional.
///	Finalmente, compruebe el funcionamiento de los operadores con el siguiente
///	programa cliente:
///	Si ocurren errores de compilaciÛn, explique su causa e implemente las
///	correcciones necesarias.
///	Analice: øQuÈ otro operador se utiliza para la clase R acional en Èste programa
///	cliente? øPor quÈ no es necesario sobrecargarlo?
	// No es necesario sobrecargar el = ya que por defecto viene sobrecargado
	
//	Racional a(3, 5), b(2, 3), c(0, 1);
//	c = a+b;
//	cout << c.VerNum() << " " << c.VerDen() << endl;
//	c = a*b;
//	c = a+b+c;
//	c = a*b*c;
//	b = c++; // error por que es preincremento no posincremento
//	a = ++c;
//	cout << a.VerNum() << " " << a.VerDen() << endl;
//	cout << b.VerNum() << " " << b.VerDen() << endl;
	
	
	
	Racional r1(3, 4);
	Racional r2(5, 2);
	Racional r3 = r1+r2;
	cout << "La suma del Racional r1 y r2 es: " << r3.VerNum() << "/" << r3.VerDen() << endl;
	Racional r4(2, 3);
	Racional r5 = r4*r1;
	cout << "El producto es valor de r5: " << r5.VerNum() << "/" << r5.VerDen() << endl;
	r5++;
	cout << "r5++ vale: " << r5.VerNum() << "/" << r5.VerDen() << endl;
	cout << "r4++ vale: " << r4.VerNum() << "/" << r4.VerDen() << endl;
	++r4;
	cout << "r4++ ahora vale: " << r4.VerNum() << "/" << r4.VerDen() << endl;
}
