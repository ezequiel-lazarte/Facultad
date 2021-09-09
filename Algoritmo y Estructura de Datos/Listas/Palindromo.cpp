#include <iostream>
#include <list>
#include <cstring>
using namespace std;

	/*Palindromo. Escribir un predicado bool is_palindromo(char* S), que reciba como parametro
	una cadena de texto S y determine si esta es un palindromo, ignorando los espacios entre palabras.
	Un palindromo es una secuencia de caracteres que se lee igual hacia adelante que hacia atras, por
	ejemplo: alli si maria avisa y asi va a ir a mi silla. Recordar que un string puede indexarse como
	un vector. Con el fin de utilizar la estructura <list>, primero deben pasarse los elementos del
	string a una lista y solo utilizar esta en el algoritmo.	*/
template<typename T>
void print_list(const list<T> &L);
bool is_palindromo(char* &S);

int main() {
	string cadena = "hola aloh";
	char *p = &cadena[0];
	bool resultado = is_palindromo(p);
	cout << resultado << endl;
	return 0;
}

template<typename T>
void print_list(const list<T> &L) {
	cout << "[ ";
	for(T x:L) {
		cout << x << " ";
	}
	cout << "]";
}

bool is_palindromo(char* &S) {
	list<char> L = {};
	for(int i=0;S[i] != '\0'; i++) if(S[i] != ' ') L.push_back(S[i]);
	list<char>::iterator it2 = L.begin(), it3 = L.end(), it4 = L.end();
	it3--, it4--, it4--;
	if(L.size() % 2 != 0) it4--;
	while(it2 != L.end()) {
		if(*it2 != *it3) break;
		if(it2 == it4) return true;
		it2++, it3--, it4--;
	}
	return false;
}
