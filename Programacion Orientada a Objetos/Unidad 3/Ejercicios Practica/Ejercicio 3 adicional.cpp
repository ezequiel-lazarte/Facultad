#include <iostream>
using namespace std;
class Rectangulo{
public:
	Rectangulo(float altura, float base) : m_altura(altura), m_base(base) {		}
	float ObtenerArea() { return m_altura*m_base; }
	float ObtenerPerimetro() { return (m_altura*2)+(m_base*2); }
	float ObtenerAltura() { return m_altura; }
	float ObtenerBase() { return m_base; }
private:
	float m_altura, m_base;
};
class PrismaRegular{
public:
	PrismaRegular(Rectangulo rectan1, Rectangulo rectan2, Rectangulo rectan3) : m_rectan1(rectan1), m_rectan2(rectan2), m_rectan3(rectan3) {		}
	float ObtenerArea() { return (m_rectan1.ObtenerArea()*2) + (m_rectan2.ObtenerArea()*2) + (m_rectan3.ObtenerArea()*2); }
	float ObtenerVolumen() { return m_rectan1.ObtenerAltura()*m_rectan2.ObtenerAltura()*m_rectan3.ObtenerAltura(); } //longitud x ancho x altura
protected:
	Rectangulo m_rectan1, m_rectan2, m_rectan3;
	friend class Cubo;
};
class Cubo{
public:
	Cubo(float medida) : m_medida(medida) {		}
	float ObtenerArea() { return m_medida*6; }
	float Obtenervolumen() { return m_medida*3;  }
	Cubo ConvertirEnCubo(PrismaRegular objeto1) { return Cubo(objeto1.m_rectan1.ObtenerBase()); }
private:
	float m_medida;
};
int main() {
///	La clase PrismaRectangular, consta de tres pares de rectángulos distintos que
///		forman sus caras. Defina atributos y métodos que permitan obtener el área y el
///		volumen de ese cuerpo. Luego otra clase amiga Cubo que tenga atributos y
///		métodos para representar un cubo, calcular su área y volumen. Agregue ademaœ
///		un método llamado ConvertirEnCubo que reciba un objeto tipo PrismaRectangular
///		y devuelva un Cubo con las dimensiones del primer rectángulo de ese prisma,
///		accediendo a los datos privados o protegidos directamente. Demuestre su
///		implementación en un programa C++.
	Rectangulo rec1(4,3), rec2(5,6), rec3(3,3);
	
	cout << "El area de los rectangulos es:\n-Primero: " << rec1.ObtenerArea() << 
		" cm2\n-Segundo: " << rec2.ObtenerArea() << " cm2\n-Tercero: " << rec3.ObtenerArea() << " cm2" << endl << endl;
	
	cout << "El perimetro de los rectangulos es:\n-Primero: " << rec1.ObtenerPerimetro() << 
		" cm2\n-Segundo: " << rec2.ObtenerPerimetro() << " cm2\n-Tercero: " << rec3.ObtenerPerimetro() << " cm2" << endl << endl;
	
	PrismaRegular prisma1(rec1, rec2, rec3);
	
	cout << "El area del prismaregular es " << prisma1.ObtenerArea() << " cm2" << endl;
	cout << "El volumen del prismaregular es " << prisma1.ObtenerVolumen() << " cm3" << endl << endl;
	
	Cubo caja(4);
	
	cout << "El area de la caja es " << caja.ObtenerArea() << " cm2" << endl;
	cout << "El volumen de la caja es " << caja.Obtenervolumen() << " cm3" << endl << endl;
	
	Cubo caja2 = caja.ConvertirEnCubo(prisma1);
	cout << "El prisma convertido en cubo tiene un area de " << caja2.ObtenerArea() << " cm2" << endl;
	cout << "El volumen del prisma convertido a cubo es " << caja2.Obtenervolumen() << " cm3" << endl;
	return 0;
}

