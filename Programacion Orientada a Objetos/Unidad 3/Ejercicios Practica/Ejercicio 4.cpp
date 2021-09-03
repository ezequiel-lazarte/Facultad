#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;
struct Punto{
	float x, y;
};
bool son_muy_muy_parecidos(float a, float b) {
	return abs(a-b)<1e-5;

}
class Recta {
public:
	virtual string ObtenerEcuacion() = 0;
	virtual bool Pertenece(Punto P) = 0;
	virtual ~Recta() { }
};

class RectaGeneral : public Recta {
public:
	RectaGeneral(Punto &p1, Punto &p2) {
		m_a = p2.y-p1.y;
		m_b = p1.x-p2.x;
		m_c = -m_a*p1.x - m_b*p1.y;
	}
	string ObtenerEcuacion() override;
	bool Pertenece(Punto P) override {
		return son_muy_muy_parecidos(m_a*P.x+m_b*P.y+m_c,0);
	}
	float Ver_a() { return m_a; }
	float Ver_b() { return m_b; }
	float Ver_c() { return m_c; }
private:
	float m_a, m_b, m_c;
};

class RectaExplicita : public Recta {
public:
	RectaExplicita(Punto &p1, Punto &p2) {
		m = (p2.y-p1.y)/(p2.x-p1.x); // (y2-y1)/(x2-x1)
		b = (p1.y-m*p1.x); // y1-m*x1
	}
	string ObtenerEcuacion() override;
	bool Pertenece(Punto p) override {
		return son_muy_muy_parecidos(p.y,m*p.x+b);
	}
	float Ver_m() { return m; }
	float Ver_b() { return b; }
private:
	float m, b;
};
int main() {
///	a) Proponga una clase RectaGeneral para representar una recta general, cuya
///	ecuación es Ax+By+C=0 , a partir de dos puntos. El prototipo de la clase se muestra
///	en el siguiente recuadro.
///	b) Diseñe un árbol de herencia que incluya una clase Recta , y dos clases
///	herederas llamadas RectaExplicita y RectaGeneral .
///	c) Utilizando los conceptos de polimorfismo, métodos virtuales y abstractos,
///	complemente el diseño con dos métodos virtuales: MostrarEcuacion(…) , para
///	mostrar en pantalla la ecuación que corresponda para cada recta, y Pertenece(…)
///	para saber si un tercer punto dado está en la recta. ¿Qué problema de diseño
///	puede marcar respecto al primer método? Nota: al comparar flotantes en el
///	segundo método, no debe utilizar ==, sino preguntar de alguna otra forma si son
///	“muy parecidos” en lugar de exactamente iguales .
	
	Punto p = { 1, 2 }, q = { 3, 4 };
	
	cout << "1 - Explicita" << endl;
	cout << "2 - General" << endl;
	
	int tipo;
	cout << "Ingrese: "; cin >> tipo;
	
	Recta *r;
	if (tipo==1) {
		r = new RectaExplicita(p,q);
	} else {
		r = new RectaGeneral(p,q);
	}
	
	cout << "La ecuación es: " << r->ObtenerEcuacion() << endl;	
	
	Punto a;
	cout << "Ingrese valor de x: "; cin >> a.x;
	cout << "Ingrese valor de y: "; cin >> a.y;
	if (r->Pertenece(a)) cout << "Pertenece";
	else cout << "No Pertenece";
	
	delete r;
	
	return 0;
}
string RectaGeneral::ObtenerEcuacion() {
	stringstream recta2;
	recta2 << setprecision(1) << fixed << m_a << "x+" << m_b << "y+" << m_c << "=0\n";  // Ax+By+C=0
	return recta2.str();
}
string RectaExplicita::ObtenerEcuacion() {
	//	return "y= " + to_string(m) + "x +" + to_string(b);
	stringstream recta1;
	recta1 << setprecision(1) << fixed << "y = " << m << "x +" << b; // y=mx+b
	return recta1.str();
}
