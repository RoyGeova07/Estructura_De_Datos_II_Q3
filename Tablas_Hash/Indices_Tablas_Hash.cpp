//aqui usaremos indices en archivos txt usando estructuras para implementarlos 

//Indices con tablas Hash
//ideal para busqueda rapida, sin importar el orden 

//Tenemos un archivo registros.txt con contenido como:

// 1001 Juan  20
// 1002 Maria 21
// 1003 Pedro 19
// Cada línea es un registro con:

// ID

// Nombre

// Edad

// Queremos usar una tabla hash en memoria que relacione el ID del registro con su posición (offset) en el archivo.

#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
using namespace std;

unordered_map<int,streampos> indiceHash;

/*

    Nos permite usar la estructura unordered_map, que es una tabla hash de C++.

    ¿Qu es unordered_map?
    Es una estructura de clave-valor, donde:

    Las claves se almacenan sin orden especifico.
    
    El acceso a los elementos es muy rapido: en promedio O(1).

    en el codigo 
    unordered_map<int, streampos> indiceHash;

    Esto crea una tabla hash donde:

    La clave es el ID del registro (por ejemplo 1001).

    El valor es la posicion (offset) en el archivo donde comienza ese registro.


    ¿Como se usa?

    En la funcion construirIndiceHash():

    Se guarda que el registro con ID id está en la posición posicion del archivo.

    Luego, en buscarPorIDHash():

    Se accede directamente a la posicion guardada para ese ID, sin buscar linea por linea. 
    Asi se accede en tiempo O(1).

*/

void ConstruirIndiceHash(const string&archivo)
{

    ifstream file(archivo);
    string linea;
    streampos posicion;

    while(file.good())
    {

        posicion=file.tellg();//con esto guarda la posicion del inicio de la linea
        int id;
        file>>id;

        indiceHash[id]=posicion;
        getline(file,linea);//salta al final de la linea actual

    }
    file.close();

}

void BuscarPorIDHash(const string&archivo,int IdBuscado)
{

    ifstream file(archivo);

    if(indiceHash.find(IdBuscado)!=indiceHash.end())
    {

        file.seekg(indiceHash[IdBuscado]);
        string linea;
        getline(file,linea);
        cout<<"Registro encontrado: "<<linea<<endl;

    }else{

        cout<<"ID no encontaro\n";

    }
    file.close();

}