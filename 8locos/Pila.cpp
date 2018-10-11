#include "pch.h"
#include "Pila.h"

template<class T>
void Pila<T>::push(T d) {
	++_size;
	NodoSimple<T>* nuevo = new NodoSimple<T>(d);
	if (!cabeza) {
		cola = nuevo;
		cabeza = nuevo;
		return;
	}
	nuevo->siguiente = cabeza;
	cabeza = nuevo;
}
template void Pila<int>::push(int);

template<class T>
T Pila<T>::pop() {
	--_size;
	NodoSimple<T>* temp;
	T val;
	if (cabeza == cola) {
		temp = cabeza;
		val = cabeza->dato;
		cola = 0;
		cabeza = 0;
	}
	else {
		temp = cabeza;
		val = temp->dato;
		cabeza = cabeza->siguiente;
	}
	//delete temp;
	temp->siguiente = 0;
	return val;
}
template int Pila<int>::pop();

template<class T>
bool Pila<T>::vacia() {
	return (cabeza == 0);
}
template bool Pila<int>::vacia();

