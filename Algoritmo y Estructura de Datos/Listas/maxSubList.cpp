#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

	/*maxSubList. Programar una funcion list<int> max_sublist(list<int> &L) la cual reciba una
	lista de enteros y encuentre y retorne la sublista Lmax que obtenga la mayor suma entre todos sus
	elementos. Notar que debido a que algunos elementos pueden ser negativos el problema no se
	resuelve simplemente tomando todos los elementos. Tambi´en es posible que la sublista resultado
	no contenga ning´un elemento, en el caso de que todos los elementos de L sean negativos. Si hay
	varias sublistas que den la misma suma, debe retornar la que comience primero y sea m´as corta.
	Por ejemplo: [1,2,-5,4,-3,2]->[4], [5,-3,-5,1,7,-2]->[1,7], [4,-3,11,-2]->[4,-3,11].
	*/
list<int> max_sublist(list<int> &L) { // la implemente de la fomra eficiente sin utilizar dos bucles
	list<int> Lmax;
	list<int> tmp;
	bool NewSublist = true; //Variable que indica si se inicio una nueva sublista
	int accum = 0;
	int max_accum = 0;
	list<int>::iterator it = L.begin();
	while (it != L.end()) {
		tmp.push_back(*it);
		accum += *it;
		if (accum <= 0) {
			accum = 0;
			tmp.clear();
			NewSublist = true;
		}
		else if (accum > max_accum) {
			max_accum = accum;
			if (NewSublist) {
				Lmax.swap(tmp);
				tmp.clear();
				NewSublist = false;
			} else {
				Lmax.splice(Lmax.end(),tmp);
			}
		}
		++it;
	}
	return Lmax;
}

template<typename T>
	void print_list(const list<T>& L) {
	cout << "[ ";
	for_each(L.begin(),L.end(),[](const T &val){cout << val << " ";});
	cout << "] \n";
}

int main() {
	list<int> L1 = {1,2,-5,4,-3,2};
	list<int> L2 =  {5,-3,-5,1,7,-2};
	list<int> L3 =  {4,-3,11,-2};
	
	list<int> L4 = {1,2,1,-5,4,-3,2};
	list<int> L5 =  {5,-3,-5,1,0,7,-2};
	list<int> L6 =  {4,-3,11,0,-2};
	
	list<int> L7 =  {4,-3,11,-11,0,-2,13};
	list<int> L8 =  {12,4,-3,11,-11,0,-2};
	list<int> L9 = {7,7,-15,4,-3,2};
	
	print_list(L1);
	print_list(max_sublist(L1));
	cout << "\n";
	
	print_list(L2);
	print_list(max_sublist(L2));
	cout << "\n";
	
	print_list(L3);
	print_list(max_sublist(L3));
	cout << "\n";
	
	print_list(L4);
	print_list(max_sublist(L4));
	cout << "\n";
	
	print_list(L5);
	print_list(max_sublist(L5));
	cout << "\n";
	
	print_list(L6);
	print_list(max_sublist(L6));
	cout << "\n";
	
	
	print_list(L7);
	print_list(max_sublist(L7));
	cout << "\n";
	
	print_list(L8);
	print_list(max_sublist(L8));
	cout << "\n";
	
	print_list(L9);
	print_list(max_sublist(L9));
	cout << "\n";
	return 0;
}







