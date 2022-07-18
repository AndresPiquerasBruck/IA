#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>

struct estado {
  int fila;
  int columna;
  int orientacion;
  bool bikini;
  bool zapatilla;
};

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado
      hay_plan = false;
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      hay_plan = false;
      ubicado = false;
      ultima_action = actIDLE;
      fila_nivel4, col_nivel4, orientacion_nivel4 = 0;
      fila_nivel3 = 4;
      col_nivel3 = 4;
      zapatilla_3 = false;
      bikini_3 = false;
      anterior.bikini = false;
      anterior.zapatilla = 0;
      anterior.fila = false;
      anterior.columna = 0;
      anterior.fila = 0;
      anterior.orientacion= 0;
      destino1.bikini=false;
      destino1.columna=0;
      destino1.fila=0;
      destino1.orientacion=0;
      destino1.zapatilla=false;
      destino2.bikini=false;
      destino2.columna=0;
      destino2.fila=0;
      destino2.orientacion=0;
      destino2.zapatilla=false;
      destino3.bikini=false;
      destino3.columna=0;
      destino3.fila=0;
      destino3.orientacion=0;
      destino3.zapatilla=false;
      for (int i=0; i<3; i++){
        llegadas[i] = false;
      }
      fila_bateria = 0;
      col_bateria = 0;
      EMERGENCIA_LOBO = false;
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizaPlan(const estado &st, const list<Action> &plan);
    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}

  private:
    // Declarar Variables de Estado
    estado actual;
    list<estado> objetivos;
    list<Action> plan;
    bool hay_plan;
    bool ubicado;
    Action ultima_action;
    int fila_nivel4;
    int col_nivel4;
    int orientacion_nivel4;
    int fila_nivel3;
    int col_nivel3;
    bool bikini_3;
    bool zapatilla_3;
    estado anterior;
    estado destino1;
    estado destino2;
    estado destino3;
    bool primer_destino;
    bool segundo_destino;
    bool tercer_destino;
    bool llegadas[3];
    int fila_bateria;
    int col_bateria;
    bool EMERGENCIA_LOBO;

    // Métodos privados de la clase
    bool pathFinding(int level, const estado &origen, const list<estado> &destino, list<Action> &plan, Sensores sensores);
    bool pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Coste(const estado &origen, const estado &destino, list<Action> &plan,Sensores sensores);
    void dibujar_mapa(Sensores sensores);
    void dibujar_mapa4(Sensores sensores);
    void pinta_barranco_4();
    bool pathFinding_Reto1(const estado &origen, list<Action> &plan,Sensores sensores);
    bool pathFinding_Reto2(const estado &origen, const list<estado> &destino, list<Action> &plan, Sensores sensores);

    void PintaPlan(list<Action> plan);
    bool HayObstaculoDelante(estado &st);

    int coste_Bateria(unsigned char terreno, Action accion,estado st);

};

#endif
