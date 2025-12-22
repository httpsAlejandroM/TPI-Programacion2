#include <iostream>
#include "utils.h"
#include <cctype>
#include <iomanip>
#include <cstring>

using namespace std;


bool leerSN(const char* mensaje) {
    char input;
    cout << mensaje;
    cin >> input;

    input = tolower(input);

    while (input != 's' && input != 'n') {
        cout << "Valor incorrecto. Ingrese 'S' o 'N': ";
        cin >> input;
        input = tolower(input);
    }

    return (input == 's');
}

int charToBoolSN(char c) {
    c = tolower(c);
    if (c == 's') return 1;
    if (c == 'n') return 0;
    return -1;
}

int leerRangoInts(const char* mensaje, int min, int max) {
    int valor;

    cout << mensaje;
    cin >> valor;

    while (cin.fail() ||valor < min || valor > max) {

        cin.clear();             //pone en false el fail
        cin.ignore(1000, '\n');  

        cout << "Opción inválida. Ingrese un número entre "
                  << min << " y " << max << ": ";
        cin >> valor;
    }

    return valor;
}

bool contieneTexto(const char* texto, const char* busqueda) {
    int lenTexto = strlen(texto);
    int lenBus = strlen(busqueda);
    int limite = lenTexto - lenBus;

    if (lenBus == 0) return true; 

    for (int i = 0; i <= limite; i++) {
        bool coincide = true;

        for (int j = 0; j < lenBus; j++) {
            char c1 = tolower(texto[i + j]);
            char c2 = tolower(busqueda[j]);

            if (c1 != c2) {
                coincide = false;
                break;
            }
        }

        if (coincide) return true;
    }

    return false;
}