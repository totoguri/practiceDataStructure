#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount) {
	ArrayList* pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {
		pReturn = (ArrayList*)malloc(sizeof(ArrayList));

		if (pReturn != NULL) {
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else {
			printf("Error, setting for memory, createArrayList() \n");
			return NULL;
		}
	}
	else {
		printf("Error, number of elements is at least more than zero\n");
		return NULL;
	}

	pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);

	if (pReturn->pElement == NULL) {
		printf("Error, 2nd setting for memory, createArrayList() \n");
		free(pReturn);
		return NULL;
	}
	memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);
	return pReturn;
}

int addALElement(ArrayList* pList, int position, ArrayListNode element) {
	int ret = FALSE;
	int i = 0;

	if (pList != NULL) {
		if (isArrayListFull(pList) != TRUE) {
			if (position >= 0 && position <= pList->currentElementCount) {
				for (i = pList->currentElementCount - 1; i >= position; i--) {
					pList->pElement[i + 1] = pList->pElement[i];
				}

				pList->pElement[position] = element;

				pList->currentElementCount++;
				ret = TRUE;
			}
			else {
				printf("Error, out of index-[%d] range, addALElement() \n", position);
			}
		}
		else {
			printf("Error, out of capacity of the list -[%d]/[%d]\n", position, pList->maxElementCount);
		}
	}
	return ret;
}

int removeALElement(ArrayList* pList, int position) {
	int ret = FALSE;
	int i = 0;

	if (pList != NULL) {
		if (position >= 0 && position < pList->currentElementCount) {
			for (i = position; i < pList->currentElementCount - 1; i++) {
				pList->pElement[i] = pList->pElement[i + 1];
			}

			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("Error, out of index-[%d] range, removeALElement() \n", position);
		}
	}

	return ret;
}

ArrayListNode* getALElement(ArrayList* pList, int position) {
	ArrayListNode* pReturn = NULL;
	if (pList != NULL) {
		if (position >= 0 && position < getArrayListLength(pList)) {
			pReturn = &(pList->pElement[position]);
		}
		else {
			printf("Error, out of index-[%d] range, getALElement() \n", position);
		}
	}

	return pReturn;
}

void displayArrayList(ArrayList* pList) {
	int i = 0;
	if (pList != NULL) {
		printf("Maxinum numbers: %d\n", pList->maxElementCount);
		printf("Current numbers: %d\n", pList->currentElementCount);

		for (i = 0; i < pList->currentElementCount; i++) {
			printf("[%d], %d\n", i, getALElement(pList, i)->data);
		}

		i = pList->currentElementCount;
		for (; i < pList->maxElementCount; i++) {
			printf("[%d], Empty\n", i);
		}
	}
	else {
		printf("ArrayList is NULL");
	}
}

int isArrayListFull(ArrayList* pList) {
	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == pList->maxElementCount) {
			ret = TRUE;
		}
	}

	return ret;
}

int getArrayListLength(ArrayList* pList) {
	int ret = 0;

	if (pList != NULL) {
		ret = pList->currentElementCount;
	}

	return ret;
}

void deleteArrayList(ArrayList* pList) {
	int i = 0;
	if (pList != NULL) {
		free(pList->pElement);
		free(pList);
	}
}

int addALElementFirst(ArrayList* pList, ArrayListNode element) {
	int position = 0;
	return addALElement(pList, position, element);
}

int addALElementLast(ArrayList* pList, ArrayListNode element) {
	int ret = FALSE;
	int position = 0;
	if (pList != NULL) {
		position = getArrayListLength(pList);
		ret = addALElement(pList, position, element);
	}

	return ret;
}

#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main(int argc, char* argv[]) {
	int i = 0;
	int arrayCount = 0;
	ArrayList* pList = NULL;
	ArrayListNode* pValue = NULL;

	pList = createArrayList(6);

	if (pList != NULL) {
		ArrayListNode node;
		node.data = 1;
		addALElement(pList, 0, node);

		node.data = 3;
		addALElement(pList, 1, node);

		node.data = 5;
		addALElement(pList, 2, node);
		displayArrayList(pList);

		removeALElement(pList, 0);
		node.data = 7;
		addALElementFirst(pList, node);
		displayArrayList(pList);

		arrayCount = getArrayListLength(pList);
		for (i = 0; i < arrayCount; i++) {
			pValue = getALElement(pList, i);
			printf("Position[%d] = %d\n", i, pValue->data);
		}
		deleteArrayList(pList);
	}

	return 0;
}

// p.138