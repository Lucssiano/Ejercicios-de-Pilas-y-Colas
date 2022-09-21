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
void modificarPila(Nodo *pila, int num, int x, int y);
void mostrarPilaDesapilada(Nodo *pila, int num);

int main()
{
  Nodo *pilaNums = NULL;
  int i, num;

  for (i = 0; i < 10; i++)
  {
    cout << "Agregar un numero: ";
    cin >> num;
    apilar(pilaNums, num);
  }

  int cantNumAgregados = i, x = 4, y = 5;

  modificarPila(pilaNums, num, x, y);

  return 0;
}

void apilar(Nodo *&pila, int dato)
{
  Nodo *p = new Nodo;
  p->info = dato;
  p->sig = pila;
  pila = p;
}

void modificarPila(Nodo *pila, int num, int x, int y)
{
  Nodo *nuevaPilaNums = NULL;
  while (pila != NULL)
  {
    desapilar(pila, num);
    if (num == y)
      apilar(nuevaPilaNums, x);
    else
      apilar(nuevaPilaNums, num);
  }
  while (nuevaPilaNums != NULL)
  {
    desapilar(nuevaPilaNums, num);
    apilar(pila, num);
  }
  // return *pila;
  mostrarPilaDesapilada(pila, num);
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

void mostrarPilaDesapilada(Nodo *pila, int num)
{
  cout << "PILA DESAPILADA" << endl;
  while (pila != NULL)
  {
    desapilar(pila, num);
    cout << num << endl;
  }
}
