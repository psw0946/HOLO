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
		printf("�޸� �Ҵ� ����, createBinSearchTree()\n");
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
			// Case-1) �ߺ��� Ű�� �߰ߵ� ���
			printf("����, �ߺ��� Ű - [%d], insertElementBST()\n", element.key);
			ret = FALSE;
			return ret;
		}
		else if (element.key < pParentNode->key) {
			/*
			 * Case-2) ���� ��� Ű ������ ���� ���: ���� ���� Ʈ���� �̵�
			 *			- ���� �ڽ� ��尡 NULL�̸�, ���ο� ��带 ������ ��ġ�� �߰�
			 *			- ���� �ڽ� ��尡 NULL�� �ƴϸ�, ��� ���� �ڽ� ���� �̵�
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
			 * Case-3) ���� ����� Ű ������ ū ���: ������ ���� Ʈ���� �̵�
			 *			- ������ �ڽ� ��尡 NULL�̸�, ���ο� ��带 ������ ��ġ�� �߰�
			 *			- ������ �ڽ� ��尡 NULL�� �ƴϸ�, ��� ������ �ڽ� ���� �̵�
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
		printf("�޸� �Ҵ� ����, insertElementBST()\n");
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
			// Case-1) Ű�� �߰ߵ� ���
			break;
		}
		pParentNode = pDelNode;
		if (key < pDelNode->key) {
			// Case-2) Ű�� ���� ��庸�� ���� ��� ���� �ڽ� ���� �̵�
			pDelNode = pDelNode->pLeftChild;
		}
		else {
			// Case-3) Ű�� ���� ��庸�� ū ��� ������ �ڽ� ���� �̵�
			pDelNode = pDelNode->pRightChild;
		}
	}
	if (pDelNode == NULL) {
		printf("����, �������� �ʴ� Ű - [%d], deleteElementBST()\n", key);
		ret = FALSE;
		return ret;
	}
	if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
		// �����Ϸ��� ����� �ڽ��� 0���� ���
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
		// �����Ϸ��� ����� �ڽ��� 2���� ���
		pPredecessor = pDelNode;
		pSuccessor = pDelNode->pLeftChild;
		while (pSuccessor->pRightChild != NULL) {
			// ���� ����Ʈ������ ���� ū Ű ���� ������ ��� ã��
			pPredecessor = pSuccessor;
			pSuccessor = pSuccessor->pRightChild;
		}
		// ������ ���� pSuccessor�� ������ ��带 ��ü�� ��ü ��带 ����Ų��.
		// ������ ��� pDelNode�� �ڽ� ��带 ��ü ��� pSuccessor�� �ڽ� ���� ����
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
		// �����Ϸ��� ����� �ڽ��� 1���� ���
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