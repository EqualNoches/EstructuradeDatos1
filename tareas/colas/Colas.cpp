#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

//* Prototype for the function
void Enqueue(Node *&, Node *&, int);
bool empty_queue(Node *);

int charToInt(char);


int main(int argc, char const *argv[])
{
    int choice;
    Node *front = NULL;
    Node *end = NULL;
    char data;
    int finalData;
    char cantElements;
    int position = 1;
    int intentos = 0;
    int choice;
    int newNumber;

    do 
    {
        cout << "Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Cuantos elementos quieres agregar a esta cola?: ";
                cin >> cantElements;
                newNumber = charToInt(cantElements);
                if (isDigit(cantElements))
                {
                    for (int i = 0; i < newNumber; i++)
                    {
                        cout << "Digite un numero: ";
                        cin >> data;
                        finalData = charToInt(data);
                        if (isDigit(data))
                        {
                        Enqueue(front,end,data);
                        }
                        else if (!isDigit(data))
                        {
                            cout << "Recuerde solo poner numeros\n";
                        }
                    }
                }
                break;

            case 2:
                cout << "\nEliminando elementos de la cola" << endl;
                cout << "Recuerde que los elementos saldran FiFo (First in First Out)" << endl;
                
                while (stack != NULL) //* while the elements inside the stack are not equal to NUll
                {
                    Dequeue(stack, finalData);
                    if (stack != NULL)
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
                DisplayStack(stack);
                break;

            case 4:
                cout << "Saliendo del programa." << endl;
                exit(0);

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                choice = 4;
                break;
        }
    }while (choice != 4);


    return 0;
}

//* Function to insert elements into a queue
void Enqueue(Node *&front, Node *&end, int n)
{
    Node *newNode = new Node();

    newNode->data = n;
    newNode->next = NULL;

    if(empty_queue(front))
    {
        front = newNode;
    }
    else
    {
        end->next = newNode;
    }

    end = newNode;

    cout << "Elemento " <<n<<" insertado a la cola correctamente."<<endl;
}

// function to determine if the queue is empty or not
bool empty_queue(Node *front)
{
    return (front == NULL)? true : false;
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
/// @return if is digit true, else false
bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}