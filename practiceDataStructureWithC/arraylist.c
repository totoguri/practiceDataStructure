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

