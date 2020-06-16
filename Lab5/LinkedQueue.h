#include <iostream>
#include <string>
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

using namespace std;

template <class ItemType>

class LinkedQueue
{
	friend ostream& operator<<(ostream &out, const LinkedQueue& other)
	{
		Node *current;
		current = other.head;
		while (current != NULL)
		{
			out << *current->data;
			current = current->next;
		}
		return out;
	};

public:

	LinkedQueue();
	~LinkedQueue();
	bool operator==(const LinkedQueue &list) const;
	bool operator!=(const LinkedQueue &list) const;
	LinkedQueue<ItemType> operator=(const LinkedQueue &list);

	bool BuildQueue(string fileName);
	void Enqueue(ItemType *obj);
	bool Dequeue(ItemType &result);
	bool Peek(ItemType &result) const;
	bool isEmpty() const;
	int Size() const;
	void DeleteQueue();
	void Reverse();
private:
	struct Node
	{
		ItemType *data;
		Node * next;
	};
	Node * head;
};

#include "LinkedQueue.cpp"
#endif"