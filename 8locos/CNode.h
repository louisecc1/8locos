#pragma once
template<class T>
class CNode
{
public:
	CNode(T data)
	{
		n_data = data;
		n_next = n_prev = nullptr;
	}
	CNode<T>*n_next;
	CNode<T>*n_pre;
	T n_data;
};
