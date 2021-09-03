#include <iostream>
using namespace std;
class Tecla{
public:
	Tecla(string nota) : m_nota(nota) { 	}
	string VerNota() { return m_nota; }
	void Apretar() { m_tecla_presion = true; }
	void Soltar() { m_tecla_presion = false; }
	bool EstaApretada() {
		if(m_tecla_presion==true)
			return true;
		else 
			return false;
		
	}
private:
	bool m_tecla_presion;
	string m_nota;
};
class Pedal{
public:
	Pedal() { m_presion_pedal = 0;	}
	void ModificaPresionPedal(float presion_pedal) { m_presion_pedal = presion_pedal; }
	float VerPrecionPedal() { return m_presion_pedal; }
private:
	float m_presion_pedal;
};
class Instrumento{
public:
	virtual string VerTipo() { return "sin_nombre"; }
};
class Piano {
public:
	string TeclaApretada(int nro_tecla) {
		switch (nro_tecla){
		case 1: return "do";  break;
		case 2: return "re";  break;
		case 3: return "mi";  break;
		case 4: return "fa";  break;
		case 5: return "sol"; break;
		case 6: return "la";  break;
		case 7: return "si";  break;
		}
	}
	
private:
	Tecla uno = "do", dos = "re", tres = "mi", cuatro = "fa", cinco = "sol", seis = "la", siete = "si";
	Pedal p;
};
int main() {
//		a. Defina una clase Tecla para representar una tecla de un piano. Cada tecla
//		puede estar o no apretada, y tiene además una nota asociada (cuyo nombre se
//																	 representará con un string). Su interfaz debe tener tener entonces:
//		- un constructor que reciba el nombre de la nota
//		- un método VerNota que retorne el nombre de la nota
//		- un método Apretar que cambie el estado de la tecla a apretada.
//		- un método Soltar que cambie el estado de la tecla a no apretada.
//		- un método EstaApretada que retorne true si la tecla está apretada, false en caso
//		contrario
//		b. Defina una clase Pedal para representar el pedal de un piano. El pedal debe
//		almacenar un valor (float ) que indica la presión que el músico ejerce sobre el pedal.
//		El constructor debe inicializar la presión en 0 , y la clase debe tener métodos para
//		modificarla y consultarla.
//		c. Reutilizando las clases Tecla , Pedal e Instrumento :
//		class Instrumento{
//		public:
//			virtual string VerTipo() { return "sin_nombre"; }
//		};
//		defina una clase Piano que modele un instrumento de tipo "piano" con solo 7 teclas
//		(“ do”, “re”, “mi”, “fa”, “sol”, “la” y “si” ) y 1 pedal. La clase piano debe tener métodos
//		para:
//		- apretar una tecla, indicando el número de tecla, y que retorne la nota que debería
//		sonar.
//		- soltar una tecla, indicando el número de tecla
//		- presionar el pedal, indicando la presión que se aplica
	
	
	return 0;
}

