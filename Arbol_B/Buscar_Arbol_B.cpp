#include<iostream>
using namespace std;

const int ORDEN=3;

struct NodoB
{
    
    int Claves[ORDEN-1];
    NodoB*hijos[ORDEN];
    int n;
    bool hoja;

};

NodoB*CrearNodo(bool esHoja)
{

    NodoB*nuevo_nodo=new NodoB;
    nuevo_nodo->n=0;
    nuevo_nodo->hoja=esHoja;
    for(int i=0;i<ORDEN;i++)
    {

        nuevo_nodo->hijos[i]=nullptr;

    }
    return nuevo_nodo;

}

void DividirHijo(NodoB*Padre,int i,NodoB*Hijo)
{

    int Clave_Central=Hijo->Claves[1];

    NodoB*nuevo_nodo=CrearNodo(Hijo->hoja);

    Hijo->n=1;

    if(!Hijo->hoja)
    {

        nuevo_nodo->hijos[0]=Hijo->hijos[2];
        nuevo_nodo->hijos[1]=Hijo->hijos[3];

    }

    for(int j=Padre->n;j>=i+1;j--)
    {

        Padre->hijos[j+1]=Padre->hijos[j];

    }
    Padre->hijos[i+1]=nuevo_nodo;

    for(int j=Padre->n-1;j>=i;j--)
    {

        Padre->Claves[j+1]=Padre->Claves[j];

    }
    Padre->Claves[i]=Clave_Central;
    Padre->n++;

}

void InsertarNoLleno(NodoB*nodo_solo,int clave_valor)
{

    int i=nodo_solo->n-1;

    if(nodo_solo->hoja)
    {

        while(i>=0&&clave_valor<nodo_solo->Claves[i])
        {

            nodo_solo->Claves[i+1]=nodo_solo->Claves[i];
            i--;

        }
        nodo_solo->Claves[i+1]=clave_valor;
        nodo_solo->n++;

    }else{

        while(i>=0&&clave_valor<nodo_solo->Claves[i])i--;
        i++;

        if(nodo_solo->hijos[i]->n==ORDEN-1)
        {

            DividirHijo(nodo_solo,i,nodo_solo->hijos[i]);

            if(clave_valor>nodo_solo->Claves[i])i++;

        }

        InsertarNoLleno(nodo_solo->hijos[i],clave_valor);
        
    }

}

void Insertar(NodoB*&Arbol,int clave_nodo_a_insertar)
{

    if(Arbol==nullptr)
    {

        Arbol=CrearNodo(true);
        Arbol->Claves[0]=clave_nodo_a_insertar;
        Arbol->n=1;

    }else{

        if(Arbol->n==ORDEN-1)
        {

            NodoB*Nueva_Raiz=CrearNodo(false);
            Nueva_Raiz->hijos[0]=Arbol;
            DividirHijo(Nueva_Raiz,0,Arbol);

            int Insertar=(clave_nodo_a_insertar>Nueva_Raiz->Claves[0])?1:0;
            InsertarNoLleno(Nueva_Raiz->hijos[Insertar],clave_nodo_a_insertar);

            Arbol=Nueva_Raiz;

        }else{

            InsertarNoLleno(Arbol,clave_nodo_a_insertar); 

        }

    }

}

void MostrarArbol(NodoB*nodo,int nivel=0)
{

    if(nodo==nullptr)
    {

        cout<<"\nArbol Vacio, inserte datos para visualizar el Arbol B\n";
        return;

    }

    if(nodo!=nullptr) 
    {
    
        for(int i=nodo->n-1;i>=0;i--)
        {

            if(!nodo->hoja)
            {

                MostrarArbol(nodo->hijos[i+1],nivel+1);

            }
            for(int j=0;j<nivel;j++)
            {

                cout<<"   ";

            }
            cout<<nodo->Claves[i]<<endl;

        }
        if(!nodo->hoja)
        {

            MostrarArbol(nodo->hijos[0],nivel+1);

        }

    }

}

NodoB*Buscar(NodoB*nodo,int clave_buscar)
{

    int iterador=0;

    //Paso 1: Buscar la primera clave mayor o igual a la clave que buscamos
    while(iterador<nodo->n&&clave_buscar>nodo->Claves[iterador])
    {

        iterador++;

        

    }

    //Paso 2: Si encontramos la clave, la retornamos
    if(iterador<nodo->n&&clave_buscar==nodo->Claves[iterador])
    {

        cout<<"Clave "<<clave_buscar<<" encontrada en el nodo con claves: ";
        for(int j=0; j<nodo->n;j++)
        {

            cout<<nodo->Claves[j]<<" ";

        }
        cout<<"\n";
        return nodo;

    }

    //Paso 3: Si es hoja y no la encontramos, la clave no existe
    if(nodo->hoja)
    {

        cout<<"\nClave "<<clave_buscar<<" no encontrada (nodo hoja alcanzado)\n";
        return nullptr;

    }

    //Paso 4: Si no es hoja, buscamos en el hijo correspondiente
    return Buscar(nodo->hijos[iterador],clave_buscar);

}

int main()
{

    NodoB*Arbol=nullptr;
    int opcion,insertar_nodo,buscar_clave;

    do
    {
        
        cout<<"\n=====ARBOL B=====\n";
        cout<<"1. Insertar elementos a Arbol B\n";
        cout<<"2. Mostrar Arbol\n";
        cout<<"3. Buscar Nodo\n";
        cout<<"4. Salir\n";
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        if(opcion==1)
        {

            cout<<"Ingrese un dato: ";
            cin>>insertar_nodo;
            Insertar(Arbol,insertar_nodo);

        }else if(opcion==2){

            MostrarArbol(Arbol);

        }else if(opcion==3){

            cout<<"Ingrese la clave a buscar: \n";
            cin>>buscar_clave;
            Buscar(Arbol,buscar_clave);

        }else if(opcion==4){

            cout<<"\nTERMINOOO";

        }


    } while (opcion!=4);
    

}