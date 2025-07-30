#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

//BUSQUEDA BINARIAAAA

int main()
{

    int arreglo[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    auto inicio=high_resolution_clock::now();

    int inf=0,sup=5,mitad,dato=4;
    char band='F';

    
    while(inf<=sup)
    {

        mitad=(inf+sup)/2;

        if(arreglo[mitad]==dato)
        {

            band='V';
            break;

        }
        if(arreglo[mitad]>dato)
        {

            sup=mitad;
            mitad=(inf+sup)/2;

        }
        if(arreglo[mitad]<dato)
        {

            inf=mitad;
            mitad=(inf+sup)/2;

        }

    }

    if(band=='V')
    {

        cout<<"El numero a sido encontrado en la posicion: "<<mitad<<'\n';

    }else{

        cout<<"El numero no se encuentra en el arreglo\n";

    }

    auto fin=high_resolution_clock::now();

    auto duracion=duration_cast<nanoseconds>(fin-inicio);
    cout<<"Tiempo de ejecucion: "<<duracion.count()<<" nanosegundos\n";

}