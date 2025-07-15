#include<iostream>
#include<string>
using namespace std;

const int tamanio_tabla=10;

struct Nodo
{
    
    int NumeroCuenta;
    string nombre;
    Nodo*siguiente;

};

//tabla hash, arreglo de punteros a nodo
Nodo*tabla[tamanio_tabla]={nullptr};

int funcionHash(int cuenta)
{

    return cuenta%tamanio_tabla;

}

void Insertar(int cuenta,string nombre)
{

    int indice=funcionHash(cuenta);
    Nodo*nuevo=new Nodo{cuenta,nombre,nullptr};

    //aqui se inserta al inicio 
    nuevo->siguiente=tabla[indice];
    tabla[indice]=nuevo;

    cout<<"\nInsertado en indice "<<indice<<endl;

}

bool BuscarEstudiante(int cuenta)
{

    int indice=funcionHash(cuenta);
    Nodo*actual=tabla[indice];

    while(actual!=nullptr)
    {

        if(actual->NumeroCuenta==cuenta)
        {

            cout<<"\nEncontrado "<<actual->nombre<<" (indice "<<indice<<")\n";
            return true;

        }
        actual=actual->siguiente;

    }
    cout<<"\nEstudiante no encontrado\n";
    return false;

}
void EliminarEstudiante(int cuenta)
{

    int indice=funcionHash(cuenta);
    Nodo*actual=tabla[indice];
    Nodo*anterior=nullptr;

    while(actual!=nullptr)
    {
        
        if(actual->NumeroCuenta==cuenta)
        {

            if(anterior==nullptr)
            {

                //se elimina el primero de la lista
                tabla[indice]=actual->siguiente;


            }else{

                anterior->siguiente=actual->siguiente;

            }
            delete actual;
            cout<<"\nEstudiante eliminado exitosamente.\n";
            return;
            
        }
        anterior=actual;
        actual=actual->siguiente;

    }
    cout<<"\nNo se encontro el estudiante a eliminar\n";
    

}

void MostrarTabla()
{

    cout<<"\n---Tabla hash---\n";
    for(int i=0;i<tamanio_tabla;++i)
    {

        cout<<"["<<i<<"]: ";
        Nodo*actual=tabla[i];
        while(actual!=nullptr)
        {
            
            cout<<"("<<actual->NumeroCuenta<<" - "<<actual->nombre<<") -> ";
            actual=actual->siguiente;

        }
        cout<<"nullptr\n";
        

    }

}

void LiberarMemoria()
{

    for(int i=0;i<tamanio_tabla;++i)
    {

        Nodo*actual=tabla[i];
        while(actual!=nullptr)
        {
            
            Nodo*aux=actual;
            actual=actual->siguiente;
            delete aux;

        }
        

    }

}

int main() 
{

    int opcion,cuenta;
    string nombre;

    do {
        cout<<"\n---Menu---\n";
        cout<<"1. Insertar estudiante\n";
        cout<<"2. Buscar estudiante\n";
        cout<<"3. Eliminar estudiante\n";
        cout<<"4. Mostrar tabla\n";
        cout<<"5. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;

        switch (opcion) 
        {
            case 1:

                cout<<"Ingrese numero de cuenta: ";
                cin>>cuenta;
                cin.ignore();
                cout<<"Ingrese nombre: ";
                getline(cin, nombre);
                Insertar(cuenta, nombre);
                break;

            case 2:

                cout<<"Ingrese numero de cuenta: ";
                cin>>cuenta;
                BuscarEstudiante(cuenta);
                break;

            case 3:

                cout<<"Ingrese numero de cuenta: ";
                cin>>cuenta;
                EliminarEstudiante(cuenta);
                break;

            case 4:

                MostrarTabla();
                break;

        }
    } while (opcion != 5);

    LiberarMemoria();
    cout << "Memoria liberada. Programa finalizado.\n";
    return 0;
}