#pragma once
#include "CNode.h"
#include "CMenor.h"
template <class T,class S,class C>
class ListaEnlazada
{
	C cM;
public:
	CNode<T, S> *cabeza = 0;
	//~ListaEnlazada();
	bool buscar(T,S,CNode<T,S> **&);
	bool buscarNodo(CNode<T,S>*&,CNode<T, S> **&);
	bool insertar(T,S);
	bool insertarNodo(CNode<T, S>*);
	bool eliminar(T,S);
	CNode<T, S>* eliminarNodo(CNode<T, S>*);
	void recorrer();
	void verPosibles(T,S,T);
	bool position(int, CNode<T, S>*&);//*******he agregado esto fijate si esta correcto
};
template ListaEnlazada<int,char,CMenor<CNode<int,char> > >;

