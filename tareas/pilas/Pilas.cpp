#include <iostream>
#include <stdlib.h>
#include <ctype.h>

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
        cout << "Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        isDigit(choice);

        switch (choice)
        {
        case 1:
            cout << "Cuantos elementos quieres agregar a esta pila?: ";
            isDigit(cantElements);
            for (int i = 0; i < cantElements; i++)
            {
                cout << "Digite un numero: ";
                isDigit(data);
                cout << data;
                Push(stack, data);
            }
            break;

        case 2:
            cout << "\nEliminando elementos de la pila" << endl;
            cout << "Recuerde que los elementos saldran LIFA (Last in First Out)" << endl;

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
    cout << "Elemento " << n << " agregado A la pila correctamente" << endl;
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
        cout << "Empty Stack." << endl;
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
        cout << "Porfavor introduzca un valor valido.";
        cin.clear();
        cin.ignore(123, '\n');
    }   
}

/// @brief normal char to int method
/// @param c
/// @return the written character comes back as an int
int charToInt(char c)
{
    return c - '0';
}
