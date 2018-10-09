#pragma once
#include "CNode.h"
#include "CMenor.h"
template <class T,class S,class C>
class ListaEnlazada
{
	CNode<T,S> *cabeza = 0;
	C cM;
public:
	~ListaEnlazada();
	bool buscar(T,S,CNode<T,S> **&);
	bool insertar(T,S);
	bool eliminar(T,S);
	CNode<T, S>* extraer();
	void recorrer();
	void verPosibles(T,S,T);
};
template ListaEnlazada<int,char,CMenor<CNode<int,char> > >;
