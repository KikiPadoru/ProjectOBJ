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

	//Создать список на основе массива
	void ArrToList(T* arr, int n);

	//Длина списка
	int LenghtList();
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

	int arr[5] = { 1, 6, 3, 12, 1 };
	List<int> B;
	B.ArrToList(arr, 5);
	B.PrintList();
	cout << endl;
	B.SortList();
	B.PrintList();
	cout << endl;

	cout << B.LenghtList() << endl;


}

template<class T>
void List<T>::PrintList()
{
	if (!head)
	{
		cout << "List is Empty";
		return;
	}
	Node<T>* cur = head;
	while (cur)
	{
		cout << cur->info << " ";
		cur = cur->next;
	}
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
	if (head)
		prev->next = nd;
	else
		head = nd;
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
