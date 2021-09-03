#include <iostream>
using namespace std;

int main() {
	///template en clases
	template<typename T>
	T menor(const vector<T> &v) {
		T men = v[0]; /// constructor de copia
		for(size_t i=1;i<v.size();i++) { 
			if(v[i]<men) ///comparar
				men = v[i]; ///asignar con =
		}
		return men;
	}
	///implementar un contructor de copia, sobrecargar el operador < y para asignar =
	
	template<typename T>
	class Vector3D {
	private:
		T m_datos[3];
	public:
		Vector3D();
		Vector operator-(const Vector3D &v2);
		Vector operator-(const Vector3D &v2);
		T operator*(const Vector3D &v2);
		T &operator[](int i);
		
	};
	template<typename T>
	T &Vector3D<T>::operator[](int i) {
		return m_datos[i];
	}
	/// main
	int main() {
		Vector3D<float> m1,m2;
		cin >> m1 >> m2;
		cout << m1*m2 << endl;
	}
	/// sobrecarcar el >> 
	///sobrecarga generica
	template<typename T>
	istream &operator>>(istream &i, Vector3D<T> &m);
	///no se puede omitir poner el tipo de dato al invocar la funcion generica
	return 0;
}

