#include "pch.h"
#include "CPlayer.h"
#include <iostream>

using namespace std;

CPlayer::CPlayer(string name)
	:cp_name(name),score(0),state(false)
	{}

void CPlayer::verMano() {
	mano.recorrer();
}

int CPlayer::getNumCartas() {
	int cnt = 0;
	for (CNode<int, char> **pNodo = &(mano.cabeza); *pNodo; pNodo = &((*pNodo)->n_next)) {
		cnt++;
	}
	return cnt;
}
