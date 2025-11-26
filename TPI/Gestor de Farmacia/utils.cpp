#include <iostream>
#include "utils.h"
#include <cctype>
using namespace std;


bool leerSN(const char* mensaje) {
    char input;
    cout << mensaje;
    cin >> input;

    input = tolower(input);

    while (input != 's' && input != 'n') {
        cout << "Valor incorrecto. Ingrese 's' o 'n': ";
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
