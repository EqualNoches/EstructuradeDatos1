#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node *izquierda;
    Node *derecha;
};

//Prototipos de funciones
Node *crearNodo(int data);
Node *InsertarElemento(Node *root, int data);
Node* FindMin(Node* root);
struct Node* EliminarElemento(struct Node *root, int data);
bool BuscarElemento(Node *root, int data);
void isDigit(int &n);


int main(int argc, char const *argv[])
{
    Node *root = nullptr;
    int choice;
    int dato;

    while (true)
    {
        cout << "-----------------------------------------------------------------------" << endl
             << "  ------------Programa de Arboles binarios de Busqueda------------  " << endl
             << "  ----Estos se diferencian del resto, debido a su organizacion----  " << endl
             << "-----------------------------------------------------------------------\n"
             << endl
             << "1. Insertar Elementos al arbol" << endl
             << "2. Buscar elementos en el arbol" << endl
             << "3. Eliminar elemento del arbol" << endl
             << "4. Mostrar Arbol" << endl
             << "5. Salir"<< endl
             << "Opcion (1-2): ";
        isDigit(choice);

        switch (choice)
        {
        case 1:
            cout << "Eliga un numero para insertar en el arbol";
            isDigit(dato);
            InsertarElemento(root, dato);
            cout <<endl;
            system("pause");
            break;
        case 2:
            cout << "Eliga que elemento quiere buscar";
            isDigit(dato);
            if (BuscarElemento(root, dato) == true) 
            {
                cout << "El elemento "<<dato<<" se encuentra en la lista"; 
            }
            else
            {
            cout << " Elemento " << dato << " no encontrado";
            }
            break;

        case 3:
            cout << "Eliga que elemento quiere eliminar del arbol";
            isDigit(dato);
            EliminarElemento(root, dato);
            break;

        case 4:
            cout <<"Este sistema de despliegue de información se llama InOrder";
            //terminar codigo
            break;
        case 5:
            cout << "Saliendo de la aplicación";
            system("cls");
            break;
        default:
            cout << "Introduzca un valor valido.";
            break;
        }
    }
    return 0;
}


/// @brief Funciona que crea el nuevo Nodo
/// @param data
/// @return Devuelve la referencia de ese nodo. Una referencia funcionará para saber donde agregar un nodo de tipo "hijo derecho" o "Hijo izquierdo"
/* 
    Este metodó tiene 4 pasos
        1. Crear un nuevo Nodo
        2. establecer el dato para este nuevo nodo
        3. Encargarse de agregar los hijos del nodo. (Estos inicialmente serán nulos porque cuando creamos un nodo nuevo, este no tendrá hijos)
        4. Entregar la referencia de este nodo
*/
Node *crearNodo(int data)
{
    Node *nuevo_nodo = new Node();
    nuevo_nodo->data = data;
    nuevo_nodo->derecha = nuevo_nodo->izquierda = nullptr;
    return nuevo_nodo;
}
/// @brief Esta función se encargará de Instertar Nodos al Arbol ya especificado
/// @param root
/// @param data
/// @return
Node *InsertarElemento(Node *root, int data)
{
    // Este primer caso es en el cual el arbol está vacio
    if (root = NULL) // si el Nodo "root" está vacio (que es la raiz).
    {
        root = crearNodo(data); // Este se agregará en la primera poscicion del arbol
        return root;            // Luego este va a retornar el valor que fue dado a la raiz
    }
    else if (data <= root->data)
    {
        root->izquierda = InsertarElemento(root->izquierda, data);
    }
    else
    {
        root->derecha = InsertarElemento(root->derecha, data);
    }
    return root;
}

Node* FindMin(Node* root)
{
    Node* actual = root;
    while (actual->izquierda != NULL)
    {
        actual = actual->izquierda;
    }
    return root;
}
/*
    Para Eliminar un elemento en una lista, hay 3 posibilidades diferentes.
    caso 1: Que el nodo a Eliimnarse no tenga un hijo
    caso 2: Que el nodo a eliminarse solo tenga 1 hijo
    caso 3: Que el nodo a eliminarse tenga ambos hijos  
*/
struct Node* EliminarElemento(struct Node *root, int data)
{
    if (root == NULL) return root; 
    else if (data < root->data)
    { 
        root->izquierda = EliminarElemento(root->izquierda, data); 
        //si la data que buscamos es menor al del nodo, este se va a eliminiar y se va a guardar la direccion de memoria en el nodo
    }
    else if (data> root->data)
    {
        root->derecha = EliminarElemento(root->derecha, data);
    }
    else //Esto se ejecuta cuando ya finalmente se encuentra el nodo para eliminar
    {
        //Caso 1: No Tiene Hijo
        if (root->derecha == NULL && root->izquierda == NULL)
        {
            delete root;
            root = NULL;
        }
        //Caso 2: Tiene 1 solo hijo
        else if (root->izquierda == NULL)
        {
            struct Node *temp = root; //esto es guardando la información del puntero que vamos a eliminar
            root = root->derecha; // Entonces volvemos el nodo derecho el principal
            delete temp; // y borramos el nodo que habiamos guardado en la variable temporal
        }
        else if (root->derecha = NULL)
        {
            struct Node *temp = root;
            root = root-> izquierda;
            delete temp; 
        }
        // caso 3: En el caso de 2 hijos
        else
        {
            struct Node *temp = FindMin(root->derecha);
            root->data = temp->data;
            root->derecha = EliminarElemento(root->derecha,temp->data);
        }
        

        return root;  
    }
    
    
}


bool BuscarElemento(Node *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return BuscarElemento(root->izquierda, data);
    else
        return BuscarElemento(root->derecha, data);
}

void isDigit(int &n)
{
    while (!(cin >> n))
    {
        cout << "Porfavor introduzca un valor valido";
        cin.clear();
        cin.ignore(123, '\n');
    }
}