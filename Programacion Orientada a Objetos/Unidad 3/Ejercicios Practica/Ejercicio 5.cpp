#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Monomio {
public:
	Monomio(int exponente, int coeficiente) : m_coeficiente(coeficiente), m_exponente(exponente) {	}
	float Evaluar(float x) {
		return m_coeficiente*pow(x, m_exponente);
	}
	void CargarCoefs(float coefs) {
		m_coeficiente = coefs;
	}
	float VerCoeficiente() { return m_coeficiente; }
	float VerExponente() { return m_coeficiente; }
private:
	float m_coeficiente, m_exponente;
};
class Polinomio {
public:
	Polinomio(int grado) {
		for(int i=0;i<=grado;i++) {
			Monomio m(i,0);
			m_poli1.push_back(m);
		}
	}
	void CargarCoef(int grado, float coef) {
		m_poli1[grado].CargarCoefs(coef);
	}
	float VerCoefs(int grado) {
		return m_poli1[grado].VerCoeficiente();
	}
	float Evaluar(float x) {
		float sum = 0;
		for(Monomio m:m_poli1)
			sum += m.Evaluar(x);
		return sum;
	}
private:
	
	vector<Monomio> m_poli1;
};
int main() {
//		Implemente una clase Monomio para representar un monomio de la forma a*x^n a
//		partir de un coeficiente y un exponente, con un método Evaluar(...) que reciba un
//		real y retorne el valor del monomio evaluado con ese real, y los demás métodos
//		que considere necesarios. Implemente, luego, una clase Polinomio que reutilice la
//		clase Monomio para modelar un polinomio, y añada un método Evaluar(...) para
//		evaluar un polinomio en un valor x real dado. ¿Qué relación debe haber entre las
//		clases Monomio y Polinomio ?
//	int a;
//	float b;
//	cout << "Ingrese el exponente y luego el coeficiente: "; cin >> a; cin >> b;
//	Monomio f(a, b);
//	float c;
//	cout << "Ingrese el valor a evaluar en el monomio: "; cin >> c;
//	cout << "El valor " << c << " evaluado en el monomio da como resultado: " << f.Evaluar(c) << endl;
	// polinomio 3x^0 + 6x^1 + 4x^2 + 9x^3
	Polinomio pol(3);
	
	pol.CargarCoef(0,3); 
	pol.CargarCoef(1,6); 
	pol.CargarCoef(2,4); 
	pol.CargarCoef(3,9);
	for(int i=0;i<=3;i++) {
		cout << pol.VerCoefs(i) << "*x^" << i;
		if(i!=3) cout << " + ";
	}
	cout << endl;
	int x;
	cout << "Ingrese el valor de x: "; cin >> x;
	
	cout << "El polinomio evaluado en " << x << " da como resultado " << pol.Evaluar(x) << endl;
	
	return 0;
}

