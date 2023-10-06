/*Realizar un programa C++ que genere los movimientos posibles (según las reglas del ajedrez) de
una Reina amenazada por dos Torres enemigas. El programa debe desplegar el tablero con las
jugadas posibles de la Reina, colocando una V donde la reina pueda moverse sin ser eliminada y
una X donde pueda moverse, pero ser eliminada por una o las dos torres enemigas.
RESTRICCIONES:
A. El programa debe solicitar al usuario las posiciones de las dos torres enemigas y la de la
reina. hecho
B. Las posiciones de las torres no deben solaparse, es decir, no deben estar en la misma
posición. Las Torres deben estar en casillas distintas.hecho
C. La posición de la reina no debe coincidir con las de las torres.hecho
D. Debe desplegar el cuadro del ajedrez indicando a la reina con una R, las torres como T y
las jugadas según se establece en el enunciado.*/
#include <iostream>
#include <regex>
using namespace std;

int tablero[8][8];
int torreA[2];
int torreB[2];
int Reina[2];

const char TOWER = 'T';
const char QUEEN = 'R';
const char NOTKILL = 'V';
const char KILL = 'X';

void run();

bool PosicionObstruida(int, int);
bool ChoquePosciciones(int TowerXaxis, int TowerYAxis, int x, int y);
bool IsValidPosition(int, int);

void ValidateInput(int &);
void GetPosition(int);
void PreguntasPosiciones();
void MovimientoReina();
void MostrarTabla();

int main(int argc, char const *argv[])
{
    run();
    return 0;
}

void run()
{
    int opcion;
    while (true)
    {

        cout << "Bienvenido al programa de Reinas vs torres" << endl
             << "Opciones" << endl
             << "1. Iniciar programa" << endl
             << "2. Mostrar tablero" << endl
             << "3. Introducir valores" << endl
             << "4. Salir" << endl
             << "Opcion(1-4): ";
        ValidateInput(opcion);

        switch (opcion)
        {
        case 1:
            PreguntasPosiciones();
            break;
        case 2:
            MostrarTabla();
            break;
        case 3:

            MovimientoReina();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Escriba un valor valido";
            break;
        }
    }
}

bool PosicionObstruida(int Row, int Col)
{
    int queenRow = Reina[1];
    int queenCol = Reina[2];
    int TowerArow = torreA[1];
    int TowerAcol = torreA[2];
    int TowerBrow = torreB[1];
    int TowerBcol = torreB[2];

    // esta es para buscar si la diagonal de la ri
    bool TowerACross =
        abs(queenRow - TowerArow) == abs(queenCol - TowerAcol);
    bool TowerBCross =
        abs(queenRow - TowerBrow) == abs(queenCol - TowerBcol);
    bool QueenCross =
        abs(queenRow - Row) == abs(queenCol - Col);

    if (!TowerACross)
    {
        bool towerAOnQueenRow = queenRow == TowerArow;
        if (queenRow == Row && towerAOnQueenRow)
        {
            if (queenCol < TowerAcol && TowerAcol < Col)
            {
                return true;
            }
            if (queenCol > TowerAcol && TowerAcol > Col)
            {
                return true;
            }
        }
        bool isTowerAOnQueenCol = queenCol == TowerAcol;
        if (queenCol == Col && isTowerAOnQueenCol)
        {
            if (queenRow < TowerArow && TowerArow < Row)
            {
                return true;
            }
            if (queenRow > TowerArow && TowerArow > Row)
            {
                return true;
            }
        }
    }
    else if (QueenCross)
    {
        // La torre esta en la misma cruz (x) que la reina
        // por lo que esa linea va a seguir hasta que termine el tablero
        if (queenRow < TowerArow && TowerArow < Row)
        {
            if (queenCol < TowerAcol && TowerAcol < Col)
            {
                return true;
            }
            if (queenCol > TowerAcol && TowerAcol > Col)
            {
                return true;
            }
        }
    }
    if (!TowerBCross)
    {
        bool TorreBRowReina = queenRow == TowerArow;
        if (queenRow == Row && TorreBRowReina)
        {
            if (queenCol < TowerBcol && TowerBcol < Col)
            {
                return true;
            }
            if (queenCol > TowerBcol && TowerBcol > Col)
            {
                return true;
            }
        }
        bool isTowerOnBQueenCol = queenCol == TowerBcol;
        if (queenCol == Col && isTowerOnBQueenCol)
        {
            if (queenRow < TowerBrow && TowerBrow < Row)
            {
                return true;
            }
            if (queenRow > TowerBrow && TowerBrow > Row)
            {
                return true;
            }
        }
    }
    else if (QueenCross)
    {
        // La torre esta en la misma diagonal que la reina
        // y a su vez la posible siguiente posición de la reina también es
        // diagonal
        if (queenRow < TowerArow && TowerArow < Row)
        {
            if (queenCol < TowerBcol && TowerBcol < Col)
            {
                return true;
            }
            if (queenCol > TowerBcol && TowerBcol > Col)
            {
                return true;
            }
        }
    }
    return false;
}

/// @brief Verifica si en esa ficha la torre mata a la reina
/// @param TowerXaxis
/// @param TowerYAxis
/// @param x
/// @param y
/// @return
bool ChoquePosciciones(int TowerXaxis, int TowerYAxis, int x, int y)
{
    if (TowerXaxis == x || TowerYAxis == y)
    {
        return true;
    }
    return false;
}

/// @brief Genera las 'V' y 'X' que marca las posibles jugadas de la reina
void MovimientoReina()
{
    int filaReina = Reina[1];
    int columnaReina = Reina[2];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            bool posicionReina = columnaReina == i && filaReina == j;
            bool posicionTorreA = torreA[1] == i && torreA[2] == j;
            bool posicionTorreB = torreB[1] == i && torreB[2] == j;
            if (posicionReina || posicionTorreA || posicionTorreB)
            {
                continue;
            }
            bool MovimientoDiagonal = abs(i - filaReina) == abs(j - columnaReina);

            // booleano que mira si es |un movimiento diagonal  |  en su columna   |    o su fila;
            bool movimientoReina = MovimientoDiagonal || i == columnaReina || j == filaReina;

            if (!movimientoReina)
            {
                continue;
            }
            if (!PosicionObstruida(j, i))
            {
                bool KillTorreA = ChoquePosciciones(torreA[1], torreA[2], i, i);
                bool KillTorreB = ChoquePosciciones(torreB[1], torreB[2], i, i);
                if (KillTorreA || KillTorreB)
                {
                    tablero[i][j] = KILL;
                }
                else
                {
                    tablero[i][j] = NOTKILL;
                }
            }
        }
    }
}

void MostrarTabla()
{
    cout << "  ";
    for (int i = 0; i < 8; i++) // introduce la fila de numeros
    {
        cout << (i + 1) << " "; // Imprime las columnas con sus respectivos numeros en vertical
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << (i + 1) << " "; // Imprime las filas
        for (int j = 0; j < 8; j++)
        {
            char value = tablero[i][j];
            if (!value)
            { // Posición vacía
                cout << "- ";
                continue;
            }

            if (value == 'T')
            {
                cout << "\033[31m" << 'T' << "\033[0m";
                cout << " ";
            }
            else if (value == 'R')
            {
                cout << "\033[34m" << 'R' << "\033[0m"; // con este codigo
                cout << " ";
            }
            else
            {
                cout << value << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool IsValidPosition(int row, int col)
{
    if (row < 1 || row > 8 || col < 1 || col > 8)
    {
        cout << "Esta poscición esta fuera de los limites" << endl;
        return false;
    }

    int i = row - 1;
    int j = col - 1;
    if (tablero[i][j] != 0)
    {
        cout << "Esta posicion esta ocupada. \n";
        return false;
    }
    return true;
}

void GetPosition(int i)
{
    int row;
    int col;
    const char name[] = {'R', 'T', 'T'};
    while (true)
    {
        ValidateInput(row);
        ValidateInput(col);
        int x = row - 1;
        int y = col - 1;
        if (IsValidPosition(row, col))
        {
            switch (i)
            {
            case 0:
                Reina[1] = x;
                Reina[2] = y;
                tablero[Reina[1]][Reina[2]] = 'R';
                break;
            case 1:
                torreA[1] = x;
                torreA[2] = y;
                tablero[torreA[1]][torreA[2]] = 'T';
                break;
            case 2:
                torreB[1] = x;
                torreB[2] = y;
                tablero[torreB[1]][torreB[2]] = 'T';
                break;
            }
            break;
        }
        else
        {
            cout << "Posicion invalida. Intente de nuevo: ";
        }
    }
}

void PreguntasPosiciones()
{
    const string names[] = {"Reina", "Primera torre", "segunda torre"};
    // Obtener los datos de las torres y la reina
    cout << endl
         << "\n****Introduzca primero la fila, luego la columna deseada: ejemplo (fila columna)****\n"
         << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Introduzca la posicion donde quiere que la " << names[i] << " sea ubicada: ";
        GetPosition(i);
        cout << endl;
    }
}

void ValidateInput(int &n)
{
    while (!(cin >> n))
    {
        cout << "Porfavor introduzca un valor valido";
        cin.clear();
        cin.ignore(123, '\n');
    }
}
