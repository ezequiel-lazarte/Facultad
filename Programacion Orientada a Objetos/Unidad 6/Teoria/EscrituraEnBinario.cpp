#include <iostream>
#include <fstream>
using namespace std;
struct Par {
	int i;
	double d;
};
int main() {
	//creo datos y despues los escribo en el archivo
	ofstream archi("datos.eze", ios::binary);
	for(int i=0;i<10;++i) {
		Par p;
		p.i = rand()%100+1;
		p.d = (rand()%1001)/1000.0;
		archi.write(reinterpret_cast<char*>(&p), sizeof(p));
		cout << p.i << " " << p.d << endl;
	}
	return 0;
}

