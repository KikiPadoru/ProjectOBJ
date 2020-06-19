#include <iostream>
using namespace std;

template <class T>
struct L_Node
{
	T info;
	L_Node<T>* next;
};

template <class T>
struct List
{
	L_Node<T>* head = NULL;

	void PrintList()
	{
		L_Node<T>* cur = head;
		while (cur)
		{
			cout << cur->info;
			cur = cur->next;
		}
	}

	void InsertAtEnd(T x)
	{
		L_Node<T>* cur = head;
		L_Node<T>* prev = NULL;
		while (cur)
		{
			prev = cur;
			cur = cur->next;
		}
		L_Node<T>* nd = new L_Node<T>;
		nd->info = x;
		nd->next = NULL;
		if (head)
			prev->next = nd;
		else
			head = nd;
	}


};

int main()
{
	List<int> A;
	A.InsertAtEnd(6);
	A.PrintList();

}