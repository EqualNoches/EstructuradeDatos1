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
void Enqueue(Node *&, Node *&, int, int, int);
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
    int psInfo = 0;
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
                    if (priority > 16)
                    {
                        priority = 16;
                    }
                    Enqueue(front, end, psInfo, data, priority);
                    psInfo++;
                    break;

                case 2: //*Si es caso 2, agrega prioridad automaticamente.
                    cout << "Digite un numero: ";
                    IsDigit(data);
                    priority = 16;
                    Enqueue(front, end, psInfo, data, priority);
                    psInfo++;
                    break;

                default:
                    cout << "Solo introduzca 1 o 2";
                    break;
                }
            }
            psInfo++;
            break;

        case 2:
            if (!empty_queue)
            {
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
                psInfo = 0;
            }
            else
            {
                cout << "\nLa cola esta vacia" << endl;
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
/// @param psInfo
/// @param n
/// @param priority
void Enqueue(Node *&front, Node *&end, int psInfo, int n, int priority)
{
    int current_priority;
    Node *newNode = new Node();

    newNode->data = n;
    newNode->priority = priority;
    newNode->next = NULL;

    if (empty_queue(front))
    {
        front = newNode;
        end = newNode;
    }
    else
    {
        if (priority == 0)
        {
            // Si la prioridad es igual a 0, el nuevo elemento se moverá enfrente
            newNode->next = front;
            front = newNode;
        }
        else
        {
            current_priority = front->priority;
            for (int i = 0; i < psInfo; i++)
            {
                if (priority <= current_priority)
                {
                    newNode->next = front->next;
                    front->next = newNode;
                    break;
                }
                else
                {
                    current_priority = front->next->priority;
                    front = front->next;
                }
            }
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
        cout << " | " << number << ". "
             << " | Number: " << first->data << " | Prioridad: " << first->priority << " | " << endl;
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
/// @param i
/// @return if is going to check if the operation is successfull
void IsDigit(int &i)
{
    while (!(cin >> i))
    {
        cout << "Porfavor introduzca un valor valido.";
        cin.clear();
        cin.ignore(123, '\n');
    }
}