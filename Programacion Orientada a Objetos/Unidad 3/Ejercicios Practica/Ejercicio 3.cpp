#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
struct Punto {
	float x, y;
};
class RectaExplicita {
public:
	RectaExplicita(Punto &p1, Punto &p2) {
		m = (p2.y-p1.y)/(p2.x-p1.x);
		b = (p1.y-m*p1.x);
	}
	string ObtenerEcuacion() {
        //	return "y= " + to_string(m) + "x +" + to_string(b);
		stringstream recta1;
		recta1 << setprecision(1) << fixed << "y= " << m << "x +" << b;
		return recta1.str(); // las "" vacia a la funcion
	}
	float Ver_m() { return m; }
	float Ver_b() { return b; }
private:
	float m, b;
};
int main() {
///	Proponga un struct Punto con atributos para definir un punto en el plano
///	(coordenadas x e y). Luego, proponga la clase RectaExplicita para definir la
///	ecuación de la recta y=mx+b a partir de dos puntos. La declaración de dicha clase
///	se muestra en el recuadro siguiente.
///	El método ObtenerEcuacion() debe devolver una cadena de texto con la ecuación
///	explícita de la recta.
	Punto p1, p2;
	cout << "Ingrese dos pares de puntos en el plano de coordenadas X y Y: "; cin >> p1.x; cin >> p1.y; cin >> p2.x; cin >> p2.y;
	RectaExplicita recta1(p1,p2);
	
	cout << "La ecuacion de la recta en el punto dado es: " << recta1.ObtenerEcuacion() << endl;
	
	return 0;
}
