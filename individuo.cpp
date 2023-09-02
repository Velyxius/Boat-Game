/*
  Archivo: individuo.cpp
  Autores:
  - Manuel Alejandro Esparza Villa
  - Marcelo Alejandro García Millán
  Fecha creación: 26/04/2021
  Fecha última modificación: 11/10/2021
  Versión: 0.4
  Licencia: GNU-GPL
*/

#include "individuo.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Individuo::Individuo(string nombre, bool estaVivo, string presa, string comando, string lugar)
{
  this->nombre = nombre;
  this->estaVivo = true;
  this->presa = presa;
  this->comando = comando;
  this->lugar = lugar;
}

Individuo::~Individuo()
{
  
}

string Individuo::getNombre()
{
  return nombre;
}

bool Individuo::getEstadoVida()
{
  return estaVivo;
}

string Individuo::getPresa()
{
  return presa;
}
  
string Individuo::getComando()
{
  return comando;
}

string Individuo::getLugar()
{
  return lugar;
}

void Individuo::setLugar(string place)
{
  lugar = place;
}

void Individuo::muere()
{
  estaVivo = false;
}