/*
  Archivo: barca.cpp
  Autores:
  - Manuel Alejandro Esparza Villa
  - Marcelo Alejandro García Millán
  Fecha creación: 26/04/2021
  Fecha última modificación: 11/10/2021
  Versión: 0.4
  Licencia: GNU-GPL
*/

#include "barca.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Barca::Barca(string nombreLugar, vector <Individuo *> individuosDelLugar, Orilla *conectadoA) : Lugar(nombreLugar, individuosDelLugar)
{
  this->conectadoA = conectadoA;
}

Barca::~Barca()
{
  
}

bool Barca::sePuedeSubir()
{
  // Se pueden subir hasta 2 individuos a la barca 
  if (individuosDelLugar.size() < 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Barca::sePuedeMover()
{
  // La barca se puede mover si hay hasta 2 individuos en ella y está el robot para manejarla
  if (individuosDelLugar.size() <= 2)
  {
    for (int I = 0; I < individuosDelLugar.size(); I++)
    {
      if (individuosDelLugar[I]->getNombre() == "ROBOT")
      {
        return true;
      }
    }
  }
  return false;
}

string Barca::enQueOrillaEsta()
{
  return conectadoA->getNombreLugar();
}

void Barca::barcaEstaEn(Orilla *orilla)
{
  conectadoA = orilla;
}