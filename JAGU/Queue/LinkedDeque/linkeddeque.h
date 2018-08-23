#ifndef _LINKED_DEQUE_
#define _LINKED_DEQUE_

template <typename T>
class Node {
public:
	T data;
	Node* pRLink;
	Node* pLLink;
};

template <typename T>
class LinkedDeque {
public:
	int currentElementCount; // 현재 원소의 개수
	Node<T>* pFrontNode; // Front 노드의 포인터
	Node<T>* pRearNode; // Rear 노드의 포인터

	LinkedDeque* createLinkedQueue();
	int insertFrontLD(Node<T> element);
	int insertRearLD(Node<T> element);
	Node<T>* deleteFrontLD();
	Node<T>* deleteRearLD();
	Node<T>* peekFrontLD();
	Node<T>* peekRearLD();
	void deleteLinkedDeque();
	int isLinkedDequeFull();
	int isLinkedDequeEmpty();
};

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE 1
#define FALSE 0

#endif