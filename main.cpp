/*
  Archivo: main.cpp
  Autores:
  - Manuel Alejandro Esparza Villa
  - Marcelo Alejandro García Millán
  Fecha creación: 26/04/2021
  Fecha última modificación: 11/10/2021
  Versión: 0.4
  Licencia: GNU-GPL
*/

#include "barca.h"
#include "individuo.h"
#include "jugador.h"
#include "lugar.h"
#include "orilla.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
  // Creamos de forma dinámica los individuos
  Individuo *robot = new Individuo("ROBOT", true, "N/A","R", "IZQUIERDA");
  Individuo *lechuga = new Individuo("LECHUGA", true, "N/A","L", "IZQUIERDA");
  Individuo *conejo = new Individuo("CONEJO", true, "LECHUGA","C", "IZQUIERDA");
  Individuo *zorro = new Individuo("ZORRO", true, "CONEJO","Z", "IZQUIERDA");

  // Creamos de forma dinámica los vectores por cada lugar

  // Agregamos los individuos al vector de objetos
  vector <Individuo *> individuosIzquierda = {robot, lechuga, conejo, zorro};
  vector <Individuo *> individuosBarca;
  vector <Individuo *> individuosDerecha;

  // Creamos de forma dinámica los lugares
  Orilla *orillaIzquierda = new Orilla("IZQUIERDA", individuosIzquierda);
  Orilla *orillaDerecha = new Orilla("DERECHA", individuosDerecha);
  Barca *barca = new Barca("BARCA", individuosBarca, orillaIzquierda);

  // Creamos de forma dinámica Jugador
  Jugador *jugador = new Jugador(orillaIzquierda, barca, orillaDerecha);

  cout << "Juego: LA BARCA" << endl << endl << "Objetivo: Hacer llegar vivos al robot, el conejo, la lechuga y el zorro a la orilla derecha" << endl << "Recuerda que el conejo se come la lechuga y el zorro se come al conejo si se quedan solos." << endl << endl;

  cout << "Instrucciones del juego:" << endl << "B: la Barca se mueve a la otra orilla" << endl << "R: el Robot salta de/a la barca" << endl << "Z: el Zorro salta de/a la barca" << endl << "C: el Conejo salta de/a la barca" << endl << "L: la Lechuga salta de/a la barca" << endl;

  // Iniciamos el Juego
  cout << jugador->iniciarJuego();

  // Devolvemos la memoria (Excepto los individuos, ya que esos están dentro de los vectores de individuos de los lugares, se borran en el destructor de lugar)
  delete orillaIzquierda;
  orillaIzquierda = nullptr;
  delete orillaDerecha;
  orillaDerecha = nullptr;
  delete barca;
  barca = nullptr;
  delete jugador;
  jugador = nullptr;
}