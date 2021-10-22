#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType {
	int data;
} ArrayListNode;

typedef struct ArrayListType {
	int maxElementCount;
	int currentElementCount;
	ArrayListNode* pElement;
} ArrayList;