// 8locos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "CPlayer.h"
#include "CListaCircular.h"
#include <iostream>
using namespace std;
int main() 
{
	CPlayer a1("juan");
	CPlayer a2("pedro");
	CListaCircular<CPlayer> p;
	p._insert(a1);
	p._insert(a2);

}

