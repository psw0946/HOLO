#include <iostream>
#include "seqindexsearch.h"
using namespace std;

int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key) {
	int ret = FAIL;
	int i = 0;
	int start = 0, end = 0;

	if (key >= value[0] && key <= value[size - 1]) {
		/*
		 * �ε��� ���̺��� ���� �˻��Ͽ� ã������ Ű ��(key)���� �ε��� ���̺� ����� Ű ���� �� ū ������ ������ ����.
		 * �� ��� �˻� ��� Ű ������ ū �ε����� ��ġ�� ���� i�� ����ȴ�.
		 */
		for (i = 0; i < indexSize; i++) {
			if (index[i].key > key)
				break;
		}
		start = index[i - 1].position;
		if (i >= indexSize)
			end = size - 1;
		else
			end = index[i].position - 1;

		ret = sequentialRangeSearchAscendingSorted(value, start, end, key);
	}

	return ret;
}

int sequentialRangeSearchAscendingSorted(int value[], int start, int end, int key) {
	int ret = FAIL;
	int i = 0;
	for (i = start; i <= end && value[i] < key; i++) {
		// do nothing
	}
	
	if (i <= end && value[i] == key)
		ret = i;

	return ret;
}

// size : value�� ũ��, indexSize : indexTable�� ũ��
IndexTable* createIndexTable(int value[], int size, int indexSize) {
	IndexTable* pReturn = NULL;
	int i = 0;
	int ratio = 0;

	if (size <= 0 || indexSize <= 0) {
		printf("�ε��� ũ�� �� �迭�� ũ��� 0���� Ŀ���մϴ�\n");
		return NULL;
	}

	ratio = size / indexSize;
	if (size % indexSize > 0)
		ratio = ratio + 1;

	pReturn = new IndexTable[indexSize];
	if (pReturn == NULL) {
		printf("����, �޸��Ҵ� in createIndexTable()\n");
		return NULL;
	}

	for (i = 0; i < indexSize; i++) {
		pReturn[i].position = i * ratio;
		pReturn[i].key = value[i * ratio];
	}

	return pReturn;
}

void showIndexTable(IndexTable *pIndexTable, int indexSize) {
	printf("showIndexTable\n");
	printf("--------------------\n");
	for (int i = 0; i < indexSize; i++) {
		printf("[%d] %d\n", pIndexTable[i].position, pIndexTable[i].key);
	}
	return;
}