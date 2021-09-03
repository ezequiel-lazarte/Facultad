#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
	int anio=2016;
	char tipo[]="msw10";   
	stringstream ss;
	for(int i=1;i<=78;i++) {
		//ss<<"welldesign"<<i<<".dat";
		//cout<<ss.str()<<endl;
		//fstream f(ss.str(),ios::binary|ios::in|ios::out);
		cout<<"welldesign"+to_string(i)+".dat"<<endl;
		fstream f("welldesign"+to_string(i)+".dat",ios::binary|ios::in|ios::out);
		f.seekp(178,ios::beg);
		f.write(reinterpret_cast<char*>(&tipo),sizeof(tipo));
		f.seekp(239,ios::beg);
		f.write(reinterpret_cast<char*>(&anio),sizeof(anio));
		f.close();
		//ss.str("");
	}
	return 0;
}

