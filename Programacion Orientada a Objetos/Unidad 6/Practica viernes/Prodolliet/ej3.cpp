#include <iostream>
#include <fstream>
using namespace std;
void crea(string archivo,int can){//creo el archivo con los numeros
	fstream fx(archivo,ios::in|ios::out|ios::binary|ios::trunc);
	int a;
	for(int i=0;i<can;i++) { 
		a=i*5;
		fx.write(reinterpret_cast<char*>(&a),sizeof(a));
		cout<<a<<" ";
	}
	fx.close();
}
int posicion(string archivo,int va){
	fstream fx(archivo,ios::in|ios::out|ios::binary|ios::ate);
	int i,a,cant=fx.tellg()/sizeof(int);
	fx.seekg(0);
	for(i=0;i<cant;i++) { 
		fx.read(reinterpret_cast<char*>(&a),sizeof(a));
		if(va<a) break;
	}
	fx.close();
	return i;
}
		
	
int main(int argc, char *argv[]) {
	crea("ordenados.dat",20);
	int valor,pos;
	cout<<"\ningrese una valor a insertar: "; cin>>valor;
	pos=posicion("ordenados.dat",valor);
	
	fstream f("ordenados.dat",ios::in|ios::out|ios::binary|ios::ate);
	int a,cant=f.tellg()/sizeof(int);
	
	for(int i=cant-1;i>=pos;i--) { 
		f.seekg(i*sizeof(int));
		f.read(reinterpret_cast<char*> (&a), sizeof(a));
		f.seekp((i+1)*sizeof(int));
		f.write(reinterpret_cast<char*> (&a), sizeof(a));
	}
	f.seekp(pos*sizeof(int));
	f.write(reinterpret_cast<char*> (&valor), sizeof(valor));
	f.close();
	
	cout<<endl;
	f.open("ordenados.dat",ios::in|ios::out|ios::binary|ios::ate);
	cant=f.tellg()/sizeof(int);
	f.seekg(0);
	for(int i=0;i<cant;i++) { 
		f.read(reinterpret_cast<char*>(&a),sizeof(a));
		cout<<a<<" ";
	}
		
	return 0;
}

