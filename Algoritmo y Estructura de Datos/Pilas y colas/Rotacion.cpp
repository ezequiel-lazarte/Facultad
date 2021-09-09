#include <iostream>
#include <queue>
using namespace std;

	/*Rotacion. Escribir una funcion void rotacion(queue<int> &C), la cual saca una cierta cantidad
	de enteros del frente de la cola C y los vuelve a insertar en fin de la misma, de tal manera que
	quede en el frente de cola un numero par. Por ejemplo, si C = [1, 3, 5, 2, 4] entonces, despues
	de rotacion(C), debe quedar C = [2, 4, 1, 3, 5].*/

void rotacion(queue<int> &C) {
	queue<int> cola_par, cola_impar;
	while(!C.empty()) {
		if(C.front()%2 == 0) {
			cola_par.push(C.front());
			C.pop();
		} else {
			cola_impar.push(C.front());
			C.pop();
		}
	}
	C = cola_par;
	while(!cola_impar.empty()) {
		C.push(cola_impar.front());
		cola_impar.pop();
	}
}

template<typename T>
void print_queue(queue<T> C) {
	cout << "[ ";
	while(!C.empty()) {
		cout << C.front() << " ";
		C.pop();
	}
	cout << "]";
}

int main() {
	queue<int> C;
	C.push(1);
	C.push(3);
	C.push(2);
	C.push(5);
	C.push(4);
	C.push(5);
	C.push(2);
	C.push(11);
	C.push(16);
	
	rotacion(C);
	print_queue(C);
	return 0;
}







