#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
struct par{
	int n;
	float r;
};

int main(int argc, char *argv[]) {
	fstream f;
	
	f.open("grupo.dat",ios::binary|ios::in|ios::out|ios::ate);
	
	int cant=f.tellg()/sizeof(par);
	
	int pos;
	par w;
	f.seekg(0);
	for(int i=0;i<cant;i++) { 
		f.read(reinterpret_cast<char*> (&w),sizeof(w));
		cout<<"par "<<i<<": "<<w.n<<"     "<<w.r<<endl;
	}
		
	cout<<"Ingrese al valor entero, flotante y la posicion:";
	cin>>w.n>>w.r>>pos;
	
	f.seekp(pos*sizeof(par),ios::beg);
	f.write(reinterpret_cast<char*> (&w),sizeof(w));
	
	
	f.seekg(0);
	for(int i=0;i<cant;i++) { 
		f.read(reinterpret_cast<char*> (&w),sizeof(w));
		cout<<"par "<<i<<": "<<w.n<<"     "<<w.r<<endl;
	}
	f.close();

	return 0;
}

