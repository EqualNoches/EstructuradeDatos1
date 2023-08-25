/*


*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    int priority;
};

//* Prototype for the function
void Enqueue(Node *&, Node *&, int, int);
void Dequeue(Node *&, Node *&, int &);
void DisplayStack(Node *);
bool empty_queue(Node *);
void isDigit(int &);
int charToInt(char);

int main(int argc, char const *argv[])
{
    Node *front = NULL;
    Node *end = NULL;
    int data;
    int cantElements;
    int position = 1;
    int intentos = 0;
    int choice;
    int priority;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        isDigit(choice);

        switch (choice)
        {
        case 1:
            cout << "Cuantos elementos quieres agregar a esta cola?: ";
            isDigit(cantElements);
            for (int i = 0; i < cantElements; i++)
            {
                cout << "Desea que su numero tenga prioridad?\n"
                     << "1\n"
                     << "2\n";

                isDigit(priority);

                switch (priority)
                {
                case 1: //*si es Caso uno, preguntará por prioridad
                    cout << "Que tipo de prioridad desea que tenga este numero?";
                    isDigit(priority);
                    cout << "Digite un numero: ";
                    isDigit(data);
                    Enqueue(front, end, data, priority);
                    break;

                case 2: //*Si es caso 2, agrega prioridad automaticamente.
                    cout << "Digite un numero: ";
                    isDigit(data);
                    priority = 16;
                    Enqueue(front, end, data, priority);
                    break;

                default:
                    cout << "Solo introduzca 1 o 2";
                    break;
                }
            }
            break;

        case 2:
            cout << "\nEliminando elementos de la cola" << endl;
            cout << "Recuerde que los elementos saldran FiFo (First in First Out)" << endl;

            while (front != NULL) //* while the elements inside the stack are not equal to NUll
            {
                Dequeue(front, end, data);
                if (front != NULL)
                {
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
            DisplayStack(front);
            break;

        case 4:
            cout << "Saliendo del programa." << endl;
            exit(0);

        default:
            cout << "introduzca un valor valido" << endl;
            choice = 4;
            break;
        }
    }

    return 0;
}

//* Function to insert elements into a queue
void Enqueue(Node *&front, Node *&end, int n, int priority)
{
    Node *newNode = new Node();

    newNode->data = n;
    newNode->priority;
    newNode->next = NULL;

    if (empty_queue(front))
    {
        front = newNode;
    }
    else
    {
        end->next = newNode;
        if (front -> priority > priority)
        {
            newNode -> next = front;
            front = newNode;
        }
        else
        {
            //*Este se va a ir desplazando atraves de la cola hasta que encuentre un nodo con 
            //*una prioridad menor o igual a la del nuevo Nodo
            Node *index = front;

            while (index->next != NULL && index->next->priority <= priority)
            {
                index = index ->next;
            }
            newNode->next = index->next;
            index->next = newNode;
        }
        
    }

    end = newNode;

    cout << "Elemento " << n << " insertado a la cola correctamente." << endl;
}

void Dequeue(Node *&front, Node *&end, int &n)
{
    n = front->data;
    Node *aux = front;
    if (front == end)
    {
        front = NULL;
        end = NULL;
    }
    else
    {
        front = front->next;
    }
    delete aux;
}
void DisplayStack(Node *first)
{
    int number = 1;
    if (first == NULL)
    {
        cout << "Empty Queue." << endl;
        return;
    }

    cout << "Elementos de queue: " << endl;
    while (first != NULL)
    {
        cout << number << ". " << first->data << endl;
        first = first->next;
        number++;
    }
}

// function to determine if the queue is empty or not
bool empty_queue(Node *front)
{
    return (front == NULL) ? true : false;
}

/// @brief function for char to int
/// @param c
/// @return if available, the char represented in an int
int charToInt(char c)
{
    return c - '0';
}

/// @brief confirm if this conditional is a digit
/// @param c
/// @return if is going to check if the operation is successfull
void isDigit(int &i)
{
    while (!(cin >> i))
    {
        cout << "Porfavor introduzca un valor valido.";
        cin.clear();
        cin.ignore(123, '\n');
    }
}