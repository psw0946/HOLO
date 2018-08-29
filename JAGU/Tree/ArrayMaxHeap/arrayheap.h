#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

class Node {
public:
	int key;
	char data;
};

class ArrayMaxHeap {
public:
	int maxElementCount; // �ִ� ��� ����
	int currentElementCount; // ���� ��� ����
	Node *pElement; // ��� ������ ���� 1���� array

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