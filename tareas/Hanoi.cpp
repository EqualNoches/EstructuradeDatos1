#include <iostream>

using namespace std;

// Funcion recursiva para mover los discos
void jugada(int disco, int torre1, int torre2, int torre3) {
    // Caso base: mover un disco
    if (disco == 1) {
        cout << "Mover disco de " << torre1 << " hacia la torre " << torre3 << endl;
    }
    // Caso recursivo: mover los discos restantes
    else {
        // Mover los discos restantes de la torre1 a la torre2
        jugada(disco - 1, torre1, torre3, torre2);
        // Mover el disco actual de la torre1 a la torre3
        cout << "Mover disco de " << torre1 << " hacia la torre " << torre3 << endl;
        // Mover los discos restantes de la torre2 a la torre3
        jugada(disco - 1, torre2, torre1, torre3);
    }
}

// Funcion principal
int main() {
    // Declarar variables
    int disco, torre1 = 1, torre2 = 2, torre3 = 3;

    // Solicitar al usuario el numero de discos
    cout << "Con cuantos discos quiere comenzar? ";
    cin >> disco;

    // Llamar a la funcion jugada
    jugada(disco, torre1, torre2, torre3);

    return 0;
}