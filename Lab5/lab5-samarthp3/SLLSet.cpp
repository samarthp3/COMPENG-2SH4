/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}
SLLSet::SLLSet(int sortedArray[], int arrSize){
	size = arrSize;
	head = NULL;

	for (int i = 0; i < size; i++){
		SLLNode *node = new SLLNode();
		node->value = sortedArray[size - i - 1];
		node->next = head;
		head = node;
	}
}

int SLLSet::getSize()
{
	return size;

}
SLLSet SLLSet::copy()

{
    SLLNode* temp = head;
    int arr[size];
    for (int i=0; i<size; i++) {
        arr[i] = temp->value;
        temp = temp->next;
            }
    return *(new SLLSet(arr,size));

}

bool SLLSet::isIn(int v)
{
	SLLNode *currentNode = head;

	while(currentNode != 0){
		if (v == (currentNode->value))
			return true;

		if(v < (currentNode->value))
			return false;

		currentNode = currentNode->next;
	}
	return false;
}

void SLLSet::add(int v)
{
	SLLNode* newNode = head;
	if(isIn(v) == false)
	{
		if(newNode == NULL)
		{
			SLLNode* temppy = new SLLNode(v,NULL);
			newNode = temppy;
		}

		else if(newNode->value > v)
		{
			SLLNode* temppy2 = new SLLNode(v,newNode);
			head = temppy2;
		}

		else
		{
			while (newNode->next!=NULL)
			{
				if (newNode->value < v && newNode->next->value > v)
				{
					SLLNode* temppy3 = new SLLNode(v,newNode->next);
					newNode->next = temppy3;
				}
				else
					newNode = newNode->next;
			}
			if(newNode->value < v)
			{
				SLLNode* temppy4 = new SLLNode(v,NULL);
				newNode->next = temppy4;
			}
		}
		size+=1;
	}
}
void SLLSet::remove(int v){

	if(isIn(v) == true)
	{
		SLLNode* node = head;

		if (v == head->value)
		{
			head = head->next;
			size -= 1;
		}

		while (node !=NULL && node->next != NULL)
		{
			if ((node->next)->value == v)
			{
				node->next = (node->next)->next;
				size -= 1;
			}
			else
				node = node->next;
		}
	}
}
SLLSet SLLSet::setUnion(SLLSet s)
{
    SLLSet *unionList = new SLLSet();

    if (s.head == NULL)
    {
        *unionList = copy();
        return(*unionList);
    }

    if (head == NULL)
    {
        *unionList = s.copy();
        return (*unionList);
    }

    *unionList = copy();

    while (s.head != NULL)
    {
        (*unionList).add(s.head->value);
        size++;
        s.head = s.head->next;
    }

    return (*unionList);
}
SLLSet SLLSet::intersection(SLLSet s)
{
		SLLSet* setIntersect = new SLLSet();
		if (head == NULL)
			return *setIntersect;

		if (s.head == NULL)
			return *setIntersect;

		SLLNode* temp = head;

		while (temp!= NULL)
		{
			if (s.isIn(temp->value) == false)
				remove(temp->value);

			temp = temp->next;
		}
		if (head == NULL)
			return *setIntersect;

		*setIntersect = copy();
		return *setIntersect;
}

SLLSet SLLSet::difference(SLLSet s)
{
	SLLSet *diff = new SLLSet();
	if (head == NULL)
		return *diff;

	if (s.head == NULL){
		*diff = copy();
		return *diff;
	}

	SLLNode *tempNode = head;

	while (tempNode != NULL){
		if (s.isIn(tempNode->value) == true)
			remove (tempNode->value);

		tempNode = tempNode->next;
	}

	if (head == NULL)
		return *diff;

	*diff = copy();
	return *diff;

}
SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
		SLLSet* setUnion = new SLLSet();
		for (int i=0; i<size; i++) {
			*setUnion = (*setUnion).setUnion(sArray[i]);
		}
		return *setUnion;
}
string SLLSet::toString()
{
    string output;
    while (head != NULL) {
        output += to_string(head->value) + ", ";
        head = head->next;
        }

    if (!output.empty())
        output.resize(output.size() - 2);

    return output;
}

