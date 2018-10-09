// 8locos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "CNode.h"
#include "CMenor.h"
#include "ListaEnlazada.h"
#include "Cola.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

void barajar(Cola<CNode<int, char>*> &ret,CNode<int,char> *bar[], bool *check,const int tam) {
	int t = 0;
	srand(time(NULL));
	for (int i = 0; i < tam; i++) {
		t = rand() % 52;
		if (check[t]==0)
		{
			check[t] = 1;
			ret.push(bar[t]);
		}
	}
}

int main() 
{
	const int numCartas=52;
	CNode<int, char>* baraja[numCartas];
	bool check[numCartas];
	for (int i = 0; i <= 12; i++) {
		for (char c = 'c'; c <= 'f'; c++) {
			baraja[i*4+(c-'c')] = new CNode<int, char>(i+1, c);
			check[i * 4 + (c - 'c')] = 0;
		}		
	}
	Cola<CNode<int,char>*> ret;
	barajar(ret, baraja, check, numCartas);
	ListaEnlazada<int, char, CMenor<CNode<int, char> > > mano;
	CNode<int, char>* temp;
	for (int i = 0; i < 5; i++) {
		temp = ret.pop();
		mano.insertarNodo(temp);
	}
	mano.recorrer();
}

