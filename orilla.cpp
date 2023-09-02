/*
  Archivo: orilla.cpp
  Autores:
  - Manuel Alejandro Esparza Villa
  - Marcelo Alejandro García Millán
  Fecha creación: 26/04/2021
  Fecha última modificación: 03/10/2021
  Versión: 0.3
  Licencia: GNU-GPL
*/

#include "orilla.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Orilla::Orilla(string nombreLugar, vector <Individuo *> individuosDelLugar) : Lugar(nombreLugar, individuosDelLugar)
{
  
}

Orilla::~Orilla()
{
  
}