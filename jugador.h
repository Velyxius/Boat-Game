/*
  Archivo: jugador.h
  Autores:
  - Manuel Alejandro Esparza Villa
  - Marcelo Alejandro García Millán
  Fecha creación: 26/04/2021
  Fecha última modificación: 03/10/2021
  Versión: 0.3
  Licencia: GNU-GPL
*/

/*
  Clase: Jugador
  Intención: Hacer que la persona juegue manejando los individuos 
  Relaciones:
  - Conoce a los individuos
  - Conoce a los lugares (Barca y Orilla)
*/

#ifndef JUGADOR_H
#define JUGADOR_H

#include "lugar.h"
#include "barca.h"
#include "orilla.h"
#include <string>
#include <vector>
using namespace std;

class Jugador
{
  // Atributos
  protected:
    Orilla *orillaIzquierda;
    Barca *barca;
    Orilla *orillaDerecha;
  // Métodos
  public:
    Jugador(Orilla *orillaIzquierda, Barca *barca, Orilla *orillaDerecha);
    virtual ~Jugador();
    virtual void moverBarca(string comando); // Mueve la barca
    virtual void subirIndividuo(Individuo *ind); // Sube un individuo a la barca (si se puede)
    virtual void bajarIndividuo(Individuo *ind); // Baja un individuo de la barca
    virtual void moverIndividuo(string comando); // Mueve a un individuo de según el comando dado
    virtual void imprimir(); // Imprime el estado del juego y los movimientos
    virtual string iniciarJuego(); // Inicia el juego
};

#else
class Jugador;
#endif