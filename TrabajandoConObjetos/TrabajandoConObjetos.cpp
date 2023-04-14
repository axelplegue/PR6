#include <iostream>
#include <Windows.h>
#include "L0nchas.h"
#include "colors.h"
using namespace std;

//getters:
int Lanchas::getVelocidad()
{
	return velocidad;
}
int Lanchas::getDistancia()
{
	return distancia;
}
int Lanchas::getNitro()
{
	return nitro;
}
string Lanchas::getName()
{
	return name;
}

//setters:
Lanchas::Lanchas(int pVelocidad, int pDistancia, bool pNitro, string pName) {
	velocidad = pVelocidad;
	distancia = pDistancia;
	nitro = pNitro;
	name = pName;
}
void Lanchas::setVelocidad(int pVelocidad)
{
	velocidad = pVelocidad;
}
void Lanchas::setDistancia(int pDistancia)
{
	distancia = pDistancia;
}
void Lanchas::setNitro(bool pNitro)
{
	nitro = pNitro;
}
void Lanchas::setName(string pName)
{
	name = pName;
}


Lanchas::Lanchas() {
	velocidad = 0;
	distancia = 0;
	nitro = 0;
	name = "";
}
//metodo propio:
void Lanchas::randomNitro()
{
	int random = rand() % 2;
	if (random == 0) {
		cout << RED << "\nNo te ha tocado el nitro :(\n";
		cout << RED << "\nHas tenido mala suerte y tu velocidad se vera reducida a la mitad.\n";
		cout << RED << "\nTu velocidad anterior era " << getVelocidad() << " y ahora sera ";
		 velocidad = getVelocidad() / 2;
		cout << velocidad << RESET<<".\n";
		Sleep(1000);
	}
	else if (random == 1){
		cout << GREEN << "\nHas tenido la suerte de tu vida, te ha tocado el nitro y tu velocidad se vera multiplicada por 2.\n";
		cout << GREEN << "\nTu velocidad anterior era " << getVelocidad() << " y ahora sera ";
		velocidad = getVelocidad() * 2;
		cout << velocidad<<RESET << ".\n";
		Sleep(1000);
	}
}



void Lanchas::turnoJugada(Lanchas& lancha, int opcion) {
	if (nitro== true)
	{
		
		do {
			cout << "\nPuedes utilizar el nitro, quieres hacerlo?\n";
			cout << "\n0. Si (50% DE QUE FUNCIONE)" << endl;
			cout << "1. No" << endl;
			cin >> opcion;
		if (opcion == 0)
		{

			lancha.randomNitro();
			nitro = false;
			Sleep(2000);

		}
		else if (opcion == 1) {
			cout << "\nNo quieres usar el nitro, pasemos al siguiente turno.\n";
			Sleep(2000);
		}
		else {
			cout << "\nNo has pulsado ni 0 ni 1, vuelve a intentarlo\n\n";
		}
		} while (opcion != 0 && opcion != 1);
		
	}
	else if (nitro==false) {
		cout << "\nNo puedes usar mas veces el nitro :(\n";
		Sleep(2000);
	}
}
