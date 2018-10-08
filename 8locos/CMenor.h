#pragma once
#include "CNode.h"

template <class T>
class CMenor
{
public:
	inline bool operator() (T a, T b) {
		return a < b;
	}
};
template CMenor<CNode<int, char> >;

