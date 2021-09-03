#include <iostream>
using namespace std;
class Complejo {
public:
	Complejo() { 	}
	Complejo(int real, int imaginario) : m_real(real), m_imag(imaginario) { 	}
	int VerParteReal() { return m_real; }
	int VerParteImag() { return m_imag; }
	void AsignarParteReal(int r) { m_real = r; }
	void AsignarParteImag(int i) { m_imag = i; }
	bool operator==(Complejo &c1);
private:
	int m_real, m_imag;
};
ostream & operator<<(ostream &o, Complejo &r1) {
	o << r1.VerParteReal() << " + " << r1.VerParteImag() << "i";
	return o;
}
istream & operator>>(istream &i, Complejo &r1) {
	int real, imag;
	i >> real >> imag;
	r1.AsignarParteReal(real);
	r1.AsignarParteImag(imag);
	return i;
}
Complejo operator+(Complejo &r1, Complejo &r2) {
	return Complejo(r1.VerParteReal()+r2.VerParteReal(), r1.VerParteImag()+ r2.VerParteImag());
}
Complejo operator-(Complejo &r1, Complejo &r2) {
	return Complejo(r1.VerParteReal()-r2.VerParteReal(), r1.VerParteImag()-r2.VerParteImag());
}
Complejo operator*(Complejo &r1, Complejo &r2) {
	return Complejo(r1.VerParteReal()*r2.VerParteReal(), r1.VerParteImag()*r2.VerParteImag());
}
bool Complejo::operator==(Complejo &c1) {
	return (m_real == c1.VerParteReal() and m_imag == c1.VerParteImag());
}
int main() {
	/**	Implemente una clase llamada Complejo para representar un número complejo.
		Sobrecargue los operadores <<, >>, +, -, * e == para mostrar, leer, sumar, restar,
		multiplicar y comparar respectivamente dos objetos de tipo Complejo. Compruebe
		el funcionamiento de los operadores desde un programa cliente.
	**/
	Complejo c1, c2;
	cout << "Ingrese los valores real y imaginario de c1: "; cin >> c1;
	cout << "Ingrese los valores real y imaginario de c2: "; cin >> c2;
	
	Complejo c3 = c1+c2;
	cout << "El nuevo complejo que resulta de la suma de c1 y c2 es: " << c3 << endl;
	
	Complejo c4 = c1-c2;
	cout << "El nuevo complejo que resulta de la resta de c1 y c2 es: " << c4 << endl;
	
	Complejo c5 = c1*c2;
	cout << "El nuevo complejo que resulta del producto de c1 y c2 es: " << c5 << endl;
	
	Complejo c6(2,3), c7(2,3);
	if(c6==c7) 
		cout << "Si son iguales";
	else
		cout << "No son iguales";
	
	return 0;
}

