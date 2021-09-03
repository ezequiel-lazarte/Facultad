#include <iostream>
using namespace std;

int main() {
	/*Investigue el uso de la clase stringstream para entender los siguientes ejemplos:
	1) Ingresar datos en un stream y obtener el string resultante:
	#include <iostream>
	#include <sstream>
	using namespace std;
	int main( int argc, char *argv[]) {
	int n1,n2;
	cout<< "Ingrese dos enteros para sumar:" ;
	cin>>n1>>n2;
	int r=n1+n2;
	stringstream ss;
	ss<<r; a la suma de los dos numeros que es r los escribo en ss
	string str=ss.str(); 
	cout<< "El resultado tiene " ;
	cout<<str.size()<< " digitos." <<endl;
	return 0;
}
	2) Convertir el contenido de un string en un stream para extraer datos:
	#include <iostream>
	#include <sstream>
	using namespace std;
	int main( int argc, char *argv[]) {
	cout<< "Ingrese dos numeros separados por un espacio: " ;
	string str;
	getline(cin,str);
	stringstream ss(str);
	double n1,n2;
	ss>>n1>>n2;
	cerr<<(n1+n2);
	return 0;
}
	*/
	return 0;
}

