#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	int x;
	ofstream archi("texto.txt");
	if(!archi.is_open()) {
		cerr << "Error el archivo no pudo abrirse" << endl;
		return 1;
	}
	for(int i=0;i<5;i++) {
		cout << "Dato " << i+1 << ": "; cin >> x;
		archi << x << setw(3) << " ";
	}
	
	archi.close();
	
	archi.open("texto.txt",ios::app);
	for(int i=0;i<3;i++) { 
		cout << "Dato adicional " << i+1 << ": "; cin >> x;
		archi << x << setw(3) << " ";
	}
	return 0;
}

