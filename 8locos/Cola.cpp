#include "pch.h"
#include "Cola.h"
#include "NodoSimple.h"

template<class T>
void Cola<T>::push(T d) {
	NodoSimple<T>* nuevo = new NodoSimple<T>(d);
	if (!cola) {
		cola = nuevo;
		cabeza = nuevo;
		return;
	}
	cola->siguiente = nuevo;
	cola = nuevo;
}

template<class T>
T Cola<T>::pop() {
	NodoSimple<T>* temp;
	T val;
	if (cabeza == cola) {
		temp = cola;
		val = cola->dato;
		cola = 0;
		cabeza = 0;
	}
	else {
		temp = cabeza;
		val = cabeza->dato;
		cabeza = cabeza->siguiente;
	}
	temp->siguiente = 0;
	//delete temp;
	return val;
}

template<class T>
bool Cola<T>::vacia() {
	return (cabeza == 0);
}

template<class T>
void Cola<T>::vaciarCola() {
	cola ->siguiente = 0;
	cabeza = 0;
	cola = 0;
}