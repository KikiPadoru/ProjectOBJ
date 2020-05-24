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

	int Size;
	Node<T>* head;


public:

	List<T>()
	{
		Size = 0;
		head = nullptr;
	}
	~List<T>() {}

	void push_back(T info)
	{
		if (head == nullptr)
		{
			head = new Node<T>(info);
			Size++;
		}
		else
		{
			Node<T>* cur = this->head;

			while (cur->next != nullptr)
			{
				cur = cur->next;
			}
			cur->next = new Node<T>(info);
			Size++;
		}
	}

	void push_front(T info)
	{
		Node<T>* h = new Node<T>(info);
		h->next = this->head;
		this->head = h;
		Size++;
	}

	Node<T>* search(T s)
	{
		Node<T>* cur = this->head;
		while (cur->next != nullptr)
		{
			if (cur->info == s)
			{
				return cur;
			}
			cur = cur->next;
		}
	}

	void del(T del)
	{
		Node<T>* cur = this->head;

		while (cur->next != nullptr)
		{
			if (cur->next->info == del)
			{
				cur->next = cur->next->next;
				cur = this->head;
			}
			cur = cur->next;
		}
	}

	void print()
	{
		Node<T>* cur = this->head;
		while (cur)
		{
			cout << cur->info << " ";
			cur = cur->next;
		}
		cout << endl;
	}

	int isEmpty()
	{
		if (Size) return 1;
		return 0;
	}

	T& operator[](const int index)
	{
		int counter = 0;
		Node<T>* cur = this->head;
		while (cur != nullptr)
		{
			if (counter == index)
			{
				return cur->info;
			}
			cur = cur->next;
			counter++;
		}
	}

	int getSize()
	{
		return this->Size;
	}
};

