#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_

template <typename T>
class Node {
public:
	T data;
	Node* pLink; // pointer to next node
};

template <typename T>
class CircularList {
public:
	int currentElementCount; // 현재 저장된 원소의 개수
	Node<T>* pLink; // 헤드 포인터 (Head Pointer) ... LinkedList는 헤드 노드

	CircularList* createCircularList();
	void deleteCircularList();
	T addCLElement(int position, Node<T> element);
	T removeCLElement(int position);
	void clearCircularList();
	T getCircularListLength();
	Node<T>* getCLElement(int position);
	void displayCircularList();
};

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif