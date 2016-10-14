#include <iostream>

using namespace std;

struct Nodo {
	int num; // valor que contiene el nodo
	Nodo* sig; // puntero al siguiente nodo
};

void agregar(Nodo*& cola, int valor)
{
	Nodo* nuevo = new Nodo;
	nuevo->num = valor;
	nuevo->sig = NULL;
	if (cola == NULL) {
		cola = nuevo;
	} else {
		Nodo* aux = cola;
		while (aux->sig != NULL) //mientras que no sea el último
			aux = aux->sig;  //avanzo al siguiente
		aux->sig = nuevo;
	}
}

int pop(Nodo* &cola)
{
	int valor = cola->num;
	Nodo* aux_elim = cola;
	cola = cola->sig;
	delete aux_elim;
	return valor;
}

void mostrar(Nodo* lista)
{
	while (lista != NULL) {
		cout << lista->num << endl;
		lista = lista->sig;
	}
}


void concatenarColasV1(Nodo*& c1, Nodo*& c2, Nodo*& cf)
{
	while(c1 != NULL) {
		agregar(cf, c1->num);
		c1 = c1->sig;
	}
	while(c2 != NULL) {
		agregar(cf, c2->num);
		c2 = c2->sig;
	}
}

Nodo* concatenarColasV2(Nodo*& c1, Nodo*& c2)
{
	Nodo* colaConcat = NULL;
	while(c1 != NULL) {
		agregar(colaConcat, c1->num);
		c1 = c1->sig;
	}
	while(c2 != NULL) {
		agregar(colaConcat, c2->num);
		c2 = c2->sig;
	}
	return colaConcat;
}

int main()
{
	Nodo* cola1 = NULL;
	Nodo* cola2 = NULL;
	Nodo* cola3 = NULL;

	// V1

	agregar(cola1, 1);
	agregar(cola1, 2);
	agregar(cola1, 3);
	cout << endl << "Cola 1 ingresamos: 1 2 3. Listamos:" << endl;
	mostrar(cola1);

	agregar(cola2, 5);
	agregar(cola2, 20);
	agregar(cola2, 15);
	cout << endl << "Cola 2 ingresamos: 5 20 15. Listamos:" << endl;
	mostrar(cola2);

	cout << endl << "Ahora concantenamos las dos colas..." << endl;
        concatenarColasV1(cola1, cola2, cola3);

        cout << "Mostramos la Cola 3" << endl;
        mostrar(cola3);

	// V2

        agregar(cola1, 10);
	agregar(cola1, 20);
	agregar(cola1, 30);
	cout << endl << "Cola 1 ingresamos: 10 20 30. Listamos:" << endl;
	mostrar(cola1);

	agregar(cola2, 325);
	agregar(cola2, 12320);
	agregar(cola2, 1532);
	cout << endl << "Cola 2 ingresamos: 325 23320 1532. Listamos:" << endl;
	mostrar(cola2);

	cout << endl << "Ahora concatenamos las dos colas..." << endl;
        Nodo* colaR = concatenarColasV2(cola1, cola2);
        mostrar(colaR);

        cout << "cola1" <<endl;
        mostrar(cola1);
        cout << "cola2" <<endl;
        mostrar(cola2);

	return 0;
}
