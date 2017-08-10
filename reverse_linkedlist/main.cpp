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
public:
	Node * head;
	List(void);
	void append( int );
	void print(void);
	void reverse(void);
};

List::List()
{
	head = NULL;
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

/*
void List::reverse(void)
{
	if (head->next != NULL)
	{
		head = head->next;
		Node * last = reverse();
		head->next->next = head;
		head->next = NULL;
		return last;
	}
	else
		return head;
}
*/

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
	//Node first (atoi(argv[1]));
	//Node * head = &first;
	//Node * p = head;
	/*
	
	{
		p->next = new Node(atoi(argv[i]));
		p = p->next;
	}
	*/
	List list;
	for (int i = 1; i < argc; i++)
	{
		list.append(atoi(argv[i]));
	}
	list.print();
	/*
	cout << "There are " << count_nodes(head) << " nodes." << endl;
	cout << "Printing nodes ..." << endl;
	print_list(head);
	cout << "Reversing nodes ..." << endl;
	head = reverse_nodes(head);
	cout << "Printing nodes ..." << endl;
	print_list(head);
	*/
	return 0;
}