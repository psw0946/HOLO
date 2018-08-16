#include <iostream>
#include "arraylist.cpp"
/* 
 * arraylist.h 로 충분하지만 만약 class를 정의하면서 template을 사용하였다면
 * cpp 파일을 직접 포함시켜야 한다. (안그러면 외부기호 참조 오류가 발생....)
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

		// 첫 번째 원소 제거
		pList->removeALElement(0);
		pList->displayArrayList();

		arrayCount = pList->getArrayListLength();
		for (i = 0; i < arrayCount; i++) {
			pValue = pList->getALElement(i);
			printf("위치 [%d]-%d\n", i, pValue);
		}

		pList->deleteArrayList();
	}

	return 0;
}