La stl es una biblioteca con muchas clases y funciones genericas(templates).
	
	Contenedores: son estructuras de datos que almacenan una coleccion de objetos de algun tipo genericos, como el de vector por ejemplo, los contenedores estan representados por clases genericas.
	
	Algoritmos: son funciones genericas y estan diseñadas para trabajar con los contenedores.
	
	Iteradores: son objetos auxiliares para referenciar elementos dentro del contenedor.
/** ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// **/
Tipos Contenedores:
	
Secuenciales(Elementos ordenados):
	
	- list(list dbl-enlazada
	- vector(arreglo lineal)
	- deque(doble cola)
	
Asociativos(claves): 
	
	- set(conjunto) ///en un conjunto no hay elementos repetidos
	- map(correspondencia) /// aparte de estar o no estar me permite tener informacion extra asociada
	- multiset
	- multimap
	- bitset
	
Adaptadores("derivados"):
	- stack(pila)
	- queue(cola)
	- priority_queue(cola con prioridades)
	
Y mas(desde c++11): /// para entender estos hay que entender los anteriores esto se vera en 2do año
	- array(vector estatico)
	- forward_list(lista simpl-enlazada)
	- unordered_*(tablas de hash)
/** ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// **/	   

Iteradores(hay distintos tipos de iteradores):
	- De entrada, de salida.
	- De acesso aleatorio, secuenciales.(este es el que usamos)
	- Direccionales, bidireccionales.
	- De insercion, etc.
///utilizan sobrecarga de operadores para emular el comportamiento de un puntero a un arreglo
	
/** ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// **/	
	
	Ejemplos:
	"std::vector"
	vector<int> v1; /// el contructor por defecto me lo declara vacio
	vector<int> v2(43,0); /// con 42 ceros
	vector<int> v3 = { 5, 7, 9 }; /// con 3 elementos
	/// obtener informacion
	v1.empty(); /// preguntar si esta vacio
	v1.size() ///preguntamos tamaño
	v1.resize(); ///redimensionamos
	
	/// Las funciones sueltas(algoritmos) y metodos de vector siempre trabajan con iteradores
	
	Obtener iteradores
	/// todo contenedor va a tener un metodo begin() y end() que devuelve un puntero(realmente es una claase)
	vector<int>::iterator itbeg = v.begin(); /// 1er elemento
	vector<int>::iterator itend = v.end(); /// no es el ultimo es la pos despues del ultimo
	vector<int>::iterator it5 = v.begin()+5;/// apunta a v[5] ya que begin es 0 + 5 = 5
	///modificar el vector
	v[0] = 25; /// modifica el vector pero solo funciona para vector
	*it = 18; /// pone 18 en la posicion apuntada por it
	v.push_back(10); /// agrega el 10 al final
	v.insert(it,20); /// inserta el 20 en la pos apuntada por it
	v.pop_back(); ///elimina el ultimo elemento
	it = v.erase(it); /// elimina el elemento de la poscicion que apunta it y me devuelve la pos actualizada
	v.erase(it1,it2); /// borra en el rango de [it,it2) osea borra desde it a it2 -1
	v.clear(); /// borra todos los elementos
	/// al eliminar elementos los iteradores se desactualizan
	
	/// Cargar datos en un vector( o recorro)
	vector<int> v;
	for(int i=0;i<15;i++) { ///1) forma
		v.push_back(1+rand()%100);
	}
	
	vector<int> v(15,0);
	for(size_t i=0;i<v.size();i++) { ///2) forma
		v[i] = 1+rand()%100;
	}
	/// el equivalente a este con iteradores es:
	vector<int> v(15,0);
	for(vector<int>::iterator it=v.begin();it != v.end();++it) { ///3
		*it = 1+rand()%100;
	}
	/// auto sirve para que el compilador deduzca de que tipo es la variable
	vector<int> v(15,0);
	for(auto it=v.begin();it != v.end();++it) { /// 4) forma
		*it = 1+rand()%100;
	}
	/// vercion abreviada
	vector<int> v(15,0);
	for(int &x : v) { /// 5) forma
		x = 1+rand()%100;
	}
	list<int> l(10);
	for(int &x : l) 
		x = 1+rand()%100;
	/// ejemplo 
	vector<Alumno> v;
	for(vector<Alumno>::iterator it=v.begin();it!=v.end();++it) {
		cout << (*it).nom << endl; ///muestra el nombre del struct Alumno
		cout << it->nom << endl; ///hace lo mismo el operador "->" que los punteros esta linea es igual a la linea de arriba
	}
	/// vector vs list
	- Organizacion en memoria: vector es contigua(arreglo) y list no es contigua(lista enlazada)
	- Tipo de acesso: vector es aleatorio y list secuencial
	- insercion y eliminacion: vector lento y list mas rapido
	/// list no permite el acesso aleatorio con [] y no los tiene sobrecargados
	/// sus iteradores solo pueden "moverse" con el ++ y el --
	/// Cuando hay que insertar o eliminar mucho conviene lista de lo contrario conviene vector
	
	
	/// Movimiento de iteradores
	/// Una poscicion modificando iterador: ++it | it++ | --it | it--
	/// una poscicion sin modificar el iterador: it1 = prev(it); it2 = next(it);
	- prev() // me da otro iterador (no me modifica) con una pos atras osea --it
	- next() // me da otro iterator (no modifica) con una pos adelante ++it
	/// Multiples pos, modificando el iterador: advance(it, N); advance(it, -N);
	- advance() // me modifica el iterador y me deja moverme varias pos

	/// Multiples pos, sin modificar iterador: it1 = it-N; it2 = it+N;
	// esto es aritmetica de punteros y solo anda para vector
	/** it1 = prew(it, N); it2 = next(it, N); **/ // esto es otra alternativa a aritmetica de 
	// punteros no modifica y sirve para vector, list y cualquier contenedor
	
