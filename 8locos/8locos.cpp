// 8locos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "CNode.h"
#include "CMenor.h"
#include "ListaEnlazada.h"
#include <time.h>
#include <stdlib.h>
#include "pch.h"/*
#include "CPlayer.h"
#include "CListaCircular.h"*/
#include "Game.h"
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
	const int numCartas = 52;
	CNode<int, char>* baraja[numCartas];
	bool check[numCartas];
	for (int i = 0; i <= 12; i++) {
		for (char c = 'c'; c <= 'f'; c++) {
			baraja[i * 4 + (c - 'c')] = new CNode<int, char>(i + 1, c);
			check[i * 4 + (c - 'c')] = 0;
		}
	}
	ListaEnlazada<int, char, CMenor<CNode<int, char> > > ret;
	barajar(ret, baraja, check, numCartas);
	ListaEnlazada<int, char, CMenor<CNode<int, char> > > mano;
	CNode<int, char>* temp;
	for (int i = 0; i < 5; i++) {
		temp = ret.extraer();
		mano.insertar(temp->n_data, temp->n_palo);
		delete temp;
	}
	mano.recorrer();

}

