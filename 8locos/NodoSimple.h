#pragma once
template<class T>
class NodoSimple{
public:
	T dato;
	NodoSimple<T>* siguiente;
	NodoSimple(T d) {
		dato = d;
		siguiente = 0;
	}
};
