/* 2) Desarrollar una función que dada una pila y un valor, inserte ese valor como tercer elemento de
la pila. */

// La pila puede tener 6 elementos, deberia sacar los elementos hasta el 3ero, reemplazar por el valor dado y poner denuevo los elementos que habia sacado

#include <iostream>

using namespace std;

struct Nodo
{
  int dato;
  Nodo *sig;
};

void apilar(Nodo *&pila, int num);
void desapilar(Nodo *&pila, int &num);
void ejercicio2(Nodo *&pila, int num, int nuevoNum, int cantValoresEnLaPila);
// void mostrarPilaDesapilada(Nodo *pila, int num);

int main()
{
  Nodo *pilaNums = NULL;
  int num, i, nuevoValor = 10;

  for (i = 0; i < 6; i++)
  {
    cout << "Agregar numero: ";
    cin >> num;
    apilar(pilaNums, num);
  }

  ejercicio2(pilaNums, num, nuevoValor, i);

  return 0;
}

void ejercicio2(Nodo *&pila, int num, int nuevoNum, int cantValoresEnLaPila)
{
  Nodo *nuevaPilaNums = NULL;

  for (int i = cantValoresEnLaPila; i >= 3; i--)
  {
    desapilar(pila, num);
    apilar(nuevaPilaNums, num);
  }

  apilar(pila, nuevoNum);

  while (nuevaPilaNums != NULL)
  {
    desapilar(nuevaPilaNums, num);
    apilar(pila, num);
  }

  // mostrarPilaDesapilada(pila, num);
}

void apilar(Nodo *&pila, int num)
{
  Nodo *p = new Nodo;
  p->dato = num;
  p->sig = pila;
  pila = p;
}

void desapilar(Nodo *&pila, int &num)
{
  if (pila == NULL)
    cout << "ERROR, la pila esta vacia" << endl;
  else
  {
    Nodo *p;
    p = pila;
    num = p->dato;
    pila = p->sig;
    delete p;
  }
}

// void mostrarPilaDesapilada(Nodo *pila, int num)
// {
//   cout << "PILA DESAPILADA" << endl;
//   while (pila != NULL)
//   {
//     desapilar(pila, num);
//     cout << num << endl;
//   }
// }