#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
	int value;
	Node * next;
	Node(int);

};

Node::Node(int v)
{
	value = v;
	next = NULL;
};

class List
{
private:
	Node * private_reverse(Node *);
	Node * private_destroy(Node *);
	unsigned private_len(Node *);
	Node * head;
public:	
	List(void);
	~List(void);
	void append(int);
	void print(void);
	void reverse(void);
	unsigned len(void);
};

List::List()
{
	head = NULL;
}

List::~List()
{
	if (!head)
	{
		Node * p = head;

	}
}

Node * List::private_destroy(Node * head)
{
	if (head->next)
	{
		private_destroy(head->next);
		delete head->next;
	}
}

void List::append(int v)
{
	if (!head)
		head = new Node(v);
	else
	{
		Node * p = head;
		while (p->next)
			p = p->next;
		p->next = new Node(v);
	}
}

void List::print(void)
{
	Node * p = head;
	while (p)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}

Node * List::private_reverse(Node * h)
{
	if (h->next)
	{
		Node * last = private_reverse(h->next);
		h->next->next = h;
		h->next = NULL;
		return last;
	}
	else
		return h;
}

unsigned List::private_len(Node * h)
{
	if (h == NULL)
		return 0;
	else
		return 1 + private_len(h->next);
}

unsigned List::len(void)
{
	return private_len(head);
}

void List::reverse(void)
{
	if (head)
		head = private_reverse(head);
}

unsigned count_nodes(Node * head)
{
	if (head == NULL)
		return 0;
	else
		return 1 + count_nodes(head->next);
}

int main(int argc, char *argv[])
{
	cout << "Creating linked list ..." << endl;
	List list;
	for (int i = 1; i < argc; i++)
	{
		list.append(atoi(argv[i]));
	}
	list.print();
	cout << "Len: " << list.len() << endl;
	list.reverse();
	cout << "Reverse: " << endl;
	list.print();

	return 0;
}