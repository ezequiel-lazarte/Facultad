#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	
	vector<int> v(20);
	for(int &x: v) x = rand()%100;
	sort(v.begin(),v.end());
	
	ofstream f("lista.dat",ios::binary);
	for(int x:v) f.write(reinterpret_cast<char*>(&x),sizeof(x));
	
	for(int &x: v) cout << x << " ";
	
	return 0;
}

