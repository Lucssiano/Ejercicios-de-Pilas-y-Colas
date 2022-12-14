/* 3) Desarrollar una función que dada una palabra devuelva true si es capicúa y falso en caso
contrario. (usar una pila) */

#include <iostream>
#include <string.h>

using namespace std;

#define cantMaxCaracteres 10

struct Nodo
{
  char letra;
  Nodo *sig;
};

void apilar(Nodo *&pila, char letra);
void desapilar(Nodo *&pila, char &letra);
bool esCapicua(char palabra[cantMaxCaracteres], int cantCaracteresDeLaPalabra);

int main()
{
  char palabra[cantMaxCaracteres];

  cout << "Ingrese una palabra de no mas de 10 caracteres: ";
  cin >> palabra;

  int cantCaracteresDeLaPalabra = strlen(palabra);

  if (esCapicua(palabra, cantCaracteresDeLaPalabra))
    cout << "Es capicua, VERDADERO" << endl;
  else
    cout << "NO es capicua, FALSO" << endl;

  return 0;
}

bool esCapicua(char palabra[cantMaxCaracteres], int cantCaracteresDeLaPalabra)
{
  Nodo *pilaCaracteres = NULL;
  bool capicua = false;

  int mitadDeLaPalabra = cantCaracteresDeLaPalabra / 2;

  for (int i = 0; i < mitadDeLaPalabra; i++)
    apilar(pilaCaracteres, palabra[i]);

  int cantLetrasIguales = 0, j;

  // neuquen - aloe
  if (cantCaracteresDeLaPalabra % 2 == 0)
    j = mitadDeLaPalabra;
  else
    j = mitadDeLaPalabra + 1;

  while (pilaCaracteres != NULL && pilaCaracteres->letra == palabra[j])
  {
    cantLetrasIguales++;
    desapilar(pilaCaracteres, palabra[j]);
    j++;
  }

  // for (j; j < cantCaracteresDeLaPalabra; j++) // while con misma condicion de for, pilaCaracteres->letra != palabra[j] me dijo la profe
  // {
  //   if (pilaCaracteres->letra == palabra[j])
  //     cantLetrasIguales++;
  //   desapilar(pilaCaracteres, palabra[j]);
  // }

  // while (pilaCaracteres != NULL)
  // {
  //   if (pilaCaracteres->letra == palabra[j])
  //     cantLetrasIguales++;
  //   desapilar(pilaCaracteres, palabra[j]);
  //   j++;
  // }

  if (mitadDeLaPalabra == cantLetrasIguales)
    capicua = true;

  return capicua;
}

void apilar(Nodo *&pila, char letra)
{
  Nodo *p = new Nodo;
  p->letra = letra;
  p->sig = pila;
  pila = p;
}

void desapilar(Nodo *&pila, char &letra)
{
  if (pila == NULL)
    cout << "ERROR, la pila esta vacia" << endl;
  else
  {
    Nodo *p;
    p = pila;
    letra = p->letra;
    pila = p->sig;
    delete p;
  }
}

/* EJERCICIOS HECHOS EN CLASE */
// Devolver aprobados
// void listar(Nodo *lista)
// {
//   Nodo *p;
//   p = lista;
//   while (p)
//   {
//     soloAprobados(p);
//     p = p->sig;
//   }
// }

// void soloAprobados(Nodo *p)
// {
//   if (p->info.nota > 6)
//     cout << p->info.leg << p->info.nom << p->info.nota << endl;
// }

// Devolver promedio del curso
// float listar(Nodo *lista)
// {
//   Nodo *p;
//   p = lista;
//   int suma = 0, promCurso, i;
//   while (p)
//   {
//     suma += p->info.nota;
//     p = p->sig;
//     i++;
//   }
//   return promedioCurso(suma, i);
// }

// float promedioCurso(int sum, int cantAlumnos)
// {
//   float prom = sum / cantAlumnos;
//   return prom;
// }