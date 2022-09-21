/* 5) Desarrollar una función que dada una cola elimine 4 nodos de la misma, y devuelva un valor
true si ello fue posible, de lo contrario un valor falso. */

#include <iostream>
#include <string.h>

using namespace std;

struct NodoCola
{
  int info;
  NodoCola *sig;
};

void encolar(NodoCola *&pri, NodoCola *&ult, int dato);
int desencolar(NodoCola *&pri, NodoCola *&ult);
bool ejercicio5(NodoCola *&pri, NodoCola *&ult);

int main()
{
  NodoCola *priColaNums = NULL;
  NodoCola *ultColaNums = NULL;

  int num;

  for (int i = 0; i < 6; i++)
  {
    cout << "Agregar un numero: ";
    cin >> num;
    encolar(priColaNums, ultColaNums, num);
  }

  if (ejercicio5(priColaNums, ultColaNums))
    cout << "Pudo desencolar 4 veces, VERDADERO";
  else
    cout << "No pudo desencolar 4 veces, FALSO";

  return 0;
}

bool ejercicio5(NodoCola *&pri, NodoCola *&ult)
{
  int i = 0;
  while (pri != NULL && i < 4)
  {
    desencolar(pri, ult);
    i++;
  }
  return i == 4;
}

void encolar(NodoCola *&pri, NodoCola *&ult, int dato)
{
  NodoCola *p = new NodoCola;
  p->info = dato;
  p->sig = NULL;
  if (ult != NULL)
    ult->sig = p;
  else
    pri = p;
  ult = p;
}

int desencolar(NodoCola *&pri, NodoCola *&ult)
{
  int dato;
  NodoCola *p = pri;
  pri = p->sig;
  dato = p->info;
  delete p;
  if (pri == NULL)
    ult = NULL;
  return dato;
}
