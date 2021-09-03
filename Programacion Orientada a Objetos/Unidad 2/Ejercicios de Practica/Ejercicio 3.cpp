#include <iostream>
#include <cmath>
using namespace std;
class Polinomio{
public:
	Polinomio(int grado); //a)
	void CargarCoeficientes(int i, int coefs); //b)
	float Evaluar(float x); //c)
	int VerGrado();
	int VerCoefs(int i);
	Polinomio Sumar(Polinomio p2);
private:
	float m_coefs[20];
	int m_grado;
};
Polinomio::Polinomio(int grado) : m_grado(grado) {
	for(int i=0;i<21;i++) {
		m_coefs[i] = 0;
	}
}
void Polinomio::CargarCoeficientes(int i, int coefs) {
	m_coefs[i] = coefs;
}
float Polinomio::Evaluar(float x) {
	float sum = 0;
	for(int i=0;i<=m_grado;i++) {
		sum += m_coefs[i]*pow(x,i);
	}
	return sum;
}
	
int Polinomio::VerGrado() {
	return m_grado;
}
int Polinomio::VerCoefs(int i) {
	return m_coefs[i];
}
Polinomio Polinomio::Sumar(Polinomio p2) {
	int grado_suma;
	if(this->VerGrado()<p2.VerGrado()) {
		grado_suma = p2.VerGrado();
	} else {
		grado_suma = this->VerGrado();
	}
	Polinomio p3(grado_suma);
	for(int i=0;i<=p3.VerGrado();i++) {
		p3.CargarCoeficientes(i, this->VerCoefs(i)+p2.VerCoefs(i) );
	}
	return p3;
}
int main() {
///		Disene una clase Polinomio cuyos atributos sean el grado (entero) y los
///		coeficientes de los terminos (hasta 20 terminos; utilice un vector estatico o la clase
///		vector, pero no new/delete). La clase debe tener:
///		a. un constructor que reciba el grado del polinomio e inicialice sus coeficientes en 0.
///		b. un metodo que permita cambiar un coeficiente.
///		c. un metodo evaluar que permita evaluar el polinomio para un valor dado de la variable x .
///		d. el/los metodos que considere necesarios para poder mostrar un polinomio desde un programa cliente.
///		e. una funcion que permita sumar dos polinomios retornando un tercer
///		polinomio con el resultado (ej. p_res=Sumar(p1,p2);). .Como variaria si en
///		lugar de ser una funci. libre fuera un metodo de la clase?
///		Verifique el funcionamiento de la funcion Sumar(...) mediante un programa cliente.
	Polinomio p1(3); // 0*x^0 + 0*X^1 + 0*X^2
	p1.CargarCoeficientes(0,3);	// 3*x^0 + 0*X^1 + 0*X^2
	p1.CargarCoeficientes(1,7);	// 3*x^0 + 7*X^1 + 0*X^2
	p1.CargarCoeficientes(3,1);// 3*x^0 + 7*X^1 + 1*X^2
	
	Polinomio p2(7);
	p2.CargarCoeficientes(0,4);
	p2.CargarCoeficientes(3,2);
	p2.CargarCoeficientes(7,8);
	
	Polinomio p_res=p1.Sumar(p2);
	
	float x;
	cout << "Ingrese valor de x: "; cin >> x;
	cout << "El Polinomio evaluado en x = " << x << " da como resultado " << p1.Evaluar(x) << endl;
	cout << "El Polinomio evaluado en x = " << x << " da como resultado " << p2.Evaluar(x) << endl;
	
	for(int i=0;i<=p_res.VerGrado();++i) {
		if(i!=0) {
			cout <<  " + ";
		}
		cout << p_res.VerCoefs(i) << "*x^" << i;
	}
	return 0;
}

