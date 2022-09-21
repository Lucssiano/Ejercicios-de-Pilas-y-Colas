/* 7) En una oficina de Aeroparque una secretaria atiende las colas de espera para Montevideo,
Punta del Este y Mar del Plata. Tiene una cola de espera para cada localidad, y en ella registra
nombre y apellido del pasajero y número de documento.

a) Desarrolle una función que, dados los datos del pasajero y el lugar de destino, lo incluya
en la cola de espera correspondiente.

b) Desarrolle una función que, dado el destino y la cantidad de asientos libres de un avión,
retire de la cola de espera a aquellas personas que ahora pueden viajar, e informe los
datos. */

#include <iostream>
#include <string.h>

using namespace std;

struct Pasajero
{
  int dni;
  char nombreYApellido[36], lugarDeDestino[36];
};

struct NodoCola
{
  Pasajero info;
  NodoCola *sig;
};

void puntoA(NodoCola *&priMDQ, NodoCola *&ultMDQ, NodoCola *&priPDE, NodoCola *&ultPDE, NodoCola *&priMV, NodoCola *&ultMV);
void puntoB();
void encolar(NodoCola *&pri, NodoCola *&ult, Pasajero dato);
Pasajero desencolar(NodoCola *&pri, NodoCola *&ult);

int main()
{
  NodoCola *priColaMontevideo = NULL, *ultColaMontevideo = NULL;
  NodoCola *priColaPDelEste = NULL, *ultColaPDelEste = NULL;
  NodoCola *priColaMDQ = NULL, *ultColaMDQ = NULL;

  puntoA(priColaMDQ, ultColaMDQ, priColaPDelEste, ultColaPDelEste, priColaMontevideo, ultColaMontevideo);
  // puntoB();
  return 0;
}

void puntoA(NodoCola *&priMDQ, NodoCola *&ultMDQ, NodoCola *&priPDE, NodoCola *&ultPDE, NodoCola *&priMV, NodoCola *&ultMV)
{
  Pasajero psj;

  // Ingreso pasajeros para agregar en la  cola
  for (int i = 0; i < 2; i++)
  {
    cout << "Ingrese DNI del pasajero: ";
    cin >> psj.dni;
    cout << "Agregar nombre y apellido del pasajero: ";
    fflush(stdin);
    cin.getline(psj.nombreYApellido, 36);
    cout << "Ingrese el lugar de destino (MDQ , PDE o MV): ";
    fflush(stdin);
    cin.getline(psj.lugarDeDestino, 36);

    NodoCola *priColaALlenar = NULL, *ultColaALlenar = NULL;
    if (strcmpi(psj.lugarDeDestino, "MDQ") == 0)
    {
      cout << "entraK1" << endl;
      priColaALlenar = priMDQ;
      ultColaALlenar = ultMDQ;
    }
    else if (strcmpi(psj.lugarDeDestino, "PDE") == 0)
    {
      cout << "entraK2" << endl;
      priColaALlenar = priPDE;
      ultColaALlenar = ultPDE;
    }
    else if (strcmpi(psj.lugarDeDestino, "MV") == 0)
    {
      cout << "entraK3" << endl;
      priColaALlenar = priMV;
      ultColaALlenar = ultMV;
    }

    // cout << "priColaAllenar " << priColaALlenar << endl;
    // cout << "priColaAllenar " << ultColaALlenar << endl;
    // cout << "priMDQ " << priMDQ << endl;
    // cout << "ultMDQ " << ultMDQ << endl;

    encolar(priColaALlenar, ultColaALlenar, psj);
  }

  // cout << priMDQ;

  cout << "COLA MDQ DESENCOLADA" << endl;
  while (priMDQ != NULL)
  {
    cout << "entra" << endl;
    desencolar(priMDQ, ultMDQ);
  }

  cout << "COLA PUNTA DEL ESTE DESENCOLADA" << endl;
  while (priPDE != NULL)
  {
    cout << "entra" << endl;
    desencolar(priPDE, ultPDE);
  }

  cout << "COLA MONTEVIDEO DESENCOLADA" << endl;
  while (priMV != NULL)
  {
    cout << "entra" << endl;
    desencolar(priMV, ultMV);
  }
}

void encolar(NodoCola *&pri, NodoCola *&ult, Pasajero dato)
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

void puntoB()
{
}

Pasajero desencolar(NodoCola *&pri, NodoCola *&ult)
{
  Pasajero dato;
  NodoCola *p = pri;
  pri = p->sig;
  dato = p->info;
  delete p;
  if (pri == NULL)
    ult = NULL;
  cout << dato.dni << endl;
  cout << dato.nombreYApellido << endl;
  cout << dato.lugarDeDestino << endl;
  return dato;
}
