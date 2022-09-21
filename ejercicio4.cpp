/* 4) Desarrollar una función que dada una pila y dos valores "x" e "y", reemplace cada valor igual a "y"
que se encuentre en la pila por el valor "x", retornando la pila modificada. */

#include <iostream>

using namespace std;

struct Nodo
{
  int info;
  Nodo *sig;
};

void apilar(Nodo *&pila, int num);
void desapilar(Nodo *&pila, int &num);
Nodo modificarPila(Nodo *pila, int x, int y);

int main()
{
  Nodo *pilaNums = NULL;
  int i, num;

  // Creo la pila
  for (i = 1; i <= 10; i++)
  {
    cout << "Agregar un numero: ";
    cin >> num;
    apilar(pilaNums, num);
  }

  int cantNumAgregados = i - 1, x = 4, y = 8;

  modificarPila(pilaNums, x, y);

  return 0;
}

void apilar(Nodo *&pila, int dato)
{
  Nodo *p = new Nodo;
  p->info = dato;
  p->sig = pila;
  pila = p;
}

Nodo modificarPila(Nodo *pila, int x, int y)
{
  int num;
  while (pila != NULL)
  {
    // desapilar(pila, dato);
    cout << num << endl;
  }
  return *pila;
}

void desapilar(Nodo *&pila, int &dato)
{
  if (pila == NULL)
    cout << "ERROR, la pila esta vacia" << endl;
  else
  {
    Nodo *p;
    p = pila;
    dato = p->info;
    pila = p->sig;
    delete p;
  }
}
