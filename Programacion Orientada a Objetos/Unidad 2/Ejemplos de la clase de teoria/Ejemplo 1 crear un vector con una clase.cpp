#include <iostream>
using namespace std;
class Vector {
private:
	int *m_p;
	int m_n;
public:
	Vector() { //Constructor
		m_p = nullptr;
		m_n = 0;
	}
	Vector(int n) { //Constructor
		m_p = new int[n];
		m_n = n;
	}
	~Vector() { //Destructor
		delete [] m_p;
	}
	void DefinirTamanio(int n) {
		if(m_p==nullptr) { /*error*/ }
		m_p = new int[n];
		m_n = 0;
		
	}
	void cargar(int i, int x) {
		m_p[i] = x;
	}
	int Ver(int i) {
		return m_p[i];
	}
	int VerTamanio() {
		return m_n;
	}
};
int main() {
	Vector v, v2(10);
	Vector v3(v); // v3 copia a v
	int n; cin >> n;
	v.DefinirTamanio(n);
	
	for(int i=0;i<v.VerTamanio();++i) {
		int x;
		cin >> x;
		v.cargar(i,x);
	}
	cout << endl;
	
	for(int i=0;i<v.VerTamanio();++i) {
		cout << v.Ver(i) << " ";
	}
	return 0;
}

