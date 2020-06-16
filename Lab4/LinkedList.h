#include <iostream>
#include <vector>
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

using namespace std;


template <class ItemType>
class LinkedList
{

	friend ostream& operator<<(ostream &out, const LinkedList& other)
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

private:
	struct Node
	{
		ItemType  *data;
		Node *next;
	};
	Node *head;


public:
	LinkedList();
	~LinkedList();



	bool Insert(ItemType *obj);


	bool Remove(ItemType target, ItemType &result);


	bool Peek(ItemType target, ItemType &result) const;


	bool isEmpty() const;

	void DeleteList();



	bool Merge(LinkedList &list1);



	LinkedList operator+(const LinkedList &list) const;

	LinkedList operator+=(const LinkedList &list);

	bool operator==(const LinkedList &list) const;

	bool operator!=(const LinkedList &list);

	LinkedList operator=(const LinkedList &list);




};

#include "LinkedList.cpp"
#endif