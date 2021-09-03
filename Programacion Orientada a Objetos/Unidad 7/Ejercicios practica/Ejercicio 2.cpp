#include <iostream>
using namespace std;
template<typename T>
T Clamp(T &var, const int &limite_superior, const int &limite_inferior) {
	if(var>limite_superior) {
		var = limite_superior;
	} else {
		if(var<limite_inferior) {
			var = limite_inferior;
		}
	}
	return var;
}
int main() {
	/**Implemente una funci�n Clamp(...) que reciba como par�metros una variable (por
	referencia) y dos valores indicando los l�mites superior e inferior para el valor de
	dicha variable. Si el valor de la variable supera su m�ximo, este debe ajustarse al
	m�ximo valor permitido. De la misma forma si el valor es inferior al m�nimo. Pruebe
	la funci�n templatizada desde un programa cliente.
	**/
	int var = 5, lim_inf = 2, lim_sup = 4;
	cout << "La variable vale: " << Clamp<int>(var, lim_sup, lim_inf) << endl;
	return 0;
}

