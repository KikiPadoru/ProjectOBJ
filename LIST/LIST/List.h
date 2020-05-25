#pragma once
#include "Price.h"
#include <iostream>
using namespace std;

template <class T>
class List
{
private:
	template <class T>
	class Node
	{
	public:
		T info;
		Node* next;
		Node(T info = T(), Node* next = nullptr)
		{
			this->info = info;
			this->next = next;
		}
	};

	int Size;
	Node<T>* head;

	int get_pos(T value);

public:
	//Constructors
	List<T>();
	List<T>(const List<T>& a);

	//Addition
	void push_back(T info);
	void push_front(T info);
	void insert(int pos, T info);
	void insert_at_sort(T value);

	//Search
	int search(T s);

	//Deletion
	void del(T del, Node<T>* pos = nullptr);
	void delete_node(const int index);
	
	//Sorting
	void insertion_sort();

	//Miscellaneous
	bool isEmpty();
	int get_Size();
	T& operator[](const int index);

	//var_1
	bool list_compare(const List<T> a);
	//var_2
	bool isSubset(const List<T> a);
	//var_8
	void dedup();

	//Output
	friend ostream& operator<<(ostream& os, const List<T> a)
	{
		Node<T>* cur = a.head;
		while (cur)
		{
			os << cur->info << endl;
			cur = cur->next;
		}
		return os;
	}

	//Intput
	friend istream& operator>>(istream& is, List<T>& a)
	{
		T in;	
		is >> in;
		a.push_back(in);
		return is;
	}

	//Miscellaneous
	Node<T>* get_node(const int index)
	{
		int counter = 0;
		Node<T>* cur = this->head;
		while (cur != nullptr)
		{
			if (counter == index)
			{
				return cur;
			}
			cur = cur->next;
			counter++;
		}
	}
};

template<class T>
inline int List<T>::get_pos(T value)
{
	Node<T>* cur = this->head;
	int pos = 0;
	while (cur)
	{
		if (value > cur->info)
			pos++;
		cur = cur->next;
	}
	return pos;
}

template<class T>
inline void List<T>::push_back(T info)
{
	if (head == nullptr)
	{
		head = new Node<T>(info);
	}
	else
	{
		Node<T>* cur = this->head;

		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = new Node<T>(info);
	}
	Size++;
}

template<class T>
inline void List<T>::push_front(T info)
{
	Node<T>* h = new Node<T>(info);
	h->next = this->head;
	this->head = h;
	Size++;
}

template<class T>
inline void List<T>::insert(int pos, T info)
{
	if (pos == 0)
		push_front(info);
	else if (pos > this->Size)
		push_back(info);
	else
	{
		Node<T>* cur = this->head;
		int counter = 0;
		while (counter != pos - 1)
		{
			cur = cur->next;
			counter++;
		}
		cur->next = new Node<T>(info, cur->next);
		Size++;
	}
}

template<class T>
inline int List<T>::search(T s)
{
	int counter = 0;
	Node<T>* cur = this->head;
	while (cur)
	{
		if (cur->info == s)
		{
			return counter;
		}
		cur = cur->next;
		counter++;
	}
}

template<class T>
inline void List<T>::del(T del, Node<T>* pos)
{
	Node<T>* cur = this->head;

	if (pos)
		cur = pos;

	if (this->head->info == del && !pos)
	{
		this->head = this->head->next;
		Size--;
		return;
	}
	while (cur->next != nullptr)
	{
		if (cur->next->info == del)
		{
			cur->next = cur->next->next;
			Size--;
			return;
		}
		cur = cur->next;
	}
}

template<class T>
inline void List<T>::delete_node(const int index)
{
	if (index > 0) {
		Node<T>* to_del = get_node(index - 1);
		to_del->next = to_del->next->next;
	}
	else
		this->head = this->head->next;
	Size--;
}

template<class T>
inline void List<T>::dedup()
{
	Node<T>* cur = this->head;
	while (cur)
	{
		for (int i = 0; i < this->Size; i++)
			del(cur->info, cur);
		cur = cur->next;
	}
}

template<class T>
inline bool List<T>::isEmpty()
{
	return !(this->Size);
}

template<class T>
inline void List<T>::insert_at_sort(T value)
{
	Node<T>* cur = this->head;
	while (cur->next != nullptr)
	{
		if (cur->info > cur->next->info)
		{
			cout << "It does not sorted!" << endl;
			return;
		}
		cur = cur->next;
	}
	insert(get_pos(value), value);
}

template<class T>
inline T& List<T>::operator[](const int index)
{
	return get_node(index)->info;
}

template<class T>
inline void List<T>::insertion_sort()
{
	for (int i = 1; i < Size; i++) {
		Node<T>* key = get_node(i);
		delete_node(i);
		int j = i - 1;
		while (j >= 0 && (*this)[j] > key->info)
		{
			j = j - 1;
		}
		insert(j + 1, key->info);
	}
}
template<class T>
inline bool List<T>::list_compare(const List<T> a)
{
	if (this->Size == a.Size)
	{
		Node<T>* cur_A = this->head;
		Node<T>* cur_B = a.head;
		while (cur_A)
		{
			if (cur_A->info != cur_B->info)
				return 0;
			cur_A = cur_A->next;
			cur_B = cur_B->next;
		}
	}
	else
		return 0;
	return 1;
}
template<class T>
inline int List<T>::get_Size()
{
	return this->Size;
}
template<class T>
inline bool List<T>::isSubset(const List<T> a)
{
	Node<T>* cur_A = this->head;
	Node<T>* cur_B = a.head;
	while (cur_A->info != cur_B->info)
		cur_B = cur_B->next;
	while (cur_A)
	{
		if (cur_A->info != cur_B->info)
			return 0;
		cur_A = cur_A->next;
		cur_B = cur_B->next;
	}
	return 1;
}
template<class T>
inline List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<class T>
inline List<T>::List(const List<T>& a)
{
	Size = 0;
	head = nullptr;
	Node<T>* cur = a.head;
	while (cur) {
		push_back(cur->info);
		cur = cur->next;
	}
}
