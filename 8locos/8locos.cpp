// 8locos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "CPlayer.h"
#include "CListaCircular.h"
#include <iostream>

void barajar(ListaEnlazada<int, char, CMenor<CNode<int, char> > > &ret,CNode<int,char> *bar[], bool *check,const int tam) {
	srand(time(NULL));
	int t = 0;
	for (int i = 0; i < tam; i++) {
		t = rand() % 52;
		if (check[t]==0)
		{
			check[t] = 1;
			ret.insertar(bar[t]->n_data, bar[t]->n_palo);
		}
	}
}

int main() 
{
	CPlayer a1("juan");
	CPlayer a2("pedro");
	CListaCircular<CPlayer> p;
	p._insert(a1);
	p._insert(a2);

}

