#pragma once 
#include "CListaCircular.h"
#include "CPlayer.h"
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
	int numbPlayers;
	const int ganador;

};

