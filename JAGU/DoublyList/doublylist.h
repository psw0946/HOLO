#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

template <typename T>
class Node {
public:
	int data;
	Node* pLLink;
	Node* pRLink;
};

template <typename T>
class DoublyList {
public:
	int currentElementCount; // 현재 저장된 원소 개수
	Node<T> headerNode; // 헤더 노드

	DoublyList* createDoublyList();
	void deleteDoublyList();
	int addDLElement(int position, Node<T> element);
	int removeDLElement(int position);
	void clearDoublyList();
	int getDoublyListLength();
	Node<T>* getDLElement(int position);
	void displayDoublyList();
};

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif