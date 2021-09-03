#include <iostream>
using namespace std;
class Fraccion {
public:
	Fraccion(double numerador, double denominador) : m_numerador(numerador), m_denominador(denominador) {		}
	double ConvertirADouble() { 
		return m_numerador / m_denominador;
	}
	double VerNumerador() { return m_numerador; }
	double VerDenominador() { return m_denominador; }
private:
	double m_numerador, m_denominador;
};
class NumeroMixto : public Fraccion {
public:
	NumeroMixto(double numerador, double denominador) : Fraccion(numerador, denominador) { 	}
	double ConvertirADouble() { 
		return this->ConvertirADouble();
	}
	int ParteEntera(double numerador, double denominador){
		int entero=numerador/denominador;
		return entero;
	}
};
int main() {
//		Implemente una clase Fraccion para representar una fracción a partir de un
//		numerador y un denominador, con un método ConvertirADouble() para obtener el
//		real que representa, y los demás métodos que considere necesarios. Implemente
//		una clase NumeroMixto para representar un número formado por una parte entera
//		y una fracción impropia (fracción menor a 1). Reutilice la clase Fraccion al
//		implementar la clase NumeroMixto . La clase NumeroMixto debe también poseer
//		un método ConvertirADouble() . ¿Qué relación entre clases puede utilizar en este
//		caso?
	
	Fraccion a(14,3);
	
	cout << "La fraccion " << a.VerNumerador() << "/" << a.VerDenominador() << " en numero entero con decimales es " << a.ConvertirADouble() << endl;
	
	// La relacion es de herencia
	NumeroMixto b(9,2);
	cout << "El numero mixto: " << b.VerNumerador() << "/" << b.VerDenominador() << endl;
	cout << "Parte entera: " << b.ParteEntera(9,2) << endl;
	return 0;
}

