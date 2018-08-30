#include <iostream>
#include "binsearchtree.h"

template <typename T>
BinSearchTree<T>* BinSearchTree<T>::createBinSearchTree() {
	BinSearchTree<T> *pReturn = NULL;
	pReturn = new BinSearchTree<T>();
	if (pReturn != NULL) {
		pReturn->pRootNode = NULL;
	}
	else {
		printf("메모리 할당 오류, createBinSearchTree()\n");
	}

	return pReturn;
}

template <typename T>
int BinSearchTree<T>::insertElementBST(Node<T> element) {
	int ret = TRUE;
	Node<T>* pParentNode = NULL;
	Node<T>* pNewNode = NULL;
	if (this == NULL) {
		ret = FALSE;
		return ret;
	}
	pParentNode = this->pRootNode;
	while (pParentNode != NULL) {
		if (element.key == pParentNode->key) {
			// Case-1) 중복된 키가 발견된 경우
			printf("오류, 중복된 키 - [%d], insertElementBST()\n", element.key);
			ret = FALSE;
			return ret;
		}
		else if (element.key < pParentNode->key) {
			/*
			 * Case-2) 현재 노드 키 값보다 작은 경우: 왼쪽 서브 트리로 이동
			 *			- 왼쪽 자식 노드가 NULL이면, 새로운 노드를 삽입할 위치를 발견
			 *			- 왼쪽 자식 노드가 NULL이 아니면, 계속 왼쪽 자식 노드로 이동
			 */
			if (pParentNode->pLeftChild == NULL) {
				break;
			}
			else {
				pParentNode = pParentNode->pLeftChild;
			}
		}
		else {
			/*
			 * Case-3) 현재 노드의 키 값보다 큰 경우: 오른쪽 서브 트리로 이동
			 *			- 오른쪽 자식 노드가 NULL이면, 새로운 노드를 삽입할 위치를 발견
			 *			- 오른쪽 자식 노드가 NULL이 아니면, 계속 오른쪽 자식 노드로 이동
			 */
			if (pParentNode->pRightChild == NULL) {
				break;
			}
			else {
				pParentNode = pParentNode->pRightChild;
			}
		}
	}
	pNewNode = new Node<T>();
	if (pNewNode != NULL) {
		*pNewNode = element;
		pNewNode->pLeftChild = NULL;
		pNewNode->pRightChild = NULL;
		if (pParentNode == NULL) {
			this->pRootNode = pNewNode;
		}
		else {
			if (pNewNode->key < pParentNode->key) {
				pParentNode->pLeftChild = pNewNode;
			}
			else {
				pParentNode->pRightChild = pNewNode;
			}
		}
		ret = TRUE;
	}
	else {
		printf("메모리 할당 오류, insertElementBST()\n");
		ret = FALSE;
	}
	return ret;
}

template <typename T>
int BinSearchTree<T>::deleteElementBST(int key) {
	int ret = TRUE;
	Node<T> *pDelNode = NULL, *pParentNode = NULL;
	Node<T> *pPredecessor = NULL, *pSuccessor = NULL;
	Node<T> *pChildNode = NULL;

	if (this == NULL) {
		ret = FALSE;
		return ret;
	}
	pParentNode = NULL;
	pDelNode = this->pRootNode;
	while (pDelNode != NULL) {
		if (key == pDelNode->key) {
			// Case-1) 키가 발견된 경우
			break;
		}
		pParentNode = pDelNode;
		if (key < pDelNode->key) {
			// Case-2) 키가 현재 노드보다 작은 경우 왼쪽 자식 노드로 이동
			pDelNode = pDelNode->pLeftChild;
		}
		else {
			// Case-3) 키가 현재 노드보다 큰 경우 오른쪽 자식 노드로 이동
			pDelNode = pDelNode->pRightChild;
		}
	}
	if (pDelNode == NULL) {
		printf("오류, 존재하지 않는 키 - [%d], deleteElementBST()\n", key);
		ret = FALSE;
		return ret;
	}
	if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
		// 삭제하려는 노드의 자식이 0개인 경우
		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = NULL;
			}
			else {
				pParentNode->pRightChild = NULL;
			}
		}
		else {
			this->pRootNode = NULL;
		}
	}
	else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) {
		// 삭제하려는 노드의 자식이 2개인 경우
		pPredecessor = pDelNode;
		pSuccessor = pDelNode->pLeftChild;
		while (pSuccessor->pRightChild != NULL) {
			// 왼쪽 서브트리에서 가장 큰 키 값을 가지는 노드 찾기
			pPredecessor = pSuccessor;
			pSuccessor = pSuccessor->pRightChild;
		}
		// 포인터 변수 pSuccessor는 삭제할 노드를 대체할 대체 노드를 가리킨다.
		// 삭제할 노드 pDelNode의 자식 노드를 대체 노드 pSuccessor의 자식 노드로 변경
		pPredecessor->pRightChild = pSuccessor->pLeftChild;
		pSuccessor->pLeftChild = pDelNode->pLeftChild;
		pSuccessor->pRightChild = pDelNode->pRightChild;

		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = pSuccessor;
			}
			else {
				pParentNode->pRightChild = pSuccessor;
			}
		}
		else {
			this->pRootNode = pSuccessor;
		}
	}
	else {
		// 삭제하려는 노드의 자식이 1개인 경우
		if (pDelNode->pLeftChild != NULL) {
			pChildNode = pDelNode->pLeftChild;
		}
		else {
			pChildNode = pDelNode->pRightChild;
		}

		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = pChildNode;
			}
			else {
				pParentNode->pRightChild = pChildNode;
			}
		}
		else {
			this->pRootNode = pChildNode;
		}
	}

	delete pDelNode;
	return ret;
}

template <typename T>
Node<T>* BinSearchTree<T>::searchBST(int key) {
	Node<T>* pReturn = NULL;

	if (this == NULL) {
		return NULL;
	}
	pReturn = this->pRootNode;
	while (pReturn != NULL) {
		if (key == pReturn->key) {
			break;
		}
		else if (key < pReturn->key) {
			pReturn = pReturn->pLeftChild;
		}
		else {
			pReturn = pReturn->pRightChild;
		}
	}

	return pReturn;
}

template <typename T>
Node<T>* BinSearchTree<T>::searchRecursiveBST(int key) {
	Node<T>* pReturn = NULL;
	if (this == NULL) return NULL;
	pReturn = this->pRootNode->searchInternalRecursiveBST(key);
	return pReturn;
}

template <typename T>
Node<T>* Node<T>::searchInternalRecursiveBST(int key) {
	Node<T>* pReturn = NULL;
	if (this == NULL) return NULL;
	if (this->key == key)
		pReturn = this;
	else if (this->key < key)
		pReturn = this->pRightChild->searchInternalRecursiveBST(key);
	else
		pReturn = this->pLeftChild->searchInternalRecursiveBST(key);
	return pReturn;
}

template <typename T>
void BinSearchTree<T>::deleteBinSearchTree() {
	if (this != NULL) {
		this->pRootNode->deleteBinSearchTreeInternal();
		delete this;
	}
}

template <typename T>
void Node<T>::deleteBinSearchTreeInternal() {
	if (this != NULL) {
		this->pLeftChild->deleteBinSearchTreeInternal();
		this->pRightChild->deleteBinSearchTreeInternal();
		delete this;
	}
}