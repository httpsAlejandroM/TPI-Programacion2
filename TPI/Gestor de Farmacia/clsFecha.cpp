#include "clsFecha.h"
using namespace std;
#include <iostream>
#include <ctime>

// Fecha::Fecha()
//   : _dia(0), _mes(0), _anio(0)
// {

// }

Fecha::Fecha() {
    time_t t = time(nullptr);

    tm ahora = *localtime(&t);

    _dia  = ahora.tm_mday;
    _mes  = ahora.tm_mon + 1;
    _anio = ahora.tm_year + 1900;
}

Fecha::Fecha (int dia, int mes, int anio)
{
  setDia(dia);
  setMes(mes);
  setAnio(anio);
}

int Fecha::getDia()
{
  return _dia;
}

void Fecha::setDia(int dia)
{
  _dia = dia;
}

int Fecha::getMes()
{
  return _mes;
}

void Fecha::setMes(int mes)
{
  _mes = mes;
}

int Fecha::getAnio()
{
  return _anio;
}

void Fecha::setAnio(int anio)
{
  _anio = anio;
}

void Fecha::cargar() {
    int dia, mes, anio;

    do {
        cout << "Dia (1-31): ";
        cin >> dia;
    } while (dia < 1 || dia > 31);

    do {
        cout << "Mes (1-12): ";
        cin >> mes;
    } while (mes < 1 || mes > 12);

    do {
        cout << "Anio (>0): ";
        cin >> anio;
    } while (anio <= 0);

    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

string Fecha::toString()
{
  return to_string(_dia) + "/"+ to_string(_mes) + "/" + to_string(_anio);
}
