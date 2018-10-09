#include "pch.h"
#include "Game.h"


Game::Game()
	:players()
{
	int n;
	cout << "INGRESE LA CANTIDAD DE JUGADORES" << endl;
	cin >> n;
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
}
