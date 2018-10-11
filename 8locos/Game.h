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
	void barajar();
	CListaCircular <CPlayer> players;
	CListaCircular <CPlayer> ::iterator iplayer;

	CNode<int, char>* baraja[52];
	bool check[52];
	Cola<CNode<int, char>*> mazo;
	Pila<CNode<int, char>*> cartMesa;//son las cartas volteadas en la mesa//es decir la pila de descarte;

	const int numbPlayers;
	const int ganador;
	bool estadoJuego=false;//para q un jugador empieze su turno;
	CNode<int, char>* auxi;//para poder buscar una posicion
	bool playCarta=false;
	bool addcarta=false;
	bool terminar_jugada = false;
	int valorC;//valor nodo
	char  paloC;//palo nodo
};

