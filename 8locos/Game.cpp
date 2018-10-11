#include <time.h>
#include <stdlib.h>
#include "pch.h"
#include "Game.h"
#include <iostream>
using namespace std;
Game::Game(int n)
	:players(),numbPlayers(n),ganador(50*n),iplayer(players.begin())
{	
	playCarta = false;
	addcarta = false;
	for (int i = 0; i <= 12; i++) {
		for (char c = 'c'; c <= 'f'; c++) {
			baraja[i * 4 + (c - 'c')] = new CNode<int, char>(i + 1, c);
			check[i * 4 + (c - 'c')] = 0;
		}
	}
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
		//barajea el mazo
		barajar();
		//repartir cartas
		iplayer = players.begin();
		CNode<int, char>* carta;
		for (int i = 0; i < 8 * numbPlayers; i++) {
			carta = mazo.pop();
			(*iplayer).mano.insertarNodo(carta);
			++iplayer;
		}
		//Carta al mazo de descarte
		cartMesa.push(mazo.pop());
		paloC = cartMesa.cabeza->dato->n_palo;//dado valor de la carta secada de la baraja para comenzar el juego 
		valorC = cartMesa.cabeza->dato->n_data;//
		iplayer.i->n_data.state = false;
		iplayer = players.begin();//para q el juego siempre comienze con el primer jugador
		render();
		while ((*iplayer).state !=true)
		{
			processEvents();
			update();
			render();
		}
	}
}
void Game::processEvents()
{
	while(cartMesa._size == 1 && cartMesa.cabeza->dato->n_data == 8  )//verificar while
	{
		cartMesa.pop();//se quita la carta de la pila y regresandola a su lista inicial
		barajar();	//luego se llama a la funcion barajear
		cartMesa.push(mazo.pop());
		paloC = cartMesa.cola->dato->n_palo;
		valorC = cartMesa.cola->dato->n_data;
	}
	
	render();
	if (estadoJuego == false)
	{
		
		int temp=0;
		
		while (temp != 1)
		{
			cout << "INGRESE 1 PARA COMENZAR SU TURNO" << endl;
			cin >> temp;
		}
		estadoJuego = true;
	}
	else
	{
		//playCarta = false;
		//addcarta = false;
			//while (playCarta || addcarta)
			while(!playCarta)
			{
				cout << "AGREGAR UNA CARTA : ingrese 0" << endl;
				cout << "JUGAR UNA CARTA   : ingrese 1" << endl;
				bool temp(false);
				cin >> temp;
				if (temp)
				{
					cout << "ESCOJA LA POSICION DE LA CARTA QUE DESEA JUGAR" << endl;
					int temp;
					cin >> temp;
					auxi = nullptr;
					if (!((*iplayer).mano.position(temp, auxi)))//verificar lista
						cout << "NO EXISTE ESTA POSICION EN LA MANO" << endl;
					else if (auxi->n_data == valorC || auxi->n_palo == paloC)
						playCarta = true;
					else
						cout << "NO SE PUEDE JUGAR ESTA CARTA" << endl;
				}
				else
				{
					if (addcarta == 1)
					{
						cout << "USTED YA NO PUEDE AGREGAR SU UNA CARTA EN ESTA RONDA" << endl;
					}
					++addcarta;
					break;
				}
			}
		
		 if (playCarta || addcarta==2)
		{
			cout << "PRESIONE 1 PARA ACABAR SU JUGADA" << endl;
			int temp = 1;
			while (temp != 1)
			{
				cin >> temp;
			}
			terminar_jugada = true;
		}
	}
}
void Game::update()
{
	if (terminar_jugada)
	{
		playCarta = false;
		addcarta = 0;
		estadoJuego = false;
		terminar_jugada = false;
		if ((*iplayer).state != true)//para asegurarme q el iplayer q salga del while sea el ganador de la primera ronda;
			++iplayer;
	}
	if (playCarta)
	{
		cartMesa.push((*iplayer).mano.eliminarNodo(auxi));
		paloC = cartMesa.cabeza->dato->n_palo;
		valorC = cartMesa.cabeza->dato->n_data;
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
		if(!mazo.vacia()) {
			CNode<int, char>* carta= mazo.pop();
			(*iplayer).mano.insertarNodo(carta);
		}
	}
}
void Game::render()
{
	if (estadoJuego == false)
	{
		cout << "Carta en mesa:     " <<valorC<<paloC<< endl<<endl;
		cout << (*iplayer).cp_name << endl;
		cout << "---------------------" << endl;
	}
	else
	{
		cout << "Carta en mesa:     " << valorC << paloC << endl << endl;
		cout << (*iplayer).cp_name << endl;
		cout << (*iplayer).cp_name << endl;

		cout << "Mano jugador:" << endl;
		(*iplayer).mano.recorrer();
		cout << endl << endl;
	}
}

void Game::barajar() {
	mazo.vaciarCola();
	for (int i = 0; i < 52; i++)
		check[i] = 0;
	int t = 0;
	srand(time(NULL));
	for (int i = 0; i < 52; i++) {
		t = rand() % 52;
		if (check[t] == 0)
		{
			check[t] = 1;
			mazo.push(baraja[t]);
		}
	}
}