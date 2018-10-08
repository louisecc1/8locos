#pragma once 
#include "CListaCircular.h"
#include "CPlayer.h"
class Game
{
public:
		Game();
		void run();
private:
	void processEvents();
	void update();
	void render();
	CListaCircular <CPlayer> players;
//	Lista_Enlazada_Doble Baraja;

};

