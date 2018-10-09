#include "pch.h"
#include "Game.h"


Game::Game(int n)
	:players(),numbPlayers(n),ganador(50*n)
{
	
	while (n)
	{
		int i = 1;
		CPlayer a;
		cout << "Player " << i <<" "<< "INGRESE SU NOMBRE" << endl;
		cin >> a.cp_name;
		if (players._insert(a))
		{
			i = i + 1;
			--n;
		}
		else
			cout << "ESTE NOMBRE YA EXISTE, INGRESE OTRO" << endl;

	}
	players.recorrer();
}/*
void Game::run()
{
	while () {

		while (!t)
		{
			processEvents();
			update();
			render();
		}
	}
}
void Game::processEvents()
{

}
void Game::update()
{
}
void Game::render()
{
}*/