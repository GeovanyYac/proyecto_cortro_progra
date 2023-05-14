/******************************************************************************
PROYECTO CORTO PROGRAMACION 1 V1.1
Programadores: 
    Elder Geovany Yac Mul - 202007018
    Andres Fernando Gonzalez Alcantara - 202308061
    Denis Alexander Lucas Ramirez - 202207036
*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int fila_1 = 3, fila_2 = 5, fila_3 = 7; // Número de objetos en cada fila
int puntos_j1 = 0, puntos_j2 = 0; // Puntos de los jugadores
char logo = 220;

void imprimir_tablero(){ //Impresion del tablero de juego
    cout << "\n   Fila 1: ";
    for(int i = 0; i < fila_1; i++) {
        cout <<logo<<" ";
    }
    cout << " (" << fila_1 << ")\n";

    cout << "   Fila 2: ";
    for(int i = 0; i < fila_2; i++) {
        cout <<logo<<" ";
    }
    cout << " (" << fila_2 << ")\n";

    cout << "   Fila 3: ";
    for(int i = 0; i < fila_3; i++) {
        cout <<logo<<" ";
    }
    cout << " (" << fila_3 << ")\n";
}

int modificacion_tablero(int fila, int cantidad){//Modifica la cantidad de objetos por fila
    switch(fila){
        case 1:
            fila_1-=cantidad;
        break;
        case 2:
            fila_2-=cantidad;
        break;
        case 3:
            fila_3-=cantidad;
        break;
    }
    return fila;
}

bool terminar_juego(){//Comprueba si queda un objeto entre las 3 filas y finaliza la partida
    int objetos_restantes = fila_1 + fila_2 + fila_3;
    return objetos_restantes == 1;
}

void mostrarGanador(string jugador) {//Muestra el jugador que gana la partida
    cout << "\n************\n";
    cout << "¡" << jugador << " ha ganado el juego!\n";
    cout << "************\n";
}

int main(){
    string jugador_1,jugador_2;
    int seleccion_fila,eliminacion;
    
    cout<<"*************************************\n";
    cout<<"/*/*/*/ Bienvenido A NIM /*/*/*/\n";
    cout<<"*************************************\n";
    cout<<"Ingrese el nombre del jugador/a 1: ";
    cin>>jugador_1;
    cout<<"Ingrese el nombre del jugador/a 2: ";
    cin>>jugador_2;
    cout<<"*************************************\n";
    cout << "*******" << jugador_1 << " vs " << jugador_2 << "*******" <<endl;
    
    bool turnoJugador1 = true; // Variable para saber de quién es el turno
    
    while(!terminar_juego()){
        cout<<"*****************************\n";
        imprimir_tablero();
        if(turnoJugador1){
            cout << "Turno de: " << jugador_1 << endl;
		    cout << "Ingrese el numero de fila en la que desea eliminar" << endl;
		    cin >> seleccion_fila;
		    cout << "Ingrese el numero de elementos a eliminar" << endl;
		    cin >> eliminacion;
		    modificacion_tablero(seleccion_fila,eliminacion);
        }else{
            cout << "Turno de: " << jugador_2 << endl;
		    cout << "Ingrese el numero de fila en la que desea eliminar" << endl;
		    cin >> seleccion_fila;
		    cout << "Ingrese el numero de elementos a eliminar" << endl;
		    cin >> eliminacion;
		    modificacion_tablero(seleccion_fila,eliminacion);
        }
        turnoJugador1 = !turnoJugador1;
    }
        
    // Mostrar ganador y sumar puntos
    if(turnoJugador1) {
        mostrarGanador(jugador_2);
        puntos_j2 += 3;
    } else {
        mostrarGanador(jugador_1);
        puntos_j1 += 3;
    }    
    cout << "\nPuntos:\n" << jugador_1 << ": " << puntos_j1 << endl << jugador_2 << ": " << puntos_j2 << "\n\n";
    return 0;
}