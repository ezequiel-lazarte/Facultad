#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	for(int i=0;i<78;++i) { 
		
		fstream f("design"+to_string(i+1)+".wds",ios::binary|ios::out|ios::in);
		
		string s = "msw10"
		f.seekp(178);
		f.write(s.c_str(),s.size()+1);
		
		f.seekp(239);
		int anio = 2003;
		f.write(reinterpret_cast<char*>(&anio),sizeof(int));
		
	}
	
	return 0;
}

