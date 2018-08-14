#ifndef _LINKEDLIST_
#define _LINKEDLIST_

template <typename T>
class ListNode {
public:
	float coef; // ��(term)�� ���
	int degree; // ��(term)�� ����

	ListNode* pLink; // pointer to next node
};

template <typename T>
class LinkedList {
public:
	int currentElementCount; // ���� ����� ������ ����
	ListNode<T> headerNode; // ��� ��� (Header Node)

	LinkedList* createLinkedList();
	T addLLElement(int position, ListNode<T> element);
	T removeLLElement(int position);
	ListNode<T>* getLLElement(int position);

	void clearLinkedList(); // �̰� �� �ִ��� �𸣰���...
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