/* Realizar un programa C++ que permita resolver el problema de las Torres de Hanoi, el cual
consiste en trasladar una cantidad x de anillos desde una torre A a una torre B.

RESTRICCIONES:
A. El juego tiene 3 torres, nombradas A, B y C y n anillos concéntricos ordenados de mayor
diámetro a menos diámetro.
B. Al iniciar se tiene un conjunto de al menos 3 anillos colocados en forma descendente,
pues cada anillo está a su vez encima de otro más grande.
C. Nunca un anillo más grande debe estar encima de uno más pequeño, es decir, de mayor
diámetro va encima de otro con diámetro menor.
D. Debe realizar los movimientos de los anillos hasta que haya traslado los anillos de una
torre X a una torre Y.


Participantes:
 #. Name - ID

 1. Edward Díaz - ID:1115808
 2. Hector Wittkop - ID:1115754
 3. Alexander Gil - ID:1116763
 4. Juan Ortiz - ID:1115143
 5. Jose de la Cruz - ID:1113682
 6. Erick Saviñon - ID:1115161

 Fecha: 6/10/2023

*/

#include <iostream>

using namespace std;

// Funcion recursiva para mover los discos
void jugada(int disco, int torre1, int torre2, int torre3, int &movimientos) {
    // Caso base: mover un disco
    if (disco == 1) {
        cout << "Mover disco de " << torre1 << " hacia la torre " << torre3 << endl;
        movimientos++;
    }
    // Caso recursivo: mover los discos restantes
    else {
        // Mover los discos restantes de la torre1 a la torre2
        jugada(disco - 1, torre1, torre3, torre2, movimientos);
        // Mover el disco actual de la torre1 a la torre3
        cout << "Mover disco de " << torre1 << " hacia la torre " << torre3 << endl;
        movimientos++;
        // Mover los discos restantes de la torre2 a la torre3
        jugada(disco - 1, torre2, torre1, torre3, movimientos);
    }
}

// Funcion principal
int main() {
    // Declarar variables
    int disco, torre1 = 1, torre2 = 2, torre3 = 3;
    int movimientos = 0;

    // Solicitar al usuario el numero de discos
    cout << "Con cuantos discos quiere comenzar? ";
    cin >> disco;

    // Llamar a la funcion jugada
    jugada(disco, torre1, torre2, torre3, movimientos);

    // Imprimir la cantidad de movimientos
    cout << "La cantidad de movimientos es: " << movimientos << endl;

    return 0;
