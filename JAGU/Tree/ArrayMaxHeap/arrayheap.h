#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

class Node {
public:
	int key;
	char data;
};

class ArrayMaxHeap {
public:
	int maxElementCount; // 최대 노드 개수
	int currentElementCount; // 현재 노드 개수
	Node *pElement; // 노드 저장을 위한 1차원 array

	ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);
	void deleteArrayMaxHeap();
	void insertMaxHeapAH(Node element);
	Node* deleteMaxHeapAH();
};

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE 1
#define FALSE 0

#endif