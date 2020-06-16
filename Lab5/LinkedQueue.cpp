
#include <fstream>
#include <vector>
#ifndef LINKED_QUEUE_CPP
#define LINKED_QUEUE_CPP

#include "LinkedQueue.h"

using namespace std;

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
	head = NULL;
}

template <class ItemType>

LinkedQueue<ItemType>::~LinkedQueue()
{
}
template <class ItemType>

bool LinkedQueue<ItemType>::operator==(const LinkedQueue &list) const
{
	Node* current = this->head;
	Node*  listNode = list.head;
	while (current != NULL || listNode != NULL)
	{
		if (*(current->data) != *(listNode->data))
			return false;
		current = current->next;
		listNode = listNode->next;
	}
	return true;
}
template <class ItemType>

bool LinkedQueue<ItemType>::operator!=(const LinkedQueue &list) const
{
	Node* current = this->head;
	Node*  listNode = list.head;
	while (current != NULL || listNode != NULL)
	{
		if (*(current->data) != *(listNode->data))
			return true;
		current = current->next;
		listNode = listNode->next;
	}
	return false;
}
template <class ItemType>

LinkedQueue<ItemType> LinkedQueue<ItemType>::operator=(const LinkedQueue &list)
{
	Node* listNode = list.head;

	while (listNode != NULL)
	{
		this->Enqueue(listNode->data);
		listNode = listNode->next;
	}
	return *this;
}


static void SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}

template <class ItemType>

bool LinkedQueue<ItemType>::BuildQueue(string fileName)
{
	fstream file;
	file.open(fileName);
	string line;
	while (getline(file, line))
	{
		vector<string> lineStr;
		SplitString(line, lineStr, " ");
		Push(new ItemType(lineStr[0], lineStr[1], atoi(lineStr[2].c_str())));
	}
	return true;
}
template <class ItemType>

void LinkedQueue<ItemType>::Enqueue(ItemType *obj)
{
	Node *newNode = new Node();
	Node *current = new Node();

	ItemType *pItemData = new ItemType;

	*pItemData = *obj;
	newNode->data = pItemData;
	newNode->next = NULL;
	if (this->head == NULL)
	{
		this->head = newNode;
	}
	else
	{

		current = this->head;
		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = newNode;

	}
}
template <class ItemType>

bool LinkedQueue<ItemType>::Dequeue(ItemType &result)
{
	Node* temp = head;
	result = *head->data;
	head = head->next;
	delete temp->data;
	delete temp;

	return true;
}
template <class ItemType>

bool LinkedQueue<ItemType>::Peek(ItemType &result) const
{
	result = *head->data;
	return true;
}
template <class ItemType>

bool LinkedQueue<ItemType>::isEmpty() const
{
	Node* temp = head;
	if (temp == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <class ItemType>

int LinkedQueue<ItemType>::Size() const
{
	if (this->isEmpty())
	{
		return 0;
	}
	int count = 1;
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	return  count;
}
template <class ItemType>

void LinkedQueue<ItemType>::DeleteQueue()
{
	Node* temp = head;
	while (temp != NULL)
	{
		head = head->next;
		delete temp->data;
		delete temp;
		temp = head;
	}
}
template <class ItemType>

void LinkedQueue<ItemType>::Reverse()
{
	ItemType tempObj;
	int length = Size();
		Node * current =head;
	for (int i = 0; i < length; i++)
	{
		current = head;
		for (int j = 0; j < length-1-i; j++)
		{
			current = current->next;
		}
		Enqueue(current->data);
	}
	for (int i = 0; i < length; i++)
	{
		Dequeue(tempObj);
	}

}



#endif