#pragma once
template<class T,class S>
class CNode
{
public:
	CNode<T,S>*n_next;
	T n_data;
	T n_palo;
	CNode();
	CNode(T, S);
	bool operator <(CNode<T,S>);
	bool operator==(CNode<T, S>);
};
template CNode<int, char>;
