// 열혈강의 data structure "List"
// 22, Oct, 2021


#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType {
	int data;
} ArrayListNode;

typedef struct ArrayListType {
	int maxElementCount;
	int currentElementCount;
	ArrayListNode* pElement; 
	// 이게 포인터인 이유는, 동적 할당을 통해서 ArrayListNode형 배열을 생성하기 위함.
	// arraylist.c에 있는 addALElement 함수에는 (ArrayListNode pElement)로 매개 변수 전달.
	// 이 의미는 ArrayListNode형 배열 pElement에 원소 하나를 추가한다는 뜻.
} ArrayList;

ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addALElement(ArrayList* pList, int position, ArrayListNode element);
int removeALElement(ArrayList* pList, int position);
ArrayListNode* getALElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif