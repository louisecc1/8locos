#pragma once
#include<iostream>
using namespace std;
template<class T>
class CNode
{
public:
	CNode(T data)
	{
		n_data = data;
		n_next = nullptr;
	}
	T n_data;
	CNode<T> *n_next;
};

template<class T>
class CListaCircular
{
public:
	CListaCircular()
	{
		n_head = nullptr;
	}
	CNode<T> *n_head;
	CNode<T> *tail;
	bool _find(T x, CNode<T> **&p)
	{
		p = &n_head;

		while (*p && (*p)->n_data != x) {
		/*	if ((*p)->n_next == n_head)
				break;*/
			p = &((*p)->n_next);
			if ((*p) == n_head)
				break;
		}
		return *p && (*p)->n_data == x;
	}
	bool _insert(T x)
	{
		CNode<T> **p;
		if (_find(x, p))return 0;
		CNode<T> *n = new CNode<T>(x);
		n->n_next = *p;
		*p = n;
		if (!n->n_next)
		{
			n->n_next = n_head;
			tail = n;
		}
	/*	else
		{
			tail->n_next = n_head;
		}*/
	}
	void recorrer()
	{
		CNode<T> **p = &n_head;
		
		do {
			cout << (*p)->n_data << " | ";
			p = &((*p)->n_next);
		} while (*p != n_head);
		cout << endl;
		
	}

};