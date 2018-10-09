#pragma once
#include "NodoSimple.h"
#include "CNode.h"

template <class T>
class Pila {
public:
	NodoSimple<T>*cabeza = 0;
	NodoSimple<T>*cola = 0;
	void push(T);
	T pop();
	bool vacia();
};
template Pila<CNode<int, char>*>;
