/******************************************************************************
PROYECTO CORTO PROGRAMACION 1 V1.2
Programadores: 
    Elder Geovany Yac Mul - 202007018
    Andres Fernando Gonzalez Alcantara - 202308061
    Denis Alexander Lucas Ramirez - 202207036
*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int fila_1 = 3, fila_2 = 5, fila_3 = 7; // Número inicial de objetos en cada fila
int puntos_j1 = 0, puntos_j2 = 0; // Puntos iniciales de cada jugador
char logo = 42;// Objetos a elminar - Cubitos
string jugador_1,jugador_2; // Nombres de los jugadores
int seleccion_fila,eliminacion; //Fila y cantidad de Cubitos a Eliminar

void imprimir_tablero(){ //Impresion del tablero de juego
    cout << "\n   Fila 1: "; //Fila 1
    for(int i = 0; i < fila_1; i++) {
        cout <<logo<<" ";
    }
    cout << " (" << fila_1 << ")\n";

    cout << "   Fila 2: "; //Fila 2
    for(int i = 0; i < fila_2; i++) {
        cout <<logo<<" ";
    }
    cout << " (" << fila_2 << ")\n";

    cout << "   Fila 3: "; //Fila 3
    for(int i = 0; i < fila_3; i++) {
        cout <<logo<<" ";
    }
    cout << " (" << fila_3 << ")\n";
}

int modificacion_tablero(int fila, int cantidad){//Modifica la cantidad de objetos por fila
    switch(fila){
        case 1:
			if(fila_1>0 && cantidad <= fila_1) //Verificacion si la fila 1 tiene elementos a eliminar 
            fila_1-=cantidad;
			else // Si la fila esta vacia mostrar mensaje de turno perdido
			cout<<"Fila o cantidad invalida"<<endl<<"Perdio su turno"<<endl;
        break;
        case 2:
			if(fila_2>0 && cantidad <= fila_2) //verificacion si la fila 2 tiene elementos a eliminar
            fila_2-=cantidad;
			else // Si la fila esta vacia mostrar mensaje de turno perdido
			cout<<"Fila o cantidad invalida"<<endl<<"Perdio su turno"<<endl;
        break;
        case 3:
			if(fila_3>0 && cantidad <= fila_3) //verificacion si la fila 3 tiene elementos a eliminar
            fila_3-=cantidad;
			else // Si la fila esta vacia mostrar mensaje de turno perdido
			cout<<"Fila o cantidad invalida"<<endl<<"Perdio su turno"<<endl;
        break;
		default:
			cout<<"Fila invalida"<<endl<<"Perdio su turno"<<endl;
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

void juego(){// Ejecuta el juego
    bool turnoJugador1 = true; // Variable para saber de quién es el turno
    int opcion;
    
    while(!terminar_juego()){
        cout<<"*************************************\n";
        imprimir_tablero();
        if(turnoJugador1){
            cout << "Turno de: " << jugador_1 << endl;
		    cout << "Ingrese el numero de fila en la que desea \neliminar" << endl;
		    cin >> seleccion_fila;
		    cout << "Ingrese el numero de elementos a eliminar" << endl;
		    cin >> eliminacion;
		    modificacion_tablero(seleccion_fila,eliminacion);
        }else{
            cout << "Turno de: " << jugador_2 << endl;
		    cout << "Ingrese el numero de fila en la que desea \neliminar" << endl;
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
    
    //Pregunta al usuario si desea jugar otra partida
    cout<<"*************************************\n";
    cout<<"Desea Volver a jugar? \nIndique 1 para SI y 2 para NO\n";
    cout<<"*************************************\n";
    cin>>opcion;
    switch(opcion){
        case 1:
            fila_1=3;
            fila_2=5;
            fila_3=7;
            juego();
        break;
        default:
            cout<<"****** GRACIAS POR JUGAR A NIM ******";
        break;
    }
}

int main(){
    cout<<"*************************************\n";
    cout<<"/*/*/*/ Bienvenido A NIM /*/*/*/\n";
    cout<<"*************************************\n";
    cout<<"Ingrese el nombre del jugador/a 1: ";
    cin>>jugador_1;
    cout<<"Ingrese el nombre del jugador/a 2: ";
    cin>>jugador_2;
    cout<<"*************************************\n";
    cout << "*******" << jugador_1 << " vs " << jugador_2 << "*******" <<endl;
    
    juego();
    return 0;
}