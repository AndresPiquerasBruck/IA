#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void ComportamientoJugador::pintar_mapa(Sensores sensores){	//pinta el mapa conforme lo ve
	if (contador_tiempo == 0){
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

	if (sensores.nivel == 0){
		ubicado_primeravez = true;
	}
	
}else	if ((contador_tiempo == 2998 or sensores.bateria < 501) and trucompletado == false and ubicado_primeravez == true){
		for (int i=3;i<mapaResultado.size()-3;i++){
			for (int j=3;j<mapaResultado[0].size()-3;j++){
				switch (mapaResultado[i][j]){
					case 'B': num_b++; break;
					case 'A': num_a++; break;
					case 'P': num_p++; break;
					case 'S': num_s++; break;
					case 'T': num_t++; break;
					case 'M': num_m++; break;
					case 'G': num_g++; break;
					case 'K': num_k++; break;
					case 'D': num_d++; break;
					case 'X': num_x++; break;
				}
			}
		}

		int maximo = (max(num_b, max(num_a, max(num_p, max(num_s, max(num_t, max(num_m, max(num_g, max(num_k, max(num_d, num_x))))))))));
		if (maximo == num_b){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'B';
					}
				}
			}
		}else if (maximo == num_a){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'A';
					}
				}
			}
		}else if (maximo == num_p){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'P';
					}
				}
			}
		}else if (maximo == num_s){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'S';
					}
				}
			}
		}else if (maximo == num_t){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'T';
					}
				}
			}
		}else if (maximo == num_m){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'M';
					}
				}
			}
		}else if (maximo == num_g){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'G';
					}
				}
			}
		}else if (maximo == num_k){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'K';
					}
				}
			}
		}else if (maximo == num_d){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'D';
					}
				}
			}
		}else if (maximo == num_x){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'X';
					}
				}
			}
		}

		trucompletado = true;
	}else if (ubicado_primeravez == false && (contador_tiempo == 2998 or sensores.bateria < 501) and trucompletado == false){
		for (int i = 0; i<200; i++){
			for (int j = 0; j<200; j++){
				switch (mymapaprovisional[i][j]){
					case 'B': num_b++; break;
					case 'A': num_a++; break;
					case 'P': num_p++; break;
					case 'S': num_s++; break;
					case 'T': num_t++; break;
					case 'M': num_m++; break;
					case 'G': num_g++; break;
					case 'K': num_k++; break;
					case 'D': num_d++; break;
					case 'X': num_x++; break;
				}
			}
		}
    
		int maximo = (max(num_b, max(num_a, max(num_p, max(num_s, max(num_t, max(num_m, max(num_g, max(num_k, max(num_d, num_x))))))))));
		
		if (maximo == num_b){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'B';
					}
				}
			}
		}else if (maximo == num_a){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'A';
					}
				}
			}
		}else if (maximo == num_p){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'P';
					}
				}
			}
		}else if (maximo == num_s){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'S';
					}
				}
			}
		}else if (maximo == num_t){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'T';
					}
				}
			}
		}else if (maximo == num_m){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'M';
					}
				}
			}
		}else if (maximo == num_g){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'G';
					}
				}
			}
		}else if (maximo == num_k){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'K';
					}
				}
			}
		}else if (maximo == num_d){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'D';
					}
				}
			}
		}else if (maximo == num_x){
			for (int i=0;i<mapaResultado.size();i++){
				for (int j=0;j<mapaResultado[0].size();j++){
					if (mapaResultado[i][j] == '?'){
						mapaResultado[i][j] = 'X';
					}
				}
			}
		}
	}
		
	if (sensores.nivel >= 2){
		if(sensores.reset == true){

			for (int i=0;i<200;i++){
				for (int j=0;j<200;j++){
					mymapaprovisional[i][j] = '?';
				}
			}
			sentido = 0;
			ult_sentido = 0;
			ubicado = false;
			repos_c = 0;
      repos_f = 0;
			zapatilla_conseguida = false;
			bikini_conseguido = false;
		}else if (ultimaAccion == actTURN_L){
			if (ult_sentido == 0){
				sentido = 3;
			}else if (ult_sentido == 1){
				sentido = 0;
			}else if (ult_sentido == 2){
				sentido = 1;
			}else if (ult_sentido == 3){
				sentido = 2;
			}
		}else if (ultimaAccion == actTURN_R){
			if (ult_sentido == 0){
				sentido = 1;
			}else if (ult_sentido == 1){
				sentido = 2;
			}else if (ult_sentido == 2){
				sentido = 3;
			}else if (ult_sentido == 3){
				sentido = 0;
			}
		}
		ult_sentido = sentido;
	}
		
	
	if (sensores.nivel == 0) {
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
	////////////////////////////////////////////////////////////////
}else if (sensores.nivel == 1){

	if (contador_tiempo == 0){
		fil = 99;
		col = 99;
		mymapatiempo[fil][col] = contador_tiempo;
		contador_tiempo++;
	}else{
		mymapatiempo[fil][col] = contador_tiempo;
		contador_tiempo++;

		if (sensores.sentido == 0){
			if (ultimaAccion == actFORWARD){
				fil--;
			}
		}else if (sensores.sentido == 1){
			if (ultimaAccion == actFORWARD){
				col++;
			}
		}else if (sensores.sentido == 2){
			if (ultimaAccion == actFORWARD){
				fil++;
			}
		}else if (sensores.sentido == 3){
			if (ultimaAccion == actFORWARD){
				col--;
			}
		}
	}

	if (sensores.terreno[0] == 'G' && ubicado == false){	//si obtenemos la posicion
		repos_c = sensores.posC - col;
		repos_f = sensores.posF - fil;

		for (int i = 0; i < 200; i++){
			for (int j = 0; j < 200; j++){
				if (mymapaprovisional[i][j] != '?'){
					mapaResultado[i+repos_f][j+repos_c] = mymapaprovisional[i][j];
				}
			}
		}

		ubicado = true;
		ubicado_primeravez = true;
	}
	
	if (ubicado == true){

		mapaResultado[fil+repos_f][col+repos_c] = sensores.terreno[0];	//pintar mapa bajo sí
		if (sensores.sentido == 0){	//si apunta al norte
			mapaResultado[fil+repos_f-1][col+repos_c-1] = sensores.terreno[1];
			mapaResultado[fil+repos_f-1][col+repos_c] = sensores.terreno[2];
			mapaResultado[fil+repos_f-1][col+repos_c+1] = sensores.terreno[3];
			mapaResultado[fil+repos_f-2][col+repos_c-2] = sensores.terreno[4];
			mapaResultado[fil+repos_f-2][col+repos_c-1] = sensores.terreno[5];
			mapaResultado[fil+repos_f-2][col+repos_c] = sensores.terreno[6];
			mapaResultado[fil+repos_f-2][col+repos_c+1] = sensores.terreno[7];
			mapaResultado[fil+repos_f-2][col+repos_c+2] = sensores.terreno[8];
			mapaResultado[fil+repos_f-3][col+repos_c-3] = sensores.terreno[9];
			mapaResultado[fil+repos_f-3][col+repos_c-2] = sensores.terreno[10];
			mapaResultado[fil+repos_f-3][col+repos_c-1] = sensores.terreno[11];
			mapaResultado[fil+repos_f-3][col+repos_c] = sensores.terreno[12];
			mapaResultado[fil+repos_f-3][col+repos_c+1] = sensores.terreno[13];
			mapaResultado[fil+repos_f-3][col+repos_c+2] = sensores.terreno[14];
			mapaResultado[fil+repos_f-3][col+repos_c+3] = sensores.terreno[15];
		}else if (sensores.sentido == 1){ //si apunta al este
			mapaResultado[fil+repos_f-1][col+repos_c+1] = sensores.terreno[1];
			mapaResultado[fil+repos_f][col+repos_c+1] = sensores.terreno[2];
			mapaResultado[fil+repos_f+1][col+repos_c+1] = sensores.terreno[3];
			mapaResultado[fil+repos_f-2][col+repos_c+2] = sensores.terreno[4];
			mapaResultado[fil+repos_f-1][col+repos_c+2] = sensores.terreno[5];
			mapaResultado[fil+repos_f][col+repos_c+2] = sensores.terreno[6];
			mapaResultado[fil+repos_f+1][col+repos_c+2] = sensores.terreno[7];
			mapaResultado[fil+repos_f+2][col+repos_c+2] = sensores.terreno[8];
			mapaResultado[fil+repos_f-3][col+repos_c+3] = sensores.terreno[9];
			mapaResultado[fil+repos_f-2][col+repos_c+3] = sensores.terreno[10];
			mapaResultado[fil+repos_f-1][col+repos_c+3] = sensores.terreno[11];
			mapaResultado[fil+repos_f][col+repos_c+3] = sensores.terreno[12];
			mapaResultado[fil+repos_f+1][col+repos_c+3] = sensores.terreno[13];
			mapaResultado[fil+repos_f+2][col+repos_c+3] = sensores.terreno[14];
			mapaResultado[fil+repos_f+3][col+repos_c+3] = sensores.terreno[15];
		}else if (sensores.sentido == 2){ //si apunta al sur
			mapaResultado[fil+repos_f+1][col+repos_c+1] = sensores.terreno[1];
			mapaResultado[fil+repos_f+1][col+repos_c] = sensores.terreno[2];
			mapaResultado[fil+repos_f+1][col+repos_c-1] = sensores.terreno[3];
			mapaResultado[fil+repos_f+2][col+repos_c+2] = sensores.terreno[4];
			mapaResultado[fil+repos_f+2][col+repos_c+1] = sensores.terreno[5];
			mapaResultado[fil+repos_f+2][col+repos_c] = sensores.terreno[6];
			mapaResultado[fil+repos_f+2][col+repos_c-1] = sensores.terreno[7];
			mapaResultado[fil+repos_f+2][col+repos_c-2] = sensores.terreno[8];
			mapaResultado[fil+repos_f+3][col+repos_c+3] = sensores.terreno[9];
			mapaResultado[fil+repos_f+3][col+repos_c+2] = sensores.terreno[10];
			mapaResultado[fil+repos_f+3][col+repos_c+1] = sensores.terreno[11];
			mapaResultado[fil+repos_f+3][col+repos_c] = sensores.terreno[12];
			mapaResultado[fil+repos_f+3][col+repos_c-1] = sensores.terreno[13];
			mapaResultado[fil+repos_f+3][col+repos_c-2] = sensores.terreno[14];
			mapaResultado[fil+repos_f+3][col+repos_c-3] = sensores.terreno[15];
		}else if (sensores.sentido == 3){ //si apunta al oeste
			mapaResultado[fil+repos_f+1][col+repos_c-1] = sensores.terreno[1];
			mapaResultado[fil+repos_f][col+repos_c-1] = sensores.terreno[2];
			mapaResultado[fil+repos_f-1][col+repos_c-1] = sensores.terreno[3];
			mapaResultado[fil+repos_f+2][col+repos_c-2] = sensores.terreno[4];
			mapaResultado[fil+repos_f+1][col+repos_c-2] = sensores.terreno[5];
			mapaResultado[fil+repos_f][col+repos_c-2] = sensores.terreno[6];
			mapaResultado[fil+repos_f-1][col+repos_c-2] = sensores.terreno[7];
			mapaResultado[fil+repos_f-2][col+repos_c-2] = sensores.terreno[8];
			mapaResultado[fil+repos_f+3][col+repos_c-3] = sensores.terreno[9];
			mapaResultado[fil+repos_f+2][col+repos_c-3] = sensores.terreno[10];
			mapaResultado[fil+repos_f+1][col+repos_c-3] = sensores.terreno[11];
			mapaResultado[fil+repos_f][col+repos_c-3] = sensores.terreno[12];
			mapaResultado[fil+repos_f-1][col+repos_c-3] = sensores.terreno[13];
			mapaResultado[fil+repos_f-2][col+repos_c-3] = sensores.terreno[14];
			mapaResultado[fil+repos_f-3][col+repos_c-3] = sensores.terreno[15];
		}


	}
		mymapaprovisional[fil][col] = sensores.terreno[0];	//pintar mapa bajo sí
		if (sensores.sentido == 0){	//si apunta al norte
			mymapaprovisional[fil-1][col-1] = sensores.terreno[1];
			mymapaprovisional[fil-1][col] = sensores.terreno[2];
			mymapaprovisional[fil-1][col+1] = sensores.terreno[3];
			mymapaprovisional[fil-2][col-2] = sensores.terreno[4];
			mymapaprovisional[fil-2][col-1] = sensores.terreno[5];
			mymapaprovisional[fil-2][col] = sensores.terreno[6];
			mymapaprovisional[fil-2][col+1] = sensores.terreno[7];
			mymapaprovisional[fil-2][col+2] = sensores.terreno[8];
			mymapaprovisional[fil-3][col-3] = sensores.terreno[9];
			mymapaprovisional[fil-3][col-2] = sensores.terreno[10];
			mymapaprovisional[fil-3][col-1] = sensores.terreno[11];
			mymapaprovisional[fil-3][col] = sensores.terreno[12];
			mymapaprovisional[fil-3][col+1] = sensores.terreno[13];
			mymapaprovisional[fil-3][col+2] = sensores.terreno[14];
			mymapaprovisional[fil-3][col+3] = sensores.terreno[15];
		}else if (sensores.sentido == 1){ //si apunta al este
			mymapaprovisional[fil-1][col+1] = sensores.terreno[1];
			mymapaprovisional[fil][col+1] = sensores.terreno[2];
			mymapaprovisional[fil+1][col+1] = sensores.terreno[3];
			mymapaprovisional[fil-2][col+2] = sensores.terreno[4];
			mymapaprovisional[fil-1][col+2] = sensores.terreno[5];
			mymapaprovisional[fil][col+2] = sensores.terreno[6];
			mymapaprovisional[fil+1][col+2] = sensores.terreno[7];
			mymapaprovisional[fil+2][col+2] = sensores.terreno[8];
			mymapaprovisional[fil-3][col+3] = sensores.terreno[9];
			mymapaprovisional[fil-2][col+3] = sensores.terreno[10];
			mymapaprovisional[fil-1][col+3] = sensores.terreno[11];
			mymapaprovisional[fil][col+3] = sensores.terreno[12];
			mymapaprovisional[fil+1][col+3] = sensores.terreno[13];
			mymapaprovisional[fil+2][col+3] = sensores.terreno[14];
			mymapaprovisional[fil+3][col+3] = sensores.terreno[15];
		}else if (sensores.sentido == 2){ //si apunta al sur
			mymapaprovisional[fil+1][col+1] = sensores.terreno[1];
			mymapaprovisional[fil+1][col] = sensores.terreno[2];
			mymapaprovisional[fil+1][col-1] = sensores.terreno[3];
			mymapaprovisional[fil+2][col+2] = sensores.terreno[4];
			mymapaprovisional[fil+2][col+1] = sensores.terreno[5];
			mymapaprovisional[fil+2][col] = sensores.terreno[6];
			mymapaprovisional[fil+2][col-1] = sensores.terreno[7];
			mymapaprovisional[fil+2][col-2] = sensores.terreno[8];
			mymapaprovisional[fil+3][col+3] = sensores.terreno[9];
			mymapaprovisional[fil+3][col+2] = sensores.terreno[10];
			mymapaprovisional[fil+3][col+1] = sensores.terreno[11];
			mymapaprovisional[fil+3][col] = sensores.terreno[12];
			mymapaprovisional[fil+3][col-1] = sensores.terreno[13];
			mymapaprovisional[fil+3][col-2] = sensores.terreno[14];
			mymapaprovisional[fil+3][col-3] = sensores.terreno[15];
		}else if (sensores.sentido == 3){ //si apunta al oeste
			mymapaprovisional[fil+1][col-1] = sensores.terreno[1];
			mymapaprovisional[fil][col-1] = sensores.terreno[2];
			mymapaprovisional[fil-1][col-1] = sensores.terreno[3];
			mymapaprovisional[fil+2][col-2] = sensores.terreno[4];
			mymapaprovisional[fil+1][col-2] = sensores.terreno[5];
			mymapaprovisional[fil][col-2] = sensores.terreno[6];
			mymapaprovisional[fil-1][col-2] = sensores.terreno[7];
			mymapaprovisional[fil-2][col-2] = sensores.terreno[8];
			mymapaprovisional[fil+3][col-3] = sensores.terreno[9];
			mymapaprovisional[fil+2][col-3] = sensores.terreno[10];
			mymapaprovisional[fil+1][col-3] = sensores.terreno[11];
			mymapaprovisional[fil][col-3] = sensores.terreno[12];
			mymapaprovisional[fil-1][col-3] = sensores.terreno[13];
			mymapaprovisional[fil-2][col-3] = sensores.terreno[14];
			mymapaprovisional[fil-3][col-3] = sensores.terreno[15];
		}
	////////////////////////////////////////////////////////////////nivel 2
	}else if (sensores.nivel >= 2){
		if (contador_tiempo == 0){
		fil = 99;
		col = 99;
		mymapatiempo[fil][col] = contador_tiempo;
		contador_tiempo++;
	}else{
		mymapatiempo[fil][col] = contador_tiempo;
		contador_tiempo++;

		if (sentido == 0){
			if (ultimaAccion == actFORWARD){
				fil--;
			}
		}else if (sentido == 1){
			if (ultimaAccion == actFORWARD){
				col++;
			}
		}else if (sentido == 2){
			if (ultimaAccion == actFORWARD){
				fil++;
			}
		}else if (sentido == 3){
			if (ultimaAccion == actFORWARD){
				col--;
			}
		}
	}

	if (sensores.terreno[0] == 'G' && ubicado == false){	//si obtenemos la posicion
		repos_c = sensores.posC - col;
		repos_f = sensores.posF - fil;

		for (int i = 0; i < 200; i++){
			for (int j = 0; j < 200; j++){
				if (mymapaprovisional[i][j] != '?'){
					mapaResultado[i+repos_f][j+repos_c] = mymapaprovisional[i][j];
				}
			}
		}

		ubicado = true;
		ubicado_primeravez = true;
	}
	
	if (ubicado == true){

		mapaResultado[fil+repos_f][col+repos_c] = sensores.terreno[0];	//pintar mapa bajo sí
		if (sentido == 0){	//si apunta al norte
			mapaResultado[fil+repos_f-1][col+repos_c-1] = sensores.terreno[1];
			mapaResultado[fil+repos_f-1][col+repos_c] = sensores.terreno[2];
			mapaResultado[fil+repos_f-1][col+repos_c+1] = sensores.terreno[3];
			mapaResultado[fil+repos_f-2][col+repos_c-2] = sensores.terreno[4];
			mapaResultado[fil+repos_f-2][col+repos_c-1] = sensores.terreno[5];
			mapaResultado[fil+repos_f-2][col+repos_c] = sensores.terreno[6];
			mapaResultado[fil+repos_f-2][col+repos_c+1] = sensores.terreno[7];
			mapaResultado[fil+repos_f-2][col+repos_c+2] = sensores.terreno[8];
			mapaResultado[fil+repos_f-3][col+repos_c-3] = sensores.terreno[9];
			mapaResultado[fil+repos_f-3][col+repos_c-2] = sensores.terreno[10];
			mapaResultado[fil+repos_f-3][col+repos_c-1] = sensores.terreno[11];
			mapaResultado[fil+repos_f-3][col+repos_c] = sensores.terreno[12];
			mapaResultado[fil+repos_f-3][col+repos_c+1] = sensores.terreno[13];
			mapaResultado[fil+repos_f-3][col+repos_c+2] = sensores.terreno[14];
			mapaResultado[fil+repos_f-3][col+repos_c+3] = sensores.terreno[15];
		}else if (sentido == 1){ //si apunta al este
			mapaResultado[fil+repos_f-1][col+repos_c+1] = sensores.terreno[1];
			mapaResultado[fil+repos_f][col+repos_c+1] = sensores.terreno[2];
			mapaResultado[fil+repos_f+1][col+repos_c+1] = sensores.terreno[3];
			mapaResultado[fil+repos_f-2][col+repos_c+2] = sensores.terreno[4];
			mapaResultado[fil+repos_f-1][col+repos_c+2] = sensores.terreno[5];
			mapaResultado[fil+repos_f][col+repos_c+2] = sensores.terreno[6];
			mapaResultado[fil+repos_f+1][col+repos_c+2] = sensores.terreno[7];
			mapaResultado[fil+repos_f+2][col+repos_c+2] = sensores.terreno[8];
			mapaResultado[fil+repos_f-3][col+repos_c+3] = sensores.terreno[9];
			mapaResultado[fil+repos_f-2][col+repos_c+3] = sensores.terreno[10];
			mapaResultado[fil+repos_f-1][col+repos_c+3] = sensores.terreno[11];
			mapaResultado[fil+repos_f][col+repos_c+3] = sensores.terreno[12];
			mapaResultado[fil+repos_f+1][col+repos_c+3] = sensores.terreno[13];
			mapaResultado[fil+repos_f+2][col+repos_c+3] = sensores.terreno[14];
			mapaResultado[fil+repos_f+3][col+repos_c+3] = sensores.terreno[15];
		}else if (sentido == 2){ //si apunta al sur
			mapaResultado[fil+repos_f+1][col+repos_c+1] = sensores.terreno[1];
			mapaResultado[fil+repos_f+1][col+repos_c] = sensores.terreno[2];
			mapaResultado[fil+repos_f+1][col+repos_c-1] = sensores.terreno[3];
			mapaResultado[fil+repos_f+2][col+repos_c+2] = sensores.terreno[4];
			mapaResultado[fil+repos_f+2][col+repos_c+1] = sensores.terreno[5];
			mapaResultado[fil+repos_f+2][col+repos_c] = sensores.terreno[6];
			mapaResultado[fil+repos_f+2][col+repos_c-1] = sensores.terreno[7];
			mapaResultado[fil+repos_f+2][col+repos_c-2] = sensores.terreno[8];
			mapaResultado[fil+repos_f+3][col+repos_c+3] = sensores.terreno[9];
			mapaResultado[fil+repos_f+3][col+repos_c+2] = sensores.terreno[10];
			mapaResultado[fil+repos_f+3][col+repos_c+1] = sensores.terreno[11];
			mapaResultado[fil+repos_f+3][col+repos_c] = sensores.terreno[12];
			mapaResultado[fil+repos_f+3][col+repos_c-1] = sensores.terreno[13];
			mapaResultado[fil+repos_f+3][col+repos_c-2] = sensores.terreno[14];
			mapaResultado[fil+repos_f+3][col+repos_c-3] = sensores.terreno[15];
		}else if (sentido == 3){ //si apunta al oeste
			mapaResultado[fil+repos_f+1][col+repos_c-1] = sensores.terreno[1];
			mapaResultado[fil+repos_f][col+repos_c-1] = sensores.terreno[2];
			mapaResultado[fil+repos_f-1][col+repos_c-1] = sensores.terreno[3];
			mapaResultado[fil+repos_f+2][col+repos_c-2] = sensores.terreno[4];
			mapaResultado[fil+repos_f+1][col+repos_c-2] = sensores.terreno[5];
			mapaResultado[fil+repos_f][col+repos_c-2] = sensores.terreno[6];
			mapaResultado[fil+repos_f-1][col+repos_c-2] = sensores.terreno[7];
			mapaResultado[fil+repos_f-2][col+repos_c-2] = sensores.terreno[8];
			mapaResultado[fil+repos_f+3][col+repos_c-3] = sensores.terreno[9];
			mapaResultado[fil+repos_f+2][col+repos_c-3] = sensores.terreno[10];
			mapaResultado[fil+repos_f+1][col+repos_c-3] = sensores.terreno[11];
			mapaResultado[fil+repos_f][col+repos_c-3] = sensores.terreno[12];
			mapaResultado[fil+repos_f-1][col+repos_c-3] = sensores.terreno[13];
			mapaResultado[fil+repos_f-2][col+repos_c-3] = sensores.terreno[14];
			mapaResultado[fil+repos_f-3][col+repos_c-3] = sensores.terreno[15];
		}


	}
		mymapaprovisional[fil][col] = sensores.terreno[0];	//pintar mapa bajo sí
		if (sentido == 0){	//si apunta al norte
			mymapaprovisional[fil-1][col-1] = sensores.terreno[1];
			mymapaprovisional[fil-1][col] = sensores.terreno[2];
			mymapaprovisional[fil-1][col+1] = sensores.terreno[3];
			mymapaprovisional[fil-2][col-2] = sensores.terreno[4];
			mymapaprovisional[fil-2][col-1] = sensores.terreno[5];
			mymapaprovisional[fil-2][col] = sensores.terreno[6];
			mymapaprovisional[fil-2][col+1] = sensores.terreno[7];
			mymapaprovisional[fil-2][col+2] = sensores.terreno[8];
			mymapaprovisional[fil-3][col-3] = sensores.terreno[9];
			mymapaprovisional[fil-3][col-2] = sensores.terreno[10];
			mymapaprovisional[fil-3][col-1] = sensores.terreno[11];
			mymapaprovisional[fil-3][col] = sensores.terreno[12];
			mymapaprovisional[fil-3][col+1] = sensores.terreno[13];
			mymapaprovisional[fil-3][col+2] = sensores.terreno[14];
			mymapaprovisional[fil-3][col+3] = sensores.terreno[15];
		}else if (sentido == 1){ //si apunta al este
			mymapaprovisional[fil-1][col+1] = sensores.terreno[1];
			mymapaprovisional[fil][col+1] = sensores.terreno[2];
			mymapaprovisional[fil+1][col+1] = sensores.terreno[3];
			mymapaprovisional[fil-2][col+2] = sensores.terreno[4];
			mymapaprovisional[fil-1][col+2] = sensores.terreno[5];
			mymapaprovisional[fil][col+2] = sensores.terreno[6];
			mymapaprovisional[fil+1][col+2] = sensores.terreno[7];
			mymapaprovisional[fil+2][col+2] = sensores.terreno[8];
			mymapaprovisional[fil-3][col+3] = sensores.terreno[9];
			mymapaprovisional[fil-2][col+3] = sensores.terreno[10];
			mymapaprovisional[fil-1][col+3] = sensores.terreno[11];
			mymapaprovisional[fil][col+3] = sensores.terreno[12];
			mymapaprovisional[fil+1][col+3] = sensores.terreno[13];
			mymapaprovisional[fil+2][col+3] = sensores.terreno[14];
			mymapaprovisional[fil+3][col+3] = sensores.terreno[15];
		}else if (sentido == 2){ //si apunta al sur
			mymapaprovisional[fil+1][col+1] = sensores.terreno[1];
			mymapaprovisional[fil+1][col] = sensores.terreno[2];
			mymapaprovisional[fil+1][col-1] = sensores.terreno[3];
			mymapaprovisional[fil+2][col+2] = sensores.terreno[4];
			mymapaprovisional[fil+2][col+1] = sensores.terreno[5];
			mymapaprovisional[fil+2][col] = sensores.terreno[6];
			mymapaprovisional[fil+2][col-1] = sensores.terreno[7];
			mymapaprovisional[fil+2][col-2] = sensores.terreno[8];
			mymapaprovisional[fil+3][col+3] = sensores.terreno[9];
			mymapaprovisional[fil+3][col+2] = sensores.terreno[10];
			mymapaprovisional[fil+3][col+1] = sensores.terreno[11];
			mymapaprovisional[fil+3][col] = sensores.terreno[12];
			mymapaprovisional[fil+3][col-1] = sensores.terreno[13];
			mymapaprovisional[fil+3][col-2] = sensores.terreno[14];
			mymapaprovisional[fil+3][col-3] = sensores.terreno[15];
		}else if (sentido == 3){ //si apunta al oeste
			mymapaprovisional[fil+1][col-1] = sensores.terreno[1];
			mymapaprovisional[fil][col-1] = sensores.terreno[2];
			mymapaprovisional[fil-1][col-1] = sensores.terreno[3];
			mymapaprovisional[fil+2][col-2] = sensores.terreno[4];
			mymapaprovisional[fil+1][col-2] = sensores.terreno[5];
			mymapaprovisional[fil][col-2] = sensores.terreno[6];
			mymapaprovisional[fil-1][col-2] = sensores.terreno[7];
			mymapaprovisional[fil-2][col-2] = sensores.terreno[8];
			mymapaprovisional[fil+3][col-3] = sensores.terreno[9];
			mymapaprovisional[fil+2][col-3] = sensores.terreno[10];
			mymapaprovisional[fil+1][col-3] = sensores.terreno[11];
			mymapaprovisional[fil][col-3] = sensores.terreno[12];
			mymapaprovisional[fil-1][col-3] = sensores.terreno[13];
			mymapaprovisional[fil-2][col-3] = sensores.terreno[14];
			mymapaprovisional[fil-3][col-3] = sensores.terreno[15];
		}
	}
}



bool ComportamientoJugador::buscar_botin(Sensores sensores){	//busca botín

	int posicion_objeto = -1;
	int posicion_recarga = -1;

	for (int i=1; i<=15; i++){
		if ((sensores.terreno[i] == 'D' && zapatilla_conseguida == false) || (sensores.terreno[i] == 'K' && bikini_conseguido == false)){
			posicion_objeto = i;
		}
	}

	if (sensores.nivel != 0 && ubicado == false){
		for (int i=1; i<=15; i++){
			if ((sensores.terreno[i] == 'G' && posicion_objeto == -1)){
				posicion_recarga = i;
			}
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

Action ComportamientoJugador::think(Sensores sensores){

		

	if (sensores.nivel == 0){

		Action accion = actIDLE;

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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')){
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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}
	
					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}
					
					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
	}
}

if (ultimaAccion == actIDLE && sensores.terreno[0] != 'X' && contador_tiempo > 1){
	if (sensores.terreno[2] != 'P' && sensores.terreno[2] != 'M'){
		if (sensores.terreno[2] == 'A' && bikini_conseguido == false){
			int accion_aleatoria = rand() % 2;
			if (accion_aleatoria == 0){
				accion = actTURN_L;
			}else if (accion_aleatoria == 1){
				accion = actTURN_R;
			}
		}else if (sensores.terreno[2] == 'B' && zapatilla_conseguida == false){
			int accion_aleatoria = rand() % 2;
			if (accion_aleatoria == 0){
				accion = actTURN_L;
			}else if (accion_aleatoria == 1){
				accion = actTURN_R;
			}
		}else{
			accion = actFORWARD;
		}
	}else{
		int accion_aleatoria = rand() % 2;
		if (accion_aleatoria == 0){
			accion = actTURN_L;
		}else if (accion_aleatoria == 1){
			accion = actTURN_R;
		}
	}
}
	//Recordar la última acción
	ultimaAccion = accion;

	//Devolver la acción
	return accion;
	////////////////////////////////////////////////////////////////////////////////////////////NIVEL 1
	}else if (sensores.nivel == 1){
		Action accion = actIDLE;

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
					
					char casilla_derecha_resultado = mymapaprovisional[fil][col+1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col-1];
					char casilla_arriba_resultado = mymapaprovisional[fil-1][col];
					char casilla_detras_resultado = mymapaprovisional[fil-1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')){
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
				if (mymapatiempo[fil][col+1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil+1][col];
					int casilla_izquierda = mymapatiempo[fil-1][col];
					int casilla_arriba = mymapatiempo[fil][col+1];
					int casilla_detras = mymapatiempo[fil][col-1];

					char casilla_derecha_resultado = mymapaprovisional[fil+1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil-1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col+1];
					char casilla_detras_resultado = mymapaprovisional[fil][col-1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
				if (mymapatiempo[fil+1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col-1];
					int casilla_izquierda = mymapatiempo[fil][col+1];
					int casilla_arriba = mymapatiempo[fil+1][col];
					int casilla_detras = mymapatiempo[fil-1][col];

					char casilla_derecha_resultado = mymapaprovisional[fil][col-1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col+1];
					char casilla_arriba_resultado = mymapaprovisional[fil+1][col];
					char casilla_detras_resultado = mymapaprovisional[fil-1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
				if (mymapatiempo[fil][col-1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil-1][col];
					int casilla_izquierda = mymapatiempo[fil+1][col];
					int casilla_arriba = mymapatiempo[fil][col-1];
					int casilla_detras = mymapatiempo[fil][col+1];

					char casilla_derecha_resultado = mymapaprovisional[fil-1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil+1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col-1];
					char casilla_detras_resultado = mymapaprovisional[fil][col+1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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

					char casilla_derecha_resultado = mymapaprovisional[fil][col+1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col-1];
					char casilla_arriba_resultado = mymapaprovisional[fil-1][col];
					char casilla_detras_resultado = mymapaprovisional[fil+1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
				if (mymapatiempo[fil][col+1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil+1][col];
					int casilla_izquierda = mymapatiempo[fil-1][col];
					int casilla_arriba = mymapatiempo[fil][col+1];
					int casilla_detras = mymapatiempo[fil][col-1];

					char casilla_derecha_resultado = mymapaprovisional[fil+1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil-1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col+1];
					char casilla_detras_resultado = mymapaprovisional[fil][col-1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
				if (mymapatiempo[fil+1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col-1];
					int casilla_izquierda = mymapatiempo[fil][col+1];
					int casilla_arriba = mymapatiempo[fil+1][col];
					int casilla_detras = mymapatiempo[fil-1][col];

					char casilla_derecha_resultado = mymapaprovisional[fil][col-1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col+1];
					char casilla_arriba_resultado = mymapaprovisional[fil+1][col];
					char casilla_detras_resultado = mymapaprovisional[fil-1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
				if (mymapatiempo[fil][col-1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil-1][col];
					int casilla_izquierda = mymapatiempo[fil+1][col];
					int casilla_arriba = mymapatiempo[fil][col-1];
					int casilla_detras = mymapatiempo[fil][col+1];

					char casilla_derecha_resultado = mymapaprovisional[fil-1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil+1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col-1];
					char casilla_detras_resultado = mymapaprovisional[fil][col+1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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

					char casilla_derecha_resultado = mymapaprovisional[fil][col+1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col-1];
					char casilla_arriba_resultado = mymapaprovisional[fil-1][col];
					char casilla_detras_resultado = mymapaprovisional[fil+1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

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
				if (mymapatiempo[fil][col+1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil+1][col];
					int casilla_izquierda = mymapatiempo[fil-1][col];
					int casilla_arriba = mymapatiempo[fil][col+1];
					int casilla_detras = mymapatiempo[fil][col-1];

					char casilla_derecha_resultado = mymapaprovisional[fil+1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil-1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col+1];
					char casilla_detras_resultado = mymapaprovisional[fil][col-1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

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
				if (mymapatiempo[fil+1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col-1];
					int casilla_izquierda = mymapatiempo[fil][col+1];
					int casilla_arriba = mymapatiempo[fil+1][col];
					int casilla_detras = mymapatiempo[fil-1][col];

					char casilla_derecha_resultado = mymapaprovisional[fil][col-1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col+1];
					char casilla_arriba_resultado = mymapaprovisional[fil+1][col];
					char casilla_detras_resultado = mymapaprovisional[fil-1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

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
				if (mymapatiempo[fil][col-1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil-1][col];
					int casilla_izquierda = mymapatiempo[fil+1][col];
					int casilla_arriba = mymapatiempo[fil][col-1];
					int casilla_detras = mymapatiempo[fil][col+1];

					char casilla_derecha_resultado = mymapaprovisional[fil-1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil+1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col-1];
					char casilla_detras_resultado = mymapaprovisional[fil][col+1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
	}
}

if (ultimaAccion == actIDLE && sensores.terreno[0] != 'X' && contador_tiempo > 1){
	if (sensores.terreno[2] != 'P' && sensores.terreno[2] != 'M'){
		if (sensores.terreno[2] == 'A' && bikini_conseguido == false){
			int accion_aleatoria = rand() % 2;
			if (accion_aleatoria == 0){
				accion = actTURN_L;
			}else if (accion_aleatoria == 1){
				accion = actTURN_R;
			}
		}else if (sensores.terreno[2] == 'B' && zapatilla_conseguida == false){
			int accion_aleatoria = rand() % 2;
			if (accion_aleatoria == 0){
				accion = actTURN_L;
			}else if (accion_aleatoria == 1){
				accion = actTURN_R;
			}
		}else{
			accion = actFORWARD;
		}
	}else{
		int accion_aleatoria = rand() % 2;
		if (accion_aleatoria == 0){
			accion = actTURN_L;
		}else if (accion_aleatoria == 1){
			accion = actTURN_R;
		}
	}
}
	//Recordar la última acción
	ultimaAccion = accion;

	//Devolver la acción
	return accion;
	}else if (sensores.nivel >= 2){
		Action accion = actIDLE;

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
			if (sentido == 0){
				mymapatiempo[fil-1][col-1] = 999999;
			}else if(sentido == 1){
				mymapatiempo[fil-1][col+1] = 999999;
			}else if(sentido == 2){
				mymapatiempo[fil+1][col+1] = 999999;
			}else if(sentido == 3){
				mymapatiempo[fil+1][col-1] = 999999;
			}
		}
		if (sensores.terreno[2] == 'M' or sensores.terreno[2] == 'P'){
			if (sentido == 0){
				mymapatiempo[fil-1][col] = 999999;
			}else if(sentido == 1){
				mymapatiempo[fil][col+1] = 999999;
			}else if(sentido == 2){
				mymapatiempo[fil+1][col] = 999999;
			}else if(sentido == 3){
				mymapatiempo[fil][col-1] = 999999;
			}
		}
		if (sensores.terreno[3] == 'M' or sensores.terreno[3] == 'P'){
			if (sentido == 0){
				mymapatiempo[fil-1][col+1] = 999999;
			}else if(sentido == 1){
				mymapatiempo[fil+1][col+1] = 999999;
			}else if(sentido == 2){
				mymapatiempo[fil+1][col-1] = 999999;
			}else if(sentido == 3){
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
			if (sentido == 0){
				if (mymapatiempo[fil-1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col+1];
					int casilla_izquierda = mymapatiempo[fil][col-1];
					int casilla_arriba = mymapatiempo[fil-1][col];
					int casilla_detras = mymapatiempo[fil-1][col];
					
					char casilla_derecha_resultado = mymapaprovisional[fil][col+1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col-1];
					char casilla_arriba_resultado = mymapaprovisional[fil-1][col];
					char casilla_detras_resultado = mymapaprovisional[fil-1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')){
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
			}else if (sentido == 1){
				if (mymapatiempo[fil][col+1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil+1][col];
					int casilla_izquierda = mymapatiempo[fil-1][col];
					int casilla_arriba = mymapatiempo[fil][col+1];
					int casilla_detras = mymapatiempo[fil][col-1];

					char casilla_derecha_resultado = mymapaprovisional[fil+1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil-1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col+1];
					char casilla_detras_resultado = mymapaprovisional[fil][col-1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
			}else if (sentido == 2){
				if (mymapatiempo[fil+1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col-1];
					int casilla_izquierda = mymapatiempo[fil][col+1];
					int casilla_arriba = mymapatiempo[fil+1][col];
					int casilla_detras = mymapatiempo[fil-1][col];

					char casilla_derecha_resultado = mymapaprovisional[fil][col-1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col+1];
					char casilla_arriba_resultado = mymapaprovisional[fil+1][col];
					char casilla_detras_resultado = mymapaprovisional[fil-1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
			}else if (sentido == 3){
				if (mymapatiempo[fil][col-1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil-1][col];
					int casilla_izquierda = mymapatiempo[fil+1][col];
					int casilla_arriba = mymapatiempo[fil][col-1];
					int casilla_detras = mymapatiempo[fil][col+1];

					char casilla_derecha_resultado = mymapaprovisional[fil-1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil+1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col-1];
					char casilla_detras_resultado = mymapaprovisional[fil][col+1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A' or casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A' or casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A' or casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A' or casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
	}else if (zapatilla_conseguida == true && bikini_conseguido == false){
		buscar_botin(sensores);	//busca zapatilla y bikini

		if (!plan_botin.empty()){
			accion = plan_botin.front();
			plan_botin.pop();
		}else{
			if (sentido == 0){
				if (mymapatiempo[fil-1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col+1];
					int casilla_izquierda = mymapatiempo[fil][col-1];
					int casilla_arriba = mymapatiempo[fil-1][col];
					int casilla_detras = mymapatiempo[fil+1][col];

					char casilla_derecha_resultado = mymapaprovisional[fil][col+1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col-1];
					char casilla_arriba_resultado = mymapaprovisional[fil-1][col];
					char casilla_detras_resultado = mymapaprovisional[fil+1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
			}else if (sentido == 1){
				if (mymapatiempo[fil][col+1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil+1][col];
					int casilla_izquierda = mymapatiempo[fil-1][col];
					int casilla_arriba = mymapatiempo[fil][col+1];
					int casilla_detras = mymapatiempo[fil][col-1];

					char casilla_derecha_resultado = mymapaprovisional[fil+1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil-1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col+1];
					char casilla_detras_resultado = mymapaprovisional[fil][col-1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
			}else if (sentido == 2){
				if (mymapatiempo[fil+1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col-1];
					int casilla_izquierda = mymapatiempo[fil][col+1];
					int casilla_arriba = mymapatiempo[fil+1][col];
					int casilla_detras = mymapatiempo[fil-1][col];

					char casilla_derecha_resultado = mymapaprovisional[fil][col-1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col+1];
					char casilla_arriba_resultado = mymapaprovisional[fil+1][col];
					char casilla_detras_resultado = mymapaprovisional[fil-1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
			}else if (sentido == 3){
				if (mymapatiempo[fil][col-1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil-1][col];
					int casilla_izquierda = mymapatiempo[fil+1][col];
					int casilla_arriba = mymapatiempo[fil][col-1];
					int casilla_detras = mymapatiempo[fil][col+1];

					char casilla_derecha_resultado = mymapaprovisional[fil-1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil+1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col-1];
					char casilla_detras_resultado = mymapaprovisional[fil][col+1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'A'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'A'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'A'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'A'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
	}else if (zapatilla_conseguida == true && bikini_conseguido == true){
		buscar_botin(sensores);	//busca zapatilla, bikini y recargas
		if (!plan_botin.empty()){
			accion = plan_botin.front();
			plan_botin.pop();
		}else{
			if (sentido == 0){
				if (mymapatiempo[fil-1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col+1];
					int casilla_izquierda = mymapatiempo[fil][col-1];
					int casilla_arriba = mymapatiempo[fil-1][col];
					int casilla_detras = mymapatiempo[fil+1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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
			}else if (sentido == 1){
				if (mymapatiempo[fil][col+1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil+1][col];
					int casilla_izquierda = mymapatiempo[fil-1][col];
					int casilla_arriba = mymapatiempo[fil][col+1];
					int casilla_detras = mymapatiempo[fil][col-1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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
			}else if (sentido == 2){
				if (mymapatiempo[fil+1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col-1];
					int casilla_izquierda = mymapatiempo[fil][col+1];
					int casilla_arriba = mymapatiempo[fil+1][col];
					int casilla_detras = mymapatiempo[fil-1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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
			}else if (sentido == 3){
				if (mymapatiempo[fil][col-1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='B' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil-1][col];
					int casilla_izquierda = mymapatiempo[fil+1][col];
					int casilla_arriba = mymapatiempo[fil][col-1];
					int casilla_detras = mymapatiempo[fil][col+1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

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
			if (sentido == 0){
				if (mymapatiempo[fil-1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col+1];
					int casilla_izquierda = mymapatiempo[fil][col-1];
					int casilla_arriba = mymapatiempo[fil-1][col];
					int casilla_detras = mymapatiempo[fil+1][col];

					char casilla_derecha_resultado = mymapaprovisional[fil][col+1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col-1];
					char casilla_arriba_resultado = mymapaprovisional[fil-1][col];
					char casilla_detras_resultado = mymapaprovisional[fil+1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

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
			}else if (sentido == 1){
				if (mymapatiempo[fil][col+1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil+1][col];
					int casilla_izquierda = mymapatiempo[fil-1][col];
					int casilla_arriba = mymapatiempo[fil][col+1];
					int casilla_detras = mymapatiempo[fil][col-1];

					char casilla_derecha_resultado = mymapaprovisional[fil+1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil-1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col+1];
					char casilla_detras_resultado = mymapaprovisional[fil][col-1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

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
			}else if (sentido == 2){
				if (mymapatiempo[fil+1][col] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil][col-1];
					int casilla_izquierda = mymapatiempo[fil][col+1];
					int casilla_arriba = mymapatiempo[fil+1][col];
					int casilla_detras = mymapatiempo[fil-1][col];

					char casilla_derecha_resultado = mymapaprovisional[fil][col-1];
					char casilla_izquierda_resultado = mymapaprovisional[fil][col+1];
					char casilla_arriba_resultado = mymapaprovisional[fil+1][col];
					char casilla_detras_resultado = mymapaprovisional[fil-1][col];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

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
			}else if (sentido == 3){
				if (mymapatiempo[fil][col-1] == 0 && ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='K' or sensores.terreno[2]=='D' or sensores.terreno[2]=='X' or sensores.terreno[2]=='A') and (sensores.superficie[2]=='_'))){
					accion = actFORWARD;
				}else{
					int casilla_derecha = mymapatiempo[fil-1][col];
					int casilla_izquierda = mymapatiempo[fil+1][col];
					int casilla_arriba = mymapatiempo[fil][col-1];
					int casilla_detras = mymapatiempo[fil][col+1];

					char casilla_derecha_resultado = mymapaprovisional[fil-1][col];
					char casilla_izquierda_resultado = mymapaprovisional[fil+1][col];
					char casilla_arriba_resultado = mymapaprovisional[fil][col-1];
					char casilla_detras_resultado = mymapaprovisional[fil][col+1];

					if (sensores.superficie[2] != '_'){
						casilla_arriba += 999999;
					}

					if (casilla_derecha_resultado == 'B'){
						casilla_derecha += 3000;
					}
					if (casilla_izquierda_resultado == 'B'){
						casilla_izquierda += 3000;
					}
					if (casilla_arriba_resultado == 'B'){
						casilla_arriba += 3000;
					}
					if (casilla_detras_resultado == 'B'){
						casilla_detras += 3000;
					}

					int minimo = min(casilla_arriba, min(casilla_derecha, min(casilla_detras,  casilla_izquierda)));

					if (casilla_arriba == minimo && (((sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P')))){
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
	}
}

if (ultimaAccion == actIDLE && sensores.terreno[0] != 'X' && contador_tiempo > 1){
	if (sensores.terreno[2] != 'P' && sensores.terreno[2] != 'M'){
		if (sensores.terreno[2] == 'A' && bikini_conseguido == false){
			int accion_aleatoria = rand() % 2;
			if (accion_aleatoria == 0){
				accion = actTURN_L;
			}else if (accion_aleatoria == 1){
				accion = actTURN_R;
			}
		}else if (sensores.terreno[2] == 'B' && zapatilla_conseguida == false){
			int accion_aleatoria = rand() % 2;
			if (accion_aleatoria == 0){
				accion = actTURN_L;
			}else if (accion_aleatoria == 1){
				accion = actTURN_R;
			}
		}else{
			accion = actFORWARD;
		}
	}else{
		int accion_aleatoria = rand() % 2;
		if (accion_aleatoria == 0){
			accion = actTURN_L;
		}else if (accion_aleatoria == 1){
			accion = actTURN_R;
		}
	}
}
	//Recordar la última acción
	ultimaAccion = accion;

	//Devolver la acción
	return accion;

	}
}


int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}