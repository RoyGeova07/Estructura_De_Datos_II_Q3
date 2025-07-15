#include<iostream>
using namespace std;

const int ORDEN=3;//2 claves 

struct NodoB
{
    
    int claves[ORDEN-1];//maximo 2 claves, si son 3 se divide 
    int cantidad_claves;
    bool hoja;

    NodoB() 
    {

        cantidad_claves=1;// osea [10], una clave
        hoja=true;
        claves[0]=10;//el arbol empieza con una clave

    }

};

void InsertarEnHoja(NodoB* nodo,int clave_valor)
{

    int i=nodo->cantidad_claves-1;

    //aqui recorremos las claves hacia atras buscando la posicion
    while(i>=0&&clave_valor<nodo->claves[i])
    {

        nodo->claves[i+1]=nodo->claves[i];//se dezplaza a la derecha
        i--;

    }
    nodo->claves[i+1]=clave_valor;//aqui se inserta en la posicion
    nodo->cantidad_claves++;//aqui se aumenta la cantidad de claves

    /*
    
        Explicacion aca:

        en este codigo, busca el lugar correcto para insertar el 'clave_valor' dentro del arreglo de claves del nodo (ya ordenado)
        Desplaza claves hacia la derecha si son mayores que la que se va a insertar.
        Inserta la clave en la posicion correcta.
        y funciona solo si el nodo no esta lleno 

        caso 1: insertamos 12 en [10], ahora en el arbol solo tenemos el valor de [10] por defecto 

        Estado inicial:
        claves = [10]
        cantidad_claves = 1

        ahora entra la funcion 
        InsertarEnHoja(nodo, 12);

        1. i = cantidad_claves - 1 = 0
        2. clave_valor = 12
        3. Compara: 12 < claves[0] = 10 -> NO entra al while
        4. Va directo a claves[i+1] = claves[1] = 12
        5. Ahora: claves = [10, 12]
        6. Aumenta cantidad_claves = 2

        Resultado visual:
        [10, 12] (ordenado correctamente)

        ============================================================
        caso 2: ahora en ves de 12 insertamos 7 en [10]

        Estado inicial:
        claves = [10]
        cantidad_claves = 1

        InsertarEnHoja(nodo, 7);

        1. i = cantidad_claves - 1 = 0
        2. clave_valor = 7
        3. Compara: 7 < claves[0] = 10 -> Si entra al while
        4. Dentro del while: Desplaza 10 a claves[1] y  Decrementa i -> -1 -> sale del while
        5. Inserta 7 en claves[i+1] = claves[0]
        6. Resultado: claves = [7, 10]
        7. cantidad_claves = 2

        Resultado visual:
        [7, 10]  (ordenado correctamente)

    */

}