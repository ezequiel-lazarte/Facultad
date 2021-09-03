#include <iostream> // imput = lectura  y  output = salida
using namespace std;
class Racional {
public:
	Racional() {	}
	Racional(int n, int d) : num(n), den(d) {}
	int VerNum() { return num; }
	int VerDen() { return den; }
	void AsignarNum(int x) { num = x; }
	void AsignarDen(int y) { den = y; }
private:
	int num, den;
};
ostream & operator<<(ostream &o, Racional &r1) {
	o << r1.VerNum() << "/" << r1.VerDen();
	return o;
}
istream & operator>>(istream &i, Racional &r1) {
	int n, d;
	i >> n >> d;
	r1.AsignarNum(n);
	r1.AsignarDen(d);
	return i;
}
int main() {
	/**Implemente sobrecargas para los operadores >> Y << para leer un objeto de tipo
	Racional desde la consola (mediante cin) y mostrarlo en pantalla (mediante cout).
	La lectura se debe realizar leyendo el numerador y denominador por separado (es
	decir, separados por un espacio o salto de línea). El operador << debe mostrar el
	numerador y el denominador separados por el carácter '/'. Analice: la sobrecarga
	de este operador, ¿debe realizarse dentro o fuera de una clase?
	**/
	Racional r1, r2;
	cout << "ingrese los valores: "; cin >> r1;
	cout << "Usted ingreso: " << r1 << endl;
	
	/// debe realizarse fuera de la clase por que la clase istream y ostream no pueden acceder a las variables de la clase racional
	return 0;
}

