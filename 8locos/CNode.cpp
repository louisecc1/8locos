#include "pch.h"
#include "CNode.h"

template<class T, class S>
CNode<T, S>::CNode()
{
	n_data = 0;
	n_palo = 0;
	n_next = nullptr;
}

template<class T, class S>
CNode<T,S>::CNode(T valor, S palo)
{
	n_data = valor;
	n_palo = palo;
	n_next = nullptr;
}

template<class T, class S>
bool CNode<T, S>::operator<(CNode<T, S> otro) {
	if (n_data < otro.n_data)
		return true;
	if(n_data == otro.n_data)
		if(n_palo<otro.n_palo)
			return true;
	return false;
}

template<class T, class S>
bool CNode<T, S>::operator==(CNode<T, S> otro) {
	return (n_data==otro.n_data&&n_palo==otro.n_palo);
}