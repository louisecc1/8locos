#pragma once
#include<iostream>
using namespace std;
template<class T>
class CCNode
{
public:
	CCNode(T data)
	{
		n_data = data;
		n_next = nullptr;
	}
	T n_data;
	CCNode<T> *n_next;
};
template<class T>
class iterator_circular
{
public:
	iterator_circular(CCNode<T> *x = nullptr) {
		i = x;
	}

	CCNode<T> *i;
	
	iterator_circular operator=(iterator_circular *x)
	{
		i = x;
		return this;
	}
	iterator_circular* operator++()
	{
		i = i->n_next;
		return this;
	}
	T operator*()
	{
		return i->n_data;
	}
};
template<class T>
class CListaCircular
{
public:
	CListaCircular()
	{
		n_head = nullptr;
	}
	CCNode<T> *n_head;
	CCNode<T> *tail;
	typedef iterator_circular<T> iterator;
	iterator begin()
	{
		return n_head;
	}
	bool _find(T x, CCNode<T> **&p)
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
		CCNode<T> **p;
		if (_find(x, p))return 0;
		CCNode<T> *n = new CCNode<T>(x);
		n->n_next = *p;
		*p = n;
		if (!n->n_next)
		{
			n->n_next = n_head;
			tail = n;
		}
	}
	void recorrer()
	{
		CCNode<T> **p = &n_head;
		
		do {
			cout << (*p)->n_data.cp_name << " | ";
			p = &((*p)->n_next);
		} while (*p != n_head);
		cout << endl;		
	}
};