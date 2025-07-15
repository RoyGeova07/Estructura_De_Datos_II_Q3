// Problema: Registro rapido de estudiantes por su numero de cuenta

// Un colegio necesita registrar y buscar estudiantes por su número de cuenta (entero único de 6 dígitos). Debes implementar un sistema que:

// Permita insertar estudiantes con su número de cuenta y nombre.

// Permita buscar rápidamente si un estudiante está registrado.

// Use una tabla hash con encadenamiento (listas en cada posición).

// Todo implementado desde cero (sin usar unordered_map).

#include<iostream>
#include<vector>
#include<list>
using namespace std;

const int tamanio=10;

struct Estudiante
{

    int NumeroCuenta;
    string nombre;

};

//vector de lista, tablita hashhh
vector<list<Estudiante>>tabla(tamanio);

//funcion hash basica
int funcionHash(int numeroCuenta)
{

    return numeroCuenta%tamanio;

}

void InsertarEstudiante(int cuenta,string nombre)
{

    int indice=funcionHash(cuenta);
    tabla[indice].push_back({cuenta,nombre});
    cout<<"Estudiante insertado en indice "<<indice<<endl;

}

bool BuscarEstudiante(int cuenta)
{

    int indice=funcionHash(cuenta);
    for(const auto& busca:tabla[indice])
    {

        if(busca.NumeroCuenta==cuenta)
        {

            cout<<"Encontrado: "<<busca.nombre<<" en indice "<<indice<<endl;
            return true;

        }

    }
    cout<<"Estudiante no encontrado"<<endl;
    return false;

}

void MostrarTabla()
{

    for(int i=0;i<tamanio;i++)
    {

        cout<<"Indice"<<i<<": ";
        for(const auto&muestra:tabla[i])
        {

            cout<<"["<<muestra.NumeroCuenta<<" - "<<muestra.nombre<<"]";

        }
        cout<<endl;

    }

}


