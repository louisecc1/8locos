#pragma once 
#include "CListaCircular.h"
#include "CPlayer.h"
#include "CNode.h"
#include "ListaEnlazada.h"
#include "Cola.h"
#include "Pila.h"
class Game
{
public:
		Game(int);
		void run();
private:
	void processEvents();
	void update();
	void render();
	CListaCircular <CPlayer> players;
	CListaCircular <CPlayer> ::iterator iplayer;

	CNode<int, char>* baraja[52];
	Cola<CNode<int, char>*> ret;
	Pila<CNode<int, char>*> CartMesa;//son las cartas volteadas en la mesa//es decir la pila de descarte;

	const int numbPlayers;
	const int ganador;
	CNode<int, char>* auxi;//para poder buscar una posicion
	bool playCarta(false);
	bool addcarta(false);
	int valorC;
	char  paloC;
};

