#include "pch.h"
#include "ListaEnlazada.h"
#include "CNode.h"
#include <iostream>

using namespace std;

/*template<class T, class S, class C>
ListaEnlazada<T, S, C>::~ListaEnlazada() {
	CNode<T, S> *temp;
	CNode<T,S>* pNodo = cabeza;
	while (pNodo){
		temp = pNodo;
		pNodo = pNodo->n_next;
		delete temp;
	}
}*/

//Compatibilidad----------------------------------------------------------------
template<class T, class S, class C>
bool ListaEnlazada<T, S, C>::buscar(T valor, S palo,CNode<T,S> **& pNodo) {
	pNodo = &cabeza;
	CNode<T, S>* temp = new CNode<T, S>(valor, palo);
	while (*pNodo&&cM(*(*pNodo),*temp))
		pNodo = &((*pNodo)->n_next);
	bool ret = (*pNodo && (*(*pNodo) == *temp));
	delete temp;
	return  ret;
}

template<class T, class S, class C>
bool ListaEnlazada<T, S, C>::buscarNodo(CNode<T, S> *&pInfo, CNode<T, S> **& pNodo) {
	pNodo = &cabeza;
	while (*pNodo&&cM(*(*pNodo), *pInfo))
		pNodo = &((*pNodo)->n_next);
	return  (*pNodo && (*(*pNodo) == *pInfo));
}

//Compatibilidad----------------------------------------------------------------
template<class T, class S, class C>
bool ListaEnlazada<T, S, C>::insertar(T valor,S palo) {
	CNode<T,S>** pNodo;
	if (buscar(valor,palo, pNodo))
		return 0;
	CNode<T,S>* n = new CNode<T,S>(valor,palo);
	n->n_next = *pNodo;
	*pNodo = n;
	return 1;
}


template<class T, class S, class C>
bool ListaEnlazada<T, S, C>::insertarNodo(CNode<T, S> *pInfo) {
	CNode<T, S>** pNodo;
	if (buscarNodo(pInfo, pNodo))
		return 0;
	//CNode<T, S>* n = new CNode<T, S>(valor, palo);
	pInfo->n_next = *pNodo;
	*pNodo = pInfo;
	return 1;
}

//Compatibilidad----------------------------------------------------------------
template<class T, class S, class C>
bool ListaEnlazada<T, S, C>::eliminar(T valor,S palo) {
	CNode<T,S>** pNodo;
	if (!buscar(valor,palo, pNodo))
		return 0;
	CNode<T,S>* temp = *pNodo;
	*pNodo = temp->n_next;
	delete temp;
	return 1;
}

template<class T, class S, class C>
CNode<T, S>* ListaEnlazada<T, S, C>::eliminarNodo(CNode<T, S>* pInfo) {
	CNode<T, S>** pNodo;
	if (!buscarNodo(pInfo, pNodo))
		return 0;
	//CNode<T, S>* temp = *pNodo;
	pInfo = (*pNodo);
	*pNodo = (*pNodo)->n_next;
	pInfo->n_next = 0;
	//delete temp;
	return pInfo;
}

template<class  T, class S, class C>
void ListaEnlazada<T, S, C>::recorrer() {
	int cnt = 1;
	for (CNode<T, S>** pNodo = &cabeza; *pNodo; pNodo = &((*pNodo)->n_next)) {
		cout << cnt<<") "<<(*pNodo)->n_data << (char)((*pNodo)->n_palo) << endl;
		cnt++;
	}
		
	//cout << endl;
}

//Compatibilidad----------------------------------------------------------------
template<class  T, class S, class C>
void ListaEnlazada<T, S, C>::verPosibles(T valor,S palo,T loco) {
	for (CNode<T,S>** pNodo = &cabeza; *pNodo; pNodo = &((*pNodo)->n_next)) {
		if((*pNodo)->n_data==loco||(*pNodo)->n_data==valor||(*pNodo)->n_palo==palo)
			cout << (*pNodo)->n_data << (*pNodo)->n_palo << " | ";
	}
	cout << endl;
}
template<class  T, class S, class C>
bool ListaEnlazada<T, S, C> ::position(int n,CNode<T,S> *&p)
{
	CNode<T, S>** pNodo = &cabeza;
	while (*pNodo && --n)
	{
		pNodo = &((*pNodo)->n_next);
	}
	p = (*pNodo);			//nose muy bn si esto esta bn dale un chequeada;
	return *pNodo;
}