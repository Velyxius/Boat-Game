/*
  Archivo: lugar.h
  Autores:
  - Manuel Alejandro Esparza Villa
  - Marcelo Alejandro García Millán
  Fecha creación: 26/04/2021
  Fecha última modificación: 03/10/2021
  Versión: 0.3
  Licencia: GNU-GPL
*/

/*
  Clase: Lugar
  Intención: Identificar y usar los lugares del juego (orillas y barca)
  Relaciones:
  - Conoce los individuos
  - Es clase base de Barca y Orilla
*/

#include <vector>
#include <string>
#include "individuo.h"
using namespace std;

#ifndef LUGAR_H
#define LUGAR_H

class Lugar
{
  // Atributos
  protected:
    string nombreLugar;
    vector <Individuo *> individuosDelLugar;

  // Métodos  
  public:
    Lugar(string nombreLugar, vector <Individuo *> individuosDelLugar);
    virtual ~Lugar();
    virtual string getNombreLugar(); // Retorna el nombre del lugar
    virtual int getCantidadIndividuos(); // Retorna la cantidad de individuos del lugar (size del vector)
    virtual Individuo *getIndividuo(string nombre); // Busca un individuo en el vector de individuos del lugar; en caso de que esté ahí, lo retorna
    virtual void agregarIndividuo(Individuo *ind); // Agrega un individuo al vector del lugar
    virtual void sacarIndividuo (Individuo *ind); // Saca a un indiviuo del vector del lugar
    virtual void sePuedenComerLosIndividuos(); // Verifica si un individuo puede comer a otro
    virtual string getNombreDeIndividuoConIndice(int I); // Este método busca a un individuo en el vector de individuos de acuerdo a la posición del individuo en el vector, y lo retorna
    virtual string getNombreDeIndividuoConElComando(string comando); // Este método conecta el comando con el nombre del individuo. De acuerdo al comando, retorna el nombre del individuo al que está asociado el comando
    virtual bool derrota(); // Verifica si hay un individuo muerto en el lugar, en caso de que haya uno, retorna true, caso contrario, retorna false
};

#else
class Lugar;
#endif