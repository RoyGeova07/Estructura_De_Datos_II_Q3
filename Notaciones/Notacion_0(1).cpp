#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;

int main()
{

    int numeros[]={1,2,3,4,5,6};

    //aqui tiempo de inicio
    auto inicio=high_resolution_clock::now();

    //OPERACION 0(1)
    cout<<"ELEMENTOS EN LA POSICION 2: "<<numeros[2]<<'\n';

    //TIEMPO FIN
    auto fin=high_resolution_clock::now();

    //aqui se calcula la duracion
    auto duracion=duration_cast<nanoseconds>(fin-inicio);
    cout<<"Tiempo de ejecucion: "<<duracion.count()<<" nanosegundos\n";

    return  0;

}