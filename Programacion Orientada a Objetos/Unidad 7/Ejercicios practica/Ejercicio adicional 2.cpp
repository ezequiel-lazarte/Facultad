#include <iostream>
#include <iomanip>
using namespace std;
template<typename T>
void Intercambia(T &a1, T &a2) {
	T aux = a1;
	a1 = a2;
	a2 = aux;
}
int main() {
	/**Desarrolle una función Intercambia(...) que reciba dos variables por referencia e
	intercambie sus valores. Pruebe la función desde un programa cliente con al
	menos dos tipos de dato distintos.
	**/
	float var1 = 18.4, var2 = 20.3;
	cout << "var1 vale: " << fixed << setprecision(1) << var1 << " y var2 vale: " << var2 << endl;
	Intercambia(var1, var2);
	cout << "ahora var1 vale: " << var1 << " y var2 vale: " << var2 << endl;
	return 0;
}

