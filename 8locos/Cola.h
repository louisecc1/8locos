#pragma once
#include "CNode.h"
#include "NodoSimple.h"

template <class T>
class Cola {
public:
	NodoSimple<T>*cabeza = 0;
	NodoSimple<T>*cola = 0;
	void push(T);
	T pop();
	void vaciarCola();
	bool vacia();
};
template Cola<CNode<int, char>*>;
