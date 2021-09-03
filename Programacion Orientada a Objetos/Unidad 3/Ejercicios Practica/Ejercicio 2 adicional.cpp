#include <iostream>
#include <cmath>
using namespace std;
class Triangulo{
public:/** area o superficie es igual a 1/2*altura*base y el perimetro es a+b+c **/
	Triangulo(float lado_a, float lado_b, float base, float altura) : m_lado_a(lado_a), m_lado_b(lado_b), m_base(base), m_altura(altura)  {		}
	float ObtenerSuperficie() { return (m_altura*m_base)/2; }
	float ObtenerPerimetro() { return m_lado_a + m_lado_b + m_base; }
private:
	float m_lado_a, m_lado_b, m_base, m_altura;
};
class Rectangulo{
public:
	Rectangulo(int altura, int base) : m_altura(altura), m_base(base) {		}
	float ObtenerSuperficie() { return m_altura*m_base; }
	float ObtenerPerimetro() { return (m_altura*2)+(m_base*2); }
private:
	int m_altura, m_base;
};
class PrismaTriangular{
public:
	PrismaTriangular(Triangulo base, Rectangulo cara_a, Rectangulo cara_b, Rectangulo cara_c) : m_base(base), m_cara_a(cara_a), m_cara_b(cara_b), m_cara_c(cara_c) { }
	float ObtenerSuperficie() {	return m_base.ObtenerSuperficie() + m_cara_a.ObtenerSuperficie() + m_cara_b.ObtenerSuperficie() + m_cara_c.ObtenerSuperficie(); }
private:
	Triangulo m_base;
	Rectangulo m_cara_a, m_cara_b, m_cara_c;
};
int main() {
/**	Cree e inicialice dos objetos, uno de tipo Triángulo y otro de Tipo
	Rectángulo, cada clase consta de atributos y métodos para calcular su
	superficie y perímetro. Diseñe un programa que calcule la superficie de
	un prisma triangular, cuyas caras son los objetos anteriores, a través
	de una función externa amiga acceda a los atributos privados y realice
	el cálculo, en el programa principal.
	¿Es necesario utilzar amistad en este caso? ¿Es conveniente?
	¿Si fuera a diseñar una clase Prisma para este fin, convendría utilizar
	herencia o composición? (justifique)**/
	Triangulo triangulo1(3,3,3,3*sin(3));
	cout << "La superficie de triangulo1 es de " << triangulo1.ObtenerPerimetro() << endl;
	Rectangulo rectan1(4,6), rectan2(4,6), rectan3(4,6);
	
	cout << "La superficie de rectan1 es de " << rectan1.ObtenerPerimetro() << endl;
	cout << "La superficie de rectan2 es de " << rectan2.ObtenerPerimetro() << endl;
	cout << "La superficie de rectan3 es de " << rectan3.ObtenerPerimetro() << endl;
	
	PrismaTriangular prisma1(triangulo1, rectan1, rectan2, rectan3);
	
	cout << "La superficie del prismatriangular es de " << prisma1.ObtenerSuperficie() << endl;
	
	
	return 0;
}



