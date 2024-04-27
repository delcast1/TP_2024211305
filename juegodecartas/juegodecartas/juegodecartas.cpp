#include "pch.h"
#include "iostream"
#include "conio.h"

using namespace std;
using namespace System;
//FUNCIONES VOID RAICES
void ventana() {

    Console::CursorVisible = 0;
}
void cursor(int x, int y) {
    Console::SetCursorPosition(x, y);
}
int valor_carta() {
    return 1 + rand() % 13; //VALOR ALEATORIO ENTRE 1 y 13
}
//PANTALLA DE CARGA Y DE INICIO
void pantallaCarga() {
    int x = 50, y = 10;

    Console::ForegroundColor = ConsoleColor::Blue;

    cursor(x + 7, y);
    cout << "Cargando...";
    cursor(x, y+2);
    cout << char(219);

    while (x <= 70) {
        cursor(x, y + 2);
        cout << char(219); // codigo ascii
        _sleep(60);
        x++;

    }
    system("cls");
}

void pantallaInicio() {
    
    Console::ForegroundColor = ConsoleColor::DarkCyan;
    int x=25, y=5, w=54, z= 18, eleccion;
    cursor(x,y); cout<<" _____                                                  _ __";
    cursor(x, y+1);cout<<"|  _  |                                                | |__|";
    cursor(x, y+2);cout<<"| | | |_ ___  ___ ___     _   _     _ ___ ___  ___  ___| |__  ___";
    cursor(x, y+3);cout<<"| | | | *_  |/  _/ _ |   | | | |   | *_  *_  |/ _ ||  _  |  |/ _ |";
    cursor(x, y+4);cout<<"| |_| | | | |  <_  __/   | |_| |   | | | | | |  __/| |_| |  | |_||";
    cursor(x, y+5);cout<<"|_____|_| |_||___|___/   |___. |   |_| |_| |_|____/|_____|__|____/";
    cursor(x, y + 6); cout << "                           __/ | ";
    cursor(x, y+7); cout << "                          |____/";
    cursor(x - 2, y + 9); cout << "______________________________________________________________________";

    cursor(w, z); cout << "[1] JUGAR";
    cursor(w, z+1); cout << "[2] INTRUCCIONES";
    cursor(w, z+2); cout << "[3] CREDITOS";
    cursor(x, z + 6); cout << "| 2024 - TRABAJO PARCIAL - MADE BY: DEL CASTILLO, MEZA, LORENZO | ";

    cursor(w, z + 3); cout << "OPCION: "; cin >> eleccion;
    while (eleccion > 3 || eleccion < 1) {
        cursor(w, z + 3); cout << "ESCOJA UNA OPCION VALIDA: "; cin >> eleccion;
    }
    
    system("cls"); //PARA LIMPIAR LA PANTALLA
}



int main() {
    srand(time(nullptr)); //Declarar semilla aleatoria
    const double LIMITE = 11.5;
    
    ventana();

    //Usando la funcion de pantalla de INICIO
    pantallaCarga();
    pantallaInicio();
    
    for (int partidas = 1; partidas <= 10; partidas++) {
        cout << "Partida: " << partidas<<endl;
        int jugador1_puntos = 0;
        int jugador2_puntos = 0;
        for (int turno = 1; turno <= 10; turno++) {
            system("color 0a");
            int cartaJugador1 = valor_carta(); //Valor aleatorio de la carta

            cout << "Turno " << turno << " - Carta de Jugador 1: " << cartaJugador1 << endl;

            // Sumar puntos al jugador 1
            if (cartaJugador1 >= 11) {
                jugador1_puntos += 0.5;
            }
            else {
                jugador1_puntos += cartaJugador1;
            }

            // Verificar si se alcanzó el límite 
            if (jugador1_puntos >= LIMITE) {
                break;
            }
            system("pause>0");
        }



        system("pause>0");
        system("cls");

        cout << "Turno del jugador 2:" << endl;

        // Turno del jugador 2
        for (int turno = 1; turno <= 10; turno++) {



            system("color 0c");
            int cartaJugador2 = valor_carta(); //Valor aleatorio de la carta 

            cout << "Turno " << turno << " - Carte de Jugador 2: " << cartaJugador2 << endl;

            // Validar y sumar puntos al jugador 2 (similar al jugador 1)
           // Sumar puntos al jugador 1
            if (cartaJugador2 >= 11) {
                jugador2_puntos += 0.5;
            }
            else {
                jugador2_puntos += cartaJugador2;
            }

            // Verificar si se alcanzó el límite
            if (jugador2_puntos >= LIMITE) {
                break;
            }
            system("pause>0");
        }

        // Determinar al ganador
        if ((jugador1_puntos > 11.5 || jugador2_puntos > 11.5) && jugador1_puntos < jugador2_puntos) {
            cout << "¡Jugador 1 gana!" << endl;
        }
        if ((jugador1_puntos > 11.5 || jugador2_puntos > 11.5) && jugador1_puntos > jugador2_puntos) {
            cout << "¡Jugador 2 gana!" << std::endl;
        }
        if ((jugador1_puntos == 11.5 && jugador2_puntos == 11.5) || (jugador2_puntos == jugador1_puntos)) {
            cout << "¡Empate!" << std::endl;
        }
        if (jugador1_puntos == 11.5 && jugador2_puntos != 11.5) {
            cout << "¡Jugador 1 gana!" << endl;
        }
        if (jugador2_puntos == 11.5 && jugador1_puntos != 11.5) {
            cout << "¡Jugador 2 gana!" << endl;
        }
        system("pause>0");
        system("cls");
    }

    
    return 0;
}
