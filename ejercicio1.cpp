/* 1) Dada una pila sacar los dos elementos del tope y reemplazarlos por uno dado (agregar) */

#include <iostream>

using namespace std;

struct Libro
{
  string titulo;
  string materia;
};

struct Nodo
{
  Libro info;
  Nodo *sig;
};

void apilar(Nodo *&pila, Libro dato);
void desapilar(Nodo *&pila, Libro &dato);
void sacarYReemplazarElementos(Nodo *&pila, Libro &dato);
void mostrarPilaDesapilada(Nodo *&pila, Libro &dato);

int main()
{
  Nodo *pilaLibros = NULL;
  Libro libro;

  for (int i = 1; i <= 4; i++)
  {
    cout << "Agregar titulo del libro: ";
    cin >> libro.titulo;
    cout << "Agregar materia del libro: ";
    cin >> libro.materia;
    apilar(pilaLibros, libro);
  }

  sacarYReemplazarElementos(pilaLibros, libro);

  mostrarPilaDesapilada(pilaLibros, libro);

  return 0;
}

void sacarYReemplazarElementos(Nodo *&pila, Libro &dato)
{
  Libro nuevoElemento;

  desapilar(pila, dato);
  desapilar(pila, dato);

  cout << "Agregar un nuevo titulo de libro: ";
  cin >> nuevoElemento.titulo;
  cout << "Agregar una nueva materia del libro: ";
  cin >> nuevoElemento.materia;

  apilar(pila, nuevoElemento);
}

void apilar(Nodo *&pila, Libro dato)
{
  Nodo *p = new Nodo;
  p->info = dato;
  p->sig = pila;
  pila = p;
}

void desapilar(Nodo *&pila, Libro &dato)
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

void mostrarPilaDesapilada(Nodo *&pila, Libro &dato)
{
  Libro elem;
  while (pila != NULL)
  {
    desapilar(pila, dato);
    cout << dato.titulo << "-" << dato.materia << endl;
  }
}