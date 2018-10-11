#pragma once
#include<iostream>
#include<string>
#include "ListaEnlazada.h"
#include "CMenor.h"
#include "CNode.h"
using namespace std;
class CPlayer
{
public:
	CPlayer() { state = score = 0; }
	CPlayer(string);
	void verMano();
	int getNumCartas();
	
	string cp_name;
	int score;
	bool state;
	ListaEnlazada<int, char, CMenor<CNode<int, char> > > mano;
};
inline bool operator== (const CPlayer & a, const CPlayer &b)
	{	return a.cp_name == b.cp_name;}
inline bool operator!= (const CPlayer & a, const CPlayer &b)
{
	return !(a.cp_name == b.cp_name);
}