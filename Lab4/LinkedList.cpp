#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP
#include "LinkedList.h"

using namespace std;

template <class ItemType>


LinkedList<ItemType>::LinkedList()
{
	this->head = NULL;
}

template <class ItemType>

LinkedList<ItemType>::~LinkedList()
{
}

template<class ItemType>
bool LinkedList<ItemType>::Insert(ItemType *obj)
{
	Node *newNode = new Node();
	ItemType *pItemData = new ItemType;
	*pItemData = *obj;
	newNode->data = pItemData;
	if (this->head == NULL)
	{
		this->head = newNode;
		this->head->next = NULL;
		return true;
	}
	Node * current = this->head;
	if (*pItemData < *this->head->data)
	{
		Node *newNode = new Node;
		newNode->data = this->head->data;
		newNode->next = this->head->next;
		this->head->data = pItemData;
		this->head->next = newNode;
		return true;
	}
	while (current != NULL) {

		if (*current->data == *pItemData)
			return false;
		current = current->next;

	}

	current = this->head;

	while (current->next != NULL)
	{
		if (*pItemData >= *current->data && *pItemData < *current->next->data)
		{

			Node * newNode=newNode = new Node();
			newNode->data = pItemData;
			newNode->next = current->next;
			current->next = newNode;
			return true;
		}

		current = current->next;
	}
	current = this->head;

	while (current->next != NULL)
	{
		current = current->next;
	}

	newNode = newNode = new Node();
	newNode->data = pItemData;
	newNode->next = current->next;
	current->next = newNode;

	return true;
}

template<class ItemType>
bool LinkedList<ItemType>::Remove(ItemType target, ItemType &result)
{
	Node *current = this->head->next;
	Node *temp = this->head;

	//continue with  head's next node
	while (current != NULL)
	{


		if (*current->data == target)
		{
			temp->next = current->next;
			result = *current->data;
			delete current->data;
			delete current;

			return true;
		}
		temp = current;
		current = current->next;
	}
}

template<class ItemType>
bool LinkedList<ItemType>::Peek(ItemType target, ItemType &result) const
{

	Node *current = this->head->next;
	Node *temp = this->head;

	//continue with  head's next node
	while (current != NULL)
	{

		if (*current->data == target)
		{
			temp->next = current->next;
			result = *current->data;
			delete current;
			return true;
		}
		temp = current;
		current = current->next;
	}
	return false;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
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
void LinkedList<ItemType>::DeleteList()
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
bool LinkedList<ItemType>::Merge(LinkedList &list1)
{
	

	if (this->head == NULL && list1.head == NULL)
	{
		return false;
	}
	Node* listNode = list1.head;

	while (listNode != NULL)
	{
		this->Insert(listNode->data);
		listNode = listNode->next;
	}

	if (*this != list1) 
	{
		list1.DeleteList();
	}
	return true;
}


template<class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList &list) const
{

	LinkedList<ItemType> tempList = *this;
	tempList += *list;
	return tempList;
}

template<class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+=(const LinkedList &list)
{
	Node* listNode = list.head;

	while (listNode != NULL)
	{
		this->Insert(listNode->data);
		listNode = listNode->next;
	}
	return *this;
}

template<class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList &list) const
{
	Node* current = this->head;
	Node*  listNode= list.head;
	while (current != NULL || listNode != NULL)
	{
		if (current->data != listNode->data)
			return false;
		current = current->next;
		listNode = listNode->next;
	}
	return true;
}

template<class ItemType>
bool LinkedList<ItemType>::operator!=(const LinkedList &list)
{
	Node* current = this->head;
	Node*  listNode = list.head;
	while (current != NULL || listNode != NULL)
	{
		if (current->data != listNode->data)
			return true;
		current = current->next;
		listNode = listNode->next;
	}
	return false;
	
}

template<class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator=(const LinkedList &list)
{
	Node* listNode = list.head;

	while (listNode != NULL)
	{
		this->Insert(listNode->data);
		listNode = listNode->next;
	}
	return *this;
}
#endif
