// 8locos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
//#include "CPlayer.h"
#include "CListaCircular.h"
int main() 
{
	CListaCircular<int> a;
	a._insert(2);
	a._insert(3);
	a._insert(9);	
	a._insert(8);
	a.recorrer();

}

