#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

struct Punto {
	float x,y;
};

bool son_muy_muy_parecidos(float a, float b) {
	return abs(a-b)<1e-5;
}

class Recta {
public:
	virtual string ObtenerEcuacion() = 0;
	virtual bool Pertenece(Punto p) = 0;
	virtual ~Recta() { }
};

// y = m*x + b
class RectaExplicita : public Recta {
	float m, b;
public:
	RectaExplicita(Punto p, Punto q) {
		m = (p.y-q.y)/(p.x-q.x);
		b = p.y - m*p.x;
	}
	float VerM() { return m; }
	float VerB() { return b; }
	string ObtenerEcuacion() override {
		stringstream ss;
		ss << "y = " << m << "*x + " << b;
		return ss.str();
	}
	bool Pertenece(Punto p) override {
		return son_muy_muy_parecidos(p.y,m*p.x+b);
	}
};


// a*x + b*y + c = 0
class RectaGeneral : public Recta {
	float a,b,c;
public:
	RectaGeneral(Punto p, Punto q) {
		a = q.y-p.y;
		b = p.x-q.x;
		c = -a*p.x - b*p.y;
	}
	float VerA() { return a; }
	float VerB() { return b; }
	float VerC() { return c; }
	string ObtenerEcuacion() override {
		stringstream ss;
		ss << a << "*x + " << b << "*y + " << c << " = 0";
		return ss.str();
	}
	bool Pertenece(Punto p) override {
		return son_muy_muy_parecidos(a*p.x+b*p.y+c,0);
	}
};

int main() {
	Punto p = { 1, 2 }, q = { 3, 4 };
	
	cout << "1 - Explicita" << endl;
	cout << "2 - General" << endl;
	
	int tipo;
	cin >> tipo;
	
	Recta *r;
	if (tipo==1) {
		r = new RectaExplicita(p,q);
	} else {
		r = new RectaGeneral(p,q);
	}
	
	cout << "La ecuación es: " << r->ObtenerEcuacion() << endl;	
	
	Punto a;
	cin >> a.x >> a.y;
	if (r->Pertenece(a)) cout << "Pertenece";
	else cout << "No Pertenece";
	
	delete r;
	
	return 0;
}











