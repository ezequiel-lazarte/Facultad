#include <iostream>
#include <cmath>
using namespace std;

const double M_PI = 2*acos(0);

class Cilindro {
private: //atributos
	float m_radio;
	float m_altura;
public: //Metodos
	//a)
	Cilindro();
	Cilindro(float radio,float altura);
	void AsignarDatos(float radio, float altura);
	float ObtenerVolumen();
};
Cilindro::Cilindro() {
	m_radio = m_altura = 0;
}
Cilindro::Cilindro(float radio,float altura) {
	m_radio = radio;
	m_altura = altura;
}
void Cilindro::AsignarDatos(float radio, float altura) {
	m_radio = radio;
	m_altura = altura;
}
float Cilindro::ObtenerVolumen() {
	
	return M_PI*m_altura*m_radio*m_altura;
}
int main() {
///	Diseñe una clase Cilindro que modele un cilindro con el objetivo de calcular el
///	volumen del cuerpo conociendo el radio de su base y la altura del mismo.
///	a. Cree los métodos AsignarDatos(...) y ObtenerVolumen(...) para asignar los
///	datos del problema y obtener el volumen del cuerpo.
///	b. Escriba un programa cliente que utilice dicha clase. Defina 2 instancias de
///	Cilindro llamadas c1 y c2 . El objeto c1 debe utilizar datos ingresados por el
///	usuario, mientras que para c2 utilice 5.3 cm y 10.2 cm para el radio y la
///	altura respectivamente.
///	c. Agregue un constructor a la clase Cilindro que reciba 2 parámetros para
///	inicializar el radio y la altura. Luego intente compilar nuevamente el
///	programa. ¿Puede explicar por qué se produce un error? Proponga una
///	solución.
	//b)
	
	Cilindro c1, c2(5.3,10.2); // instancias // puedo inicializaarlas gracias al constructor
	float r, h; // Las utilizo como auxiliares ya que la clase guardara estos datos
	cout << "Ingrese el radio de c1: "; cin >> r;
	cout << "Ingrese la altura de c1: "; cin >> h;
	c1.AsignarDatos(r,h);
	
	cout << "El volumen de c1 es " << c1.ObtenerVolumen() << endl;
	cout << "El volumen de c2 es " << c2.ObtenerVolumen() << endl;
	
	//c) No funcionaba por que me faltaba el contructor vacio el cual si no recibe argumentos ahora los inicializa en 0
	return 0;
}

