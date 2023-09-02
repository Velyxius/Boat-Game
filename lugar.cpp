/*
  Archivo: lugar.cpp
  Autores:
  - Manuel Alejandro Esparza Villa
  - Marcelo Alejandro García Millán
  Fecha creación: 26/04/2021
  Fecha última modificación: 03/10/2021
  Versión: 0.3
  Licencia: GNU-GPL
*/

#include "lugar.h"
#include "individuo.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Lugar::Lugar(string nombreLugar, vector <Individuo *> individuosDelLugar)
{
  this->nombreLugar = nombreLugar;

  for (int I = 0; I < individuosDelLugar.size(); I++)
  {
    this->individuosDelLugar.push_back(individuosDelLugar[I]);
  }
}

Lugar::~Lugar()
{
  for (int I = 0; I < individuosDelLugar.size(); I++)
  {
    delete individuosDelLugar[I];
    individuosDelLugar[I] = nullptr;
  }
  individuosDelLugar.clear();
}

string Lugar::getNombreLugar()
{
  return nombreLugar;
}

int Lugar::getCantidadIndividuos()
{
  return individuosDelLugar.size();
}

Individuo *Lugar::getIndividuo(string nombre)
{
  Individuo *ind = nullptr;
  for (int I = 0; I < individuosDelLugar.size(); I++)
  {
    if (individuosDelLugar[I]->getNombre() == nombre)
    {
      ind = individuosDelLugar[I];
      return ind;
    }
  }
  return nullptr;
}

void Lugar::agregarIndividuo(Individuo *ind)
{
  individuosDelLugar.push_back(ind);
}

void Lugar::sacarIndividuo(Individuo *ind)
{
  for (int I = 0; I < individuosDelLugar.size(); I++)
  {
    if (individuosDelLugar[I] == ind)
    {
      individuosDelLugar.erase(individuosDelLugar.begin() + I);
      break; 
    }
  }
}

void Lugar::sePuedenComerLosIndividuos()
{
  // Si está el robot en el lugar, los individuos no se pueden comer entre sí
  bool estaElRobot = false;
  for (int I = 0; I < individuosDelLugar.size(); I++)
  {
    if (individuosDelLugar[I]->getNombre() == "ROBOT")
    {
      estaElRobot = true;
    }
  }

  if (estaElRobot == true)
  {
    // No hacer nada
  }
  else if (estaElRobot == false)
  {
    for (int I = 0; I < individuosDelLugar.size(); I++) // Depredador
    {
      for (int J = 0; J < individuosDelLugar.size(); J++) // Presa
      {
        if (individuosDelLugar[I]->getPresa() == individuosDelLugar[J]->getNombre())
        {
          individuosDelLugar[J]->muere();
          cout << endl << "¡OOPS! " << individuosDelLugar[I]->getNombre() << " se ha comido a " << individuosDelLugar[J]->getNombre() << endl;
        }
      }
    }
  }
}

string Lugar::getNombreDeIndividuoConIndice(int I)
{
  if (individuosDelLugar.size() > I)
  {
    string nombre = individuosDelLugar[I]->getNombre();
    return nombre;
  }
  return "     ";
}

string Lugar::getNombreDeIndividuoConElComando(string comando)
{
  string nombre = "N/A";
  if (individuosDelLugar.size() > 0)
  {
    for (int I = 0; I < individuosDelLugar.size(); I++)
    {
      if (individuosDelLugar[I]->getComando() == comando)
      {
        nombre = individuosDelLugar[I]->getNombre();
        return nombre;
      }
    }
  }
  return nombre;
}

bool Lugar::derrota()
{
  for (int I = 0; I < individuosDelLugar.size(); I++)
  {
    if (individuosDelLugar[I]->getEstadoVida() == false)
    {
      return true;
    }
  }
  return false;
}