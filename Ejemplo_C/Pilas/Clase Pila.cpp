#include "NodoPila.hpp"

class Pila
{
public:
    Pila();
    ~Pila();
    void insertar(int v);
    int extraer();
    int cima();
    void mostrar();
    int getLongitud();

private:
    pnodoPila ultimo;
    int longitud;
};

int Pila::cima() 
{ 
    pnodoPila nodo; 
    if(!ultimo) 
        return 0; 
    return ultimo->valor; 
}

void Pila::mostrar() 
{ 
    pnodoPila aux = ultimo; 
    cout << "\tEl contenido de la pila es: "; 
    while(aux) { 
        cout << "<-" << aux->valor; 
        aux = aux->siguiente; 
    } 
    cout << endl; 
}

int Pila::getLongitud() 
{ 
    return this->longitud; 
}

Pila::~Pila() 
{ 
    pnodoPila aux; 
    while(ultimo) { 
        aux = ultimo; 
        ultimo = ultimo->siguiente; 
        delete aux; 
    } 
}