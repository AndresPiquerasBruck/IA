#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
#include <queue>
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      // Dar el valor inicial a las variables de estado
      fil = col = 0;
      brujula = 0;    //0 norte, 1 este, 2 sur, 3 oeste
      ultimaAccion = actIDLE;
      girar_derecha = false;
      bien_situado = false;
      bikini_conseguido = false;
      zapatilla_conseguida = false;
      for (int i=0;i<200;i++){
        for (int j=0;j<200;j++){
          mymapatiempo[i][j] = 0;
          //nivel 1
          mymapaprovisional[i][j] = '?';
          //////
        }
      }
      contador_tiempo = 0;
      giroR_pendiente = false;

      //nivel 1
      ubicado = false;
      repos_c = 0;
      repos_f = 0;

      //nivel 2
      sentido = 0;
      ult_sentido = 0;

      //truquito
      num_b = 0;
			num_a = 0;
			num_p = 0;
			num_s = 0;
			num_t = 0;
		  num_m = 0;
			num_g = 0;
			num_k = 0;
			num_d = 0;
			num_x = 0;
      trucompletado = false;
      bool ubicado_primeravez = false;
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    bool buscar_botin(Sensores sensores);
    bool buscar_recarga(Sensores sensores);
    void pintar_mapa(Sensores sensores);
    Action moverse_tiempo(Sensores sensores);
    Action minimo_bikini(Sensores sensores, char izquierda, char derecha, char arriba, char abajo, int izquierda_tiempo, int derecha_tiempo, int arriba_tiempo, int abajo_tiempo);
    Action minimo_zapatilla(Sensores sensores, char izquierda, char derecha, char arriba, char abajo, int izquierda_tiempo, int derecha_tiempo, int arriba_tiempo, int abajo_tiempo);
    Action minimo_nada(Sensores sensores, char izquierda, char derecha, char arriba, char abajo, int izquierda_tiempo, int derecha_tiempo, int arriba_tiempo, int abajo_tiempo);
  private:
  
  // Declarar aquí las variables de estado
  int fil, col, brujula;
  Action ultimaAccion;
  bool girar_derecha;
  bool bien_situado;
  queue<Action> plan_botin;
  bool zapatilla_conseguida;
  bool bikini_conseguido;
  long int mymapatiempo[200][200];
  long int contador_tiempo;
  bool giroR_pendiente;
  //nivel 1
  char mymapaprovisional[200][200];
  bool ubicado;
  int repos_c;
  int repos_f;
  //nivel 2
  int sentido;
  int ult_sentido;

  //truquito
  int num_b;
  int num_a;
  int num_p;
  int num_s;
  int num_t;
  int num_m;
  int num_g;
  int num_k;
  int num_d;
  int num_x;
  bool trucompletado;
  bool ubicado_primeravez;
  
};

#endif