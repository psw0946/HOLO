#include <iostream>
#include "bintree.h"

template <typename T>
BinTree<T>* BinTree<T>::makeBinTree(Node<T> rootNode) {
	BinTree<T> *pReturn = NULL;
	pReturn = new BinTree<T>();
	if (pReturn != NULL) {
		pReturn->pRootNode = new Node<T>();
		if (pReturn->pRootNode != NULL) {
			*(pReturn->pRootNode) = rootNode;
			pReturn->pRootNode->pLeftChild = NULL;
			pReturn->pRootNode->pRightChild = NULL;
		}
		else {
			printf("�޸� �Ҵ� ���� 2, makeBinTree()\n");
			delete pReturn;
			pReturn = NULL;
		}
	}
	else {
		printf("�޸� �Ҵ� ���� 1, makeBinTree()\n");
	}
	return pReturn;
}

template <typename T>
Node<T>* BinTree<T>::insertLeftChildNodeBT(Node<T>* pParentNode, Node<T> element) {
	Node<T>* pReturn = NULL;
	if (pParentNode != NULL) {
		if (pParentNode->pLeftChild == NULL) {
			pParentNode->pLeftChild = new Node<T>();
			if (pParentNode->pLeftChild != NULL) {
				*(pParentNode->pLeftChild) = element;
				pParentNode->pLeftChild->pLeftChild = NULL;
				pParentNode->pLeftChild->pRightChild = NULL;
				pReturn = pParentNode->pLeftChild;
			}
			else {
				printf("�޸� �Ҵ� ����, insertLeftChildNodeBT()\n");
			}
		}
		else {
			printf("�̹� ��尡 �����մϴ�, insertLeftChildNodeBT()\n");
		}
	}
	return pReturn;
}

template <typename T>
Node<T>* BinTree<T>::insertRightChildNodeBT(Node<T>* pParentNode, Node<T> element) {
	Node<T>* pReturn = NULL;
	if (pParentNode != NULL) {
		if (pParentNode->pRightChild == NULL) {
			pParentNode->pRightChild = new Node<T>();
			if (pParentNode->pRightChild != NULL) {
				*(pParentNode->pRightChild) = element;
				pParentNode->pRightChild->pLeftChild = NULL;
				pParentNode->pRightChild->pRightChild = NULL;
				pReturn = pParentNode->pRightChild;
			}
			else {
				printf("�޸� �Ҵ� ����, insertRightChildNodeBT()\n");
			}
		}
		else {
			printf("�̹� ��尡 �����մϴ�, insertRightChildNodeBT()\n");
		}
	}
	return pReturn;
}

template <typename T>
Node<T>* BinTree<T>::getRootNodeBT() {
	Node<T>* pReturn = NULL;
	
	if (this != NULL) {
		pReturn = this->pRootNode;
	}

	return pReturn;
}

template <typename T>
Node<T>* BinTree<T>::getLeftChildNodeBT(Node<T>* pNode) {
	Node<T>* pReturn = NULL;

	if (pNode != NULL) {
		pReturn = pNode->pLeftChild;
	}

	return pReturn;
}

template <typename T>
Node<T>* BinTree<T>::getRightChildNodeBT(Node<T>* pNode) {
	Node<T>* pReturn = NULL;

	if (pNode != NULL) {
		pReturn = pNode->pRightChild;
	}

	return pReturn;
}

template <typename T>
void BinTree<T>::deleteBinTree() {
	if (this != NULL) {
		deleteBinTreeNode(this->pRootNode);
		delete this;
	}
}

template <typename T>
void BinTree<T>::deleteBinTreeNode(Node<T>* pNode) {
	if (pNode != NULL) {
		delete pNode->pLeftChild;
		delete pNode->pRightChild;
		delete pNode;
	}
}