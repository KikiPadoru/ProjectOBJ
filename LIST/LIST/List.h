#pragma once
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
	//Init
	int Size;
	Node<T>* head;

public:

	//Default Constructor
	List<T>();
	List(T* a, int n);

	//Copy Constructor
	List<T>(const List<T>& a);
	//Destructor
	~List<T>() { clear(); }

	//Addition
	void push_back(T info);
	void push_front(T info);
	void insert(int pos, T info);
	void insert_at_sort(T value);
	void insert_node(int pos, Node<T>* node);

	//Search
	int search(T s);

	//Deletion
	void del(T del, Node<T>* pos = nullptr);
	void pop_front();
	void clear();

	//Sorting
	void insertion_sort();

	//Miscellaneous
	bool isEmpty();
	int get_Size();

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

	//Input
	friend istream& operator>>(istream& is, List<T>& a)
	{
		if (a.head) a.clear();
		a.head = nullptr;
		Node<T>* temp = nullptr;
		Node<T>* ptr = nullptr;
		T k;
		while (is >> k) {
			temp = new Node<T>(k, nullptr);
			if (!a.head) a.head = ptr = temp;
			else ptr->next = temp;
			ptr = temp;
		}
		if (is.bad()) cout << "bad";

		return is;
	}
};

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
inline void List<T>::pop_front()
{
	Node<T>* tmp = this->head;
	this->head = this->head->next;
	Size--;
	delete tmp;
}

template<class T>
inline void List<T>::clear()
{
	while (this->Size)
		pop_front();
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
	Node<T>* nd = new Node<T>(value, nullptr);
	cur = this->head;
	while (cur->next->info < nd->info)
	{
		cur = cur->next;
	}
	nd->next = cur->next->next;
	cur->next = nd;
}

template<class T>
inline void List<T>::insert_node(int pos, Node<T>* node)
{
	Node<T>* cur = this->head;
	if (pos == 0) {
		node->next = this->head;
		this->head = node;
	}
	else if (pos > this->Size)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = node;
	}
	else
	{
		int counter = 0;
		while (counter < pos - 1)
			cur = cur->next;
		node->next = cur->next->next;
		cur->next = node;
	}
	Size++;
}

template<class T>
inline void List<T>::insertion_sort()
{
	Node<T>* prev1 = this->head;
	Node<T>* prev2 = nullptr;
	Node<T>* cur1 = prev1->next;
	Node<T>* cur2 = nullptr;

	while (cur1)
	{
		cur2 = this->head;
		prev2 = nullptr;
		while (cur2 != cur1 && cur2->info < cur1->info)
		{
			prev2 = cur2;
			cur2 = cur2->next;
		}
		if (cur1 == cur2)
		{
			prev1 = cur1;
			cur1 = cur1->next;
		}
		else
		{
			prev1->next = cur1->next;
			if (prev2)
				prev2->next = cur1;
			else
				head = cur1;
			cur1->next = cur2;
			cur1 = prev1->next;
		}
	}
}

template<class T>
inline int List<T>::get_Size()
{
	return this->Size;
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

template<class T>
inline List<T>::List(T* a, int n)
{
	head = nullptr;

	Node<T>* ptr;
	for (int i = 0; i < n; i++)
	{
		Node<T>* temp = new Node<T>(a[i], nullptr);
		if (!head)
			head = ptr = temp;
		else
			ptr->next = temp;
		ptr = temp;
	}
}
