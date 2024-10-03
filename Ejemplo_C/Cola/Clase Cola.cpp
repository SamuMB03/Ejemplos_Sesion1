#include "Cola.hpp"

Cola::Cola() {
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(int v) {
    pnodoCola nuevo;
    nuevo = new NodoCola(v); // Crear un nuevo nodo con el valor v
    if (ultimo)
        ultimo->siguiente = nuevo; // Enlazar el nuevo nodo al final de la cola

    ultimo = nuevo; // Actualizar el puntero de último

    if (!primero) // Si la cola estaba vacía, el nuevo nodo es el primero
        primero = nuevo;

    longitud++; // Aumentar la longitud de la cola
}

void Cola::mostrar() {
    pnodoCola aux = primero;
    cout << "\tEl contenido de la cola es: ";
    while (aux) {
        cout << "-> " << aux->valor; // Imprimir el valor de cada nodo
        aux = aux->siguiente; // Avanzar al siguiente nodo
    }
    cout << endl;
}

int Cola::eliminar() {
    pnodoCola nodo;
    int v;
    nodo = primero;
    if (!nodo)
        return 0;
    primero = nodo->siguiente;
    v = nodo->valor;
    delete nodo;
    if (!primero)
        ultimo = NULL;
    longitud--;
    return v;
}

int Cola::verPrimero() {
    return primero->valor;
}

Cola::~Cola() {
    while (primero)
        eliminar();
}