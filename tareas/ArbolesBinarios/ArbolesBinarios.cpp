/*
Tarea 7. Gestión de un Árbol Binario de Búsqueda.
Fecha de Entrega: 22 de Septiembre 2022, horario de Laboratorio 20/22

Realizar un programa C++ que permita gestionar un Árbol Binario de Búsqueda. El programa
debe permitir insertar, buscar y eliminar un nodo; además de presentar (utilizando cualquiera
de los recorridos) el árbol de acuerdo a las reglas que existen para el árbol binario de búsqueda.

RESTRICCIONES:
    A. El primer nodo siempre será el root.
    B. Al presentar el árbol debe ser de un modo intuitivo, que muestre la topología de forma
        que represente en árbol.
    C. Puede utilizar cualquiera de los recorridos para arboles (InOrden, PreOrden o
        PostOrden).
    D. Al eliminar un nodo debe observar las reglas para la sustitución del nodo, permitiendo
        así que el árbol se reconstruya.
    E. Al insertar un nodo deben observarse las reglas para arboles binarios de búsqueda, es
        decir, los nodos cuyo valor sea mayor que el nodo raíz a la derecha (en el subárbol
        derecho), en caso contrario a la izquierda (en el subárbol izquierdo). Recordando que
        deben ocupar el lugar que le corresponda según la topología del árbol.

Participantes:
 #. Name - ID

 1. Edward Díaz - ID:1115808
 2. Hector Wittkop - ID:1115754
 3. Alexander Gil - ID:1116763
 4. Juan Ortiz - ID:1115143
 5. Jose de la Cruz - ID:1113682
 6. Erick Saviñon - ID:1115161

*/

/*

Realizar un programa C++ que permita gestionar un Árbol Binario de Búsqueda. El programa
debe permitir insertar, buscar y eliminar un nodo; además de presentar (utilizando cualquiera
de los recorridos) el árbol de acuerdo a las reglas que existen para el árbol binario de búsqueda.


RESTRICCIONES:
A. El primer nodo siempre será el root.
B. Al presentar el árbol debe ser de un modo intuitivo, que muestre la topología de forma
que represente en árbol.
C. Puede utilizar cualquiera de los recorridos para arboles (InOrden, PreOrden o
PostOrden).
D. Al eliminar un nodo debe observar las reglas para la sustitución del nodo, permitiendo
así que el árbol se reconstruya.
E. Al insertar un nodo deben observarse las reglas para arboles binarios de búsqueda, es
decir, los nodos cuyo valor sea mayor que el nodo raíz a la derecha (en el subárbol
derecho), en caso contrario a la izquierda (en el subárbol izquierdo). Recordando que
deben ocupar el lugar que le corresponda según la topología del árbol.


Participantes:
 #. Name - ID

 1. Edward Díaz - ID:1115808
 2. Hector Wittkop - ID:1115754
 3. Alexander Gil - ID:1116763
 4. Juan Ortiz - ID:1115143
 5. Jose de la Cruz - ID:1113682
 6. Erick Saviñon - ID:1115161

 Fecha: 22/9/2023

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node *izquierda;
    Node *derecha;
};

// Prototipos de funciones
Node *crearNodo(int);
Node *InsertarElemento(Node *&, int);
Node *FindMin(Node *);
struct Node *EliminarElemento(struct Node *, int);
void MostrarArbol(Node *, int);
void preOrden(Node*);
void inOrden(Node*);
void postOrden(Node *);
bool BuscarElemento(Node *, int);
void isDigit(int &);

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    int choice;
    int dato;
    int count = 0;

    while (true)
    {
        cout << "\n-----------------------------------------------------------------------" << endl
             << "  ------------Programa de Arboles binarios de Busqueda------------  " << endl
             << "  ----Estos se diferencian del resto, debido a su organizacion----  " << endl
             << "-----------------------------------------------------------------------\n"
             << endl
             << "1. Insertar Elementos al arbol" << endl
             << "2. Buscar elementos en el arbol" << endl
             << "3. Eliminar elemento del arbol" << endl
             << "4. Mostrar Arbol" << endl
             << "5. Pre-Orden"<< endl
             << "6. In-Orden"<< endl
             << "7. Post-Orden"<< endl
             << "8. Salir" << endl
             << "Opcion (1-5): ";
        isDigit(choice);

        switch (choice)
        {
        case 1:
            cout << "Eliga un numero para insertar en el arbol: ";
            isDigit(dato);
            InsertarElemento(root, dato);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Eliga que elemento quiere buscar";
            isDigit(dato);
            if (BuscarElemento(root, dato) == true)
            {
                cout << "El elemento " << dato << " se encuentra en la lista" << endl;
            }
            else
            {
                cout << " Elemento " << dato << " no encontrado" << endl;
            }
            system("pause");
            system("cls");
            break;

        case 3:
            cout << "Eliga que elemento quiere eliminar del arbol" << endl;
            isDigit(dato);
            EliminarElemento(root, dato);

            break;

        case 4:
            system("cls");
            cout << "Este es el despliegue del Arbol Binario de Busqueda" << endl;
            MostrarArbol(root, count);
            system("pause");
            system("cls");
            // terminar codigo
            break;
        case 5:
            system("cls");
            cout << "Pre-Orden";
            preOrden(root);
            cout << "\n\n";
            system("pause");
            break;
        case 6:
            system("cls");
            cout << "In-Orden";
            inOrden(root);
            cout << "\n\n";
            system("pause");
            break;
        case 7:
            system("cls");
            cout << "Post-Orden";
            postOrden(root);
            system("pause");
            break;
        case 8:
            cout << "Saliendo de la aplicación" << endl;
            system("cls");
            exit(0);
            break;
        default:
            cout << "Introduzca un valor valido." << endl;
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
    nuevo_nodo->derecha = nuevo_nodo->izquierda = NULL;
    return nuevo_nodo;
}
/// @brief Esta función se encargará de Instertar Nodos al Arbol ya especificado
/// @param root
/// @param data
/// @return
Node *InsertarElemento(Node *&root, int data)
{
    // Este primer caso es en el cual el arbol está vacio
    if (root == NULL) // si el Nodo "root" está vacio (que es la raiz).
    {
        Node *new_node = crearNodo(data); // Este se agregará en la primera poscicion del arbol
        root = new_node;
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

Node *FindMin(Node *root)
{
    Node *actual = root;
    while (actual->izquierda != NULL)
    {
        actual = actual->izquierda;
    }
    return actual;
}

Node *FindMax(Node *root)
{
    Node *actual = root;
    while (actual->derecha != NULL)
    {
        actual = actual->derecha;
    }
    return actual;
}
/*
    Para Eliminar un elemento en una lista, hay 3 posibilidades diferentes.
    caso 1: Que el nodo a Eliimnarse no tenga un hijo
    caso 2: Que el nodo a eliminarse solo tenga 1 hijo
    caso 3: Que el nodo a eliminarse tenga ambos hijos
*/
struct Node *EliminarElemento(struct Node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
    {
        root->izquierda = EliminarElemento(root->izquierda, data);
        // si la data que buscamos es menor al del nodo, este se va a eliminiar y se va a guardar la direccion de memoria en el nodo
    }
    else if (data > root->data)
    {
        root->derecha = EliminarElemento(root->derecha, data);
    }
    else // Esto se ejecuta cuando ya finalmente se encuentra el nodo para eliminar
    {
        // Caso 1: No Tiene Hijo
        if (root->derecha == NULL && root->izquierda == NULL)
        {
            delete root;
            root = NULL;
        }
        // Caso 2: Tiene 1 solo hijo
        else if (root->izquierda == NULL)
        {
            struct Node *temp = root; // esto es guardando la información del puntero que vamos a eliminar
            root = root->derecha;     // Entonces volvemos el nodo derecho el principal
            delete temp;              // y borramos el nodo que habiamos guardado en la variable temporal
        }
        else if (root->derecha == NULL)
        {
            struct Node *temp = root;
            root = root->izquierda;
            delete temp;
        }
        // caso 3: En el caso de 2 hijos
        else
        {
            if(root->derecha->izquierda)//si el nodo derecha tiene izquierda
            {
                Node *temp = FindMin(root->derecha);
                root->data = temp->data;
                root->derecha = EliminarElemento(root->derecha, temp->data);
            }
            else if (root->izquierda)
            {
                Node *temp = FindMax(root->izquierda);
                root->data = temp->data;
                root->izquierda = EliminarElemento(root->izquierda, temp->data);
            }
        }
    }
    return root;
}

void MostrarArbol(Node *root, int count)
{
    if (root == NULL)
        return;

    else
    {
        MostrarArbol(root->derecha, count + 1);
        for (int i = 0; i < count; i++)
        {
            cout << " ";
        }
        cout << root->data << endl;
        MostrarArbol(root->izquierda, count + 1);
    }
}

void preOrden(Node *root)
{
    if (root == NULL) return;
    else
    {
        cout <<root->data<<" - ";
        preOrden(root->izquierda);
        preOrden(root->derecha);
    }
    
}
void inOrden(Node *root)
{
    if (root == NULL)
        return;

    else
    {
        cout << root->data << " - ";
        inOrden(root->derecha);
    }
}

void postOrden(Node *root)
{
    if (root == NULL) return;
    else
    {
        postOrden(root->izquierda);
        postOrden(root->derecha);
        cout <<root->data<<" - ";
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
