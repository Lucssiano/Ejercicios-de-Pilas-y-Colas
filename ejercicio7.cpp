/* 7) En una oficina de Aeroparque una secretaria atiende las colas de espera para Montevideo,
Punta del Este y Mar del Plata. Tiene una cola de espera para cada localidad, y en ella registra
nombre y apellido del pasajero y número de documento.

a) Desarrolle una función que, dados los datos del pasajero y el lugar de destino, lo incluya
en la cola de espera correspondiente. // Un solo pasajero

b) Desarrolle una función que, dado el destino y la cantidad de asientos libres de un avión,
retire de la cola de espera a aquellas personas que ahora pueden viajar, e informe los
datos. */

#include <iostream>
#include <string.h>

using namespace std;

struct Pasajero
{
  int dni;
  char nombreYApellido[36];
};

struct NodoCola
{
  Pasajero info;
  NodoCola *sig;
};

void puntoA(NodoCola *&priMDQ, NodoCola *&ultMDQ, NodoCola *&priPDE, NodoCola *&ultPDE, NodoCola *&priMV, NodoCola *&ultMV);
void puntoB(NodoCola *&priMDQ, NodoCola *&ultMDQ, NodoCola *&priPDE, NodoCola *&ultPDE, NodoCola *&priMV, NodoCola *&ultMV);
void encolar(NodoCola *&pri, NodoCola *&ult, Pasajero dato);
Pasajero desencolar(NodoCola *&pri, NodoCola *&ult);

int main()
{
  NodoCola *priColaMontevideo = NULL, *ultColaMontevideo = NULL;
  NodoCola *priColaPDelEste = NULL, *ultColaPDelEste = NULL;
  NodoCola *priColaMDQ = NULL, *ultColaMDQ = NULL;

  /* PARA ARMAR LA COLA DE PASAJEROS (OPCIONAL) */
  Pasajero psj;
  string lugarDeDestino;

  for (int i = 0; i < 3; i++)
  {
    cout << "Ingrese DNI del pasajero: ";
    cin >> psj.dni;
    cout << "Agregar nombre y apellido del pasajero: ";
    fflush(stdin);
    cin.getline(psj.nombreYApellido, 36);
    cout << "Ingrese el lugar de destino (MDQ , PDE o MV): ";
    cin >> lugarDeDestino;

    if (lugarDeDestino == "MDQ")
    {
      encolar(priColaMDQ, ultColaMDQ, psj);
      cout << "PASAJERO A MDQ PUESTO EN LA COLA DE ESPERA" << endl;
    }
    else if (lugarDeDestino == "PDE")
    {
      encolar(priColaPDelEste, ultColaPDelEste, psj);
      cout << "PASAJERO A PDE PUESTO EN LA COLA DE ESPERA" << endl;
    }
    else if (lugarDeDestino == "MV")
    {
      encolar(priColaMontevideo, ultColaMontevideo, psj);
      cout << "PASAJERO A MV PUESTO EN LA COLA DE ESPERA" << endl;
    }
  }
  /* ###### */

  puntoA(priColaMDQ, ultColaMDQ, priColaPDelEste, ultColaPDelEste, priColaMontevideo, ultColaMontevideo);
  puntoB(priColaMDQ, ultColaMDQ, priColaPDelEste, ultColaPDelEste, priColaMontevideo, ultColaMontevideo);
  return 0;
}

void puntoA(NodoCola *&priMDQ, NodoCola *&ultMDQ, NodoCola *&priPDE, NodoCola *&ultPDE, NodoCola *&priMV, NodoCola *&ultMV)
{
  Pasajero psj;
  string lugarDeDestino;

  cout << "PASAJERO NUEVO" << endl;
  cout << "Ingrese DNI del pasajero: ";
  cin >> psj.dni;
  cout << "Agregar nombre y apellido del pasajero: ";
  fflush(stdin);
  cin.getline(psj.nombreYApellido, 36);
  cout << "Ingrese el lugar de destino (MDQ , PDE o MV): ";
  cin >> lugarDeDestino;

  if (lugarDeDestino == "MDQ")
  {
    encolar(priMDQ, ultMDQ, psj);
    cout << "PASAJERO A MDQ PUESTO EN LA COLA DE ESPERA" << endl;
  }
  else if (lugarDeDestino == "PDE")
  {
    encolar(priPDE, ultPDE, psj);
    cout << "PASAJERO A PDE PUESTO EN LA COLA DE ESPERA" << endl;
  }
  else if (lugarDeDestino == "MV")
  {
    encolar(priMV, ultMV, psj);
    cout << "PASAJERO A MV PUESTO EN LA COLA DE ESPERA" << endl;
  }
}

void puntoB(NodoCola *&priMDQ, NodoCola *&ultMDQ, NodoCola *&priPDE, NodoCola *&ultPDE, NodoCola *&priMV, NodoCola *&ultMV)
{
  string lugarDeDestino;
  int cantAsientosLibres = 40;

  cout << "Ingrese el lugar de destino (MDQ , PDE o MV): ";
  cin >> lugarDeDestino;

  int cantDesencolados = 0;
  if (lugarDeDestino == "MDQ")
  {
    cout << "COLA MDQ DESENCOLADA" << endl;
    while (cantDesencolados < cantAsientosLibres && priMDQ != NULL)
    {
      Pasajero personaDesencolada = desencolar(priMDQ, ultMDQ);
      cout << personaDesencolada.dni << endl;
      cout << personaDesencolada.nombreYApellido << endl;
      cantDesencolados++;
    }
  }
  else if (lugarDeDestino == "PDE")
  {
    cout << "COLA PDE DESENCOLADA" << endl;
    while (cantDesencolados < cantAsientosLibres)
    {
      Pasajero personaDesencolada = desencolar(priPDE, ultPDE);
      cout << personaDesencolada.dni << endl;
      cout << personaDesencolada.nombreYApellido << endl;
      cantDesencolados++;
    }
  }
  else if (lugarDeDestino == "MV")
  {
    cout << "COLA MV DESENCOLADA" << endl;
    while (cantDesencolados < cantAsientosLibres)
    {
      Pasajero personaDesencolada = desencolar(priMV, ultMV);
      cout << personaDesencolada.dni << endl;
      cout << personaDesencolada.nombreYApellido << endl;
      cantDesencolados++;
    }
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

Pasajero desencolar(NodoCola *&pri, NodoCola *&ult)
{
  Pasajero dato;
  NodoCola *p = pri;
  pri = p->sig;
  dato = p->info;
  delete p;
  if (pri == NULL)
    ult = NULL;
  return dato;
}
