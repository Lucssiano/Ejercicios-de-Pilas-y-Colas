/* 6) Desarrollar una función que dada una cola de personas (de cada persona se tiene dni y nombre)
y un dni, si esta persona está en la cola, la mueva al último lugar de la misma. */

#include <iostream>
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
void moverPersonas(NodoCola *&pri, NodoCola *&ult, Persona persona, int dni, int cantPersonasEnLaCola);

int main()
{
  NodoCola *priColaNums = NULL;
  NodoCola *ultColaNums = NULL;

  Persona pj;

  int i;

  for (i = 0; i < 5; i++)
  {
    cout << "Agregar un numero de dni: ";
    cin >> pj.dni;
    // cout << "Agregar el nombre de la persona: ";
    // cin >> pj.nombre;
    pj.nombre = "Carlos";
    encolar(priColaNums, ultColaNums, pj);
  }

  int dni = 4;
  moverPersonas(priColaNums, ultColaNums, pj, dni, i);

  return 0;
}

// Pensaba recorrer con dos punteros pero creo que eso es una lista , ¿deberia usar una pila para guardar los datos que desencolo?
// void moverPersonas(NodoCola *&pri, NodoCola *&ult, Persona persona, int dni)
// {
//   NodoCola *pRecorrido = pri;
//   NodoCola *pAntRecorrido;

//   while (pRecorrido->info.dni != dni || pRecorrido == NULL)
//     pRecorrido = pRecorrido->sig;

//   if (pRecorrido != NULL)
//   {
//   }
// }

void moverPersonas(NodoCola *&pri, NodoCola *&ult, Persona persona, int dni, int cantPersonasEnLaCola)
{
  while (pri != NULL && pri->info.dni != dni)
  {
    desencolar(pri, ult);
  }
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
