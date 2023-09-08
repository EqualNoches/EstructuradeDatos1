

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* next;
};

Nodo* lista = NULL;
void Insertar(Nodo *&, int n);
void Mostrar(Nodo *);
void Buscar(Nodo *, int n);
void eliminarElemento(Nodo*&, int n);
void eliminarLista(Nodo*&, int&);
void ValidarElemento(int &);
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu() 
{
    int opcion, dato;
    do
    {
        cout << "\t.:Menu de Listas Enlazadas:.\n";
        cout << "1.Insertar un elemento de la lista\n";
        cout << "2.Mostar los elementos de la lista\n ";
        cout << "3.Buscar un elemento de la lista\n";
        cout << "4.Eliminar un elemento de la lista\n";
        cout << "5.Eliminar la lista\n";
        cout << "6.Salir\n";

        cout << " Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Inserta un numero: ";
            ValidarElemento(dato);
            Insertar(lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 2:
            if (lista == NULL) 
            {
                cout << "La lista esta vacia\n";
                system("pause");
            }
            else
            {
                Mostrar(lista);
                cout << "\n";
                system("pause");
            }
           
            break;
        case 3:
            if (lista == NULL)
            {
                cout << "La lista esta vacia\n";
                system("pause");
            }
            else
            {
                cout << "Digite el numero que desea buscar en la lista: ";
                ValidarElemento(dato);
                Buscar(lista, dato);
                cout << "\n";
                system("pause");
            }
            break;
        case 4:
            if (lista == NULL)
            {
                cout << "La lista esta vacia\n";
                system("pause");
            }
            else
            {
                cout << "Digite el numero que desea eliminar de la lista: ";
                ValidarElemento(dato);
                eliminarElemento(lista, dato);
                cout << "\n";
                system("pause");
                break;
            }
        case 5: while (lista != NULL)
        {
            eliminarLista(lista, dato);
            cout << dato << " -> ";
        }
              cout << "\n";
              system("pause");
            break;

        }

        system("cls");
        
        
    } while (opcion != 6);
}

void Insertar(Nodo *&lista,int n) 
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2 = NULL;

    while ((aux1 != NULL) && (aux1->dato < n))
    {
        aux2 = aux1;
        aux1 = aux1->next;
    }
    if (lista == aux1)
    {
        lista = nuevo_nodo;
    }
    else
    {
        aux2 -> next = nuevo_nodo;
    }
    
    nuevo_nodo->next = aux1;
    
    cout << "\tElemento " << n << " insertado a la lista correctamente\n";
}

void Mostrar(Nodo*lista) 
{
    Nodo* actual = new Nodo();

    actual = lista;
    while (actual != NULL)
    {
        cout << actual->dato << " -> ";
        actual = actual->next;
    }
}

void Buscar(Nodo *lista, int n) 
{
    bool found = false;

    Nodo* actual = new Nodo();
    actual = lista;

    while ((actual != NULL) && (actual->dato <= n))
    {
        if (actual->dato == n)
        {
            found = true;
        }
        actual = actual->next;

    }

    if (found == true)
    {
        cout << "Elemento " << n << " ha sido encontrado\n";
    }
    else
    {
        cout << "Elemento " << n << " no ha sido encontrado\n";
    }
}

void eliminarElemento(Nodo *&lista, int n) 
{
    if (lista != NULL)
    {
        Nodo* aux_borrar;
        Nodo* anterior = NULL;
        aux_borrar = lista;

        while ((aux_borrar != NULL) && (aux_borrar->dato != n))
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->next;
        }

        if (aux_borrar == NULL)
        {
            cout << "El elemento no existe";
        }
        else if (anterior == NULL)
        {
            lista = lista->next;
            delete aux_borrar;
        }
        else
        {
            anterior->next = aux_borrar->next;
            delete aux_borrar;
        }

    }
}

void eliminarLista(Nodo *&lista, int &n) 
{
    Nodo* aux = lista;
    n = aux->dato;
    lista = aux->next;
    delete aux;
}

void ValidarElemento(int &n) 
{
    while (!(cin >> n))
    {
        cout << "Porfavor introduzca un valor valido";
        cin.clear();
        cin.ignore(123, '\n');
    }
}


