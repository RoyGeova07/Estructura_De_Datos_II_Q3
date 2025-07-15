//¿Que es "hashing"?

//Hashing es una tecnica para almacenar y buscar datos rapidamente. En lugar de buscar dato por dato
//Se usa una formula llamada funcion hash que nos dice donde esta el dato directamente 

// [0]  
// [1]  
// [2]  
// [3]  
// [4]  
// [5]  
// [6]  
// [7]  
// [8]  
// [9]

//Si queremos guardar el nombre "Juan", en lugar de ponerlo en cualquier lugar,
//calculamos una posicion exacta con una funcion.

//¿Que es una funcion hash?

//Es una formula que convierte un dato (clave) en un numero que usaremos como indice en la tabla
//ejem función_hash("Juan") = 398
//posición_en_tabla = 398 % 10 = 8
//Entonces "Juan" se guarda en la posicin 8.

//¿Que es una tabla hash?

//Es una estructura de datos donde guardamos los elementos usando hashing 

//Se ve asi:
//tabla[0] = vacio
// tabla[1] = vacio
// ...
// tabla[8] = "Juan"

//cuando se quiera buscar a juan, no se recorre todo, aqui se aplica la funciona hash otra vez, 
//se cae en la posicion 8 directamente. MAS RAPIDOOOOOOO

// Objetivo del hashing
//1. Guardar datos en posiciones exactas y rapidas
//2. Buscar sin recorrer todo
//3. Insertar y eliminar rapidamente

// El tiempo promedio es:

// O(1) en el mejor caso (constante)

// Pero puede subir a O(n) si no se maneja bien (por colisiones)

//¿Que pasa si dos claves caen en la misma posicion?
// Eso se llama colision.

//EJEMPLO=====
// función_hash("Juan") = 398 → 398 % 10 = 8
// función_hash("Ana") = 288 → 288 % 10 = 8
// Ambos caen en la posición 8. Eso es una colisión. Tenemos que manejarla para no perder datos.


//================

//Metodos para manejar colisiones

// 1. Encadenamiento (Chaining)

//Cada casilla de la tabla contiene una lista.
//tabla[8] -> ["Juan" -> "Ana"]
//si hay colision, se agrega en esa lista

//2. Direccionamiento abierto (Open Addressing)
//si una casilla esta ocupada, se busca otra vacia con un patron
//Lineal: i+1, i+2, i+3, ...
//Cuadratico: i+1², i+2², ...
//Doble hashing: se usa una segunda funcion hash para saltar posiciones.

//¿Por que es tan importante hashing?
//Se usa en bases de datos, redes, seguridad, buscadores, diccionarios
//Es la base de estructuras como:

// unordered_map (C++)

// HashMap (Java)

// dict (Python)

// Se usa en contraseñas y criptografía (SHA, MD5...)


