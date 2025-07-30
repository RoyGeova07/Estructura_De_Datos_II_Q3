#include<iostream>
#include<chrono>
#include<vector>
using namespace std::chrono;
using namespace std;

void ImprimirPares(int n,vector<pair<int,int>>&pares)
{

    for(int i=0;i<=n;i++)
    {

        for(int j=0;j<=n;j++)
        {

            pares.push_back({i,j});

        }

    }

}

int main()
{

   int n = 35; // Puedes cambiarlo para ver la diferencia

    vector<pair<int, int>> pares;

    auto inicio=high_resolution_clock::now();

    ImprimirPares(n, pares);

    auto fin=high_resolution_clock::now();

    
    for (auto& p : pares) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;

    auto duracionmili =duration_cast<milliseconds>(fin- inicio);
    cout << "Tiempo de ejecucion O(n2): " << duracionmili.count() << " milisegundos\n";

    auto duracionNano= duration_cast<nanoseconds>(fin-inicio);
    cout << "\nTiempo de ejecucion O(n2): " << duracionNano.count() << " nanosegundos\n";

}