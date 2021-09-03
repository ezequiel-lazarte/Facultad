#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class Tabla {
public:
	Tabla() {		}
	void CargarPuntaje(int puntos) {
		for(size_t i=0;i<puntajes.size();i++) {
			if(puntos==puntajes[i]) {
				return;
			}
		}
		puntajes.push_back(puntos);
		sort(puntajes.begin(), puntajes.end());
		reverse(puntajes.begin(), puntajes.end());
		actualizar();
	}
	int MostrarPuntaje(int pos) {
		return puntajes[pos];
	}
	void actualizar() {
		ofstream archi("Tabla.juego", ios::trunc|ios::binary);
		for(size_t i=0;i<puntajes.size();i++) { 
			archi.write(reinterpret_cast<char*>(&puntajes[i]), sizeof(puntajes[i]));
		}
		archi.close();
	}
private:
	
	vector<int> puntajes;
};
int main() {
	/**Escriba una clase para gestionar la tabla de las N mejores Tabla de un
	juego. La clase debe permitir ingresar un nuevo puntaje (y encargarse de ubicarlo
	en la posición de la tabla que corresponda, o descartarlo), consultar los datos, y
	almacenar y recuperar los mismos mediante un archivo binario.
	**/
	int N=0, puntaje =0;
	cout << "Ingrese N numero de puntajes a ingresar: "; cin >> N;
	
	Tabla juego;
	for(int i=0;i<N;i++) {
		cout << "Ingrese puntaje: "; cin >> puntaje;
		juego.CargarPuntaje(puntaje);
	}
	
	cout << "La lista de puntajes es: " << endl;
	for(int i=0;i<N;i++) { 
		cout << "Posicion Nº " << i+1 << ": " << juego.MostrarPuntaje(i) << endl;
	}
	
	return 0;
}
