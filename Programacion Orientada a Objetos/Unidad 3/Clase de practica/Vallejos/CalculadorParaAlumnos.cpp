#include <iostream>
using namespace std;

/// Necesito una estructura para almacenar t�rminos de operaciones
struct termino{
	char oper; /// +   -    *    /
	int nro;
	///  ocupa 5 bytes
};

class Calculador{
	
	int tamanio;          /// Cantidad de t�rminos
	termino *terminos;    /// un puntero a una lista de t�rminos
	void AgregarLugar();  /// Generar un espacio para almacenar un nuevo t�rmino
	void Calcular();      /// Va a recorrer la lista de t�rminos para obtener el resultado
	float resultado;     /// resultado final de todas las operaciones
public:
	/// para inicializar variables y punteros, necesito un constructor
	Calculador(){tamanio=0;terminos=nullptr;};
	void CargarTermino(char oper,int nro);
	float VerResultado(){return resultado;};
	
	/// Si se destruye una instancia de Calculador, no significa
	/// que se destruya o se libere la memoria de la lista de punteros
	~Calculador(){delete []terminos;};
	
};
void Calculador::AgregarLugar(){
	/// declarar un puntero a una variable de tipo t�rmino
	termino *aux;
	aux = new termino[tamanio+1];
	for (int i = 0;i<tamanio;i++){
		*(aux+i) = *(terminos+i);
	}
	/// una vez traspasado los valores de la lista original al auxiliar
	/// libero la memoria
	delete []terminos;
	
	/// ahora, le asigno a terminos, la lista auxiliar
	terminos = aux;
	tamanio++; /// incremento en 1 el tamanio
}
void Calculador::Calcular(){
	float ret = 0;
	/// Recorrer la lista de t�rminos ejecutando las operaciones
	for (int i = 0;i<tamanio;i++){
		if (i == 0) {
			ret = terminos[i].nro;}
		else{
			switch (terminos[i].oper){
			case '+':ret = ret + terminos[i].nro;break;
			case '-':ret = ret - terminos[i].nro;break;
			case '*':ret = ret * terminos[i].nro;break;
			case '/':ret = ret / terminos[i].nro;break;
			}
		}
	}
	resultado = ret;
}
void Calculador::CargarTermino(char oper,int nro){
	/// declarar una variable aux de tipo t�rmino
	termino t;
	t.nro=nro;t.oper=oper;
	AgregarLugar(); /// Agrega un lugar a la lista
	*(terminos + (tamanio-1)) = t;
	
	///terminos[tamanio-1] = t;
	
	Calcular();
}

int main() {
	Calculador c;
	c.CargarTermino(' ',20);
	c.CargarTermino('+',30);
	c.CargarTermino('/',10);
	c.CargarTermino('*',15);
	
	cout<<c.VerResultado()<<endl<<endl;
	c.CargarTermino('*',19);
	cout<<c.VerResultado()<<endl;
	return 0;
}

