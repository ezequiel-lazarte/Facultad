/// funciones vistas en la practica
vector<int> v1(42,0);
int* max = *max_element(v1.begin(), v1.end()); ///algoritmo que me devuelve un puntero a la pos del elemento mas grande
int* min = *min_element(v1.begin(), v1.end());  /// algoritmo que me devuelve un puntero a la pos del elemento mas chico
accumulate(v1.begin(), v1.end(), 0); /// funcion que me retorna la suma de todos los elementos del vector, el 3er argumento es para decir en que valor se inicializa el acumulador
distance(v1.begin(),it); /// me da la distancia entre dos punteros me sirve tanto como para list y vectores
it = find(v1.begin(),v1.end(),valor); /// me busca un valor en el vector
v1.erase(it); /// me elimina un elemento apuntado por un iterator como it o un elemento sipongo una variable, y me reduce el vector
vector<int>::iterator it=remove(v1[x]); /// remove es un algoritmo no un metodo, me elimina todos los elementos que son iguales a v1[x]
/// y me tira esos elementos al ultimo lugar del vecto, me devuelve un puntero al ultimo elemento que no sea el borrado, realmente me ordena el vector y los datos "borrados" los tira
/// al final del vector y me retorna el puntero a la pos del elemento que no sea uno de los "eliminados"
