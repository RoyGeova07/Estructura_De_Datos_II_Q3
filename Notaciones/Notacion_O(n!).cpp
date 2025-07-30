#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
   
int contador=1;
void Permutar(string dato,int inicio,int fin)
{

    if(inicio==fin)
    {

        cout<<contador<<"."<<dato<<'\n';
        contador++;

    }else{

        for(int i=inicio;i<=fin;i++)
        {

            swap(dato[inicio],dato[i]);
            Permutar(dato,inicio+1,fin);
            swap(dato[inicio],dato[i]);

        }

    }

}
int main()
{

    auto inicio=high_resolution_clock::now();

    Permutar("ERICKAL",0,6);

    auto fin=high_resolution_clock::now();

    auto duracion=duration_cast<milliseconds>(fin-inicio);
    cout << "Tiempo de ejecucion: " << duracion.count() << " milisegundos\n";


    auto duracionNano = duration_cast<nanoseconds>(fin - inicio);
    cout << "\nTiempo de ejecucion O(n2): " << duracionNano.count() << " nanosegundos\n";


    return 0;
}
