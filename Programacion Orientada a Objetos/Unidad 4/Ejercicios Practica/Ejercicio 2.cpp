#include <iostream>
using namespace std;
class Racional {
public:
	Racional() {	}
	Racional(int n, int d) : num(n), den(d) {}
	int VerNum() { return num; }
	int VerDen() { return den; }
	bool operator<(Racional &r1) {
		return num*r1.VerDen() < r1.VerNum()*den;
	}
	bool operator>(Racional &r1) {
		return num*r1.VerDen() > r1.VerNum()*den;
	}
	bool operator<=(Racional &r1) {
		return !(*this > r1);
	}
	bool operator>=(Racional &r1) {
		return !(*this < r1);
	}
	bool operator==(Racional &r1) {
		return num*r1.VerDen() == r1.VerNum()*den;
	}
	bool operator!=(Racional &r1) {
		return !(*this ==r1);
	}
private:
	int num, den;
};
int main() {
///	Para la clase Racional utilizada en el ejercicio anterior, implemente los operadores
///	relacionales <, <=, >, >=, == y != para comparar dos números racionales. Haga uso
///	de dichos operadores desde un programa cliente.
	
	Racional r1(1, 2), r2(2,3), r3(1,3), r4(2,5);
	if(r3<r1)
		cout << "si 1/3 es mas chico que 1/2" << endl;
	else 
		cout << "no 1/3 no es mas chico que 1/2" << endl;

	if(r3>r1)
		cout << "si 1/3 es mas grande que 1/2" << endl;
	else
		cout << "no 1/3 no es mas grande que 1/2" << endl;
	
	if(r2<=r4)
		cout << "si 2/3 es mas chico o igual que 2/5" << endl;
	else
		cout << "no 2/3 no es mas chico o igual que 2/5" << endl;
	
	if(r2>=r4)
		cout << "si 2/3 es mas grande o igual que 2/5" << endl;
	else
		cout << "no 2/3 no es mas grande o igual que 2/5" << endl;
	
	
	r4 = r2;
	cout << "r4 vale lo mismo que r2" <<endl;
	if(r2==r4)
		cout << "si 2/3 es igual que 2/3" << endl;
	else
		cout << "no 2/3 no es igual que 2/3" << endl;
	
	
	r4 = r3;
	cout << "r4 vale 1/3" << endl;
	if(r2!=r4)
		cout << "si 2/3 es distinto que 1/3" << endl;
	else
		cout << "no 2/3 no es distinto que 1/3" << endl;
	return 0;
}

