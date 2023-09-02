/*
  Archivo: orilla.h
  Autores:
  - Manuel Alejandro Esparza Villa
  - Marcelo Alejandro García Millán
  Fecha creación: 26/04/2021
  Fecha última modificación: 03/10/2021
  Versión: 0.3
  Licencia: GNU-GPL
*/

/*
  Clase: Orilla
  Intención: Construir las orillas donde se bajan los individuos
  Relaciones:
  - Es un lugar
  - Conoce los individuos
  - Conoce la barca
*/

#include "lugar.h"
using namespace std;

#ifndef ORILLA_H
#define ORILLA_H

class Orilla : public Lugar
{
  // Atributos
  protected:
  
  // Métodos
  public:
    Orilla(string nombreLugar, vector <Individuo *> individuosDelLugar);
    virtual ~Orilla();
};

#else
class Orilla;
#endif
