#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;

void Merge(int arr[],int izq,int mid, int der)
{

    int n1=mid-izq+1;
    int n2=der-mid;

    int* L=new int[n1];
    int* R=new int[n2];
    for(int i=0;i<n1;i++) L[i]=arr[izq+i];
    for(int j=0;j<n2;j++)R[j]=arr[mid+1+j];

    int i=0,j=0,k=izq;
    
    while(i<n1&&j<n2)
    arr[k++]=(L[i]<=R[j])?L[i++]:R[j++];

    while(i<n1)arr[k++]=L[i++];
    while(j<n2)arr[k++]=R[j++];

    delete[] L;
    delete[] R;


}

void MergeSort(int arr[],int izq,int der)
{

    if(izq<der)
    {

        int mid=(izq+der)/2;
        MergeSort(arr,izq,mid);
        MergeSort(arr,mid+1,der);
        Merge(arr,izq,mid,der);

    }

}

int main()
{

    int arr[]={8,4,1,9,6,2,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    auto inicio=high_resolution_clock::now();

    cout<<"Arreglo orginal: \n";
    for(int i=0;i<n;i++)
    {

        cout<<arr[i]<<" ";

    }

    MergeSort(arr,0,n-1);
    cout<<"\nArreglo ordenado: ";
    for(int i=0;i<n;i++)
    {

        cout<<arr[i]<<" ";

    }

    auto fin=high_resolution_clock::now();

    auto duracion=duration_cast<nanoseconds>(fin-inicio);
    cout<<"Tiempo de ejecucion: "<<duracion.count()<<" nanosegundos\n";


}