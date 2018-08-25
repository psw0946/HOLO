#include "bintree.cpp"
using namespace std;

int main() {
	BinTree<char> *pBinTree = NULL;
	Node<char> *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
	Node<char> *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;
	Node<char> node = { 0, };

	node.data = 'A';
	pBinTree = pBinTree->makeBinTree(node);
	if (pBinTree != NULL) {
		pNodeA = pBinTree->getRootNodeBT();

		node.data = 'B';
		pNodeB = pBinTree->insertLeftChildNodeBT(pNodeA, node);

		node.data = 'C';
		pNodeC = pBinTree->insertRightChildNodeBT(pNodeA, node);

		if (pNodeB != NULL) {
			node.data = 'D';
			pNodeD = pBinTree->insertLeftChildNodeBT(pNodeB, node);
		}

		if (pNodeC != NULL) {
			node.data = 'E';
			pNodeE = pBinTree->insertLeftChildNodeBT(pNodeC, node);

			node.data = 'F';
			pNodeF = pBinTree->insertRightChildNodeBT(pNodeC, node);
		}
		pBinTree->deleteBinTree();
	}

	return 0;
}