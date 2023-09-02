/*
  Archivo: barca.h
  Autores:
  - Manuel Alejandro Esparza Villa
  - Marcelo Alejandro García Millán
  Fecha creación: 26/04/2021
  Fecha última modificación: 11/10/2021
  Versión: 0.4
  Licencia: GNU-GPL
*/

/*
  Clase: Barca
  Intención: Realizar la barca donde van a viajar los individuos
  Relaciones:
  - Es parecido a un lugar
  - Conoce a los individuos
  - Conoce las orillas
*/

#include "lugar.h"
#include "orilla.h"
#include <vector>
#include <string>
using namespace std;

#ifndef BARCA_H
#define BARCA_H

class Barca : public Lugar
{
  // Atributos
  protected:
    // Con este puntero puedo conectar la barca con la orilla en la que está
    Lugar *conectadoA;
  // Métodos
  public:
    Barca(string nombreLugar, vector <Individuo*> individuosDelLugar, Orilla *conectadoA);
    virtual ~Barca();
    virtual bool sePuedeSubir(); // Verifica si se puede subir a la barca
    virtual bool sePuedeMover(); // Verifica si la barca se puede mover de una orilla a otra
    virtual string enQueOrillaEsta(); // Retorna el nombre de la orilla en la que está la barca
    virtual void barcaEstaEn(Orilla *orilla); // Cambia la orilla a la que está ligada la barca
};


#else
class Barca;
#endif