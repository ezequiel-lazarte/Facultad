#include <iostream>
#include <cmath>
using namespace std;
const double M_PI = 2*acos(0);
class Tanque {
public:
	Tanque(float peso) : m_volumen(0), m_peso(peso) { 	}
	void AsignarPeso(float p) { m_peso = p; }
	virtual float CalcularVolumen()=0;
	float VerVolumen() { return m_volumen; }
	float verPeso() { return m_peso; }
protected:
	float m_volumen;
	float m_peso;
};
class Cilindro : public Tanque {
public:
	Cilindro(float radio, float altura, float peso) :  Tanque(peso), m_radio(radio), m_altura(altura) { 	}
	float CalcularVolumen() override{
		float base = M_PI*pow(m_radio,2);
		m_volumen = base*m_altura;
		return m_volumen;
	}
private:
	float m_radio;
	float m_altura;
};
class Esfera : public Tanque {
public:
	Esfera(float altura, float radio, float peso) : Tanque(peso) { 
		m_altura = altura;
		m_radio = radio;
	}
	float CalcularVolumen() override {
		m_volumen = (4/3)*M_PI*pow(m_radio,3);
		return m_volumen;
	}
	float VerRadio() { return m_radio; }
	float VerAltura() { return m_altura; }
private:
	float m_radio;
	float m_altura;
};
int main() {
//	Una fábrica de Tanques los hace de forma de Cilindro o de Esfera, en ambos
//	envases debemos rotular el volumen en m3 y el peso en kilogramos.
//	Modele una clase base Tanque con los atributos volumen y peso. Un método
//	público AsignarPeso(p), un método virtual puro CalcularVolumen() que calcule el
//	volumen de acuerdo a los parámetros de los hijos y otros 2 métodos para
//	VerVolumen() y VerPeso().
//	Modele la clase hija Cilindro que tendrá los atributos radio y altura, cuya fórmula de
//	volumen es: área de la base x altura, donde el area de la base se calcula como
//	PI*radio^2; y otra clase hija Esfera que tendrá el atributo radio, cuya fórmula de
//	volumen es: 4/3*PI*radio^3. Los atributos (medidas y peso) los debe cargar con un
//	constructor.
//	En el programa principal debe usar un único puntero de tipo Tanque para crear
//	primero un Cilindro y mostrar su volúmen, y luego una Esfera y también mostrar su
//	volúmen.
	float radio, altura, peso;
	cout << "Ingrese radio del tanque cilindrico: "; cin >> radio;
	cout << "Ingrese la altura: "; cin >> altura;
	cout << "Ingrese el peso: "; cin >> peso;
	
	Cilindro t_90a(radio, altura, peso);
	
	cout << "El volumen del tanque T-90A es de " << t_90a.CalcularVolumen() << " m3" << endl;
	
	float c_radio, c_altura, c_peso;
	
	cout << "Ingrese radio del tanque esferico: "; cin >> c_radio;
	cout << "Ingrese la altura: "; cin >> c_altura;
	cout << "Ingrese el peso: "; cin >> c_peso;
	
	Esfera leopard(c_altura, c_radio, c_peso);
	
	cout << "El volumen del tanque Leopard es de " << leopard.CalcularVolumen() << " m3" << endl;
	return 0;
}

