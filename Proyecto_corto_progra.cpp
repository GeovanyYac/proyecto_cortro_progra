
/***************************
PROYECTO CORTO PROGRAMACION 1 V1.0
Programadores: 
    Elder Geovany Yac Mul - 202007018
    Andres Fernando Gonzalez Alcantara - 202308061
    Denis Alexander Lucas Ramirez - 202207036
***************************/

#include <iostream>
#include <string.h>

using namespace std;

string jugador_1;  //Variables globales
string jugador_2;  //Variables globales
char logo=220;     //Variables globales

void fila_1(int a)  //Despliegue de la primera fila
{
    if(a>0)
    {
        cout<<"    ";
        for(int fila_1=1; fila_1<=a; fila_1++){
            cout<<logo<<" ";
        }
    }

}

void fila_2(int a)   //Despliegue de la segunda fila
{
    if(a>0)
    {
        cout<<"  ";
        for(int fila_2=1; fila_2<=a; fila_2++){
        cout<<logo<<" ";
        }
    }
}

void fila_3(int a)   //Despliegue de la tercera fila
{
    if(a>0)
    {
        for(int fila_3=1; fila_3<=a; fila_3++){
            cout<<logo<<" ";
        }
    }
}

int main()         //Funcion principal
{
    int seleccion_fila;
    int eliminacion;
    int fila_a=3;
    int fila_b=5;
    int fila_c=7;
    cout<<"Ingrese el nombre del jugador 1"<<endl;
    cin>>jugador_1;
    cout<<"Ingrese el nombre del jugador 2"<<endl;
    cin>>jugador_2;

    cout<<"**"<<jugador_1<<" vs "<<jugador_2<<"**"<<endl;

    fila_1(fila_a);   //Llamado a la primera fila
    cout<<endl;
    fila_2(fila_b);   //Llamado a la segunda fila
    cout<<endl;
    fila_3(fila_c);   //Llamado a la tercera fila
    cout<<endl;

    for (int a = 1; a > 0; a++)
    {
        if (a % 2 == 0)//TURNO JUGADOR 2
        {
            cout << "El turno de: " << jugador_2 << endl;
            cout << "Ingrese el numero de fila en la que desea eliminar" << endl;
            cin >> seleccion_fila;
            cout << "Ingrese el numero de elementos a eliminar" << endl;
            cin >> eliminacion;

            if (seleccion_fila == 1)
            {
                fila_a -= eliminacion;
                fila_1(fila_a);
                cout << endl;
                fila_2(fila_b);
                cout << endl;
                fila_3(fila_c);
                cout << endl;
            }
            if (seleccion_fila == 2)
            {
                fila_b -= eliminacion;
                fila_1(fila_a);
                cout << endl;
                fila_2(fila_b);
                cout << endl;
                fila_3(fila_c);
                cout << endl;
            }
            if (seleccion_fila == 3)
            {
                fila_c -= eliminacion;
                fila_1(fila_a);
                cout << endl;
                fila_2(fila_b);
                cout << endl;
                fila_3(fila_c);
                cout << endl;
            }
        }
        else //TURNO JUGADOR 1
        {
            cout << "Turno de: " << jugador_1 << endl;
            cout << "Ingrese el numero de fila en la que desea eliminar" << endl;
            cin >> seleccion_fila;
            cout << "Ingrese el numero de elementos a eliminar" << endl;
            cin >> eliminacion;

            if (seleccion_fila == 1)
            {
                fila_a -= eliminacion;
                fila_1(fila_a);
                cout << endl;
                fila_2(fila_b);
                cout << endl;
                fila_3(fila_c);
                cout << endl;
            }
            if (seleccion_fila == 2)
            {
                fila_b -= eliminacion;
                fila_1(fila_a);
                cout << endl;
                fila_2(fila_b);
                cout << endl;
                fila_3(fila_c);
                cout << endl;
            }
            if (seleccion_fila == 3)
            {
                fila_c -= eliminacion;
                fila_1(fila_a);
                cout << endl;
                fila_2(fila_b);
                cout << endl;
                fila_3(fila_c);
                cout << endl;
            }
        }

    }

    return 0;
}
