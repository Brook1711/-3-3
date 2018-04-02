#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	struct Node<T>*next;
};

template<class T>
class LinkList
{
public:
	LinkList();
	~LinkList();

	void printList(int n);
private:
	Node<T>*front;
	Node<T>*r;
};

template<class T>
LinkList<T>::LinkList()
{
	int len;
	cin >> len;
	front = new Node<T>;
	r = front;

	for (int i = 0; i < len - 1; i++)
	{

		r->next = new Node<T>;
		r = r->next;
		r->data = i + 1;

	}
	r->next = front;
	front->data = len;
}

template<class T>
LinkList<T>::~LinkList()
{
	delete r;
}

template<class T>
void LinkList<T>::printList(int n)
{
	r = front;
	front = NULL;
	while (r != r->next)
	{
		for (int i = 0; i < n - 1; i++)
		{
			r = r->next;
		}
		Node<T> * q = r->next;
		cout << q->data << " ";
		r->next = q->next;
		delete q;
	}
	cout << r->data;
}

int main()
{
	LinkList<int> L;
	int N;
	cin >> N;
	L.printList(N);
	return 0;
}