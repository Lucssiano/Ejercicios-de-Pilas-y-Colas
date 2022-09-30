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
void moverPersonas(NodoCola *&pri, NodoCola *&ult, int dni);
void moverPersonas2(NodoCola *&pri, NodoCola *&ult, int dni);

int main()
{
  NodoCola *priColaNums = NULL;
  NodoCola *ultColaNums = NULL;

  Persona pj;

  for (int i = 0; i < 5; i++)
  {
    cout << "Agregar un numero de dni: ";
    cin >> pj.dni;
    // cout << "Agregar el nombre de la persona: ";
    // cin >> pj.nombre;
    pj.nombre = "Carlos";
    encolar(priColaNums, ultColaNums, pj);
  }

  int dni = 1;
  // moverPersonas(priColaNums, ultColaNums, dni);
  moverPersonas2(priColaNums, ultColaNums, dni);

  return 0;
}

// 1 2 3 4 5
// 3
// 1 2 4 5 3

// void moverPersonas(NodoCola *&pri, NodoCola *&ult, int dni)
// {
//   NodoCola *priNuevaCola = NULL;
//   NodoCola *ultNuevaCola = NULL;

//   Persona personaAMover;

//   while (pri != NULL)
//   {
//     if (pri->info.dni != dni)
//       encolar(priNuevaCola, ultNuevaCola, pri->info);
//     else
//       personaAMover = pri->info;
//     desencolar(pri, ult);
//   }

//   while (priNuevaCola != NULL)
//   {
//     encolar(pri, ult, priNuevaCola->info);
//     desencolar(priNuevaCola, ultNuevaCola);
//   }
//   encolar(pri, ult, personaAMover);

//   // Para ver el ejercicio resuelto
//   while (pri != NULL)
//   {
//     cout << pri->info.dni << " ";
//     desencolar(pri, ult);
//   }
// }

void moverPersonas2(NodoCola *&pri, NodoCola *&ult, int dni)
{

  if (pri->info.dni == dni)
  {
    encolar(pri, ult, pri->info); // ¿Está bien encolar y despues desencolar en la misma lista siendo "la misma persona"?
    desencolar(pri, ult);
  }
  else
  {
    Persona priElemCola = pri->info, personaAMover;
    while (pri->info.dni != priElemCola.dni)
    {
      if (pri->info.dni != dni)
      {
        encolar(pri, ult, pri->info);
        desencolar(pri, ult);
      }
      else
      {
        personaAMover = pri->info;
        desencolar(pri, ult);
      }
    }
    encolar(pri, ult, personaAMover);
  }

  // Para ver el ejercicio resuelto
  while (pri != NULL)
  {
    cout << pri->info.dni << " ";
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
