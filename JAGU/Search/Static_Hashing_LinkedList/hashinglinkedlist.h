#ifndef STATIC_HASHING_LIST_HASHINGLINKEDLIST_H
#define STATIC_HASHING_LIST_HASHINGLINKEDLIST_H

#define TRUE 1
#define FALSE 0

class Node {
public:
	HashElement data;
	Node *pLink;
};

class LinkedList {
public:
	int currentElementCount;
	Node headerNode;
};

LinkedList *createLinkedList();
int addLLElement(LinkedList *pList, int position, Node element);
int removeLLElement(LinkedList *pList, int position);
Node* getLLElement(LinkedList *pList, int position);
void clearLinkedList(LinkedList *pList);
int getLinkedListLength(LinkedList *pList);
void deleteLinkedList(LinkedList *pList);

#endif