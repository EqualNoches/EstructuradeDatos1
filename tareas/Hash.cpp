/* Realizar un programa C++ que acepte un ID (su ID asignado por el INTEC) y ubique al estudiante en el índice correspondiente. La estructura para este caso debe ser:

struct Estudiante {
    int id;
    string nombre;
    string cod_carrera
    int indice_acad;
} hash[MAX];  //  MAX  es la cantidad de estudiantes de su sección

La tabla hash está limitada a MAX (en su caso estará limitada al número de estudiantes de su sección de Estructuras de Datos y Algoritmos), por lo que solo aceptará los ID distintos de su clase y asignará la posición correspondiente.

RESTRICCIONES:

1-	Colecte todas los ID de su clase
2-	El algoritmo hash no debe permitir generar un índice mayor a MAX (cantidad de estudiantes en su sección)
3-	Realice una función hash que le permita asignar un índice a cada estudiante, evitando colisiones. Recuerde que el índice máximo es la cantidad de estudiante de su clase.
4-	Una opción que permita que una vez se suministre el ID y se indique su índice, permita insertar los datos correspondientes al registro señalado en el índice asignado:
        ID: (ID dado)
        NOMBRE:
        CARRERA:
        INDICE ACADEMICO: 
5-	Una opción que permita desplegar todos los registros en la tabla 
6-	Una opción que permite desplegar el contenido del registro, dado el ID


Participantes:
 #. Name - ID

 1. Edward Díaz - ID:1115808
 2. Hector Wittkop - ID:1115754
 3. Alexander Gil - ID:1116763
 4. Juan Ortiz - ID:1115143
 5. Jose de la Cruz - ID:1113682
 6. Erick Saviñon - ID:1115161

 Fecha: 6/10/2023

*/

#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

struct Estudiante 
{
	int id;
	string nombre;
	string cod_carrera;
	float indice_acad;
};

struct NodoEstudiante //NodoEstudiante para listaEnlazada, esto con el fin de manejar las posibles colisiones de la tabla
{
	Estudiante estudiante;
	NodoEstudiante* siguiente;
};

vector<NodoEstudiante*> tablaHash;
vector <int> indices;
int funcionHash(int id)
{
	int indice;
	bool repetido = false;
	indice = id % tablaHash.size();
	for (int i = 0; i < indices.size(); i++) //Este bucle sirve para recorrer la tabla de manera ascendente intentando evitar colisiones en la insercion
	{
		while (indices[i] == indice)// Si el programa entra en este bucle tenemos una colision por ende incrementa el indice y comienza desde 0
		{
			indice++;
			i = 0;
		}
		if (indice == tablaHash.size()) //Esta condicion nos sirve para evaluar si llegamos al final de la tabla en busca de un indice
		{
			for (int e = 0; e < indices.size(); e++) //Este bucle recorre de manera descendiente la tabla en busca de un indice que no colisione
			{
				while (indices[e] == indice)
				{
					indice--;
					e = 0;
				}
			}

		}
	}
	indices.push_back(indice); //agregamos el indice al registro de indices
	return indice;

}

string verificar() //Esta funcion nos sirve para validar que la entrada del usuario sea una cadena de letras unicamente
{

	string entrada;
	bool valido = false;
	while (!valido)
	{
		cin >> entrada;
		for (char c : entrada) {
			if (!('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z')) {
				cout << "\nEntrada invalida: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else valido = true;
		}
	}
	return entrada;
}

int obtenerIntValido() //Como su nombre indica verifica que el dato ingresado por el usuario sea un INT.
{
	int number;
	while (!(cin >> number)) {
		cout << "\nEntrada invalida: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return number;
}

void insertarEstudiante(int id) 
{
	int indice = funcionHash(id);
	NodoEstudiante* nuevoEstudiante = new NodoEstudiante;
	nuevoEstudiante->estudiante.id = id;
	cout << "Indice: " << indice;
	cout << "\nNOMBRE: ";
	cin.ignore(); //Sirve para eliminar caracteres adicionales que hayan permanecido luego de la ultima entrada
	nuevoEstudiante->estudiante.nombre = verificar();
	cout << "CARRERA: ";
	nuevoEstudiante->estudiante.cod_carrera = verificar();
	while (true) //Utilizamos este bucle para validar que el usuario introduzca un indice academico valido, digase entre 0 y 4.
	{
		cout << "INDICE ACADEMICO: ";
		nuevoEstudiante->estudiante.indice_acad = obtenerIntValido();

		if (nuevoEstudiante->estudiante.indice_acad < 0 || nuevoEstudiante->estudiante.indice_acad > 4)
		{
			cout << "Entrada invalida, el indice debe ser entre 0-4\n";
		}
		else break;
	}
	nuevoEstudiante->siguiente = nullptr; //inicializamos el puntero siguiente
	if (indice != 0) //Verifica que el indice calculado no sea cero
	{
		if (tablaHash[indice - 1] == nullptr)//Si el indice previo esta vacio insertamos el estudiante ahi
		{
			tablaHash[indice - 1] = nuevoEstudiante;
		}
		else 
		{
			NodoEstudiante* actual = tablaHash[indice - 1];
			while (actual->siguiente != nullptr) //Recorremos la lista hasta encontrar el ultimo estudiante
			{
				actual = actual->siguiente;
			}
			actual->siguiente = nuevoEstudiante; //Enlaza el estudiante al final de la lista
		}
	}
	else //Si el indice es 0 usamos una logica similar
	{
		if (tablaHash[indice] == nullptr)// si el indice esta vacio colocamos el estudiante ahi
		{
			tablaHash[indice] = nuevoEstudiante;
		}
		else {
			NodoEstudiante* actual = tablaHash[indice];
			while (actual->siguiente != nullptr) //Caso contrario llegamos hasta al final para colocarlo ahi
			{
				actual = actual->siguiente;
			}
			actual->siguiente = nuevoEstudiante;
		}
	}
}

bool hayRegistros() //Sirve para verificar si la tabla tiene algun estudiante
{
	for (size_t i = 0; i < tablaHash.size(); i++) {
		if (tablaHash[i] != nullptr) {
			return true;
		}
	}
	return false;
}

void mostrarRegistros() 
{
	if (!hayRegistros()) {
		cout << "No hay registros para mostrar." << endl;
		return;
	}

	for (size_t i = 0; i < tablaHash.size(); i++) {
		NodoEstudiante* actual = tablaHash[i];
		while (actual != nullptr) {
			cout << "ID: " << actual->estudiante.id << endl;
			cout << "Indice: " << indices[i] << endl;
			cout << "NOMBRE: " << actual->estudiante.nombre << endl;
			cout << "CARRERA: " << actual->estudiante.cod_carrera << endl;
			cout << "INDICE ACADEMICO: " << actual->estudiante.indice_acad << endl;
			cout << "-------------------------" << endl;
			actual = actual->siguiente;
		}
	}
}

void mostrarRegistroPorID(int id) //Mostrar registro especifico
{

	for (int i = 0; i < tablaHash.size(); i++)
	{
		NodoEstudiante* actual = tablaHash[i];
		while (actual != nullptr) {
			int indice = indices[i];
			if (actual->estudiante.id == id) {
				cout << "Indice: " << indice << endl;
				cout << "NOMBRE: " << actual->estudiante.nombre << endl;
				cout << "CARRERA: " << actual->estudiante.cod_carrera << endl;
				cout << "INDICE ACADEMICO: " << actual->estudiante.indice_acad << endl;
				return;
			}
			actual = actual->siguiente;
		}
	}


	cout << "El ID no fue encontrado." << endl;
}

void eliminarRegistroPorID(int id) //Eliminar registro especifico
{
	NodoEstudiante* anterior = nullptr;
	for (int i = 0; i < tablaHash.size(); i++)
	{
		NodoEstudiante* actual = tablaHash[i];
		while (actual != nullptr) {
			int indice = indices[i];
			if (actual->estudiante.id == id) {
				if (anterior == nullptr) {
					tablaHash[indice - 1] = actual->siguiente;
				}
				else {
					anterior->siguiente = actual->siguiente;
				}
				delete actual;
				cout << "El registro con ID " << id << " ha sido eliminado." << endl;
				return;
			}
			anterior = actual;
			actual = actual->siguiente;

		}
	}
	cout << "El ID no fue encontrado." << endl;
}

void eliminarTodosLosRegistros() 
{
	for (size_t i = 0; i < tablaHash.size(); i++) {
		NodoEstudiante* actual = tablaHash[i];
		while (actual != nullptr) {
			NodoEstudiante* siguiente = actual->siguiente;
			delete actual;
			actual = siguiente;
		}
		tablaHash[i] = nullptr;
	}
	cout << "Todos los registros han sido eliminados." << endl;
}

bool continuar() //Sirve para continuar iterando el programa
{
	cout << "¿Desea continuar? (S/N)\n";
	string ans;
	cin >> ans;
	for (char& c : ans) {
		c = tolower(c);
	}
	if (ans != "s" && ans != "n") {
		do {
			cout << "Opción inválida.\n";
			cin >> ans;
		} while (ans != "s" && ans != "n");
	}
	return ans == "s";
}

void cls() {
	if (continuar()) {
		cout << "Entendido" << endl;
		system("cls");
	}
	else {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		exit(0);
	}
}

int main() {
	cout << "Ingrese la cantidad de estudiantes en su seccion: ";
	int numEstudiantes = obtenerIntValido();
	tablaHash.resize(numEstudiantes, nullptr);

	int opcion, id, contador = 0, indice;
	bool repetido = false;
	vector <int> Ids;
	do {
		cout << "Menu:" << endl;
		cout << "1. Insertar estudiante" << endl;
		cout << "2. Mostrar todos los registros" << endl;
		cout << "3. Mostrar registro por ID" << endl;
		cout << "4. Eliminar registro por ID" << endl; // Nueva opción
		cout << "5. Eliminar todos los registros" << endl; // Nueva opción
		cout << "6. Salir" << endl;
		cout << "Ingrese su opcion: ";
		opcion = obtenerIntValido();

		switch (opcion) {
		case 1: {
			id = 0;
			if (contador >= numEstudiantes)
			{
				cout << "ya se a alcanzado el limite de estudiantes en la seccion\n";
				contador = 0;
				cls();
				break;
			}
			while (id <= 1000000 || id >= 9999999 || repetido == true) //Esta condicion sirve para asegurarse de que el ID ingresado sea valido y unico
			{
				cout << "\nID: ";
				id = obtenerIntValido();
				for (int i = 0; i < Ids.size(); i++)
				{
					if (Ids[i] == id)
					{
						cout << "Dos estudiantes no pueden tener el mismo id";
						repetido = true;
					}
					else repetido = false;

				}
				if (id <= 1000000 || id >= 9999999)
				{
					cout << "entrada invalida(ingresar numero de 7 digitos)";
				}
			}
			insertarEstudiante(id);
			Ids.push_back(id);
			contador++;
			cls();
			break;
		}
		case 2:
			mostrarRegistros();
			cls();
			break;
		case 3: {
			if (!hayRegistros()) {
				cout << "No hay registros para buscar." << endl;
				cls();
				continue;
			}
			cout << "ID: ";
			int id = obtenerIntValido();
			mostrarRegistroPorID(id);
			cls();
			break;
		}
		case 4: {
			if (!hayRegistros()) {
				cout << "No hay registros para eliminar." << endl;
				cls();
				continue;
			}
			cout << "ID a eliminar: ";
			int id = obtenerIntValido();
			eliminarRegistroPorID(id);
			contador--;
			cls();
			break;
		}
		case 5: {
			if (!hayRegistros()) {
				cout << "No hay registros para eliminar." << endl;
				cls();
				continue;
			}
			eliminarTodosLosRegistros();
			contador = 0;
			cls();
			break;
		}
		case 6:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opcion inválida. Intente nuevamente." << endl;
			break;
		}
	} while (opcion != 6);

	return 0;
}
