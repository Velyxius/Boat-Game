/*
  Archivo: individuo.h
  Autores:
  - Manuel Alejandro Esparza Villa
  - Marcelo Alejandro García Millán
  Fecha creación: 26/04/2021
  Fecha última modificación: 03/10/2021
  Versión: 0.3
  Licencia: GNU-GPL
*/

/*
  Clase: Individuo
  Intención: Crear los diferentes individuos, es decir, el conejo, el zorro, la lechuga y el robot
  Relaciones:
  - Conoce los individuos que se puede comer
  - Conoce los lugares (Orilla y Barca)
*/

#include <string>
using namespace std;

#ifndef INDIVIDUO_H
#define INDIVIDUO_H

class Individuo
{
  // Atributos
  protected:
    string nombre;
    bool estaVivo;
    string presa;
    string comando;
    string lugar;
    
  // Métodos
  public:
    Individuo(string nombre, bool estaVivo, string presa, string comando, string lugar);
    virtual ~Individuo();
    // Los get retornan los atributos del individuo
    virtual string getNombre();
    virtual bool getEstadoVida();
    virtual string getPresa();
    virtual string getComando();
    virtual string getLugar();
    virtual void setLugar(string place); // Cambia el lugar del individuo
    virtual void muere(); // Cambia el estado de vida del individuo de true a false
};


#else
class Individuo;
#endif