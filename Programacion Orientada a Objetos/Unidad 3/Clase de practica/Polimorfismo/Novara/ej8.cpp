#include <iostream>
#include <cmath>
using namespace std;

const double PI = 2*acos(0);

class Tanque {
	float m_peso;
public:
	Tanque(float peso) : m_peso(peso) { }
	float VerPeso() { return m_peso; }
	virtual float CalcVolumen() = 0;
	virtual string VerTipo() { return "Tanque desconocido"; }
	virtual ~Tanque() { }
};

class TCil : public Tanque {
	float m_radio, m_altura;
public:
	TCil(float peso, float radio, float altura) : Tanque(peso), m_radio(radio), m_altura(altura) { }
	float CalcVolumen() override { return PI*m_radio*m_radio*m_altura; }
	string VerTipo() override { return "cilindrico"; }
};

class TEsf : public Tanque {
	float m_radio;
public:
	TEsf(float peso, float radio) : Tanque(peso), m_radio(radio) { }
	float CalcVolumen() override { return 4.0/3.0*PI*m_radio*m_radio*m_radio; }
	string VerTipo() override { return "esferico"; }
};

int main() {
	
	Tanque *t;
	
	for(int k=0;k<2;++k) {
		if (k==0) t = new TCil(10,2,3);
		else      t = new TEsf(12,3);
		
		cout << "El tanque " << t->VerTipo() << " pesa " << t->VerPeso() 
			 << " y tiene un capacidad de " << t->CalcVolumen() << endl;
		
		delete t;
	}
	
	return 0;
}

