#include <iostream>
#include <fstream>
using namespace std;

int main() {
	/**Con un software de tratamiento de imagenes llamado WellDesign se han generado
	78 archivos con los nombres "design1.wds", "design2.wds", … "design78.wds". El
	software fue creado para Windows XP . Estos archivos presentan el problema que
	en el nuevo sistema operativo Windows 10 al tratar de abrirlos con WellDesign
	presentan un molesto mensaje. Al consultar al soporte tecnico de la empresa que
	desarrollo WellDesign nos mencionan que si se modifica la cabecera de cada
	archivo se soluciona el problema. A partir del byte 178 se debe reemplazar "mswxp"
	por "msw10", y a partir del byte 239 reemplazar el valor entero 2003 por el valor
	2016. Escriba un programa en C++ que realice esas correcciones en los 78
	archivos almacenados.
	**/
	int anio=2016;
	string s1 = "desingn", s3 = ".wds";
	char tipo[] = "ms10";
	for(int i=0;i<78;i++) {
		string s2 = to_string(i+1);
		string nombre = s1 + s2 + s3;
		cout << nombre << endl;
		fstream archi(nombre, ios::binary|ios::in|ios::out);
		archi.seekp(178,ios::beg);
		archi.write(reinterpret_cast<char*>(&tipo),sizeof(tipo));
		archi.seekp(239,ios::beg);
		archi.write(reinterpret_cast<char*>(&anio),sizeof(anio));
	}
	return 0;
}

