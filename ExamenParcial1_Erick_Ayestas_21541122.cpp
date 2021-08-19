#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

void agregar2(Nodo*&, Nodo*&, int);
void sacar1(Nodo*&, Nodo*&, int&);
bool esta_Vacia(Nodo*);

int main()
{
	Nodo* inicio = NULL;
	Nodo* final = NULL;

	int dato;
	cout << "Digite el codigo de barras:";
	cin >> dato;
	agregar2(inicio, final, dato);
	cout << "Digite el codigo de barras:";
	cin >> dato;
	agregar2(inicio, final, dato);
	cout << "Quitar los nodos";
	while (inicio != NULL) {
		sacar1(inicio, final, dato);
		if (inicio != NULL) {
			cout << dato << ",";
		}
		else {
			cout <<"Cantidad de cajas en existencia:" << dato << ",";
		}
	}
	return 0;
}


void agregar2(Nodo*&inicio ,Nodo *&final, int n) {
	Nodo* nuevo_nodo = new Nodo();

	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;

	if (esta_Vacia(inicio)) {
		inicio = nuevo_nodo;
	}
	else {
		final->siguiente = nuevo_nodo;
	}

	final = nuevo_nodo;
	cout << "\nElmento " << n << " Agregado correctamente" << endl;
}

void sacar1(Nodo*&inicio, Nodo *&final, int& n) {
	n = inicio->dato;
	Nodo* temp = inicio;
	if (inicio = final) {
		inicio = NULL;
		final = NULL;
	}
	else {
		inicio = inicio->siguiente;
	}
	delete temp;
}

bool esta_Vacia(Nodo*inicio) {
	return(inicio == NULL) ? true : false;
}