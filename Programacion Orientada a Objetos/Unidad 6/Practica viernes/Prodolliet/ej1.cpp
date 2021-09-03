#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
struct par{
	int n;
	float r;
};

int main(int argc, char *argv[]) {
	fstream f("grupo.dat",ios::binary|ios::in|ios::out|ios::trunc);
	par w;
	for(int i=0;i<10;i++) { 
		w.n=rand()%100;
		w.r=rand()%100+rand()%100/100.0;
		f.write(reinterpret_cast<char*> (&w),sizeof(w));
	}
	f.close();
	
	f.open("grupo.dat",ios::binary|ios::in|ios::out|ios::ate);
	int cant=f.tellg()/sizeof(par);
	cout<<"cantidad: "<<cant<<endl;
	f.seekg(0,ios::beg);
	for(int i=0;i<cant;i++) { 
		f.read(reinterpret_cast<char*> (&w),sizeof(w));
		cout<<"par "<<i<<": "<<w.n<<"     "<<w.r<<endl;
	}
	
	cout<<"\nmodificar el tercero\n";
	f.seekp(pos *sizeof(par),ios::beg);
	f.read(reinterpret_cast<char*> (&w),sizeof(w));
	cout<<"par "<<3<<": "<<w.n<<"     "<<w.r<<endl;
	w.n=100;
	w.r=123.45;
	
	
	f.write(reinterpret_cast<char*> (&w),sizeof(w));
	
	cout<<"......"<<f.tellg()<<endl;
	
	f.seekg(0,ios::beg);
	for(int i=0;i<cant;i++) { 
		f.read(reinterpret_cast<char*> (&w),sizeof(w));
		cout<<"par "<<i<<": "<<w.n<<"     "<<w.r<<endl;
	}
	
	
	f.close();
	
	
	return 0;
}

