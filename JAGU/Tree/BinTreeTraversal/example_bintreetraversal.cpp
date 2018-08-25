#include "bintree.cpp"
#include "bintreetraversalrec.cpp"
using namespace std;

BinTree<char>* createExampleBinTree() {
	BinTree<char> *pReturn = NULL;
	Node<char> *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
	Node<char> *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;
	Node<char> node = { 0, };

	node.data = 'A';
	pReturn = pReturn->makeBinTree(node);
	if (pReturn != NULL) {
		pNodeA = pReturn->getRootNodeBT();

		node.data = 'B';
		pNodeB = pReturn->insertLeftChildNodeBT(pNodeA, node);

		node.data = 'C';
		pNodeC = pReturn->insertRightChildNodeBT(pNodeA, node);

		if (pNodeB != NULL) {
			node.data = 'D';
			pNodeD = pReturn->insertLeftChildNodeBT(pNodeB, node);
		}

		if (pNodeC != NULL) {
			node.data = 'E';
			pNodeE = pReturn->insertLeftChildNodeBT(pNodeC, node);

			node.data = 'F';
			pNodeF = pReturn->insertRightChildNodeBT(pNodeC, node);
		}
	}

	return pReturn;
}

int main() {
	BinTree<char> *pBinTree = NULL;
	pBinTree = createExampleBinTree();
	if (pBinTree != NULL) {
		printf("Preorder Recursive Traversal\n");
		preorderTraversalRecursiveBinTree(pBinTree);

		printf("\nInorder Recursive Traversal\n");
		inorderTraversalRecursiveBinTree(pBinTree);

		printf("\nPostorder Recursive Traversal\n");
		postorderTraversalRecursiveBinTree(pBinTree);

		pBinTree->deleteBinTree();
	}

	return 0;
}