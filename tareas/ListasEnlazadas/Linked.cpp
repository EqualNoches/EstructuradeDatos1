

#include <iostream>
#include<stdlib.h>
using namespace std;

//Estructura de lista
struct LinkedList
{
	int dato;
	LinkedList *next;
};

//Prototipos de funcion
void Insertar(LinkedList *&, int);
void Mostrar(LinkedList*);
void Menu();
void Buscar(LinkedList*, int);
void Eliminar(LinkedList*&, int);

//Hacemos lista una variable global
LinkedList* lista = NULL;

int main()
{
	Menu();

	return 0;
}

//Metodo de insercion ordenado
void Insertar(LinkedList*& lista, int n) 
{
	LinkedList *nuevo = new LinkedList();
	nuevo->dato = n;

	LinkedList* aux1 = lista;
	LinkedList* aux2 = NULL;

	while ((aux1 != NULL) && (aux1->dato < n)) //Este bucle sirve para recorrer de manera ordenada la lista
	{
		aux2 = aux1;
		aux1 = aux1->next;
	}

	if (lista == aux1)//Este condicional se ejecuta cuando insertamos un elemento al principio
	{
		lista = nuevo;
		
	}
	else //Si ejecutamos este condicional significa que ya entramos al while y por ende recorrimos una posicion
	{
		aux2->next = nuevo;

	}
	nuevo->next = aux1;

	cout << "\tElemento " << n << " Insertado correctamente\n";

}

//Funcion para mostrar la lista en pantalla
void Mostrar(LinkedList* lista) 
{
	LinkedList* actual = new LinkedList();
	actual = lista;

	while (actual != NULL)//Este bucle nos sirve para imprimir al mismo tiempo en que recorremos la lista.
	{
		cout << actual->dato << " -> ";
		actual = actual->next;
	}
	if (lista == NULL)
	{
		cout << "La lista esta vacia\n";
	}
}

//Metodo del menu
void Menu() 
{
	int opc;
	int dato;

	do
	{
		cout << "\tMENU\n";
		cout << "1.Insertar elementos a la lista\n";
		cout << "2.Mostrar elementos de la lista \n";
		cout << "3.Buscar un elemento de la lista \n";
		cout << "4.Eliminar un elemento de la lista\n";
		cout << "5.Salir\n";
		cout << "\n";
		cout << "Digite la opcion que desea ejecutar: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "Inserta un numero: ";
			cin >> dato;
			Insertar(lista, dato);
			cout << "\n";
			system("pause");
			break;
		case 2:
			Mostrar(lista);
			cout << "\n";
			system("pause");
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
				cin >> dato;
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
				cin >> dato;
				Eliminar(lista, dato);
				cout << "\n";
				system("pause");
				break;
			}
			
		}

		system("cls");
	} while (opc != 5);

}

//Metodo para buscar elementos en la lista
void Buscar(LinkedList* lista, int n) 
{
	bool band = false; //Esta variable no sirve para determinar si encontramos el elemento

	LinkedList* actual = new LinkedList();
	actual = lista;

	while ((actual != NULL) && (actual->dato <= n))//Recorremos la lista con el bucle
	{
		if (actual->dato == n)//Si esta condicion se cumple encontramos el elemento
		{
			band = true;
		}
		actual = actual->next;
	}
	if (band == true)
	{
		cout << "Elemento " << n << " HA sido encontrado en la lista\n";
	}
	else
	{
		cout << "Elemento " << n << " NO existe en la lista\n";
	}



}

void Eliminar(LinkedList*& lista, int n) 
{

	if (lista != NULL)//Si esta condicion no se cumple significa que la lista esta vacia por ende todo el codigo de esta funcion se corre dentro del condicional
	{
		LinkedList* aux_del;
		LinkedList* prev = NULL;

		aux_del = lista;

		while ((aux_del != NULL) && (aux_del->dato != n))//Recorremos la lista en busca del valor a eliminar
		{
			prev = aux_del;
			aux_del = aux_del->next;
		}

		if (aux_del == NULL)
		{
			cout << "Elemento no encontrado en la lista";
		}
		else if (prev == NULL)//Si esta condicion se cumple signfica que estamos eliminando el primer elemento de la lista
		{
			lista = lista->next;
			delete aux_del;
			cout << "El elemento " << n << " Ha sido eliminado de la lista";
		}
		else
		{
			prev->next = aux_del->next;
			delete aux_del;
			cout << "El elemento " << n << " Ha sido eliminado de la lista";
		}



	}

}
