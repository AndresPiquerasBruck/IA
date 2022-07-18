#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//vector <vector <long int>> mymapaTiempo

//vector <long int> auxP(200, 0);
//for (unisgned int i=0; i<200; i++){
//mymapaTiempo.push_back(auxP);

void ComportamientoJugador::pintar_mapa(Sensores sensores){	//pinta el mapa conforme lo ve
		//Pintar el mapa
	fil = sensores.posF;
	col = sensores.posC;

	mymapatiempo[fil][col] = contador_tiempo;
	contador_tiempo++;

	mapaResultado[fil][col] = sensores.terreno[0];	//pintar mapa bajo sí
	if (sensores.sentido == 0){	//si apunta al norte
		mapaResultado[fil-1][col-1] = sensores.terreno[1];
		mapaResultado[fil-1][col] = sensores.terreno[2];
		mapaResultado[fil-1][col+1] = sensores.terreno[3];
		mapaResultado[fil-2][col-2] = sensores.terreno[4];
		mapaResultado[fil-2][col-1] = sensores.terreno[5];
		mapaResultado[fil-2][col] = sensores.terreno[6];
		mapaResultado[fil-2][col+1] = sensores.terreno[7];
		mapaResultado[fil-2][col+2] = sensores.terreno[8];
		mapaResultado[fil-3][col-3] = sensores.terreno[9];
		mapaResultado[fil-3][col-2] = sensores.terreno[10];
		mapaResultado[fil-3][col-1] = sensores.terreno[11];
		mapaResultado[fil-3][col] = sensores.terreno[12];
		mapaResultado[fil-3][col+1] = sensores.terreno[13];
		mapaResultado[fil-3][col+2] = sensores.terreno[14];
		mapaResultado[fil-3][col+3] = sensores.terreno[15];
	}else if (sensores.sentido == 1){ //si apunta al este
		mapaResultado[fil-1][col+1] = sensores.terreno[1];
		mapaResultado[fil][col+1] = sensores.terreno[2];
		mapaResultado[fil+1][col+1] = sensores.terreno[3];
		mapaResultado[fil-2][col+2] = sensores.terreno[4];
		mapaResultado[fil-1][col+2] = sensores.terreno[5];
		mapaResultado[fil][col+2] = sensores.terreno[6];
		mapaResultado[fil+1][col+2] = sensores.terreno[7];
		mapaResultado[fil+2][col+2] = sensores.terreno[8];
		mapaResultado[fil-3][col+3] = sensores.terreno[9];
		mapaResultado[fil-2][col+3] = sensores.terreno[10];
		mapaResultado[fil-1][col+3] = sensores.terreno[11];
		mapaResultado[fil][col+3] = sensores.terreno[12];
		mapaResultado[fil+1][col+3] = sensores.terreno[13];
		mapaResultado[fil+2][col+3] = sensores.terreno[14];
		mapaResultado[fil+3][col+3] = sensores.terreno[15];
	}else if (sensores.sentido == 2){ //si apunta al sur
		mapaResultado[fil+1][col+1] = sensores.terreno[1];
		mapaResultado[fil+1][col] = sensores.terreno[2];
		mapaResultado[fil+1][col-1] = sensores.terreno[3];
		mapaResultado[fil+2][col+2] = sensores.terreno[4];
		mapaResultado[fil+2][col+1] = sensores.terreno[5];
		mapaResultado[fil+2][col] = sensores.terreno[6];
		mapaResultado[fil+2][col-1] = sensores.terreno[7];
		mapaResultado[fil+2][col-2] = sensores.terreno[8];
		mapaResultado[fil+3][col+3] = sensores.terreno[9];
		mapaResultado[fil+3][col+2] = sensores.terreno[10];
		mapaResultado[fil+3][col+1] = sensores.terreno[11];
		mapaResultado[fil+3][col] = sensores.terreno[12];
		mapaResultado[fil+3][col-1] = sensores.terreno[13];
		mapaResultado[fil+3][col-2] = sensores.terreno[14];
		mapaResultado[fil+3][col-3] = sensores.terreno[15];
	}else if (sensores.sentido == 3){ //si apunta al oeste
		mapaResultado[fil+1][col-1] = sensores.terreno[1];
		mapaResultado[fil][col-1] = sensores.terreno[2];
		mapaResultado[fil-1][col-1] = sensores.terreno[3];
		mapaResultado[fil+2][col-2] = sensores.terreno[4];
		mapaResultado[fil+1][col-2] = sensores.terreno[5];
		mapaResultado[fil][col-2] = sensores.terreno[6];
		mapaResultado[fil-1][col-2] = sensores.terreno[7];
		mapaResultado[fil-2][col-2] = sensores.terreno[8];
		mapaResultado[fil+3][col-3] = sensores.terreno[9];
		mapaResultado[fil+2][col-3] = sensores.terreno[10];
		mapaResultado[fil+1][col-3] = sensores.terreno[11];
		mapaResultado[fil][col-3] = sensores.terreno[12];
		mapaResultado[fil-1][col-3] = sensores.terreno[13];
		mapaResultado[fil-2][col-3] = sensores.terreno[14];
		mapaResultado[fil-3][col-3] = sensores.terreno[15];
	}
}

bool ComportamientoJugador::buscar_botin(Sensores sensores){	//busca botín
	int posicion_objeto = -1;
	int posicion_recarga = -1;
	
	cout << "norte " <<mymapatiempo[fil-1][col] << " ";
	cout <<"sur " <<mymapatiempo[fil+1][col] << " ";
	cout <<"oeste " <<mymapatiempo[fil][col-1] << " ";
	cout <<"este " <<mymapatiempo[fil][col+1] << " ";
	cout <<"\n";

	for (int i=1; i<=15; i++){
		if ((sensores.terreno[i] == 'D' && zapatilla_conseguida == false) || (sensores.terreno[i] == 'K' && bikini_conseguido == false)){
			posicion_objeto = i;
		}
	}

	if (sensores.bateria < 3000){
		for (int i=1; i<=15; i++){
			if ((sensores.terreno[i] == 'X' && posicion_objeto == -1)){
				posicion_recarga = i;
			}
		}
	}
	
	if (posicion_objeto != -1 && plan_botin.empty()){
		if (posicion_objeto == 1){
			if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_'){
				plan_botin.push(actFORWARD);
				plan_botin.push(actTURN_L);
				plan_botin.push(actFORWARD);
			}
		}else if (posicion_objeto == 2){
			if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_'){
				plan_botin.push(actFORWARD);
			}
		}else if (posicion_objeto == 3){
			if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_'){
				plan_botin.push(actFORWARD);
				plan_botin.push(actTURN_R);
				plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_objeto == 4){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_L);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
		}else if (posicion_objeto == 5){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_L);
					plan_botin.push(actFORWARD);
			}
		}else if (posicion_objeto == 6){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
		}else if (posicion_objeto == 7){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
			&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' )){
				plan_botin.push(actFORWARD);
				plan_botin.push(actFORWARD);
				plan_botin.push(actTURN_R);
				plan_botin.push(actFORWARD);
			}
		}else if (posicion_objeto == 8){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_R);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
		}else if (posicion_objeto == 9){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )
				&& (sensores.terreno[11] != 'M' && sensores.terreno[11] != 'P' )
				&& (sensores.terreno[10] != 'M' && sensores.terreno[10] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_L);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
		}else if (posicion_objeto == 10){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )
				&& (sensores.terreno[11] != 'M' && sensores.terreno[11] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_L);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_objeto == 11){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_L);
					plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_objeto == 12){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) ){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_objeto == 13){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_R);
					plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_objeto == 14){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )
				&& (sensores.terreno[13] != 'M' && sensores.terreno[13] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_R);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_objeto == 15){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )
				&& (sensores.terreno[13] != 'M' && sensores.terreno[13] != 'P' )
				&& (sensores.terreno[14] != 'M' && sensores.terreno[14] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_R);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
		}
		return true;

	}
	else if(posicion_recarga != -1 && plan_botin.empty()){
		if (posicion_recarga == 1){
			if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_'){
				plan_botin.push(actFORWARD);
				plan_botin.push(actTURN_L);
				plan_botin.push(actFORWARD);
			}
		}else if (posicion_recarga == 2){
			if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_'){
				plan_botin.push(actFORWARD);
			}
		}else if (posicion_recarga == 3){
			if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_'){
				plan_botin.push(actFORWARD);
				plan_botin.push(actTURN_R);
				plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_recarga == 4){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_L);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
		}else if (posicion_recarga == 5){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_L);
					plan_botin.push(actFORWARD);
			}
		}else if (posicion_recarga == 6){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
		}else if (posicion_recarga == 7){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
			&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' )){
				plan_botin.push(actFORWARD);
				plan_botin.push(actFORWARD);
				plan_botin.push(actTURN_R);
				plan_botin.push(actFORWARD);
			}
		}else if (posicion_recarga == 8){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_R);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
		}else if (posicion_recarga == 9){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )
				&& (sensores.terreno[11] != 'M' && sensores.terreno[11] != 'P' )
				&& (sensores.terreno[10] != 'M' && sensores.terreno[10] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_L);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
		}else if (posicion_recarga == 10){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )
				&& (sensores.terreno[11] != 'M' && sensores.terreno[11] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_L);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_recarga == 11){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_L);
					plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_recarga == 12){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) ){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_recarga == 13){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_R);
					plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_recarga == 14){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )
				&& (sensores.terreno[13] != 'M' && sensores.terreno[13] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_R);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
			
		}else if (posicion_recarga == 15){
			if ((sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.superficie[2] == '_') 
				&& (sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P' ) 
				&& (sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P' )
				&& (sensores.terreno[13] != 'M' && sensores.terreno[13] != 'P' )
				&& (sensores.terreno[14] != 'M' && sensores.terreno[14] != 'P' )){
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actTURN_R);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
					plan_botin.push(actFORWARD);
			}
		}
		return true;	
	}else{
		return false;
	}
}


//antes de tomar la decision del minimo, sumamos valores en caso de haber agua y no tener bikini o cesped en caso de no tener zapatillas

//comprueba si no queda más remedio que ir sobre terreno demandante de batería en caso de tener:


Action ComportamientoJugador::minimo_zapatilla(Sensores sensores, char izquierda_resultado, char derecha_resultado, char delante_resultado, char detras_resultado, int izquierda, int derecha, int delante, int detras){	//comprobacion si tienes la zapatilla
	Action accion;

	if (sensores.terreno[2] == 'A'){
		delante = delante + 3000;
	}
	if (izquierda_resultado == 'A'){
		izquierda = izquierda + 3000;
	}
	if (derecha_resultado == 'A'){
		derecha = derecha + 3000;
	}
	if (detras_resultado == 'A'){
		detras = detras + 3000;
	}

	if (sensores.terreno[2] == 'M' or sensores.terreno[2] == 'P'){
		delante = 999999;
	}
	if (izquierda_resultado == 'M' or izquierda_resultado == 'P'){
		izquierda = 999999;
	}
	if (derecha_resultado == 'M' or derecha_resultado == 'P'){
		derecha = 999999;
	}
	if (detras_resultado == 'M' or detras_resultado == 'P'){
		detras = 999999;
	}

	int minimo = min(delante, min(detras, min(izquierda,  derecha)));
	
	if (delante == minimo && (sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')){
		accion = actFORWARD;
	}else if (izquierda == minimo){
		accion = actTURN_L;
	}else if (derecha == minimo){
		accion = actTURN_R;
	}else if (detras == minimo){
		accion = actTURN_R;
		giroR_pendiente = true;
	}
}

Action ComportamientoJugador::minimo_bikini(Sensores sensores, char izquierda_resultado, char derecha_resultado, char delante_resultado, char detras_resultado, int izquierda, int derecha, int delante, int detras){	 //comprobación si tienes el bikini
	Action accion;

	if (sensores.terreno[2] == 'B'){
		delante = delante + 3000;
	}
	if (izquierda_resultado == 'B'){
		izquierda = izquierda + 3000;
	}
	if (derecha_resultado == 'B'){
		derecha = derecha + 3000;
	}
	if (detras_resultado == 'B'){
		detras = detras + 3000;
	}

	if (sensores.terreno[2] == 'M' or sensores.terreno[2] == 'P'){
		delante = 999999;
	}
	if (izquierda_resultado == 'M' or izquierda_resultado == 'P'){
		izquierda = 999999;
	}
	if (derecha_resultado == 'M' or derecha_resultado == 'P'){
		derecha = 999999;
	}
	if (detras_resultado == 'M' or detras_resultado == 'P'){
		detras = 999999;
	}

	int minimo = min(delante, min(detras, min(izquierda,  derecha)));
	
	if (delante == minimo && (sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')){
		accion = actFORWARD;
	}else if (izquierda == minimo){
		accion = actTURN_L;
	}else if (derecha == minimo){
		accion = actTURN_R;
	}else if (detras == minimo){
		accion = actTURN_R;
		giroR_pendiente = true;
	}
}

Action ComportamientoJugador::minimo_nada(Sensores sensores, char izquierda_resultado, char derecha_resultado, char delante_resultado, char detras_resultado, int izquierda, int derecha, int delante, int detras){	//comprobación si no tienes nada
	Action accion;

	if (sensores.terreno[2] == 'A'){
		delante = delante + 3000;
	}else if (sensores.terreno[2] == 'B'){
		delante = delante + 2500;
	}
	if (izquierda_resultado == 'A'){
		izquierda = izquierda + 3000;
	}else if (izquierda_resultado == 'B'){
		izquierda = izquierda + 2500;
	}
	if (derecha_resultado == 'A'){
		derecha = derecha + 3000;
	}else if (derecha_resultado == 'B'){
		derecha = derecha + 2500;
	}
	if (detras_resultado == 'A'){
		detras = detras + 3000;
	}else if (detras_resultado == 'B'){
		detras = detras + 2500;
	}

	if (sensores.terreno[2] == 'M' or sensores.terreno[2] == 'P'){
		delante = 999999;
	}
	if (izquierda_resultado == 'M' or izquierda_resultado == 'P'){
		izquierda = 999999;
	}
	if (derecha_resultado == 'M' or derecha_resultado == 'P'){
		derecha = 999999;
	}
	if (detras_resultado == 'M' or detras_resultado == 'P'){
		detras = 999999;
	}

	int minimo = min(delante, min(detras, min(izquierda,  derecha)));
	
	if (delante == minimo && (sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')){
		accion = actFORWARD;
	}else if (izquierda == minimo){
		accion = actTURN_L;
	}else if (derecha == minimo){
		accion = actTURN_R;
	}else if (detras == minimo){
		accion = actTURN_R;
		giroR_pendiente = true;
	}

}

Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actIDLE;
	switch (ultimaAccion){
		case actFORWARD:
			switch (brujula){
				case 0: fil --; break;
				case 1: col ++; break;
				case 2: fil ++; break;
				case 3: col --; break;
			}
			break;
		case actTURN_L:
			brujula = (brujula+3)%4;
			girar_derecha = (rand()%2 == 0);
			break;
		case actTURN_R:
			brujula = (brujula+1)%4;
			girar_derecha = (rand()%2==0);
			break;
	}

	pintar_mapa(sensores);

	//Decidir la nueva accion

	if (sensores.terreno[0] == 'D'){	//actualiza si hemos recogido botin
		zapatilla_conseguida = true;
	}

	if (sensores.terreno[0] == 'K'){
		bikini_conseguido = true;
	}

	//desestimar muros y precipicios en a la hora de dibujar el mapa de tiempo

	if (sensores.terreno[1] == 'M' or sensores.terreno[1] == 'P'){
		if (sensores.sentido == 0){
			mymapatiempo[fil-1][col-1] = 999999;
		}else if(sensores.sentido == 1){
			mymapatiempo[fil-1][col+1] = 999999;
		}else if(sensores.sentido == 2){
			mymapatiempo[fil+1][col+1] = 999999;
		}else if(sensores.sentido == 3){
			mymapatiempo[fil+1][col-1] = 999999;
		}
	}
	if (sensores.terreno[2] == 'M' or sensores.terreno[2] == 'P'){
		if (sensores.sentido == 0){
			mymapatiempo[fil-1][col] = 999999;
		}else if(sensores.sentido == 1){
			mymapatiempo[fil][col+1] = 999999;
		}else if(sensores.sentido == 2){
			mymapatiempo[fil+1][col] = 999999;
		}else if(sensores.sentido == 3){
			mymapatiempo[fil][col-1] = 999999;
		}
	}
	if (sensores.terreno[3] == 'M' or sensores.terreno[3] == 'P'){
		if (sensores.sentido == 0){
			mymapatiempo[fil-1][col+1] = 999999;
		}else if(sensores.sentido == 1){
			mymapatiempo[fil+1][col+1] = 999999;
		}else if(sensores.sentido == 2){
			mymapatiempo[fil+1][col-1] = 999999;
		}else if(sensores.sentido == 3){
			mymapatiempo[fil-1][col-1] = 999999;
		}
	}

if (giroR_pendiente == true){
	accion = actTURN_R;
	giroR_pendiente = false;
}else if (sensores.terreno[0] == 'X' && sensores.bateria < 5000){
	accion = actIDLE;
}else{
	if (zapatilla_conseguida == false && bikini_conseguido == false){
		buscar_botin(sensores);	//busca zapatilla, bikini y recargas
		if (!plan_botin.empty()){
			accion = plan_botin.front();
			plan_botin.pop();
		}else{
			if (sensores.sentido == 0){
				if (mymapatiempo[fil-1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col+1];
					int casilla_izquierda = mymapatiempo[fil][col-1];
					int casilla_arriba = mymapatiempo[fil-1][col];
					int casilla_detras = mymapatiempo[fil-1][col];

					char casilla_derecha_resultado = mapaResultado[fil][col+1];
					char casilla_izquierda_resultado = mapaResultado[fil][col-1];
					char casilla_arriba_resultado = mapaResultado[fil-1][col];
					char casilla_detras_resultado = mapaResultado[fil-1][col];

					accion = minimo_nada(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);

				}
			}else if (sensores.sentido == 1){
				if (mymapatiempo[fil][col+1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil+1][col];
					int casilla_izquierda = mymapatiempo[fil-1][col];
					int casilla_arriba = mymapatiempo[fil][col+1];
					int casilla_detras = mymapatiempo[fil][col-1];

					char casilla_derecha_resultado = mapaResultado[fil+1][col];
					char casilla_izquierda_resultado = mapaResultado[fil-1][col];
					char casilla_arriba_resultado = mapaResultado[fil][col+1];
					char casilla_detras_resultado = mapaResultado[fil][col-1];

					accion = minimo_nada(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);
				}
			}else if (sensores.sentido == 2){
				if (mymapatiempo[fil+1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col-1];
					int casilla_izquierda = mymapatiempo[fil][col+1];
					int casilla_arriba = mymapatiempo[fil+1][col];
					int casilla_detras = mymapatiempo[fil-1][col];

					char casilla_derecha_resultado = mapaResultado[fil][col-1];
					char casilla_izquierda_resultado = mapaResultado[fil][col+1];
					char casilla_arriba_resultado = mapaResultado[fil+1][col];
					char casilla_detras_resultado = mapaResultado[fil-1][col];

					accion = minimo_nada(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);
				}
			}else if (sensores.sentido == 3){
				if (mymapatiempo[fil][col-1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil-1][col];
					int casilla_izquierda = mymapatiempo[fil+1][col];
					int casilla_arriba = mymapatiempo[fil][col-1];
					int casilla_detras = mymapatiempo[fil][col+1];

					char casilla_derecha_resultado = mapaResultado[fil-1][col];
					char casilla_izquierda_resultado = mapaResultado[fil+1][col];
					char casilla_arriba_resultado = mapaResultado[fil][col-1];
					char casilla_detras_resultado = mapaResultado[fil][col+1];

					accion = minimo_nada(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);
				}
			}
		}
	}else if (zapatilla_conseguida == true && bikini_conseguido == false){
		buscar_botin(sensores);	//busca zapatilla y bikini

		if (!plan_botin.empty()){
			accion = plan_botin.front();
			plan_botin.pop();
		}else{
			if (sensores.sentido == 0){
				if (mymapatiempo[fil-1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col+1];
					int casilla_izquierda = mymapatiempo[fil][col-1];
					int casilla_arriba = mymapatiempo[fil-1][col];
					int casilla_detras = mymapatiempo[fil+1][col];

					char casilla_derecha_resultado = mapaResultado[fil][col+1];
					char casilla_izquierda_resultado = mapaResultado[fil][col-1];
					char casilla_arriba_resultado = mapaResultado[fil-1][col];
					char casilla_detras_resultado = mapaResultado[fil+1][col];

					accion = minimo_zapatilla(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);
				}
			}else if (sensores.sentido == 1){
				if (mymapatiempo[fil][col+1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil+1][col];
					int casilla_izquierda = mymapatiempo[fil-1][col];
					int casilla_arriba = mymapatiempo[fil][col+1];
					int casilla_detras = mymapatiempo[fil][col-1];

					char casilla_derecha_resultado = mapaResultado[fil+1][col];
					char casilla_izquierda_resultado = mapaResultado[fil-1][col];
					char casilla_arriba_resultado = mapaResultado[fil][col+1];
					char casilla_detras_resultado = mapaResultado[fil][col-1];

					accion = minimo_zapatilla(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);
				}
			}else if (sensores.sentido == 2){
				if (mymapatiempo[fil+1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col-1];
					int casilla_izquierda = mymapatiempo[fil][col+1];
					int casilla_arriba = mymapatiempo[fil+1][col];
					int casilla_detras = mymapatiempo[fil-1][col];

					char casilla_derecha_resultado = mapaResultado[fil][col-1];
					char casilla_izquierda_resultado = mapaResultado[fil][col+1];
					char casilla_arriba_resultado = mapaResultado[fil+1][col];
					char casilla_detras_resultado = mapaResultado[fil-1][col];

					accion = minimo_zapatilla(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);
				}
			}else if (sensores.sentido == 3){
				if (mymapatiempo[fil][col-1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil-1][col];
					int casilla_izquierda = mymapatiempo[fil+1][col];
					int casilla_arriba = mymapatiempo[fil][col-1];
					int casilla_detras = mymapatiempo[fil][col+1];

					char casilla_derecha_resultado = mapaResultado[fil-1][col];
					char casilla_izquierda_resultado = mapaResultado[fil+1][col];
					char casilla_arriba_resultado = mapaResultado[fil][col-1];
					char casilla_detras_resultado = mapaResultado[fil][col+1];

					accion = minimo_zapatilla(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);
				}
			}
		}
	}else if (zapatilla_conseguida == true && bikini_conseguido == true){
		buscar_botin(sensores);	//busca zapatilla, bikini y recargas
		if (!plan_botin.empty()){
			accion = plan_botin.front();
			plan_botin.pop();
		}else{
			if (sensores.sentido == 0){
				if (mymapatiempo[fil-1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col+1];
					int casilla_izquierda = mymapatiempo[fil][col-1];
					int casilla_arriba = mymapatiempo[fil-1][col];
					int casilla_detras = mymapatiempo[fil+1][col];
					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && ((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'))){
						accion = actFORWARD;
					}else if (casilla_izquierda == minimo){
						accion = actTURN_L;
					}else if (casilla_derecha == minimo){
						accion = actTURN_R;
					}else if (casilla_detras == minimo){
						accion = actTURN_R;
						giroR_pendiente = true;
					}
				}
			}else if (sensores.sentido == 1){
				if (mymapatiempo[fil][col+1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil+1][col];
					int casilla_izquierda = mymapatiempo[fil-1][col];
					int casilla_arriba = mymapatiempo[fil][col+1];
					int casilla_detras = mymapatiempo[fil][col-1];
					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && ((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'))){
						accion = actFORWARD;
					}else if (casilla_izquierda == minimo){
						accion = actTURN_L;
					}else if (casilla_derecha == minimo){
						accion = actTURN_R;
					}else if (casilla_detras == minimo){
						accion = actTURN_R;
						giroR_pendiente = true;
					}
				}
			}else if (sensores.sentido == 2){
				if (mymapatiempo[fil+1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col-1];
					int casilla_izquierda = mymapatiempo[fil][col+1];
					int casilla_arriba = mymapatiempo[fil+1][col];
					int casilla_detras = mymapatiempo[fil-1][col];
					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && ((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'))){
						accion = actFORWARD;
					}else if (casilla_izquierda == minimo){
						accion = actTURN_L;
					}else if (casilla_derecha == minimo){
						accion = actTURN_R;
					}else if (casilla_detras == minimo){
						accion = actTURN_R;
						giroR_pendiente = true;
					}
				}
			}else if (sensores.sentido == 3){
				if (mymapatiempo[fil][col-1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil-1][col];
					int casilla_izquierda = mymapatiempo[fil+1][col];
					int casilla_arriba = mymapatiempo[fil][col-1];
					int casilla_detras = mymapatiempo[fil][col+1];
					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && ((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'))){
						accion = actFORWARD;
					}else if (casilla_izquierda == minimo){
						accion = actTURN_L;
					}else if (casilla_derecha == minimo){
						accion = actTURN_R;
					}else if (casilla_detras == minimo){
						accion = actTURN_R;
						giroR_pendiente = true;
					}
				}
			}
		}
		
	}else if (zapatilla_conseguida == false && bikini_conseguido == true){
		buscar_botin(sensores);	//busca zapatilla y bikini
		if (!plan_botin.empty()){
			accion = plan_botin.front();
			plan_botin.pop();
		}else{
			if (sensores.sentido == 0){
				if (mymapatiempo[fil-1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col+1];
					int casilla_izquierda = mymapatiempo[fil][col-1];
					int casilla_arriba = mymapatiempo[fil-1][col];
					int casilla_detras = mymapatiempo[fil+1][col];

					char casilla_derecha_resultado = mapaResultado[fil][col+1];
					char casilla_izquierda_resultado = mapaResultado[fil][col-1];
					char casilla_arriba_resultado = mapaResultado[fil-1][col];
					char casilla_detras_resultado = mapaResultado[fil+1][col];

					accion = minimo_bikini(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);

				}
			}else if (sensores.sentido == 1){
				if (mymapatiempo[fil][col+1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil+1][col];
					int casilla_izquierda = mymapatiempo[fil-1][col];
					int casilla_arriba = mymapatiempo[fil][col+1];
					int casilla_detras = mymapatiempo[fil][col-1];

					char casilla_derecha_resultado = mapaResultado[fil+1][col];
					char casilla_izquierda_resultado = mapaResultado[fil-1][col];
					char casilla_arriba_resultado = mapaResultado[fil][col+1];
					char casilla_detras_resultado = mapaResultado[fil][col-1];

					accion = minimo_bikini(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);

				}
			}else if (sensores.sentido == 2){
				if (mymapatiempo[fil+1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col-1];
					int casilla_izquierda = mymapatiempo[fil][col+1];
					int casilla_arriba = mymapatiempo[fil+1][col];
					int casilla_detras = mymapatiempo[fil-1][col];

					char casilla_derecha_resultado = mapaResultado[fil][col-1];
					char casilla_izquierda_resultado = mapaResultado[fil][col+1];
					char casilla_arriba_resultado = mapaResultado[fil+1][col];
					char casilla_detras_resultado = mapaResultado[fil-1][col];

					accion = minimo_bikini(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);

				}
			}else if (sensores.sentido == 3){
				if (mymapatiempo[fil][col-1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil-1][col];
					int casilla_izquierda = mymapatiempo[fil+1][col];
					int casilla_arriba = mymapatiempo[fil][col-1];
					int casilla_detras = mymapatiempo[fil][col+1];

					char casilla_derecha_resultado = mapaResultado[fil-1][col];
					char casilla_izquierda_resultado = mapaResultado[fil+1][col];
					char casilla_arriba_resultado = mapaResultado[fil][col-1];
					char casilla_detras_resultado = mapaResultado[fil][col+1];

					accion = minimo_bikini(sensores, casilla_izquierda_resultado, casilla_derecha_resultado, casilla_arriba_resultado, casilla_detras_resultado, casilla_izquierda, casilla_derecha, casilla_arriba, casilla_detras);

				}
			}
		}
	}
}

if (ultimaAccion == actIDLE && sensores.terreno[0] != 'X'){
	int accion_aleatoria = rand() % 2;
	if (accion_aleatoria == 0){
		accion = actTURN_L;
	}else{
		accion = actTURN_R;
	}
}
	//Recordar la última acción
	ultimaAccion = accion;

	//Devolver la acción
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}