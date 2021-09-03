#include <fstream>
#include <algorithm> // sort
#include <vector>
#include <iostream>
using namespace std;

int main() {
	
	vector<string> v;

	ifstream archi_in("palabras.txt");
	if (!archi_in.is_open()) {
		cerr << "No se pudo abrir el archivo palabras.txt" << endl;
		return 1;
	}
	string s;
	while(getline(archi_in,s)) {
		v.push_back(s);
	}
	archi_in.close();

	cout << "Hay " << v.size() << " palabras" << endl;
	sort(v.begin(),v.end());
	
	ofstream archi_out("palabras.txt",ios::trunc);
	for(string s : v)
		archi_out << s << endl;
	
	return 0;
}

