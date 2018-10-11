#include "pch.h"
#include "Game.h"
Game::Game(int n)
	:players(),numbPlayers(n),ganador(50*n),iplayer(players.begin())
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
}
void Game::run()
{
	while (ganador<=(*iplayer).score) {//verifica si el puntaje del ganador de la anterior ronda, es sufuciente para nadar el juego
		// aqui implementa barajear y q se reinicie  la mando de los jugadores, y tambien se da cartas a los jugadores




		//****wee tambien inicia CartMesa , es decir quita una carta de la baraja y ponle a la pila, CartMesa es la pila de descarte;
		paloC = CartMesa.cola->dato->n_palo;//dado valor de la carta secada de la baraja para comenzar el juego 
		valorC = CartMesa.cola->dato->n_data;//
		(*iplayer).state = false;
		iplayer = players.begin();//para q el juego siempre comienze con el primer jugador
		render();
		while ((*iplayer).state!=true)
		{
			processEvents();
			update();
			render();
			if ((*iplayer).state != true)//para asegurarme q el iplayer q salga del while sea el ganador de la primera ronda;
				++iplayer;
		}
	}
}
void Game::processEvents()
{
	if(CartMesa._size == 1 && CartMesa.cola->dato->n_data == 8  )
	{
			//se quita la carta de la pila y regresandola a su lista inicial
			//luego se llama a la funcion barajear
		paloC = CartMesa.cola->dato->n_palo;
		valorC = CartMesa.cola->dato->n_data;
		render();
	}
	playCarta=false;
	addcarta=false;
	while (playCarta || addcarta)
	{
		cout <<"AGREGAR UNA CARTA : ingrese 0" << endl;
		cout <<"JUGAR UNA CARTA   : ingrese 1" <<endl;
		bool temp(false);
		cin >> temp;
		if (temp)
		{
			cout << "ESCOJA LA POSICION DE LA CARTA QUE DESEA JUGAR" << endl;
			int temp;
			cin >> temp;
			auxi = nullptr;
			if (!((*iplayer).mano.position(temp, auxi)))
				cout << "NO EXISTE ESTA POSICION EN LA MANO" << endl;
			else if (auxi->n_data == valorC || auxi->n_palo == paloC)
				playCarta = true;
			else
				cout << "NO SE PUEDE AGREGAR ESTA PARTA" << endl;
		}
		else
			addcarta = true;
	}

}
void Game::update()
{
	if (playCarta)
	{
		//agrego una carta en la pila de descarte//es decir enCartMesa
				




















		//////////////////////////
		paloC = CartMesa.cola->dato->n_palo;
		valorC = CartMesa.cola->dato->n_data;
		if (valorC == 8)
		{
			cout << "USTED PUEDE CAMBIAR EL PALO A COLOCAR" << endl;
			cout << " ESCOJA E INGRESE ENTRE: c d e f";
			char auxi3;
			cin >> auxi3;
			while (auxi3 != 'c' || auxi3 != 'd' || auxi3 != 'e' || auxi3 != 'f')
			{
				cin >> auxi3;
				cout << "ESTE PALO NO EXISTE INGRESE ESCOJA OTRA VEZ" << endl;
			}
		}
	}
	if (addcarta) 
	{














	}
}
void Game::render()
{































}