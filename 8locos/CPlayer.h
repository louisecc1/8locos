#pragma once
#include<iostream>
#include<string>;
using namespace std;
class CPlayer
{
public:
	CPlayer() { state = score = 0; }
	CPlayer(string);	
	
	string cp_name;
	int score;
	bool state;
};
inline bool operator== (const CPlayer & a, const CPlayer &b)
	{	return a.cp_name == b.cp_name;}
inline bool operator!= (const CPlayer & a, const CPlayer &b)
{
	return !(a.cp_name == b.cp_name);
}