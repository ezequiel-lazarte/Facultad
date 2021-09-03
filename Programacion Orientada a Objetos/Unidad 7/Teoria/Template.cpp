#include <iostream>
using namespace std;

int main() {
	///Template en funciones
	///funcion generica o plantilla
	///ejemplo una funcion que busca el menor del vector
	??? menor(const vector<???> &v) {
		??? men = v[0];
		for(size_t i=1;i<v.size();i++) { 
			if(v[i]<men)
				men = v[i];
		}
		return men;
	}
	/// sepodria remplazar ??? por cualquier tipo de dato
	/// la programacion generica ignora los tipos de datos y se centra en el algoritmo
	/// funcion generica(plantilla) + argumentos
	template<typename T>
	T menor(const vector<T> &v) {
		T men = v[0];
		for(size_t i=1;i<v.size();i++) { 
			if(v[i]<men)
				men = v[i];
		}
		return men;
	}
	/// template indica que es una plantilla
	/// en el main se invoca como 
	vector<float> v;
	....
	float men = menor<float>(v);
	/// el template remplaza la T por float
	///para una funcion el tipo de dato generalmente se puede deducir a partir de sus parametros
	///se puede omitir poner el tipo de dato al invocar la funcion generica
	return 0;
}

