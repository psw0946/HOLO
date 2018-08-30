#include "binsearchtree.cpp"
using namespace std;

void displayBinSearchTreeInternal(Node<char> *pTreeNode, int level, char type) {
	int i = 0;
	for (i = 0; i < level; i++) {
		printf("     ");
	}
	if (pTreeNode != NULL) {
		printf("-[%i, %c] %i - %c\n", level, type, pTreeNode->key, pTreeNode->value);
		displayBinSearchTreeInternal(pTreeNode->pLeftChild, level + 1, 'L');
		displayBinSearchTreeInternal(pTreeNode->pRightChild, level + 1, 'R');
	}
	else {
		printf("NULL\n");
	}
}

int main() {
	BinSearchTree<char> *pTree = NULL;
	Node<char> *pSearchNode = NULL;
	int key = 0;

	Node<char> e1 = { 30, 'A' };
	Node<char> e2 = { 20, 'B' };
	Node<char> e3 = { 40, 'C' };
	Node<char> e4 = { 10, 'D' };
	Node<char> e5 = { 24, 'E' };
	Node<char> e6 = { 34, 'F' };
	Node<char> e7 = { 46, 'G' };
	Node<char> e8 = { 6, 'H' };
	Node<char> e9 = { 14, 'I' };
	Node<char> e10 = { 22, 'J' };
	Node<char> e11 = { 50, 'K' };
	Node<char> e12 = { 2, 'L' };
	Node<char> e13 = { 38, 'M' };

	pTree = pTree->createBinSearchTree();
	if (pTree != NULL) {
		pTree->insertElementBST(e1);
		pTree->insertElementBST(e2);
		pTree->insertElementBST(e3);
		pTree->insertElementBST(e4);
		pTree->insertElementBST(e5);
		pTree->insertElementBST(e6);
		pTree->insertElementBST(e7);
		pTree->insertElementBST(e8);
		pTree->insertElementBST(e9);
		pTree->insertElementBST(e10);
		pTree->insertElementBST(e11);
		pTree->insertElementBST(e12);
		pTree->insertElementBST(e13);
		displayBinSearchTreeInternal(pTree->pRootNode, 0, 'O');

		key = 14;
		pSearchNode = pTree->searchBST(key);
		if (pSearchNode != NULL) {
			printf("key : [%d], node : [%c]\n", key, pSearchNode->value);
		}

		key = 14;
		pSearchNode = pTree->searchRecursiveBST(key);
		if (pSearchNode != NULL) {
			printf("key : [%d], node : [%c]\n", key, pSearchNode->value);
		}

		key = 30;
		pTree->deleteElementBST(key);
		displayBinSearchTreeInternal(pTree->pRootNode, 0, 'O');

		key = 46;
		pTree->deleteElementBST(key);
		displayBinSearchTreeInternal(pTree->pRootNode, 0, 'O');

		key = 40;
		pTree->deleteElementBST(key);
		displayBinSearchTreeInternal(pTree->pRootNode, 0, 'O');

		pTree->deleteBinSearchTree();
	}

	return 0;
}