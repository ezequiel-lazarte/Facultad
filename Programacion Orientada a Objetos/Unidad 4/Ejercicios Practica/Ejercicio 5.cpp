#include <iostream>
using namespace std;
class Complejo {
public:
	Complejo() { 	}
	Complejo(int real, int imaginario) : m_real(real), m_imag(imaginario) { 	}
	int VerParteReal() { return m_real; }
	int VerParteImag() { return m_imag; }
	int & operator[](int pos);
	void AsignarParteReal(int r) { m_real = r; }
	void AsignarParteImag(int i) { m_imag = i; }
private:
	int m_real, m_imag;
};
int & Complejo::operator[](int pos) {
	if(pos==0) 
		return m_real; 
	else 
		return m_imag;
}
istream & operator>>(istream &i, Complejo &c1) {
	int real, imag;
	i >> real >> imag;
	c1.AsignarParteReal(real);
	c1.AsignarParteImag(imag);
	return i;
}
ostream & operator<<(ostream &o, Complejo &c1) {
	o << c1.VerParteReal() << " + " << c1.VerParteImag() << "i";
	return o;
}
int main() {
/**	Implemente una sobrecarga del operador[ ] para la clase C omplejo que permita
	obtener las partes real e imaginaria como si fueran 2 elementos en un arreglo:
**/
	Complejo c(1,2); // 1+2i
	cout << "Parte Real: " << c[0] << endl;
	cout << "Parte Imaginaria: " << c[1] << endl;
	
/** Explique: ¿Podría su sobrecarga utilizarse para modificar las partes del número
	complejo?
	Rta: Si pero sobrecargando el operador >> y opcinalmente el << para mostrarlo
**/
	
	Complejo c1;
	cout << "Ingrese parte real: "; cin >> c1[0];
	cout << "Ingrese parte imaginaria: "; cin >> c1[1];
	
	cout << "El nuevo complejo es: " << c1 << endl;
	return 0;
}

