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
			cout << cur->info << " ";
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
	void DeleteFirst(T x)
	{
		L_Node<T>* cur = head;
		L_Node<T>* prev = NULL;
		while (cur && cur->info != x)
		{
			prev = cur;
			cur = cur->next;
		}
		if (!cur)
			return;
		if (prev)
			prev->next = cur->next;
		else
			head = head->next;
		delete cur;
	}
	void SortList()
	{
		L_Node<T>* prev1 = head;
		L_Node<T>* prev2;
		L_Node<T>* cur1 = prev1->next;
		L_Node<T>* cur2;
		while (cur1)
		{
			cur2 = head;
			prev2 = NULL;
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

};

int main()
{
	List<int> A;
	A.InsertAtEnd(6);
	A.InsertAtEnd(1);
	A.InsertAtEnd(4);

	A.PrintList();

	cout << endl;

	A.SortList();
	A.PrintList();

	cout << endl;

	A.DeleteFirst(4);
	A.PrintList();
}