#include "List.h"

template<typename T>
bool custom::List<T>::PushBack(T value)
{
	if (mISize == 0)
	{
		head = new Node();
		head->mValue = value;
		head->next = nullptr;
		head->prev = nullptr;
		tail = head;
	}
	else
	{
		if (tail)
		{
			Node* last = tail;
			tail = new Node();
			tail->mValue = value;
			tail->next = nullptr;
			tail->prev = last;
			last->next = tail;
		}
	}
	mISize++;
	return true;
}

template<typename T>
custom::List<T>::~List()
{
	if (head)
	{
		while (head)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
}