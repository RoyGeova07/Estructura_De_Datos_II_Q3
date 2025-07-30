#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int suma(int n)
{

    if(n==0)
    {

        return 0;

    }else{

        return n+suma(n-1);

    }

}

int main()
{

    auto inicio=high_resolution_clock::now();

    cout<<"La suma de los numero del 1 al "<<6<<" es: "<<suma(100)<<'\n';

    auto fin=high_resolution_clock::now();

    auto duracion=duration_cast<nanoseconds>(fin-inicio);
    cout<<"Tiempo de ejecucion: "<<duracion.count()<<" nanosegundos\n";

    return 0;
}