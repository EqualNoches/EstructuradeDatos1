/*
Una pila (stack) es una estructura de datos en donde el último en entrar es el primero en salir.
Construir un programa C++ que simule una pila, utilizando una estructura de datos como la que
sigue para los nodos:

struct Pila {
    int dato;
    Pila *next;
    };

RESTRICCIONES:
    A. La pila debe poder realizar las operaciones de Push y Pop.
    B. Tener en consideración de desplegar un mensaje de “Empty Stack”, cuando se trate de
        hacer un Pop cuando la pila este vacía.
    C. El programa debe tener un menú para realizar las operaciones de Push, Pop y Desplegar
        toda la pila realizando Pops hasta el último nodo. Además, debe tener una opción de
        salir del programa

Participantes:
 #. Name - ID

 1. Edward Díaz - ID:1115808
 2. Hector Wittkop - ID:1115754
 3. Alexander Gil - ID:1116763
 4. Juan Ortiz - ID:1115143
 5. Jose de la Cruz - ID:1113682
 6. Erick Saviñon - ID:1115161

 Fecha: 25/8/2023
*/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void Push(Node *&, int); //* References for the functions
void Pop(Node *&, int &);
void isDigit(int &);
int charToInt(char c);
void DisplayStack(Node *stack);

int main(int argc, char const *argv[])
{
    Node *stack = NULL;
    int data;
    int cantElements;
    int position = 1;
    int intentos = 0;
    int choice;
    int newNumber;

    while (true)
    {
        cout << "\nMenu:" << endl
             << "1. Push" << endl
             << "2. Pop" << endl
             << "3. Display Stack" << endl
             << "4. Exit" << endl
             << "Elección: ";

        isDigit(choice);

        switch (choice)
        {
        case 1:
            cout << "\nCuantos elementos quieres agregar a esta pila?: ";
            isDigit(cantElements);
            for (int i = 0; i < cantElements; i++)
            {
                cout << "Digite un numero: ";
                isDigit(data);
                Push(stack, data);
            }
            break;

        case 2:
            cout << "\nEliminando elementos de la pila" << endl;
            cout << "Recuerde que los elementos saldran LIFA (Last in First Out)\n" << endl;

            while (stack != NULL) //* while the elements inside the stack are not equal to NUll
            {

                if (stack != NULL)
                {
                    Pop(stack, data);
                    cout << position << ". " << data << "\n";
                }
                else
                {
                    cout << position << ". " << data << "\n";
                }
                position++;
            }
            break;

        case 3:
            DisplayStack(stack);
            break;

        case 4:
            cout << "Saliendo del programa." << endl;
            exit(0);
            break;

        default:
            cout << "Opción invalida, solo puede elegir digitos del 1 - 4." << endl;
            choice = 4;
            break;
        }
    }

    return 0;
}

/// @brief Method in charge of pushing into the stack
/// @param stack
/// @param n
void Push(Node *&stack, int n)
{
    Node *new_node = new Node();
    new_node->data = n;
    new_node->next = stack;
    stack = new_node;
    cout << "\nElemento " << n << " agregado A la pila correctamente\n" << endl;
}

/// @brief Method in charge of pulling out of the stack
/// @param stack
/// @param n
void Pop(Node *&stack, int &n)
{
    Node *aux = stack;
    n = aux->data;
    stack = aux->next;
    delete aux;
}

/// @brief method in charge of displaying the stack
/// @param stack
void DisplayStack(Node *stack)
{
    int number = 1;
    if (stack == NULL)
    {
        cout << "\nEmpty Stack." << endl;
        return;
    }

    cout << "Elementos de stack: " << endl;
    while (stack != NULL)
    {
        cout << number << ". " << stack->data << endl;
        stack = stack->next;
        number++;
    }
}

/// @brief my own isDigit implementation
/// @param i
/// @return true or false
void isDigit(int &i)
{
    while (!(cin >> i))
    {
        // Como funciona es muy sencillo. Solamente valida si la entrada a ese tipo de dato es valida. Si no lo es, manda false
        cout << "\nPorfavor introduzca un valor valido.\n"
             << "Intente nuevamente: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
}
