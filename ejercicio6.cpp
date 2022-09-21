/* 6) Desarrollar una función que dada una cola de personas (de cada persona se tiene dni y nombre)
y un dni, si esta persona está en la cola, la mueva al último lugar de la misma. */

// Tengo una cola con 6 personas por ej (con su respectivo dni y nombre), me viene una nueva persona con estos datos, entonces verifico si está en la cola, si está la muevo al ultimo lugar (?)

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Persona
{
  int dni;
  string nombre;
};

struct NodoCola
{
  Persona info;
  NodoCola *sig;
};

void encolar(NodoCola *&pri, NodoCola *&ult, Persona persona);
Persona desencolar(NodoCola *&pri, NodoCola *&ult);

int main()
{
  NodoCola *priColaNums = NULL;
  NodoCola *ultColaNums = NULL;

  int num;

  // for (int i = 0; i < 6; i++)
  // {
  //   cout << "Agregar un numero: ";
  //   cin >> num;
  //   encolar(priColaNums, ultColaNums, num);
  // }

  // if (ejercicio5(priColaNums, ultColaNums))
  //   cout << "Pudo desencolar 4 veces, VERDADERO";
  // else
  //   cout << "No pudo desencolar 4 veces, FALSO";

  return 0;
}

void encolar(NodoCola *&pri, NodoCola *&ult, Persona persona)
{
  NodoCola *p = new NodoCola;
  p->info = persona;
  p->sig = NULL;
  if (ult != NULL)
    ult->sig = p;
  else
    pri = p;
  ult = p;
}

Persona desencolar(NodoCola *&pri, NodoCola *&ult)
{
  Persona pers;
  NodoCola *p = pri;
  pri = p->sig;
  pers = p->info;
  delete p;
  if (pri == NULL)
    ult = NULL;
  return pers;
}
