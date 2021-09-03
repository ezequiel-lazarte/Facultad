#include <iostream>
using namespace std;
class EcuacionCuadratica{
public:
	EcuacionCuadratica(int a, int b, int c);
	bool TieneRaicesReales(EcuacionCuadratica ecuacion);
	float VerRaiz1(EcuacionCuadratica ecuacion);
	float VerRaiz2(EcuacionCuadratica ecuacion);
	float VerParteReal1(EcuacionCuadratica ecuacion);
	float VerParteImag(EcuacionCuadratica ecuacion);
	
private:
	int m_a, m_b, m_c;
	float raiz_real_1, raiz_2;
	
};
int main() {
///		Proponga una clase EcuacionCuadratica para modelar ecuaciones cuadráticas de
///		la forma ax^2 + bx + c = 0 . La clase debe incluir:
///		a. Un constructor que reciba los valores de los coeficientes a, b y c .
///		b. Un método TieneRaicesReales(...) que devuelva verdadero si las raíces de
///		la ecuación son reales.
///		c. Dos métodos VerRaiz1(...) y VerRaiz2(...) que permitan obtener las raíces
///		reales (en caso de que lo sean).
///		d. Dos métodos VerParteReal(...) y VerParteImag(...) que permitan obtener las
///		partes real e imaginaria de las raíces complejas (en caso de que lo sean).
///		e. Cree un programa cliente que utilice un objeto de la clase
///		EcuaciónCuadratica para determinar las raíces de una ecuación
///		cuadrática cuyos coeficientes sean ingresados por el usuario, y las muestre
///		en el formato que corresponda (según sean reales o complejas).
	
	EcuacionCuadratica ecuacion;
	int a, b, c;
	cout << "Ingrese coeficientes a,b y c: "; cin >> a, b, c;
	ecuacion.EcuacionCuadratica(a, b, c);
	
	return 0;
}
EcuacionCuadratica::EcuacionCuadratica(int a, int b, int c) {
	m_a = a;
	m_b = b;
	m_c = c;
};
bool EcuacionCuadratica::TieneRaicesReales(int a, int b, int c)  {
	float m_d = pow(b,2)-4*a*c;
	bool raices_reales;
	
	if(d >= 0){
		//raices reales
		float r1 = (-b + sqrt(d)/(2*a));
		float r2 = (-b - sqrt(d)/(2*a));
		raices_reales = true;
	} else {
		// raices complejas
		float pr = -b/(2*a); // pr significa parte real
		float pi = sqrt(-d)/(2*a); // pi significa parte imaginaria
		raices_reales = false;
	}
	return raices_reales;
}
float EcuacionCuadratica::VerRaiz1(EcuacionCuadratica ecuacion) {
	
}
float EcuacionCuadratica::VerRaiz2(EcuacionCuadratica ecuacion) {
	
}
float EcuacionCuadratica::VerParteReal1(EcuacionCuadratica ecuacion) {
	
}
float EcuacionCuadratica::VerParteImag(EcuacionCuadratica ecuacion) {
	
}
