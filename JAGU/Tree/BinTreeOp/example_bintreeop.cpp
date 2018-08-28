#include "bintree.cpp"
#include "bintreeop.cpp"
using namespace std;

BinTree<char>* createExampleBinTree();

int main() {
	int compareResult = FALSE;
	int count = 0;
	BinTree<char> *pBinTree = NULL, *pCopyBinTree = NULL;

	pBinTree = createExampleBinTree();
	printf("���� Ʈ�� ����:\n");
	displayBinTree(pBinTree);

	pCopyBinTree = copyBinTree(pBinTree);
	printf("���� Ʈ�� ���纻:\n");
	displayBinTree(pCopyBinTree);

	compareResult = equalBinTree(pBinTree, pCopyBinTree);
	printf("\n���� Ʈ�� �� ���: (%d)\n", compareResult);

	count = getNodeCountBT(pBinTree);
	printf("\n���� Ʈ�� ��� ����: %d\n", count);

	count = getLeafNodeCountBT(pBinTree);
	printf("\n���� Ʈ�� �ܸ� ��� ����: %d\n", count);

	count = getHeightBT(pBinTree);
	printf("\n���� Ʈ���� ����: %d\n", count);

	pBinTree->deleteBinTree();
	pCopyBinTree->deleteBinTree();
	return 0;
}

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