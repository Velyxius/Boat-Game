/*
  Archivo: jugador.cpp
  Autores:
  - Manuel Alejandro Esparza Villa
  - Marcelo Alejandro García Millán
  Fecha creación: 26/04/2021
  Fecha última modificación: 11/10/2021
  Versión: 0.4
  Licencia: GNU-GPL
*/

#include "jugador.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Jugador::Jugador(Orilla *orillaIzquierda, Barca *barca, Orilla *orillaDerecha)
{
  this->orillaIzquierda = orillaIzquierda;
  this->barca = barca;
  this->orillaDerecha = orillaDerecha;
}

Jugador::~Jugador()
{
  
}

void Jugador::moverBarca(string comando)
{
  if ( (comando == "B" or comando == "b") and barca->sePuedeMover() == true)
  {
    if (barca->enQueOrillaEsta() == "IZQUIERDA")
    {
      barca->barcaEstaEn(orillaDerecha);
    }
    else if (barca->enQueOrillaEsta() == "DERECHA")
    {
      barca->barcaEstaEn(orillaIzquierda);
    }
  }
  else if ( (comando == "B" or comando == "b") and barca->sePuedeMover() == false )
  {
    cout << endl << "¡ERROR! No es posible mover la barca. Intente con otro movimiento" << endl;
  }
}

void Jugador::subirIndividuo(Individuo *ind)
{
  if (barca->enQueOrillaEsta() == ind->getLugar()) // El individuo se intenta subir, y hay barca
  {
    if (barca->sePuedeSubir()) // Hay espacio en la barca, el individuo se puede subir
    {
      if (barca->enQueOrillaEsta() == "IZQUIERDA")
      {
        orillaIzquierda->sacarIndividuo(ind);
        orillaIzquierda->sePuedenComerLosIndividuos();
      }
      if (barca->enQueOrillaEsta() == "DERECHA")
      {
        orillaDerecha->sacarIndividuo(ind);
        orillaDerecha->sePuedenComerLosIndividuos();
      }
      barca->agregarIndividuo(ind);
      ind->setLugar("BARCA");
      barca->sePuedenComerLosIndividuos();
    }
    else // No hay espacio en la barca, el individuo no se puede subir
    {
      cout << endl << "¡ERROR! La barca está llena, no es posible subirse. Intente con otro movimiento" << endl;
    }
  }
  else // El individuo se intenta subir pero no hay barca, entonces se ahoga y muere
  {
    ind->muere();
    cout << endl << "¡OOPS! " << ind->getNombre() << " se ha ahogado!" << endl;
  }
}

void Jugador::bajarIndividuo(Individuo *ind)
{
  if (barca->enQueOrillaEsta() == "DERECHA") // Si la barca está en la orilla derecha, los individuos se bajan a esa orilla
  {
    orillaDerecha->agregarIndividuo(ind);
    ind->setLugar("DERECHA");
    barca->sacarIndividuo(ind);
    orillaDerecha->sePuedenComerLosIndividuos();
  }
  if (barca->enQueOrillaEsta() == "IZQUIERDA") // Si la barca está en la orilla izquierda, los individuos se bajan en esa orilla
  {
    orillaIzquierda->agregarIndividuo(ind);
    ind->setLugar("IZQUIERDA");
    barca->sacarIndividuo(ind);
    orillaIzquierda->sePuedenComerLosIndividuos();
  }
}

void Jugador::moverIndividuo(string comando)
{
  // Pasamos las minúsculas a maýusculas para que se puedan usar ambas
  if (comando == "l")
  {
    comando = "L";
  }
  else if (comando == "r")
  {
    comando = "R";
  }
  else if (comando == "c")
  {
    comando = "C";
  }
  else if (comando == "z")
  {
    comando = "Z";
  }
  else if (comando == "b")
  {
    comando = "B";
  }

  if (orillaIzquierda->getNombreDeIndividuoConElComando(comando) != "N/A")
  {
    string nombre = orillaIzquierda->getNombreDeIndividuoConElComando(comando);
    subirIndividuo(orillaIzquierda->getIndividuo(nombre));
  }
  else if (barca->getNombreDeIndividuoConElComando(comando) != "N/A")
  {
    string nombre = barca->getNombreDeIndividuoConElComando(comando);
    bajarIndividuo(barca->getIndividuo(nombre));
  }
  else if (orillaDerecha->getNombreDeIndividuoConElComando(comando) != "N/A")
  {
    string nombre = orillaDerecha->getNombreDeIndividuoConElComando(comando);
    subirIndividuo(orillaDerecha->getIndividuo(nombre));
  }
  else if (comando != "B")
  {
    cout << "¡ERROR! Comando no válido" << endl;
  }
}

void Jugador::imprimir()
{
  if (barca->enQueOrillaEsta() == "IZQUIERDA")
  {
    cout << endl << "\t│\t IZQUIERDA  \t│\t   BARCA    \t│\t             \t│\t   DERECHA  \t│"; 
  }
  if (barca->enQueOrillaEsta() == "DERECHA")
  {
    cout << endl << "\t│\t IZQUIERDA  \t│\t            \t│\t    BARCA    \t│\t   DERECHA   \t│";
  }

  for (int I = 0; I <= 3; I++)
  {
    if(barca->enQueOrillaEsta() == "IZQUIERDA")
    {
      cout << endl << "\t│\t\t" << orillaIzquierda->getNombreDeIndividuoConIndice(I) << "\t\t│\t\t" << barca->getNombreDeIndividuoConIndice(I) << "\t\t│\t             \t│\t\t" << orillaDerecha->getNombreDeIndividuoConIndice(I) << "\t\t│";
    }
    
    if (barca->enQueOrillaEsta() == "DERECHA")
    {
      cout << endl << "\t│\t\t" << orillaIzquierda->getNombreDeIndividuoConIndice(I) << "\t\t│\t             \t│\t\t" << barca->getNombreDeIndividuoConIndice(I) << "\t\t│\t\t" << orillaDerecha->getNombreDeIndividuoConIndice(I) << "\t\t│";
    }
  }
  cout << endl;
}

string Jugador::iniciarJuego()
{
  bool victoria = false;
  bool derrota = false;
  string mensaje;

  // El juego se ejecuta hasta que el jugador gane o pierda
  while (victoria == false and derrota == false)
  {
    imprimir();

    string comando;
    cout << endl;
    cout << "¿Qué acción desea realizar?: ";
    getline(cin, comando);

    moverBarca(comando);
    moverIndividuo(comando);

    if (barca->derrota() == true or orillaIzquierda->derrota() == true or orillaDerecha->derrota() == true)
    {
      derrota = true;
      mensaje = "\n¡PERDISTE! Intentalo de nuevo";
    }

    if (orillaDerecha->getCantidadIndividuos() == 4)
    {
      victoria = true;
      mensaje = "\n¡GANASTE! Felicidades, gracias por jugar";
    }
  }

  imprimir();
  return mensaje;
}