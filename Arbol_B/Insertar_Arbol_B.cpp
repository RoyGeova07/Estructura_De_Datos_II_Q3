#include<iostream>
using namespace std;

const int ORDEN=3;//2 claves por nodo

struct NodoB
{
    
    int claves[ORDEN-1];
    NodoB*hijos[ORDEN];//maximo 3 hijos para autobalancear
    int n;//para la cantidad de claves
    bool hoja;//y para identificar si es hoja o nodo interno

};

//funcion para crear nodos
NodoB*CrearNodo(bool EsHoja)
{

    NodoB*nuevo_nodo=new NodoB;
    nuevo_nodo->n=0;
    nuevo_nodo->hoja=EsHoja;
    for(int i=0;i<ORDEN;i++)//con este for prepara a los punteros hijos en null que son 3
    {

        nuevo_nodo->hijos[i]=nullptr;

    }
    return nuevo_nodo;  

}

void dividirHijo(NodoB*padre,int i,NodoB*hijo)
{

    //aqui se ordenan las claves si se quiere insertar antes de dividir  (simula que el hijo ya estaba lleno)
    //en este caso, ya estan bien distribuidas, asi que tomamos directamente
    int claveCentral=hijo->claves[1];

    // Paso 1: crear nuevo nodo (hermano derecho)
    NodoB*nuevo_nodo=CrearNodo(hijo->hoja);

    //Paso 2: reasignar hijo original con la clave menor
    hijo->n=1;

    //Paso 3: copiar hijos si no es hoja
    if(!hijo->hoja)
    {

        nuevo_nodo->hijos[0]=hijo->hijos[2];
        nuevo_nodo->hijos[1]=hijo->hijos[3];

    }
    
    //Paso 4: insertar nuevo hijo al padre
    for(int j=padre->n;j>=i+1;j--)
        padre->hijos[j+1]=padre->hijos[j];
    padre->hijos[i+1]=nuevo_nodo;

    //Paso 5 : insertar claveCentral al padre
    for(int j=padre->n-1;j>=i;j--)
        padre->claves[j+1]=padre->claves[j];
    padre->claves[i]=claveCentral;
    padre->n++;

}

//que hace esta funcion de InsertarNoLleno?
//esta funcion inserta una nueva clave 'clave_calor' dentro de un nodo que aun no esta lleno

void InsertarNoLleno(NodoB* nodo_solo,int clave_valor)
{

    int i=nodo_solo->n-1;

    //====  CASO 1 ====
    if(nodo_solo->hoja)
    {

        //se recorre hacia atras para encontrar donde va la clave
        while(i>=0&&clave_valor<nodo_solo->claves[i])
        {

            nodo_solo->claves[i+1]=nodo_solo->claves[i];//aqui desplazamos claves(nodo) hacia la derecha
            i--;

        }
        nodo_solo->claves[i+1]=clave_valor;//aqui inserta la nueva clave(valor) en orden
        nodo_solo->n++;//aqui aumenta el numero de claves

        //ejemplo visual de como funciona este caso 1, cuando es hoja

        //tenemos este arbol:

        /*
        
             [20]
            /     \
          [10]   [30, 40]

          los nodos hojas son:  [10], hijo izquierdo  [30,40], hijo derecho

          vamos a insertar 15 dentro de este arbol para ver como funciona este caso 1

          donde ira el 15?   15<20, baja al hijo izquierdo: [10]
          ese nodo es una hoja, actualmente tiene n=1, clave=[10] -> NO ESTA LLENO
            entonces llama a: insertarNoLleno(nodo_solo = [10], clave_valor = 15);

          int i = nodo_solo->n - 1;  // i = 0
          
          if (nodo_solo->hoja) {
          cumple, si es hoja, entra a la condicional

          ahora pasa por el while, i=0? si, clave_valor= 15 es menor que nodo_solo=10? no, no entra al while, asi que no dezplaza nada 
          asi que, inserta directamente, claves[i + 1] = clave_valor; claves[1] = 15

          ahora el nodo queda -> [10,15], n++ -> n2

        
        */

    }else{//caso 2, no es hoja

        while(i>=0&&clave_valor<nodo_solo->claves[i])i--;//se busca el hijo apropiado
        i++;//se corrige el indice para el hijo donde bajaremos 

        if(nodo_solo->hijos[i]->n==ORDEN-1)
        {

            dividirHijo(nodo_solo,i,nodo_solo->hijos[i]);//si esta lleno lo dividimos

            if(clave_valor>nodo_solo->claves[i])i++;// si el nodo nuevo a insertar es menor que el nodo solo baja

        }

        InsertarNoLleno(nodo_solo->hijos[i],clave_valor);//bajamos al hijo 

        /*
        
            ¿Que hace aqui, en el caso 2?
            Busca el hijo correcto:

            Recorre el arreglo de claves para saber en que hijo i debe bajar.

            Antes de bajar, verifica si ese hijo esta lleno:

            Si si -> lo divide usando dividirHijo

            Luego actualiza i si la clave que subio es menor o mayor que k

            Llama recursivamente insertarNoLleno sobre el hijo i.
        
        */

    }

}

void Insertar(NodoB*&raiz_arbol,int clave_nodo_a_insertar)
{

    if(raiz_arbol==nullptr)
    {

        raiz_arbol=CrearNodo(true);
        raiz_arbol->claves[0]=clave_nodo_a_insertar;//aqui se coloca la clave en la primera posicion
        raiz_arbol->n=1;//tiene una clave

        /*
        
            Se crea el primer nodo del arbol (la raiz).

            El nuevo nodo se marca como hoja (porque no tiene hijos).

            Se almacena la clave en claves[0].

            Se indica que tiene 1 clave (n = 1).

        */

    }else{

        //CASO A: La raiz esta llena
        if(raiz_arbol->n==ORDEN-1)
        {

            NodoB*nueva_Raiz=CrearNodo(false);//se crea una nueva raiz (no hoja)
            nueva_Raiz->hijos[0]=raiz_arbol;//el hijo izquierdo es la antigua raiz
            dividirHijo(nueva_Raiz,0,raiz_arbol);//aqui se divide ese hijo lleno en la posicion 0

            int insertar=(clave_nodo_a_insertar>nueva_Raiz->claves[0])?1:0;//aqui se elige a que hijo insertar en la clave 
            InsertarNoLleno(nueva_Raiz->hijos[insertar],clave_nodo_a_insertar);//se inserta en el hijo correcto 

            raiz_arbol=nueva_Raiz;//aqui se actualiza la nueva raiz del arbol

            /*

                en este caso 1

                El nodo raiz ya no puede crecer mas (esta lleno).

                Se crea una nueva raiz, y la vieja raiz se convierte en el hijo izquierdo.

                Se divide esa raiz vieja en dos mitades y se sube una clave al centro.

                Dependiendo del valor de 'clave_nodo_a_insertar', decidimos si insertar en el hijo izquierdo (i = 0) o derecho (i = 1).

                Finalmente, actualizamos la raiz para que apunte a la nueva raiz.

                Este es el momento en que el arbol crece en altura.
            
            */


        }else{//CASO B: La raiz no esta llena 

            InsertarNoLleno(raiz_arbol,clave_nodo_a_insertar);

            /*
            
                en este caso B
                Simplemente llamamos a la funcion insertarNoLleno() para insertar la 'clave_nodo_a_insertar' 
                en el lugar correcto del arbol.

                Esto no causara divisiones de raiz, porque aun hay espacio.
            
            */

        }

    }

}

//con esta funcion el arbol se imprimira de forma descendente (de derecha a izquierda)
//para que los nodos mas profundos aparezcan mas abajo y mas indentados.

void MostrarArbol(NodoB*nodo,int nivel=0)//con el nivel indica la profundidad del nodo para controlar la indentacion 
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
                MostrarArbol(nodo->hijos[i+1],nivel+1);
            for(int j=0;j<nivel;j++)cout<<"   ";
            cout<<nodo->claves[i]<<endl;
        }
        if(!nodo->hoja)
            MostrarArbol(nodo->hijos[0],nivel+1);

    }
}

int main()
{

    NodoB*raiz_arbol=nullptr;
    int opcion,insertar_nodo;

    do
    {
        
        cout<<"\n=====ARBOL B=====\n";
        cout<<"1. Insertar elementos a Arbol B\n";
        cout<<"2. Mostrar Arbol\n";
        cout<<"3. Salir\n";
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        if(opcion==1)
        {

            cout<<"Ingrese un dato: ";
            cin>>insertar_nodo;
            Insertar(raiz_arbol,insertar_nodo);

        }else if(opcion==2){

            MostrarArbol(raiz_arbol);

        }else if(opcion==3){

            cout<<"\nTERMINOOO";

        }


    } while (opcion!=3);
    

}