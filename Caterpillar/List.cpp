#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
	front = back = NULL;
}

List::~List()
{
	ListElement *n;
	while (front)
	{
		n = front->next;
		delete front;
		front = n;
	}
}

void List::push_front(ListElement *n)
{
	n->next = front;
	n->prev = NULL;
	if (front)
	{
		front->prev = n;
		front = n;
	}
	if (!back)
	{
		back = front;
	}
}

void List::push_back(ListElement *n)
{
	if (back)
	{
		back->next = n;
		n->next = NULL;
		n->prev = back;
		back = n;
	}
	if (!front)
	{
		front = back;
	}
	 
}

ListElement* List::pop_front()
{
	ListElement *n;
	if (front)
	{
		n = front;
		front = front->next;
		if (!front)
		{
			back = NULL;
		}
		else
		{
			front->prev = NULL;
		}
		return n;
	}
	else
	{
		return NULL;
	}
}

ListElement* List::pop_back()
{
	ListElement *n;
	if (back)
	{
		n = back;
		if (n == front)
		{
			front = back = NULL;
		}
		else
		{
			back = back->prev;
			back->next = NULL;
		}
		return n;
	}
	else
	{
		return NULL;
	}
}