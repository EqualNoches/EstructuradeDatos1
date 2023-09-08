/*
Realizar un programa C++ que simule una Cola (Queue).

Una Cola (Queue) es una estructura de datos en donde el primero en entrar es el primero en salir. Para 
nuestro caso, haremos el problema un poco mas complejo añadiéndole lo que se conoce como 
prioridad. En los casos en que una Cola tiene prioridad se considera esta al momento de insertar un 
nuevo nodo a la estructura. La Cola tiene la siguiente forma para los nodos:

struct Queue { 
 int dato; 
 Queue *next; 
}; 

RESTRICCIONES:

    A. La Cola debe poder realizar las operaciones Enqueue y Dequeue. 
    B. Las prioridades van de 0 a 16. En los casos que el usuario decida una prioridad más alta que 16 se 
    considerara la default, y se insertara el nuevo nodo al final de la estructura.
    C. El programa deberá tener un menu con las opciones para Enqueue y Dequeue, además de poder 
    desplegar todos los elementos de la cola, provocando Dequeue de toda la estructura Cola.
    D. Las entradas de datos del usuario deben ser debidamente validas.
    E. El programas debe ser lo suficientemente especializado para informar al usuario cuando la cola esta 
    vacía

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
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    int priority;
};

//* Prototipos de Funciones
void Enqueue(Node *&, Node *&, int, int);
void Dequeue(Node *&, Node *&, int &);
void DisplayStack(Node *);
bool empty_queue(Node *);
void IsDigit(int &);

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
        //*Menu de inicio
        cout << "\nMenu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        IsDigit(choice);

        switch (choice)
        {
        case 1:
            cout << "Cuantos elementos quieres agregar a esta cola?: ";
            IsDigit(cantElements);
            for (int i = 0; i < cantElements; i++)
            {
                cout << "\nDesea que su numero tenga prioridad?\n"
                     << "1. Si\n"
                     << "2. No\n"
                     << "Opcion: ";

                IsDigit(priority);

                switch (priority)
                {
                case 1: //*si es Caso uno, preguntará por prioridad
                    cout << "Que tipo de prioridad desea que tenga este numero?: ";
                    IsDigit(priority);
                    cout << "\nDigite un numero: ";
                    IsDigit(data);
                    Enqueue(front, end, data, priority);
                    break;

                case 2: //*Si es caso 2, agrega prioridad automaticamente.
                    cout << "Digite un numero: ";
                    IsDigit(data);
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
/// @brief Function in charge of Adding elements to the queue
/// @param front
/// @param end
/// @param n
/// @param priority
void Enqueue(Node *&front, Node *&end, int n, int priority)
{
    Node *newNode = new Node();

    newNode->data = n;
    newNode->priority = priority;
    newNode->next = NULL;

    if (empty_queue(front))
    {
        front = newNode;
    }
    else
    {
        if (front->priority > priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            //*Este se va a ir desplazando atraves de la cola hasta que encuentre un nodo con
            //*una prioridad menor o igual a la del nuevo Nodo
            Node *index = front;

            while (index->next != NULL && index->next->priority <= priority)
            {
                index = index->next;
            }
            newNode->next = index->next;
            index->next = newNode;
        }
    }
    cout << "\nElemento " << n << " insertado a la cola correctamente. con una prioridad: " << priority << endl;
}
/// @brief This method is in charge of deleting data to the corresponding queue
/// @param front 
/// @param end 
/// @param n 
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
        cout <<" | "<< number << ". "<<" | Number: "  << first->data << " | Prioridad: " << first->priority << " | "<<  endl;
        first = first->next;
        number++;
    }
}

/// @brief  function to determine if the queue is empty or not
/// @param front
/// @return true if queue is empty
bool empty_queue(Node *front)
{
    return (front == NULL) ? true : false;
}

/// @brief confirm if this conditional is a digit by macking the "cin" inside of the function
/// @param c

/// @return if is going to check if the operation is successfull
void IsDigit(int &i)
/// @return if the operation is succesfull it will return a true, else it will return false

{
    while (!(cin >> i))
    {
        cout << "Porfavor introduzca un valor valido.";
        cin.clear();
        cin.ignore(123, '\n');
    }
}