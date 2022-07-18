//dos variables de estado: estoy_ubicado y hay_plan
//llamar acciones en el método think

#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <queue>


void ComportamientoJugador::dibujar_mapa4(Sensores sensores){
mapaResultado[fila_nivel4][col_nivel4] = sensores.terreno[0];	//pintar mapa bajo sí
	if (orientacion_nivel4 == 0){	//si apunta al norte
		mapaResultado[fila_nivel4-1][col_nivel4-1] = sensores.terreno[1];
		mapaResultado[fila_nivel4-1][col_nivel4] = sensores.terreno[2];
		mapaResultado[fila_nivel4-1][col_nivel4+1] = sensores.terreno[3];
		mapaResultado[fila_nivel4-2][col_nivel4-2] = sensores.terreno[4];
		mapaResultado[fila_nivel4-2][col_nivel4-1] = sensores.terreno[5];
		mapaResultado[fila_nivel4-2][col_nivel4] = sensores.terreno[6];
		mapaResultado[fila_nivel4-2][col_nivel4+1] = sensores.terreno[7];
		mapaResultado[fila_nivel4-2][col_nivel4+2] = sensores.terreno[8];
		mapaResultado[fila_nivel4-3][col_nivel4-3] = sensores.terreno[9];
		mapaResultado[fila_nivel4-3][col_nivel4-2] = sensores.terreno[10];
		mapaResultado[fila_nivel4-3][col_nivel4-1] = sensores.terreno[11];
		mapaResultado[fila_nivel4-3][col_nivel4] = sensores.terreno[12];
		mapaResultado[fila_nivel4-3][col_nivel4+1] = sensores.terreno[13];
		mapaResultado[fila_nivel4-3][col_nivel4+2] = sensores.terreno[14];
		mapaResultado[fila_nivel4-3][col_nivel4+3] = sensores.terreno[15];
	}else if (orientacion_nivel4 == 1){
		mapaResultado[fila_nivel4][col_nivel4+1] = sensores.terreno[3];
		mapaResultado[fila_nivel4][col_nivel4+2] = sensores.terreno[8];
		mapaResultado[fila_nivel4][col_nivel4+3] = sensores.terreno[15];
		mapaResultado[fila_nivel4-1][col_nivel4] = sensores.terreno[1];
		mapaResultado[fila_nivel4-1][col_nivel4+1] = sensores.terreno[2];
		mapaResultado[fila_nivel4-1][col_nivel4+2] = sensores.terreno[7];
		mapaResultado[fila_nivel4-1][col_nivel4+3] = sensores.terreno[14];
		mapaResultado[fila_nivel4-2][col_nivel4] = sensores.terreno[4];
		mapaResultado[fila_nivel4-2][col_nivel4+1] = sensores.terreno[5];
		mapaResultado[fila_nivel4-2][col_nivel4+2] = sensores.terreno[6];
		mapaResultado[fila_nivel4-2][col_nivel4+3] = sensores.terreno[13];
		mapaResultado[fila_nivel4-3][col_nivel4] = sensores.terreno[9];
		mapaResultado[fila_nivel4-3][col_nivel4+1] = sensores.terreno[10];
		mapaResultado[fila_nivel4-3][col_nivel4+2] = sensores.terreno[11];
		mapaResultado[fila_nivel4-3][col_nivel4+3] = sensores.terreno[12];
	}else if (orientacion_nivel4 == 2){ //si apunta al este
		mapaResultado[fila_nivel4-1][col_nivel4+1] = sensores.terreno[1];
		mapaResultado[fila_nivel4][col_nivel4+1] = sensores.terreno[2];
		mapaResultado[fila_nivel4+1][col_nivel4+1] = sensores.terreno[3];
		mapaResultado[fila_nivel4-2][col_nivel4+2] = sensores.terreno[4];
		mapaResultado[fila_nivel4-1][col_nivel4+2] = sensores.terreno[5];
		mapaResultado[fila_nivel4][col_nivel4+2] = sensores.terreno[6];
		mapaResultado[fila_nivel4+1][col_nivel4+2] = sensores.terreno[7];
		mapaResultado[fila_nivel4+2][col_nivel4+2] = sensores.terreno[8];
		mapaResultado[fila_nivel4-3][col_nivel4+3] = sensores.terreno[9];
		mapaResultado[fila_nivel4-2][col_nivel4+3] = sensores.terreno[10];
		mapaResultado[fila_nivel4-1][col_nivel4+3] = sensores.terreno[11];
		mapaResultado[fila_nivel4][col_nivel4+3] = sensores.terreno[12];
		mapaResultado[fila_nivel4+1][col_nivel4+3] = sensores.terreno[13];
		mapaResultado[fila_nivel4+2][col_nivel4+3] = sensores.terreno[14];
		mapaResultado[fila_nivel4+3][col_nivel4+3] = sensores.terreno[15];
	}else if (orientacion_nivel4 == 3){
		mapaResultado[fila_nivel4][col_nivel4+1] = sensores.terreno[1];
		mapaResultado[fila_nivel4][col_nivel4+2] = sensores.terreno[4];
		mapaResultado[fila_nivel4][col_nivel4+3] = sensores.terreno[9];
		mapaResultado[fila_nivel4+1][col_nivel4] = sensores.terreno[3];
		mapaResultado[fila_nivel4+1][col_nivel4+1] = sensores.terreno[2];
		mapaResultado[fila_nivel4+1][col_nivel4+2] = sensores.terreno[5];
		mapaResultado[fila_nivel4+1][col_nivel4+3] = sensores.terreno[10];
		mapaResultado[fila_nivel4+2][col_nivel4] = sensores.terreno[8];
		mapaResultado[fila_nivel4+2][col_nivel4+1] = sensores.terreno[7];
		mapaResultado[fila_nivel4+2][col_nivel4+2] = sensores.terreno[6];
		mapaResultado[fila_nivel4+2][col_nivel4+3] = sensores.terreno[11];
		mapaResultado[fila_nivel4+3][col_nivel4] = sensores.terreno[15];
		mapaResultado[fila_nivel4+3][col_nivel4+1] = sensores.terreno[14];
		mapaResultado[fila_nivel4+3][col_nivel4+2] = sensores.terreno[13];
		mapaResultado[fila_nivel4+3][col_nivel4+3] = sensores.terreno[12];
	}else if (orientacion_nivel4 == 4){ //si apunta al sur
		mapaResultado[fila_nivel4+1][col_nivel4+1] = sensores.terreno[1];
		mapaResultado[fila_nivel4+1][col_nivel4] = sensores.terreno[2];
		mapaResultado[fila_nivel4+1][col_nivel4-1] = sensores.terreno[3];
		mapaResultado[fila_nivel4+2][col_nivel4+2] = sensores.terreno[4];
		mapaResultado[fila_nivel4+2][col_nivel4+1] = sensores.terreno[5];
		mapaResultado[fila_nivel4+2][col_nivel4] = sensores.terreno[6];
		mapaResultado[fila_nivel4+2][col_nivel4-1] = sensores.terreno[7];
		mapaResultado[fila_nivel4+2][col_nivel4-2] = sensores.terreno[8];
		mapaResultado[fila_nivel4+3][col_nivel4+3] = sensores.terreno[9];
		mapaResultado[fila_nivel4+3][col_nivel4+2] = sensores.terreno[10];
		mapaResultado[fila_nivel4+3][col_nivel4+1] = sensores.terreno[11];
		mapaResultado[fila_nivel4+3][col_nivel4] = sensores.terreno[12];
		mapaResultado[fila_nivel4+3][col_nivel4-1] = sensores.terreno[13];
		mapaResultado[fila_nivel4+3][col_nivel4-2] = sensores.terreno[14];
		mapaResultado[fila_nivel4+3][col_nivel4-3] = sensores.terreno[15];
	}else if (orientacion_nivel4 == 5){
		mapaResultado[fila_nivel4][col_nivel4-1] = sensores.terreno[3];
		mapaResultado[fila_nivel4][col_nivel4-2] = sensores.terreno[8];
		mapaResultado[fila_nivel4][col_nivel4-3] = sensores.terreno[15];
		mapaResultado[fila_nivel4+1][col_nivel4] = sensores.terreno[1];
		mapaResultado[fila_nivel4+1][col_nivel4-1] = sensores.terreno[2];
		mapaResultado[fila_nivel4+1][col_nivel4-2] = sensores.terreno[7];
		mapaResultado[fila_nivel4+1][col_nivel4-3] = sensores.terreno[14];
		mapaResultado[fila_nivel4+2][col_nivel4] = sensores.terreno[4];
		mapaResultado[fila_nivel4+2][col_nivel4-1] = sensores.terreno[5];
		mapaResultado[fila_nivel4+2][col_nivel4-2] = sensores.terreno[6];
		mapaResultado[fila_nivel4+2][col_nivel4-3] = sensores.terreno[13];
		mapaResultado[fila_nivel4+3][col_nivel4] = sensores.terreno[9];
		mapaResultado[fila_nivel4+3][col_nivel4-1] = sensores.terreno[10];
		mapaResultado[fila_nivel4+3][col_nivel4-2] = sensores.terreno[11];
		mapaResultado[fila_nivel4+3][col_nivel4-3] = sensores.terreno[12];
	}else if (orientacion_nivel4 == 6){ //si apunta al oeste
		mapaResultado[fila_nivel4+1][col_nivel4-1] = sensores.terreno[1];
		mapaResultado[fila_nivel4][col_nivel4-1] = sensores.terreno[2];
		mapaResultado[fila_nivel4-1][col_nivel4-1] = sensores.terreno[3];
		mapaResultado[fila_nivel4+2][col_nivel4-2] = sensores.terreno[4];
		mapaResultado[fila_nivel4+1][col_nivel4-2] = sensores.terreno[5];
		mapaResultado[fila_nivel4][col_nivel4-2] = sensores.terreno[6];
		mapaResultado[fila_nivel4-1][col_nivel4-2] = sensores.terreno[7];
		mapaResultado[fila_nivel4-2][col_nivel4-2] = sensores.terreno[8];
		mapaResultado[fila_nivel4+3][col_nivel4-3] = sensores.terreno[9];
		mapaResultado[fila_nivel4+2][col_nivel4-3] = sensores.terreno[10];
		mapaResultado[fila_nivel4+1][col_nivel4-3] = sensores.terreno[11];
		mapaResultado[fila_nivel4][col_nivel4-3] = sensores.terreno[12];
		mapaResultado[fila_nivel4-1][col_nivel4-3] = sensores.terreno[13];
		mapaResultado[fila_nivel4-2][col_nivel4-3] = sensores.terreno[14];
		mapaResultado[fila_nivel4-3][col_nivel4-3] = sensores.terreno[15];
	}else if (orientacion_nivel4 == 7){ 
		mapaResultado[fila_nivel4][col_nivel4-1] = sensores.terreno[1];
		mapaResultado[fila_nivel4][col_nivel4-2] = sensores.terreno[4];
		mapaResultado[fila_nivel4][col_nivel4-3] = sensores.terreno[9];
		mapaResultado[fila_nivel4-1][col_nivel4] = sensores.terreno[3];
		mapaResultado[fila_nivel4-1][col_nivel4-1] = sensores.terreno[2];
		mapaResultado[fila_nivel4-1][col_nivel4-2] = sensores.terreno[5];
		mapaResultado[fila_nivel4-1][col_nivel4-3] = sensores.terreno[10];
		mapaResultado[fila_nivel4-2][col_nivel4] = sensores.terreno[8];
		mapaResultado[fila_nivel4-2][col_nivel4-1] = sensores.terreno[7];
		mapaResultado[fila_nivel4-2][col_nivel4-2] = sensores.terreno[6];
		mapaResultado[fila_nivel4-2][col_nivel4-3] = sensores.terreno[11];
		mapaResultado[fila_nivel4-3][col_nivel4] = sensores.terreno[15];
		mapaResultado[fila_nivel4-3][col_nivel4-1] = sensores.terreno[14];
		mapaResultado[fila_nivel4-3][col_nivel4-2] = sensores.terreno[13];
		mapaResultado[fila_nivel4-3][col_nivel4-3] = sensores.terreno[12];
	}
}


void ComportamientoJugador::dibujar_mapa(Sensores sensores){
	//dibujarMapa
	int fila = sensores.posF;
	int columna = sensores.posC;
mapaResultado[fila][columna] = sensores.terreno[0];	//pintar mapa bajo sí
		if (sensores.sentido == 0){	//si apunta al norte
			mapaResultado[fila-1][columna-1] = sensores.terreno[1];
			mapaResultado[fila-1][columna] = sensores.terreno[2];
			mapaResultado[fila-1][columna+1] = sensores.terreno[3];
			mapaResultado[fila-2][columna-2] = sensores.terreno[4];
			mapaResultado[fila-2][columna-1] = sensores.terreno[5];
			mapaResultado[fila-2][columna] = sensores.terreno[6];
			mapaResultado[fila-2][columna+1] = sensores.terreno[7];
			mapaResultado[fila-2][columna+2] = sensores.terreno[8];
			mapaResultado[fila-3][columna-3] = sensores.terreno[9];
			mapaResultado[fila-3][columna-2] = sensores.terreno[10];
			mapaResultado[fila-3][columna-1] = sensores.terreno[11];
			mapaResultado[fila-3][columna] = sensores.terreno[12];
			mapaResultado[fila-3][columna+1] = sensores.terreno[13];
			mapaResultado[fila-3][columna+2] = sensores.terreno[14];
			mapaResultado[fila-3][columna+3] = sensores.terreno[15];
		}else if (sensores.sentido == 1){
			mapaResultado[fila][columna+1] = sensores.terreno[3];
			mapaResultado[fila][columna+2] = sensores.terreno[8];
			mapaResultado[fila][columna+3] = sensores.terreno[15];
			mapaResultado[fila-1][columna] = sensores.terreno[1];
			mapaResultado[fila-1][columna+1] = sensores.terreno[2];
			mapaResultado[fila-1][columna+2] = sensores.terreno[7];
			mapaResultado[fila-1][columna+3] = sensores.terreno[14];
			mapaResultado[fila-2][columna] = sensores.terreno[4];
			mapaResultado[fila-2][columna+1] = sensores.terreno[5];
			mapaResultado[fila-2][columna+2] = sensores.terreno[6];
			mapaResultado[fila-2][columna+3] = sensores.terreno[13];
			mapaResultado[fila-3][columna] = sensores.terreno[9];
			mapaResultado[fila-3][columna+1] = sensores.terreno[10];
			mapaResultado[fila-3][columna+2] = sensores.terreno[11];
			mapaResultado[fila-3][columna+3] = sensores.terreno[12];
		}else if (sensores.sentido == 2){ //si apunta al este
			mapaResultado[fila-1][columna+1] = sensores.terreno[1];
			mapaResultado[fila][columna+1] = sensores.terreno[2];
			mapaResultado[fila+1][columna+1] = sensores.terreno[3];
			mapaResultado[fila-2][columna+2] = sensores.terreno[4];
			mapaResultado[fila-1][columna+2] = sensores.terreno[5];
			mapaResultado[fila][columna+2] = sensores.terreno[6];
			mapaResultado[fila+1][columna+2] = sensores.terreno[7];
			mapaResultado[fila+2][columna+2] = sensores.terreno[8];
			mapaResultado[fila-3][columna+3] = sensores.terreno[9];
			mapaResultado[fila-2][columna+3] = sensores.terreno[10];
			mapaResultado[fila-1][columna+3] = sensores.terreno[11];
			mapaResultado[fila][columna+3] = sensores.terreno[12];
			mapaResultado[fila+1][columna+3] = sensores.terreno[13];
			mapaResultado[fila+2][columna+3] = sensores.terreno[14];
			mapaResultado[fila+3][columna+3] = sensores.terreno[15];
		}else if (sensores.sentido == 3){
			mapaResultado[fila][columna+1] = sensores.terreno[1];
			mapaResultado[fila][columna+2] = sensores.terreno[4];
			mapaResultado[fila][columna+3] = sensores.terreno[9];
			mapaResultado[fila+1][columna] = sensores.terreno[3];
			mapaResultado[fila+1][columna+1] = sensores.terreno[2];
			mapaResultado[fila+1][columna+2] = sensores.terreno[5];
			mapaResultado[fila+1][columna+3] = sensores.terreno[10];
			mapaResultado[fila+2][columna] = sensores.terreno[8];
			mapaResultado[fila+2][columna+1] = sensores.terreno[7];
			mapaResultado[fila+2][columna+2] = sensores.terreno[6];
			mapaResultado[fila+2][columna+3] = sensores.terreno[11];
			mapaResultado[fila+3][columna] = sensores.terreno[15];
			mapaResultado[fila+3][columna+1] = sensores.terreno[14];
			mapaResultado[fila+3][columna+2] = sensores.terreno[13];
			mapaResultado[fila+3][columna+3] = sensores.terreno[12];
		}else if (sensores.sentido == 4){ //si apunta al sur
			mapaResultado[fila+1][columna+1] = sensores.terreno[1];
			mapaResultado[fila+1][columna] = sensores.terreno[2];
			mapaResultado[fila+1][columna-1] = sensores.terreno[3];
			mapaResultado[fila+2][columna+2] = sensores.terreno[4];
			mapaResultado[fila+2][columna+1] = sensores.terreno[5];
			mapaResultado[fila+2][columna] = sensores.terreno[6];
			mapaResultado[fila+2][columna-1] = sensores.terreno[7];
			mapaResultado[fila+2][columna-2] = sensores.terreno[8];
			mapaResultado[fila+3][columna+3] = sensores.terreno[9];
			mapaResultado[fila+3][columna+2] = sensores.terreno[10];
			mapaResultado[fila+3][columna+1] = sensores.terreno[11];
			mapaResultado[fila+3][columna] = sensores.terreno[12];
			mapaResultado[fila+3][columna-1] = sensores.terreno[13];
			mapaResultado[fila+3][columna-2] = sensores.terreno[14];
			mapaResultado[fila+3][columna-3] = sensores.terreno[15];
		}else if (sensores.sentido == 5){
			mapaResultado[fila][columna-1] = sensores.terreno[3];
			mapaResultado[fila][columna-2] = sensores.terreno[8];
			mapaResultado[fila][columna-3] = sensores.terreno[15];
			mapaResultado[fila+1][columna] = sensores.terreno[1];
			mapaResultado[fila+1][columna-1] = sensores.terreno[2];
			mapaResultado[fila+1][columna-2] = sensores.terreno[7];
			mapaResultado[fila+1][columna-3] = sensores.terreno[14];
			mapaResultado[fila+2][columna] = sensores.terreno[4];
			mapaResultado[fila+2][columna-1] = sensores.terreno[5];
			mapaResultado[fila+2][columna-2] = sensores.terreno[6];
			mapaResultado[fila+2][columna-3] = sensores.terreno[13];
			mapaResultado[fila+3][columna] = sensores.terreno[9];
			mapaResultado[fila+3][columna-1] = sensores.terreno[10];
			mapaResultado[fila+3][columna-2] = sensores.terreno[11];
			mapaResultado[fila+3][columna-3] = sensores.terreno[12];
		}else if (sensores.sentido == 6){ //si apunta al oeste
			mapaResultado[fila+1][columna-1] = sensores.terreno[1];
			mapaResultado[fila][columna-1] = sensores.terreno[2];
			mapaResultado[fila-1][columna-1] = sensores.terreno[3];
			mapaResultado[fila+2][columna-2] = sensores.terreno[4];
			mapaResultado[fila+1][columna-2] = sensores.terreno[5];
			mapaResultado[fila][columna-2] = sensores.terreno[6];
			mapaResultado[fila-1][columna-2] = sensores.terreno[7];
			mapaResultado[fila-2][columna-2] = sensores.terreno[8];
			mapaResultado[fila+3][columna-3] = sensores.terreno[9];
			mapaResultado[fila+2][columna-3] = sensores.terreno[10];
			mapaResultado[fila+1][columna-3] = sensores.terreno[11];
			mapaResultado[fila][columna-3] = sensores.terreno[12];
			mapaResultado[fila-1][columna-3] = sensores.terreno[13];
			mapaResultado[fila-2][columna-3] = sensores.terreno[14];
			mapaResultado[fila-3][columna-3] = sensores.terreno[15];
		}else if (sensores.sentido == 7){ 
			mapaResultado[fila][columna-1] = sensores.terreno[1];
			mapaResultado[fila][columna-2] = sensores.terreno[4];
			mapaResultado[fila][columna-3] = sensores.terreno[9];
			mapaResultado[fila-1][columna] = sensores.terreno[3];
			mapaResultado[fila-1][columna-1] = sensores.terreno[2];
			mapaResultado[fila-1][columna-2] = sensores.terreno[5];
			mapaResultado[fila-1][columna-3] = sensores.terreno[10];
			mapaResultado[fila-2][columna] = sensores.terreno[8];
			mapaResultado[fila-2][columna-1] = sensores.terreno[7];
			mapaResultado[fila-2][columna-2] = sensores.terreno[6];
			mapaResultado[fila-2][columna-3] = sensores.terreno[11];
			mapaResultado[fila-3][columna] = sensores.terreno[15];
			mapaResultado[fila-3][columna-1] = sensores.terreno[14];
			mapaResultado[fila-3][columna-2] = sensores.terreno[13];
			mapaResultado[fila-3][columna-3] = sensores.terreno[12];
		}

		for (int i = 0; i< mapaResultado.size(); i++){
			for (int j = 0; j< 3; j++){
				mapaResultado[i][j] = 'P';
			}
		}

		for (int i = 0; i< 3; i++){
			for (int j = 0; j< mapaResultado[0].size(); j++){
				mapaResultado[i][j] = 'P';
			}
		}

		for (int i = 0; i < mapaResultado[0].size(); i++){
			mapaResultado[mapaResultado.size()-1][i] = 'P';
			mapaResultado[mapaResultado.size()-2][i] = 'P';
			mapaResultado[mapaResultado.size()-3][i] = 'P';
		}

		for (int i = 0; i < mapaResultado.size(); i++){
			mapaResultado[i][mapaResultado[0].size()-1] = 'P';
			mapaResultado[i][mapaResultado[0].size()-2] = 'P';
			mapaResultado[i][mapaResultado[0].size()-3] = 'P';
		}	
}


// Este es el método principal que se piden en la practica.
// Tiene como entrada la información de los sensores y devuelve la acción a realizar.
// Para ver los distintos sensores mirar fichero "comportamiento.hpp"
Action ComportamientoJugador::think(Sensores sensores)
{

	if (sensores.nivel < 3){
		//Actualizo la variable actual
		actual.fila = sensores.posF;
		actual.columna = sensores.posC;
		actual.orientacion = sensores.sentido;

		cout << "Fila: " << actual.fila << endl;
		cout << "Col : " << actual.columna << endl;
		cout << "Ori : " << actual.orientacion << endl;

		// Capturo los destinos
		cout << "sensores.num_destinos : " << sensores.num_destinos << endl;
		objetivos.clear();
		for (int i = 0; i < sensores.num_destinos; i++)
		{
			estado aux;
			aux.fila = sensores.destino[2 * i];
			aux.columna = sensores.destino[2 * i + 1];
			objetivos.push_back(aux);
		}

		//Si no hay plan, construyo uno
		if (!hay_plan){
			hay_plan = pathFinding(sensores.nivel, actual, objetivos, plan, sensores);
		}

		Action sig_action;
		if (hay_plan and plan.size()>0){ //hay plan no vacío
			sig_action = plan.front();     //tomo la siguiente accion del plan
			plan.erase(plan.begin());	     //elminamos la accion del plan
		}
			
		return sig_action;
	}else if (sensores.nivel == 3){
		//Actualizo la variable actual
		actual.fila = sensores.posF;
		actual.columna = sensores.posC;
		actual.orientacion = sensores.sentido;
		actual.bikini = anterior.bikini;
		actual.zapatilla = anterior.zapatilla;

		if (sensores.terreno[0] == 'K'){
			actual.bikini = true;
			actual.zapatilla = false;
		}else if (sensores.terreno[0] == 'D'){
			actual.zapatilla = true;
			actual.bikini = false;
		}

		
		cout << "Fila: " << actual.fila << endl;
		cout << "Col : " << actual.columna << endl;
		cout << "Ori : " << actual.orientacion << endl;

		dibujar_mapa(sensores);
		
		//Si no hay plan o si hemos visto el objetivo de nuestro plan, trazamos uno nuevo
		if (!hay_plan || mapaResultado[fila_nivel3][col_nivel3] != '?'){
			pathFinding(sensores.nivel, actual, objetivos, plan, sensores);
			hay_plan = true;
		}

		Action sig_action;
		if (hay_plan and plan.size()>0){ //hay plan no vacío
			if (plan.front() == actFORWARD){
				if (sensores.terreno[2] == 'M' || sensores.terreno[2] == 'P'){
					pathFinding(sensores.nivel, actual, objetivos, plan, sensores);
				}else if ( sensores.terreno[2] == 'A' && actual.bikini == false){
					pathFinding(sensores.nivel, actual, objetivos, plan, sensores);
				}else if (sensores.terreno[2] == 'B' && actual.zapatilla == false){
					pathFinding(sensores.nivel, actual, objetivos, plan, sensores);
				}
			}
				sig_action = plan.front();     //tomo la siguiente accion del plan
				plan.erase(plan.begin());	     //elminamos la accion del plan
		}
		
		anterior.bikini = actual.bikini;
		anterior.zapatilla = actual.zapatilla;
		return sig_action;

	}else if (sensores.nivel == 4){
		Action sig_action;
		actual.bikini = anterior.bikini;
		actual.zapatilla = anterior.zapatilla;

		if (sensores.terreno[0] == 'K'){
				actual.bikini = true;
				actual.zapatilla = false;
			}else if (sensores.terreno[0] == 'D'){
				actual.zapatilla = true;
				actual.bikini = false;
			}

		if (ultima_action == actWHEREIS){
			fila_nivel4 = sensores.posF;
			col_nivel4  = sensores.posC;
			orientacion_nivel4 = sensores.sentido;
			ubicado = true;
		}

		if (sensores.colision){
			ubicado = false;
		}

		if (ultima_action == actTURN_R){
			orientacion_nivel4 = (orientacion_nivel4 + 2 ) % 8;
		}else if (ultima_action == actSEMITURN_R){
			orientacion_nivel4 = (orientacion_nivel4 + 1 ) % 8;
		}else if (ultima_action == actTURN_L){
			orientacion_nivel4 = (orientacion_nivel4 + 6 ) % 8;
		}else if (ultima_action == actSEMITURN_L){
			orientacion_nivel4 = (orientacion_nivel4 + 7 ) % 8;
		}else if (ultima_action == actFORWARD){																			//cuadrar la orientacion
			if (orientacion_nivel4 == 0){
					fila_nivel4--;
			}else if (orientacion_nivel4 == 1){
					fila_nivel4--;
					col_nivel4++;
			}else if (orientacion_nivel4 == 2){
					col_nivel4++;
			}else if (orientacion_nivel4 == 3){
					col_nivel4++;
					fila_nivel4++;
			}else if (orientacion_nivel4 == 4){
				fila_nivel4++;
			}else if (orientacion_nivel4 == 5){
				col_nivel4--;
				fila_nivel4++;
			}else if (orientacion_nivel4 == 6){
				col_nivel4--;
			}else if (orientacion_nivel4 == 7){
				col_nivel4--;
				fila_nivel4--;
			}
		}

		if (!ubicado){
			sig_action = actWHEREIS;
		}else{
			dibujar_mapa4(sensores);


			actual.fila = fila_nivel4;
			actual.columna = col_nivel4;
			actual.orientacion = orientacion_nivel4;

				// Capturo los destinos
			cout << "sensores.num_destinos : " << sensores.num_destinos << endl;
			objetivos.clear();
			for (int i = 0; i < sensores.num_destinos; i++)		//capturar los objetivos
			{
				estado aux;
				aux.fila = sensores.destino[2 * i];
				aux.columna = sensores.destino[2 * i + 1];
				objetivos.push_back(aux);
			}

			for (int i = 0; i < sensores.num_destinos; i++)		//comprobar que si ha llegado al objetivo
			{
				if (fila_nivel4 == sensores.destino[2 * i] && col_nivel4 == sensores.destino[2 * i + 1]){
					llegadas[i] = true;
				}
			}
			
			if (llegadas[0] == true && llegadas[1] == true && llegadas[2] == true){
				llegadas[0] = false;
				llegadas[1] = false;
				llegadas[2] = false;
			}
			
			if (EMERGENCIA_LOBO == false){

			
				if(sensores.terreno[0] == 'X' && sensores.bateria < 2989){
					sig_action = actIDLE;
				}else if (sensores.superficie[2] == '_'){
					//Si no hay plan, construyo uno
					if (!hay_plan || plan.size() == 0){
						pathFinding(sensores.nivel, actual, objetivos, plan, sensores);
						hay_plan = true;
					}

					if (hay_plan and plan.size()>0){ //hay plan no vacío
						if (plan.front() == actFORWARD){
							if (sensores.terreno[2] == 'M' || sensores.terreno[2] == 'P'){
								pathFinding(sensores.nivel, actual, objetivos, plan, sensores);
							}else if ( sensores.terreno[2] == 'A' && actual.bikini == false){
								pathFinding(sensores.nivel, actual, objetivos, plan, sensores);
							}else if (sensores.terreno[2] == 'B' && actual.zapatilla == false){
								pathFinding(sensores.nivel, actual, objetivos, plan, sensores);
							}
						}
						sig_action = plan.front();     //tomo la siguiente accion del plan
						plan.erase(plan.begin());	     //elminamos la accion del plan
					}
				}else{
					if (sensores.colision){
						sig_action = actWHEREIS;
					}else{
						if (sensores.superficie[2] != 'l'){
							sig_action = actIDLE;
						}else{
							if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.superficie[1] == '_'){
								sig_action = actSEMITURN_L;
								EMERGENCIA_LOBO = true;
							}else if(sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.superficie[3] == '_'){
								sig_action = actSEMITURN_R;
								EMERGENCIA_LOBO = true;
							}
						}
					}
				}
			}else{
				if (sensores.terreno[2] != 'M' || sensores.terreno[2] != 'P'){
					sig_action = actFORWARD;
					EMERGENCIA_LOBO = false;
				}else{
					sig_action = actSEMITURN_L;
				}
			}
		}

		anterior.bikini = actual.bikini;
		anterior.zapatilla = actual.zapatilla;
		ultima_action = sig_action;

		return sig_action;

	}
	
}

// Llama al algoritmo de busqueda que se usara en cada comportamiento del agente
// Level representa el comportamiento en el que fue iniciado el agente.
bool ComportamientoJugador::pathFinding(int level, const estado &origen, const list<estado> &destino, list<Action> &plan, Sensores sensores)
{
	switch (level)
	{
	case 0:
		cout << "Demo\n";
		estado un_objetivo;
		un_objetivo = objetivos.front();
		cout << "fila: " << un_objetivo.fila << " col:" << un_objetivo.columna << endl;
		return pathFinding_Profundidad(origen, un_objetivo, plan);
		break;

	case 1:
		cout << "Optimo numero de acciones\n";
		// Incluir aqui la llamada al busqueda en anchura
		estado un_objetivo1;
		un_objetivo1 = objetivos.front();
		cout << "fila: " << un_objetivo1.fila << " col:" << un_objetivo1.columna << endl;
		return pathFinding_Anchura(origen, un_objetivo1, plan);
		break;
	case 2:
		cout << "Optimo en coste\n";
		// Incluir aqui la llamada al busqueda de costo uniforme/A*
		estado un_objetivo2;
		un_objetivo2 = objetivos.front();
		cout << "fila: " << un_objetivo2.fila << " col:" << un_objetivo2.columna << endl;
		return pathFinding_Coste(origen, un_objetivo2, plan, sensores);
		break;
	case 3:
		cout << "Reto 1: Descubrir el mapa\n";
		// Incluir aqui la llamada al algoritmo de busqueda para el Reto 1
		return pathFinding_Reto1(origen,plan,sensores);
		break;
	case 4:
		cout << "Reto 2: Maximizar objetivos\n";
		// Incluir aqui la llamada al algoritmo de busqueda para el Reto 2
		return pathFinding_Reto2(origen, objetivos, plan,  sensores);
		break;
	}
	return false;
}

//---------------------- Implementación de la busqueda en profundidad ---------------------------

// Dado el codigo en caracter de una casilla del mapa dice si se puede
// pasar por ella sin riegos de morir o chocar.
bool EsObstaculo(unsigned char casilla)
{
	if (casilla == 'P' or casilla == 'M')
		return true;
	else
		return false;
}

// Comprueba si la casilla que hay delante es un obstaculo. Si es un
// obstaculo devuelve true. Si no es un obstaculo, devuelve false y
// modifica st con la posición de la casilla del avance.
bool ComportamientoJugador::HayObstaculoDelante(estado &st)
{
	int fil = st.fila, col = st.columna;

	// calculo cual es la casilla de delante del agente
	switch (st.orientacion)
	{
	case 0:
		fil--;
		break;
	case 1:
		fil--;
		col++;
		break;
	case 2:
		col++;
		break;
	case 3:
		fil++;
		col++;
		break;
	case 4:
		fil++;
		break;
	case 5:
		fil++;
		col--;
		break;
	case 6:
		col--;
		break;
	case 7:
		fil--;
		col--;
		break;
	}

	// Compruebo que no me salgo fuera del rango del mapa
	if (fil < 0 or fil >= mapaResultado.size())
		return true;
	if (col < 0 or col >= mapaResultado[0].size())
		return true;

	// Miro si en esa casilla hay un obstaculo infranqueable
	if (!EsObstaculo(mapaResultado[fil][col]))
	{
		// No hay obstaculo, actualizo el parametro st poniendo la casilla de delante.
		st.fila = fil;
		st.columna = col;
		return false;
	}
	else
	{
		return true;
	}
}

struct ComparaEstados{    
    bool operator()(const estado &a, const estado &n) const{
			if ((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
				(a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion) or 
				(a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini > n.bikini) or
				(a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.zapatilla > n.zapatilla))
				return true;
			else
				return false;
    }
};

struct nodo
{
	estado st;
	list<Action> secuencia;
	int coste = 0;
};

// Implementación de la busqueda en profundidad.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan)
{
	// Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado, ComparaEstados> Cerrados; // Lista de Cerrados
	stack<nodo> Abiertos;				  // Lista de Abiertos

	nodo current;
	current.st = origen;
	current.secuencia.empty();

	Abiertos.push(current);

	while (!Abiertos.empty() and (current.st.fila != destino.fila or current.st.columna != destino.columna))
	{

		Abiertos.pop();
		Cerrados.insert(current.st);

		// Generar descendiente de girar a la derecha 90 grados
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion + 2) % 8;
		if (Cerrados.find(hijoTurnR.st) == Cerrados.end())
		{
			hijoTurnR.secuencia.push_back(actTURN_R);
			Abiertos.push(hijoTurnR);
		}

		// Generar descendiente de girar a la derecha 45 grados
		nodo hijoSEMITurnR = current;
		hijoSEMITurnR.st.orientacion = (hijoSEMITurnR.st.orientacion + 1) % 8;
		if (Cerrados.find(hijoSEMITurnR.st) == Cerrados.end())
		{
			hijoSEMITurnR.secuencia.push_back(actSEMITURN_R);
			Abiertos.push(hijoSEMITurnR);
		}

		// Generar descendiente de girar a la izquierda 90 grados
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion + 6) % 8;
		if (Cerrados.find(hijoTurnL.st) == Cerrados.end())
		{
			hijoTurnL.secuencia.push_back(actTURN_L);
			Abiertos.push(hijoTurnL);
		}

		// Generar descendiente de girar a la izquierda 45 grados
		nodo hijoSEMITurnL = current;
		hijoSEMITurnL.st.orientacion = (hijoSEMITurnL.st.orientacion + 7) % 8;
		if (Cerrados.find(hijoSEMITurnL.st) == Cerrados.end())
		{
			hijoSEMITurnL.secuencia.push_back(actSEMITURN_L);
			Abiertos.push(hijoSEMITurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st))
		{
			if (Cerrados.find(hijoForward.st) == Cerrados.end())
			{
				hijoForward.secuencia.push_back(actFORWARD);
				Abiertos.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty())
		{
			current = Abiertos.top();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna)
	{
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else
	{
		cout << "No encontrado plan\n";
	}

	return false;
}

// Implementación de la busqueda en anchura.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan)
{
	// Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado, ComparaEstados> Cerrados; // Lista de Cerrados
	queue<nodo> Abiertos;				  // Lista de Abiertos

	nodo current;
	current.st = origen;
	current.secuencia.empty();

	Abiertos.push(current);

	while (!Abiertos.empty() and (current.st.fila != destino.fila or current.st.columna != destino.columna))
	{

		Abiertos.pop();
		Cerrados.insert(current.st);

		// Generar descendiente de girar a la derecha 90 grados
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion + 2) % 8;
		if (Cerrados.find(hijoTurnR.st) == Cerrados.end())
		{
			hijoTurnR.secuencia.push_back(actTURN_R);
			Abiertos.push(hijoTurnR);
		}

		// Generar descendiente de girar a la derecha 45 grados
		nodo hijoSEMITurnR = current;
		hijoSEMITurnR.st.orientacion = (hijoSEMITurnR.st.orientacion + 1) % 8;
		if (Cerrados.find(hijoSEMITurnR.st) == Cerrados.end())
		{
			hijoSEMITurnR.secuencia.push_back(actSEMITURN_R);
			Abiertos.push(hijoSEMITurnR);
		}

		// Generar descendiente de girar a la izquierda 90 grados
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion + 6) % 8;
		if (Cerrados.find(hijoTurnL.st) == Cerrados.end())
		{
			hijoTurnL.secuencia.push_back(actTURN_L);
			Abiertos.push(hijoTurnL);
		}

		// Generar descendiente de girar a la izquierda 45 grados
		nodo hijoSEMITurnL = current;
		hijoSEMITurnL.st.orientacion = (hijoSEMITurnL.st.orientacion + 7) % 8;
		if (Cerrados.find(hijoSEMITurnL.st) == Cerrados.end())
		{
			hijoSEMITurnL.secuencia.push_back(actSEMITURN_L);
			Abiertos.push(hijoSEMITurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st))
		{
			if (Cerrados.find(hijoForward.st) == Cerrados.end())
			{
				hijoForward.secuencia.push_back(actFORWARD);
				Abiertos.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty())
		{
			current = Abiertos.front();
		}
		while(Cerrados.find(current.st)!=Cerrados.end() && !Abiertos.empty()){ //Sirve para optimizar mucho el tiempo
			Abiertos.pop();
			current=Abiertos.front();
    }
	}

	cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna)
	{
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else
	{
		cout << "No encontrado plan\n";
	}

	return false;
}

//---------------------- Implementación de la busqueda por coste uniforme ---------------------------

int ComportamientoJugador::coste_Bateria(unsigned char terreno, Action accion,estado st){
    int coste = 0;
    if(accion == actFORWARD){
			switch (terreno){
				case 'A':
					if (st.bikini){
						coste = 10;
					}else{
						coste = 200;
					}
				break;
				case 'B':
					if (st.zapatilla){
						coste = 15;
					}else{
						coste = 100;
					}
				break;
				case 'T':
					coste = 2;
				break;
				default :
					coste = 1;
				break;
			}
    }else if(accion == actTURN_L or accion == actTURN_R){
			switch (terreno){
				case 'A':
					if (st.bikini){
						coste = 5;
					}else{
						coste = 500;
					}
				break;
				case 'B':
					if (st.zapatilla){
						coste = 1;
					}else{
						coste = 3;
					}
				break;
				case 'T':
					coste = 2;
				break;
				default :
					coste = 1;
				break;
			}
    }
		else if(accion == actSEMITURN_L or accion == actSEMITURN_R){
			switch (terreno){
				case 'A':
					if (st.bikini){
						coste = 2;
					}else{
						coste = 300;
					}
				break;
				case 'B':
					if (st.zapatilla){
						coste = 1;
					}else{
						coste = 2;
					}
				break;
				case 'T':
					coste = 1;
				break;
				default :
					coste = 1;
				break;
			}
    }else if (accion == actWHEREIS){
			coste = 200;
		}
    return coste;
}


struct comparaCosteNodos{
	bool operator()(const nodo &n1, const nodo &n2) const{
		return ((n1.coste > n2.coste) or (n1.coste == n2.coste and n1.secuencia.size() > n2.secuencia.size()));
	}
};

bool ComportamientoJugador::pathFinding_Coste(const estado &origen, const estado &destino, list<Action> &plan,Sensores sensores){
    //Borro la lista
    cout << "Calculando plan\n";
    plan.clear();
    set<estado,ComparaEstados> Cerrados; // Lista de Cerrados
    priority_queue<nodo,vector<nodo>,comparaCosteNodos> prioridadA; // Cola de prioridad Abiertos

    nodo current;
		current.st.bikini=false;
    current.st.zapatilla=false;
    current.st = origen;
    current.secuencia.clear();
    current.coste=0;
    prioridadA.push(current);

    while (!prioridadA.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){
        unsigned char casilla = mapaResultado[current.st.fila][current.st.columna];
        prioridadA.pop();
        Cerrados.insert(current.st);

        if(casilla == 'K'){
					current.st.bikini = true;
					current.st.zapatilla = false;
					zapatilla_3 = false;
					bikini_3 = true;
        }else if(casilla == 'D'){
					current.st.bikini = false;
					current.st.zapatilla = true;
					zapatilla_3 = true;
					bikini_3 = false;
        }

        nodo hijoIdle = current;
        if (Cerrados.find(hijoIdle.st) == Cerrados.end()){
            hijoIdle.secuencia.push_back(actIDLE);
            hijoIdle.coste += coste_Bateria(casilla,actIDLE,hijoIdle.st);
            prioridadA.push(hijoIdle);
        }

        // Generar descendiente de girar a la derecha 90 grados
        nodo hijoTurnR = current;
        hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+2)%8;
        if (Cerrados.find(hijoTurnR.st) == Cerrados.end()){
            hijoTurnR.secuencia.push_back(actTURN_R);
            hijoTurnR.coste += coste_Bateria(casilla,actTURN_R,hijoTurnR.st);
            prioridadA.push(hijoTurnR);
        }

				// Generar descendiente de girar a la derecha 45 grados
        nodo hijoSEMITurnR = current;
        hijoSEMITurnR.st.orientacion = (hijoSEMITurnR.st.orientacion+1)%8;
        if (Cerrados.find(hijoSEMITurnR.st) == Cerrados.end()){
            hijoSEMITurnR.secuencia.push_back(actSEMITURN_R);
            hijoSEMITurnR.coste += coste_Bateria(casilla,actSEMITURN_R,hijoSEMITurnR.st);
            prioridadA.push(hijoSEMITurnR);
        }

        // Generar descendiente de girar a la izquierda 90 grados
        nodo hijoTurnL = current;
        hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+6)%8;
        if (Cerrados.find(hijoTurnL.st) == Cerrados.end()){
            hijoTurnL.secuencia.push_back(actTURN_L);
            hijoTurnL.coste += coste_Bateria(casilla,actTURN_L,hijoTurnL.st);
            prioridadA.push(hijoTurnL);
        }

				// Generar descendiente de girar a la izquierda 45 grados
        nodo hijoSEMITurnL = current;
        hijoSEMITurnL.st.orientacion = (hijoSEMITurnL.st.orientacion+7)%8;
        if (Cerrados.find(hijoSEMITurnR.st) == Cerrados.end()){
            hijoSEMITurnL.secuencia.push_back(actSEMITURN_L);
            hijoSEMITurnL.coste += coste_Bateria(casilla,actSEMITURN_L,hijoSEMITurnL.st);
            prioridadA.push(hijoSEMITurnL);
        }

        // Generar descendiente de avanzar
        nodo hijoForward = current;
        hijoForward.coste += coste_Bateria(casilla,actFORWARD,hijoForward.st);
        if (!HayObstaculoDelante(hijoForward.st)){
            if (Cerrados.find(hijoForward.st) == Cerrados.end()){
                hijoForward.secuencia.push_back(actFORWARD);
                prioridadA.push(hijoForward);
            }
        }

        // Tomo el siguiente valor de la pila
        if (!prioridadA.empty()){
            current = prioridadA.top();
        }
        while(Cerrados.find(current.st)!=Cerrados.end() && !prioridadA.empty()){ //Sirve para optimizar mucho el tiempo
            prioridadA.pop();
            current=prioridadA.top();
        }
				
    }

    cout << "Terminada la busqueda\n";

    if (current.st.fila == destino.fila and current.st.columna == destino.columna){
        cout << "Cargando el plan\n";
        plan = current.secuencia;
        cout << "Longitud del plan: " << plan.size() << endl;
        PintaPlan(plan);
        // ver el plan en el mapa
        VisualizaPlan(origen, plan);
        return true;
    }
    else{
        cout << "No encontrado plan\n";
    }

    return false;
}

//---------------------- Implementación del primer reto ---------------------------

bool ComportamientoJugador::pathFinding_Reto1(const estado &origen, list<Action> &plan,Sensores sensores){		
	
	for (int i = 3; i < mapaResultado.size()-3; i++){
		for (int j = 3; j<mapaResultado.size()-3; j++){
			if (mapaResultado[i][j] == '?'){
				fila_nivel3 = i;
				col_nivel3 = j;
				goto salir;
			}
		}
	}
	

		salir:
			estado destino;
			destino.fila = fila_nivel3;
			destino.columna = col_nivel3;
			pathFinding_Coste(origen, destino, plan, sensores);

	
	

}

//---------------------- Implementación del segundo reto ---------------------------

void ComportamientoJugador::pinta_barranco_4(){
	for (int i = 0; i< mapaResultado.size(); i++){
		for (int j = 0; j< 3; j++){
			mapaResultado[i][j] = 'P';
		}
	}

	for (int i = 0; i< 3; i++){
		for (int j = 0; j< mapaResultado[0].size(); j++){
			mapaResultado[i][j] = 'P';
		}
	}

	for (int i = 0; i < mapaResultado[0].size(); i++){
		mapaResultado[mapaResultado.size()-1][i] = 'P';
		mapaResultado[mapaResultado.size()-2][i] = 'P';
		mapaResultado[mapaResultado.size()-3][i] = 'P';
	}

	for (int i = 0; i < mapaResultado.size(); i++){
		mapaResultado[i][mapaResultado[0].size()-1] = 'P';
		mapaResultado[i][mapaResultado[0].size()-2] = 'P';
		mapaResultado[i][mapaResultado[0].size()-3] = 'P';
	}
}
	

bool ComportamientoJugador::pathFinding_Reto2(const estado &origen, const list<estado> &destino, list<Action> &plan, Sensores sensores){
	pinta_barranco_4();

	for (int i = 3; i < mapaResultado.size()-3; i++){
		for (int j = 3; j<mapaResultado.size()-3; j++){
			if (mapaResultado[i][j] == 'X'){
				fila_bateria = i;
				col_bateria = j;
				goto salir;
			}
		}
	}

	salir:
		estado destino_bateria;
		destino_bateria.fila = fila_bateria;
		destino_bateria.columna = col_bateria;

	if (sensores.bateria > 1000 || fila_bateria == 0){
		list<estado> aux = destino;
		destino1 = aux.front();
		aux.pop_front();
		destino2 = aux.front();
		aux.pop_front();
		destino3 = aux.front();

		if (!llegadas[0]){
			pathFinding_Coste(origen, destino1, plan, sensores);
		}else if(!llegadas[1]){
			pathFinding_Coste(origen, destino2, plan, sensores);
		}else if(!llegadas[2]){
			pathFinding_Coste(origen, destino3, plan, sensores);
		}
	}else{
		pathFinding_Coste(origen, destino_bateria, plan, sensores);
	}
		
}


// Sacar por la consola la secuencia del plan obtenido
void ComportamientoJugador::PintaPlan(list<Action> plan)
{
	auto it = plan.begin();
	while (it != plan.end())
	{
		if (*it == actFORWARD)
		{
			cout << "A ";
		}
		else if (*it == actTURN_R)
		{
			cout << "D ";
		}
		else if (*it == actSEMITURN_R)
		{
			cout << "d ";
		}
		else if (*it == actTURN_L)
		{
			cout << "I ";
		}
		else if (*it == actSEMITURN_L)
		{
			cout << "I ";
		}
		else
		{
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}

// Funcion auxiliar para poner a 0 todas las casillas de una matriz
void AnularMatriz(vector<vector<unsigned char>> &m)
{
	for (int i = 0; i < m[0].size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			m[i][j] = 0;
		}
	}
}

// Pinta sobre el mapa del juego el plan obtenido
void ComportamientoJugador::VisualizaPlan(const estado &st, const list<Action> &plan)
{
	AnularMatriz(mapaConPlan);
	estado cst = st;

	auto it = plan.begin();
	while (it != plan.end())
	{
		if (*it == actFORWARD)
		{
			switch (cst.orientacion)
			{
			case 0:
				cst.fila--;
				break;
			case 1:
				cst.fila--;
				cst.columna++;
				break;
			case 2:
				cst.columna++;
				break;
			case 3:
				cst.fila++;
				cst.columna++;
				break;
			case 4:
				cst.fila++;
				break;
			case 5:
				cst.fila++;
				cst.columna--;
				break;
			case 6:
				cst.columna--;
				break;
			case 7:
				cst.fila--;
				cst.columna--;
				break;
			}
			mapaConPlan[cst.fila][cst.columna] = 1;
		}
		else if (*it == actTURN_R)
		{
			cst.orientacion = (cst.orientacion + 2) % 8;
		}
		else if (*it == actSEMITURN_R)
		{
			cst.orientacion = (cst.orientacion + 1) % 8;
		}
		else if (*it == actTURN_L)
		{
			cst.orientacion = (cst.orientacion + 6) % 8;
		}
		else if (*it == actSEMITURN_L)
		{
			cst.orientacion = (cst.orientacion + 7) % 8;
		}
		it++;
	}
}

int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}
