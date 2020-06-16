#pragma once
#include <iostream>
#include <vector>
#ifndef LINKED_STACK_H
#define LINKED_STACK_H

using namespace std;


template <class ItemType>
class LinkedStack
{

	friend ostream& operator<<(ostream &out, const LinkedStack& other)
	{

		int count = 0;
		if (other.head != NULL)
		{
			Node* temp = other.head;
			while (temp != NULL)
			{
				temp = temp->next;
				count++;
			}

		}
		Node *current = other.head;
		for (int i = 0; i < count; i++)
		{
			current = other.head;
			for (int j = 0; j < count-1-i; j++)
			{
				current = current->next;
			}
			out << *(current->data);
		}


		return out;
	};


public:
	LinkedStack();
	~LinkedStack();

	bool operator==(const LinkedStack &list) const;
	bool operator!=(const LinkedStack &list) const;
	LinkedStack<ItemType> operator=(const LinkedStack &list);
	bool BuildStack(string fileName);
	void Push(ItemType *obj);
	bool Pop(ItemType &result);
	bool Peek(ItemType &result) const;
	bool isEmpty() const;
	int Size() const;
	void DeleteStack();
	bool isPalindrome() const;

private:
	struct Node 
	{
		ItemType *data;
		Node * next;
	};
	Node * head;
};

#include "LinkedStack.cpp"
#endif

