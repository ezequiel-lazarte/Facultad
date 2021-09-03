#include <iostream>
using namespace std;

class Racional {
	int num, den;
public:
	Racional(int n=0, int d=1) : num(n), den(d) { }
	int VerNum() const { return num; }
	int VerDen() const { return den; }
	
	Racional operator*(Racional b) const;
	bool operator==(Racional b) const {
		return this->VerNum()*b.VerDen() == b.VerNum()*this->VerDen();
	}
	bool operator!=(Racional b) const {
		return not (*this==b);
	}
	
	Racional &operator++() { // pre
		num += den;
		return *this;
	}
	
	Racional operator++(int) { // post
		Racional v = *this;
		num += den;
		return v;
	}
	
	int operator[](int i) const {
		if (i==0) return num;
		else return den;
	}
	
	int& operator[](int i) {
		if (i==0) return num;
		else return den;
	}
	
};

ostream& operator<<(ostream &o, const Racional &r) {
	o <<     r[0]        << "/" << r[1];
	return o;
}

istream& operator>>(istream &i, Racional &r) {
	i >> r[0] >> r[1];
	return i;
}

Racional operator+(Racional a, Racional b);
Racional operator+(Racional a, int x);
Racional operator+(int x, Racional a);

bool operator<(Racional a, Racional b) {
	return a.VerNum()*b.VerDen() < b.VerNum()*a.VerDen();
}
bool operator<=(Racional a, Racional b) {
	return (a<b) or (a==b);
}
bool operator>=(Racional a, Racional b) {
	return not (a<b);
}
bool operator>(Racional a, Racional b) {
	return not (a<=b);
}


int main() {
//	Racional r(1,2)/*, pi(22,7)*/;
	
	Racional c;
	cin >> c;
	cout << "c = " << c+5 << endl;
	cout << "c = " << 5+c << endl;
	
//	if (r==pi) cout << "r es igual que pi" << endl;
//	if (r!=pi) cout << "r es distindo de pi" << endl;
//	if (r<pi) cout << "r es menor que pi" << endl;
//	if (r<=pi) cout << "r es menor o igual que pi" << endl;
//	if (r>pi) cout << "r es mayor que pi" << endl;
//	if (r>=pi) cout << "r es mayor o igual que pi" << endl;
	
//	Racional s = r+pi; // Racional s = operator+(r,pi);
//	cout << s.VerNum() << "/" << s.VerDen() << endl;
//	
//	Racional p = r*pi; // Racional p = r.operator*(pi)
//	cout << p.VerNum() << "/" << p.VerDen() << endl;
	return 0;
}


Racional Racional::operator*(Racional b) const {
	Racional r(0,0);
	r.num = this->num*b.num;
	r.den = this->den*b.den;
	return r;
}

Racional operator+(Racional a, int x) {
	return Racional(a.VerNum() + x*a.VerDen(), a.VerDen());
}
Racional operator+(int x, Racional a) {
	return Racional(a.VerNum() + x*a.VerDen(), a.VerDen());
}
Racional operator+(Racional a, Racional b) {
	int d = a.VerDen()*b.VerDen();
	int n = a.VerNum()*b.VerDen() + b.VerNum()*a.VerDen();
	return Racional(n,d);
}

