#include<iostream>
#include<chrono>
#include<vector>
using namespace std::chrono;
using namespace std;

//voy hacer un fibonacci recursivo
int fibonacci(int n)
{

    if(n<=1)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);

}


int main()
{

    vector<int> resultados;
   int n=35;

    auto inicio = high_resolution_clock::now();

    for(int i=0;i<=n;i++) 
    {

        resultados.push_back(fibonacci(i));

    }

    auto fin=high_resolution_clock::now();

    for(int val:resultados) cout<<val<<" ";
    cout << endl;

    auto duracion=duration_cast<milliseconds>(fin-inicio);
    cout << "Tiempo de ejecucion: " << duracion.count() << " milisegundos\n";


    auto duracionNano = duration_cast<nanoseconds>(fin - inicio);
    cout << "\nTiempo de ejecucion O(n2): " << duracionNano.count() << " nanosegundos\n";

    return 0;

}
