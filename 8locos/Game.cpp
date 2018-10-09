#include "pch.h"
#include "Game.h"


Game::Game()
	:players()
{
	int n;
	cout << "ingrese la cantidad de jugadores" << endl;
	cin >> n;
	--n;
	while (n)
	{
		CPlayer a;
		cin >> a.cp_name;
			
		if (players._insert(a))
		{
			--n;
		}
	}
}

/*
Game::~Game()
{
}
*/