1. ¿Que es la programacion generica?¿Como se implementa en C++?
2. ¿Cual es la diferencia entre una plantilla de clase y una plantilla de funcion?
3. ¿A que se denomina instanciacion o especializacion de una plantilla?
4. ¿Por que la implementacion de una clase templatizada no puede separarse en dos archivos .cpp y .h?

1- La programacion generica es una forma de crear codigo mas universal, osea crear codigo no solo para un tipo de dato
	sino para muchos y ademas se centra mas en el algoritmo. Se implementa en funciones o clases para ello ahy que programar
	la clase o funcion como de costumbre pero remplazando el tipo del dato manipulado por una letra T, arriba de la clase
	o funcion se indica que es generica con "template<typename T>".
2- la unica diferencia es que al instanciar un objeto de una clase esta me pide que le indique el tipo de dato que se va a
	utilizar con el <tipo dato>v1 por ejemplo en cambio en las funciones no es indispensable y por simplicidad se lo suele omitir.
3- La especializacion de una plantilla es cuando el codigo se centra en el algoritmo y no en el tipo de dato utilizado.
4- Por que la plantilla no es un codigo que llega a ejecutarse y procesarse, el main solo lo ve para asegurarse que existe pero 
	no lo interpreta como parte del codigo a ejecutar.
