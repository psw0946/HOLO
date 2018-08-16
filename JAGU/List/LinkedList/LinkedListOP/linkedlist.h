#ifndef _LINKEDLIST_
#define _LINKEDLIST_

template <typename T>
class ListNode {
public:
	T data;
	ListNode* pLink; // pointer to next node
};

template <typename T>
class LinkedList {
public:
	int currentElementCount; // 현재 저장된 원소의 개수
	ListNode<T> headerNode; // 헤더 노드 (Header Node)

	LinkedList* createLinkedList();
	T addLLElement(int position, ListNode<T> element);
	T removeLLElement(int position);
	ListNode<T>* getLLElement(int position);

	void clearLinkedList(); // 이건 왜 있는지 모르겠음...
	T getLinkedListLength();
	void deleteLinkedList();
	T isEmpty();
	void displayLinkedList();
};

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
