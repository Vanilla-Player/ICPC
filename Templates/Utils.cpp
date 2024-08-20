// .emplace_back()
 myvector.emplace_back (100); // Es como pushback, pero te crea el tipo de datos solo. Por ejemplo, si estas usando tuplas. O Pares/

//sizeof() en array no devuelve el tamanio, sino la cantidad ocupada en memoria
// Ej int arr[10] => sizeof(arr) = 40!!!
// Para hacer que ande, deberian hacer: 
sizeof(arr)/sizeof(int);

//,size() devulve el size de vector o string, queue tambien
vec.size()
str.size()
set.size()
queue.size()
// Tambien lo podes calcular con punteros end() - begin()

// Lower bound, busca por el primer elemento del rango que no es menor al valor o comparcion, es decir, mayor o igual
lower_bound(begin(), end(), valor, comp) // comparacion es opcional en donde comp(&1, &2) 1 es el tipo de los elemntos de donde se itera.
                                                                                        // Y 2 es el tipo del valor
// upper_bound,  busca por el primer elemento del rango que es estrictamente mayor al valor o comparcio, o en caso de no haber. Devuelve el ultimo
lower_bound(begin(), end(), valor, comp)
// Calve, 
//lower_bound te dice dónde empiezan los elementos no menores que el valor, 
// upper_bound te dice dónde terminan los elementos iguales al valor.

