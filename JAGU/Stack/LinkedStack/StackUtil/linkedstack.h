#ifndef _LINKED_STACK_
#define _LINKED_STACK_

template <typename T>
class Node {
public:
	T data;
	Node* pLink;
};

template <typename T>
class LinkedStack {
public:
	int currentElementCount; // 현재 원소의 개수
	Node<T>* pTopElement; // Top 노드의 포인터

	LinkedStack* createLinekdStack();
	int pushLS(Node<T> element);
	Node<T>* popLS();
	Node<T>* peekLS();
	void deleteLinkedStack();
	int isLinkedStackFull();
	int isLinkedStackEmpty();
};

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0

#endif