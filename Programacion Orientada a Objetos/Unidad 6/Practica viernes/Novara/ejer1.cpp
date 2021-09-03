#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Par {
	int x;
	float y;
};

int main() {
	
	ofstream fout("datos.dat",ios::binary);
	
	for(int i=0;i<200;++i) { 
		
		Par p = { rand()%101, (rand()%101)/100.f };
		
		cout << "Par " << i << ": " << p.x << ", " << p.y << endl;
		
		fout.write( reinterpret_cast<char*>( &p ), sizeof(p) );
		
	}
	
	return 0;
}

