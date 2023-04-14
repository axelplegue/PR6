#pragma once
#include <iostream>
using namespace std;

class Lanchas {
private:
	int velocidad;
	int distancia;
	int nitro;
	string name;

public:
	//getters:
	int getVelocidad();
	int getDistancia();
	int getNitro();
	string getName();
	

	//setters:
	void setVelocidad(int pVelocidad);
	void setDistancia(int pDistancia);
	void setNitro(bool pNitro);
	void setName(string pName);
	

	//constructores:
	Lanchas(int pVelocidad, int pDistancia, bool pNitro, string pName);
	Lanchas();
	
	//metodos propios:
	void randomNitro();
	void turnoJugada(Lanchas& lancha, int opcion);
	
	


};