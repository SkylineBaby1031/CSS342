
#include <fstream>
#include <vector>
#include <string>
#ifndef LINKED_STACK_CPP
#define LINKED_STACK_CPP
#include "LinkedStack.h"

using namespace std;

template <class ItemType>
LinkedStack<ItemType>::LinkedStack()
{
	this->head = NULL;
}

template <class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
}
static void SplitS(const string& s, vector<string>& v, const string& c)
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
bool LinkedStack<ItemType>::BuildStack(string fileName)
{
	fstream file;
	file.open(fileName);
	string line;
	while (getline(file, line))
	{
		vector<string> lineStr;
		SplitS(line, lineStr, " ");
		Push(new ItemType(lineStr[0], lineStr[1], atoi(lineStr[2].c_str())));
	}
	return true;
}


template <class ItemType>
void LinkedStack<ItemType>::Push(ItemType *obj)
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
bool LinkedStack<ItemType>::Pop(ItemType &result)
{
	Node *current = this->head;

	int f = Size();
	//continue with  head's next node
	for (int i = 0; i < f -1; i++)
	{
		current = current->next;
	}
	result = *current->data;
	delete current->data;
	delete current;

	current = this->head;
	for (int i = 0; i < f - 2; i++)
	{
		current = current->next;
	}
	current->next = NULL;
	return true;

}

template<class ItemType>
bool LinkedStack<ItemType>::Peek(ItemType &result) const
{
	Node * current = new Node();
	for (int i = 0; i < Size() - 1; i++)
	{
		current = current->next;
	}
	result = *current->data;
	delete current;
	return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
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

template<class ItemType>
int LinkedStack<ItemType>::Size() const
{
	if (this->isEmpty())
	{
		return 0;
	}
	int count =1;
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	return  count;
}

template<class ItemType>
void LinkedStack<ItemType>::DeleteStack()
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

template<class ItemType>
bool LinkedStack<ItemType>::isPalindrome() const
{
	int count = Size() / 2;
	for (int i = 0; i < count; i++)
	{
		Node * top = head;
		Node * bot = head;
		for (int j = 0; j < i; j++)
		{
			top = top->next;
		}
		for (int j = 0; j < Size()-1-i; j++)
		{
			bot = bot->next;
		}
		if (*(top->data) != *(bot->data))
		{
			return false;
		}
	}
	return true;
}



template<class ItemType>
bool LinkedStack<ItemType>::operator==(const LinkedStack &list) const
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

template<class ItemType>
bool LinkedStack<ItemType>::operator!=(const LinkedStack &list) const
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

template<class ItemType>
LinkedStack<ItemType> LinkedStack<ItemType>::operator=(const LinkedStack &list)
{
	Node* listNode = list.head;

	while (listNode != NULL)
	{
		this->Push(listNode->data);
		listNode = listNode->next;
	}
	return *this;
}
#endif