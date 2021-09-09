#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

	/*Inverso. Escribir un procedimiento bool inverso(list<char>&z) para determinar si una cadena
	de caracteres de entrada es de la forma z=xy donde y es la cadena inversa (o espejo) de la cadena
	x, ignorando los espacios en blanco. Emplear una cola y una pila auxiliares.*/

bool inverso(list<char>&z) {
	stack<char> pila;
	queue<char> cola;
	list<char>::iterator it = z.begin();
	while(it != z.end()) {
		if(*it != ' ') {
			pila.push(*it);
			cola.push(*it);
		}
		it++;
	}
	while(pila.size() != 0) {
		if(pila.top() != cola.front()) return false;
		pila.pop();
		cola.pop();
	}
	return true;
}

int main() {
	list<char> L = {'a','f','b','c','e','e','c','b','f','a'};
	cout << inverso(L);
	return 0;
}







