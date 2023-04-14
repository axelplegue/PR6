#include "L0nchas.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <wincon.h>
#include <cstdlib>
#include "colors.h"
#include <mmsystem.h>

using namespace std;




int tirarDado() {
	int valDado=0;
	valDado = rand() % 6 + 1;
	return valDado;
}


Lanchas* variosJugadores(int numJugadores) {
	Lanchas* arrayLanchas = new Lanchas[numJugadores];

	for (size_t i = 0; i < numJugadores; i++)
	{
		string nombre;
		cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
		cin >> nombre;
		arrayLanchas[i] = Lanchas(0, 0, true, nombre);

	}
	return arrayLanchas;
}


int main() {



	srand(time(NULL));
	SetConsoleTitle(L"CARRERAS DE LANCHAS");

	string nombreLancha1;
	string nombreLancha2;
	string nombreLancha3 = "PC";
	int distancia1 = 0;
	int distancia2 = 0;
	int contador3 = 0;
	int opcion = 0;
	int tirada;
	int players = 0;
	int jugarMas = 0;
	int contador = 0;
			cout << LGREEN << "\t\t    ===========================================================================" << endl;
			cout << "\t\t    =			   CARRERAS DE L0NCHAS				      =" << endl;
			cout << "\t\t    =			      by axelplegue				      =" << endl;
			cout << "\t\t    ===========================================================================" << endl;
	do {
		
		cout << RESET << "\n\nCuantos jugadores van a jugar? [1 (VS PC) / LOS QUE QUIERAS] : ";
		cin >> players;


		if (players == 1) {
			cout << ORANGE << "\n\nIngrese el nombre del usuario que utilizara la lancha: ";
			cin >> nombreLancha1;
			Lanchas lancha1(0, 0, true, nombreLancha1);
			string nombreLancha3 = "PC";
			Lanchas lancha2(0, 0, true, nombreLancha3);
			cout << BLUE << "\nJugaras contra " << nombreLancha3;
			Sleep(1500);



			system("CLS");


			for (size_t i = 0; i < 5; i++) {

				cout << RESET << "\n\nRONDA " << i + 1 << "\n\n";


				cout << ORANGE << "\nTURNO DEL JUGADOR " << lancha1.getName() << "\n\n";

				//TIRADA DE DADO DEL JUGADOR 1

				cout << "\nTIRA TU DADO " << lancha1.getName() << ": (Pulsa 0)\n\n";
				cin >> tirada;
				lancha1.setVelocidad(tirarDado() + lancha1.getVelocidad());
				cout << "\nTras la tirada del dado, la lancha de " << lancha1.getName() << " tiene una velocidad de " << lancha1.getVelocidad() << "km/h\n\n";

				lancha1.turnoJugada(lancha1, opcion);

				cout << BLUE << "\nTURNO DEL JUGADOR " << lancha2.getName() << "\n\n";


				//TIRADA DE DADO DEL JUGADOR 2

				cout << "\nLa maquina va a tirar el dado.\n\n";
				tirarDado();
				lancha2.setVelocidad(tirarDado() + lancha2.getVelocidad());
				cout << "\nTras la tirada del dado, la lancha de " << lancha2.getName() << " tiene una velocidad de " << lancha2.getVelocidad() << "km/h\n\n";
				Sleep(3000);

				distancia1 = lancha1.getVelocidad() * 100;
				distancia2 = lancha2.getVelocidad() * 100;

				if (contador3 == 0)
				{
					cout << "\nLa maquina tiene la posibilidad de usar nitro.\n";
					if (distancia1 - distancia2 > 200) {
						lancha2.randomNitro();
						contador3++;
						Sleep(3000);
					}
					else
					{
						cout << "\nLa maquina ha decidido no utilizar el nitro :(\n";
						Sleep(3000);
					}
				}
				else if (contador3 > 0) {
					cout << "\nLa maquina no puede utilizar mas veces el nitro :(\n";
					Sleep(3000);
				}



				cout << "\t";
				system("CLS");



				//IMPRIMIR LANCHA 1
				cout << "BARCO DE: " << lancha1.getName() << ". LLEVA " << distancia1 << " METROS.\n";
				for (size_t i = 0; i < distancia1 / 100; i++)
				{
					cout << ORANGE << "--";
					Sleep(50);
				}
				cout << "    /\\" << endl;

				for (size_t i = 0; i < distancia1 / 100; i++)
				{
					cout << ORANGE << "--";
					Sleep(50);
				}
				cout << "___/  \\___" << endl;

				for (size_t i = 0; i < distancia1 / 100; i++)
				{
					cout << ORANGE << "--";
					Sleep(50);
				}
				cout << "\\________/" << RESET << endl;
				Sleep(2000);
				//IMPRIMIR BARCO 3
				cout << "BARCO DE: " << lancha2.getName() << ". LLEVA " << distancia2 << " METROS.\n";
				cout << "\n\n";
				for (size_t i = 0; i < distancia2 / 100; i++)
				{
					cout << BLUE << "--";
					Sleep(50);
				}
				cout << "    /\\" << endl;

				for (size_t i = 0; i < distancia2 / 100; i++)
				{
					cout << BLUE << "--";
					Sleep(50);
				}
				cout << "___/  \\___" << endl;

				for (size_t i = 0; i < distancia2 / 100; i++)
				{
					cout << BLUE << "--";
					Sleep(50);
				}
				cout << "\\________/" << RESET << endl;
				Sleep(4000);

				if (i == 4) {
					if (distancia1 > distancia2)
					{
						cout << BG_ORANGE << BLUE << "\n\n\nEL GANADOR DE LA CARRERA HA SIDO " << lancha1.getName() << " CON UNA DISTANCIA DE " << distancia1 << " METROS.\n";
						cout << "\n\nLE HA SACADO " << distancia1 - distancia2 << " METROS DE DIFERENCIA A " << lancha2.getName() << ".\n" << RESET;
					}
					else if (distancia2 > distancia1) {
						cout << BG_BLUE << ORANGE << "\n\n\nHAS PERDIDO LA CARRERA CONTRA LA MAQUINA CON UNA DISTANCIA DE " << distancia2 << " METROS.\n";
						cout << "\n\nTE HA SACADO " << distancia2 - distancia1 << " METROS DE DIFERENCIA.\n" << RESET;
					}
					else if (distancia1 == distancia2) {
						cout << BG_GREEN << "\n\n\nHA HABIDO UN EMPATE ENTRE " << lancha2.getName() << " Y " << lancha1.getName() << "CON UNA DISTANCIA DE " << distancia2 << " METROS.\n" << RESET;
					}
				}
			}
		}
		else {
			Lanchas* jugadores = new Lanchas[players];
			jugadores = variosJugadores(players);

			Sleep(500);
			system("CLS");
			for (size_t i = 0; i < 5; i++)
			{

				cout << ORANGE << "RONDA " << i + 1 << RESET << "\n\n\n";
				for (size_t i = 0; i < players; i++)
				{
					cout << "\nTURNO DEL JUGADOR " << jugadores[i].getName() << "\n\n";

					//TIRADA DE DADO DEL JUGADOR 1

					cout << "\nTIRA TU DADO " << jugadores[i].getName() << ": (Pulsa 0)\n\n";
					cin >> tirada;
					jugadores[i].setVelocidad(tirarDado() + jugadores[i].getVelocidad());
					cout << "\nTras la tirada del dado, la lancha de " << jugadores[i].getName() << " tiene una velocidad de " << jugadores[i].getVelocidad() << "km/h\n\n";

					jugadores[i].turnoJugada(jugadores[i], opcion);

					jugadores[i].setDistancia(jugadores[i].getDistancia() + (jugadores[i].getVelocidad() * 100));

					cout << "\nLa distancia recorrida por " << jugadores[i].getName() << " es de " << jugadores[i].getDistancia() << " metros.\n\n";
					Sleep(1250);
					system("CLS");

				}
				if (i != 4)
				{
					cout << RED << "\nRESULTADOS DE LA RONDA " << i + 1 << "\n\n" << RESET;
				}
				else {
					cout << RED << "\nRESULTADOS FINALES\n\n" << RESET;
				}
				int x = 0;
				do {

					cout << "BARCO DE: " << jugadores[x].getName() << ". LLEVA " << jugadores[x].getDistancia() << " METROS.\n";
					cout << "\n";
					for (size_t j = 0; j < jugadores[x].getDistancia() / 100; j++)
					{
						cout << BLUE << "--" << RESET;
						Sleep(25);
					}
					cout << "    /\\" << endl;

					for (size_t j = 0; j < jugadores[x].getDistancia() / 100; j++)
					{
						cout << BLUE << "--" << RESET;
						Sleep(25);
					}
					cout << "___/  \\___" << endl;

					for (size_t j = 0; j < jugadores[x].getDistancia() / 100; j++)
					{
						cout << BLUE << "--" << RESET;
						Sleep(25);
					}
					cout << "\\________/" << endl;
					x++;
					cout << "\n\n";
				} while (x < players);
				if (i != 4)
				{
					cout << "Pulsa 0 para continuar con el juego:\n";
					cin >> tirada;
					system("CLS");
				}




				//Comparar distancias para ver quien es el ganador
				if (i == 4) {


					int bestDistance = 0;
					int winnerNumber = 0;
					bool tie = false;
					for (size_t i = 0; i < players; i++)
					{
						if (jugadores[i].getDistancia() > bestDistance) {
							bestDistance = jugadores[i].getDistancia();
							winnerNumber = i;
							tie = false;
						}
						else if (jugadores[i].getDistancia() == bestDistance) {
							tie = true;
						}
					}

					if (tie) {

						cout << GREEN << "\n\n\nHAY UN EMPATE ENTRE ";
						for (size_t i = 0; i < players; i++) {
							if (jugadores[i].getDistancia() == bestDistance) {
								cout << jugadores[i].getName() << " Y ";
							}
						}
						cout << "CON UNA DISTANCIA DE " << bestDistance << " METROS.\n";
					}
					else {
						cout << GREEN << "\n\n\nEL GANADOR DE LA CARRERA HA SIDO " << jugadores[winnerNumber].getName() << " CON UNA DISTANCIA DE " << bestDistance << " METROS.\n" << RESET;
						
					}
				}
				
			}
		}
		cout <<BLUE<< "\n\nQUIERES JUGAR OTRA VEZ? [0 (SI)/ 1 (NO)]\n\n"<<RESET;
		cin >> jugarMas;
		system("CLS");
	} while (jugarMas == 0);


}
