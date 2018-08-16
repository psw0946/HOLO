#include <iostream>
#include "arraylist.cpp"
/* 
 * arraylist.h �� ��������� ���� class�� �����ϸ鼭 template�� ����Ͽ��ٸ�
 * cpp ������ ���� ���Խ��Ѿ� �Ѵ�. (�ȱ׷��� �ܺα�ȣ ���� ������ �߻�....)
 */
using namespace std;

int main() {
	int i = 0;
	int arrayCount = 0;
	ArrayList<int> *pList = NULL;
	int pValue = 0;

	pList = pList->createArrayList(6);
	if (pList != NULL) {
		pList->addALElement(0, 1);
		pList->addALElement(1, 3);
		pList->addALElement(2, 5);
		pList->displayArrayList();

		// ù ��° ���� ����
		pList->removeALElement(0);
		pList->displayArrayList();

		arrayCount = pList->getArrayListLength();
		for (i = 0; i < arrayCount; i++) {
			pValue = pList->getALElement(i);
			printf("��ġ [%d]-%d\n", i, pValue);
		}

		pList->deleteArrayList();
	}

	return 0;
}