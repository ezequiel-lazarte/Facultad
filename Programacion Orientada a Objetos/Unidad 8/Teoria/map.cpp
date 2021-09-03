/// std::map

// map guarda un conjunto de asociados entre objetos, pares clave-valor.
// clave y valor pueden ser de tipos diferentes.

/// ejemplo

map<string,int> v; ///para cada string ahy asociados un entero

v["hola"] = 0; /// el string es la clave o indice y el numero es el valor o par asociado
v["foo"] = 42;
v["hola"] = 7;

// no puede haber claves repetidas, en este caso los string
// El tipo de clave debe ser ordenable( operator< ) osea tiene que tener el < sobrecargado
// En el mapa es muy rapido insertar o buscar una clave.

map<string,int> agenda; // creo un mapa: asocia ints a los strings

// Guardar datos en el mapa:
agenda["Fulano"] = 15647352;
agenda["Mengano"] = 15473673;
agenda["Sultano"] = 15435252;
agenda["Chuck Norris"] = 154738592;
agenda["Juan Perez"] = 15536632;
// al consultar por ejemplo a un string si el valor asociado no existia se crea y si ya estaba se actualiza

// parece un arreglo, pero con un tipo de indice diferente

// Consultar un dato del mapa, si se que existe:
cout << "El nro de Chuck es: " << agenda["Chuck Norris"] << endl;

// Consultar un dato cuando no se si existe:
auto it = agenda.find("Wally"); // sino lo encontro me da el end
if(it==agenda.end())
	cout << "No lo encontro a Wally!" << endl;
else
	cout << "Nro de Wally: " << it->second; // cada elemento del mapa es un struct con su clave(first) y su valor(second)

// Ejemplo para recorrer todo el contenido de un map:
for(auto it=agenda.begin();it!=agenda.end();++it) { // auto es "map<string,int>::iterator
	cout << it->first << " esta asociado a " << it->second << endl;
}
// otro ejemplo
for(auto &p : m) { // cada par p y "auto" es "pair<const string,int>
	cout << p.first << " esta asociado a " << p.second << endl;
}
//
