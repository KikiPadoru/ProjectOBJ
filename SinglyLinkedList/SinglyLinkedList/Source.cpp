#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T info;
	Node<T>* next;
};

template <class T>
struct List
{
	Node<T>* head = NULL;
	int Size = 0;

	//Напечатать список
	void PrintList();
	//Добавить элемент в конец списка
	void InsertAtEnd(T x);
	//Удалить первое вхождение элемента
	void DeleteFirst(T x);
	//Отсортировать список
	void SortList();
	//Удалить первый элемент списка
	void DeleteHead();
	//Очистить список
	void DeleteAll();
	//Добавить элемент в начало списка
	void InsertAtForward(T x);
	//Создать список на основе массива
	void ArrToList(T* arr, int n);
	//Длина списка
	int LenghtList();
	//Найти i-й по счёту элемент списка
	void FindIndexList(const int index);
	//Удалить i-й по счёту элемент списка
	void DeleteIndexList(const int index);
	//Вставить элемент x на i-ю позицию
	void InsertAtPos(T x, const int pos);
	//Переставить последний элемент списка в начало
	void ReplaceLastToForward();
	//Перевернуть список
	void ReverseList();
	//Вставить элемент x в упорядоченный список
	void InsertAtSort(T x);
};

int main()
{
	List<int> A;
	A.InsertAtEnd(6);
	A.InsertAtEnd(1);
	A.InsertAtEnd(4);
	A.PrintList();
	A.SortList();
	A.PrintList();
	int arr[5] = { 1, 6, 3, 12, 1 };
	List<int> B;
	B.ArrToList(arr, 5);
	B.PrintList();
	B.SortList();
	B.PrintList();
	B.FindIndexList(4);
	B.DeleteIndexList(4);
	B.DeleteHead();
	B.PrintList();
	B.ReplaceLastToForward();
	B.PrintList();
	B.InsertAtForward(5);
	B.PrintList();
	B.ReverseList();
	B.PrintList();
	B.InsertAtPos(7, 7);
	B.PrintList();
	B.SortList();
	B.PrintList();
	B.InsertAtSort(19);
	B.PrintList();
	B.DeleteFirst(20);
	B.PrintList();
	cout << B.LenghtList();
}

template<class T>
void List<T>::PrintList()
{
	if (!head)
	{
		cout << "List is Empty" << endl;
		return;
	}
	Node<T>* cur = head;
	while (cur)
	{
		cout << cur->info << " ";
		cur = cur->next;
	}
	cout << endl;
}

template<class T>
void List<T>::InsertAtEnd(T x)
{
	Node<T>* cur = head;
	Node<T>* prev = NULL;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
	}
	Node<T>* nd = new Node<T>;
	nd->info = x;
	nd->next = NULL;
	Size++;
	if (head)
		prev->next = nd;
	else
		head = nd;
}

template<class T>
void List<T>::InsertAtForward(T x)
{
	Node<T>* tmp = new Node<T>;
	tmp->info = x;
	tmp->next = head;
	Size++;
	head = tmp;
}

template<class T>
void List<T>::DeleteFirst(T x)
{
	Node<T>* cur = head;
	Node<T>* prev = NULL;
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
	Size--;
	delete cur;
}

template<class T>
void List<T>::SortList()
{
	Node<T>* prev1 = head;
	Node<T>* prev2;
	Node<T>* cur1 = prev1->next;
	Node<T>* cur2;
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

template<class T>
void List<T>::DeleteHead()
{
	Node<T>* tmp = head;
	head = head->next;
	Size--;
	delete tmp;
}

template<class T>
void List<T>::DeleteAll()
{
	while (head) DeleteHead();
}

template<class T>
void List<T>::ArrToList(T* arr, int n)
{
	if (head) DeleteAll();

	Node<T>* cur = head;
	for (int i = 0; i < n; i++)
	{
		Node<T>* tmp = new Node<T>;
		tmp->info = arr[i];
		tmp->next = NULL;
		if (!head)
			head = cur = tmp;
		else
			cur->next = tmp;
		cur = tmp;
		Size++;
	}
}

template<class T>
int List<T>::LenghtList()
{
	Node<T>* cur = head;
	int counter = 0;
	while (cur)
	{
		counter++;
		cur = cur->next;
	}
	return counter;
}

template<class T>
void List<T>::FindIndexList(const int index)
{
	Node<T>* cur = head;
	int counter = 0;
	while (counter != index && cur)
	{
		counter++;
		cur = cur->next;
	}
	if (cur)
		cout << cur->info << endl;
	else
		cout << "Item not found" << endl;
}
template<class T>
void List<T>::DeleteIndexList(const int index)
{
	Node<T>* cur = head;
	Node<T>* prev = NULL;
	int counter = 0;
	while (counter < index && cur)
	{
		counter++;
		prev = cur;
		cur = cur->next;
	}
	if (counter == index)
	{
		Node<T>* tmp = cur;
		cout << "Item " << tmp->info << " has been deleted" << endl;
		if (cur != head)
			prev->next = cur->next;
		else
			head = cur->next;
		Size--;
		delete tmp;
	}
	else
		cout << "Item not found" << endl;
}

template<class T>
void List<T>::InsertAtPos(T x, const int pos)
{
	Node<T>* cur = head;
	Node<T>* prev = NULL;
	int counter = 0;
	while (counter < pos)
	{
		if (cur)
		{
			prev = cur;
			cur = cur->next;
			counter++;
		}
		else {
			Node<T>* h = new Node<T>;
			h->info = T();
			h->next = NULL;
			cur = h;
			prev->next = cur;
			Size++;
		}
	}
	Node<T>* nd = new Node<T>;
	nd->info = x;
	nd->next = cur;
	if (!prev)
	{
		nd->next = cur;
		head = nd;
	}
	else
		prev->next = nd;
	Size++;
}

template<class T>
void List<T>::ReplaceLastToForward()
{
	Node<T>* cur = head;
	Node<T>* prev = NULL;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur != head && cur) {
		prev->next = NULL;
		cur->next = head;
		head = cur;
	}
}

template<class T>
void List<T>::ReverseList()
{
	Node<T>* cur = head->next;
	Node<T>* cur2 = head->next->next;
	Node<T>* tmp = head; tmp->next = NULL;
	while (cur2)
	{
		cur->next = tmp;
		tmp = cur;
		cur = cur2;
		cur2 = cur2->next;
	}
	cur->next = tmp;
	head = cur;
}

template<class T>
void List<T>::InsertAtSort(T x)
{
	Node<T>* cur = head;
	while (cur->next)
	{
		if (cur->info > cur->next->info)
		{
			cout << "It does not sorted!" << endl;
			return;
		}
		cur = cur->next;
	}
	Node<T>* nd = new Node<T>;
	nd->info = x;
	nd->next = NULL;
	cur = head;
	Node<T>* prev = NULL;
	while (cur && cur->info < nd->info)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == head)
	{
		nd->next = cur;
		head = nd;
	}
	else
	{
		prev->next = nd;
		nd->next = cur;
	}
	Size++;
}
