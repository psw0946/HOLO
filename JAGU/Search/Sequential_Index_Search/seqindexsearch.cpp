#include <iostream>
#include "seqindexsearch.h"
using namespace std;

int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key) {
	int ret = FAIL;
	int i = 0;
	int start = 0, end = 0;

	if (key >= value[0] && key <= value[size - 1]) {
		/*
		 * 인덱스 테이블을 순차 검색하여 찾으려는 키 값(key)보다 인덱스 테이블에 저장된 키 값이 더 큰 경우까지 루프를 돈다.
		 * 이 경우 검색 대상 키 값보다 큰 인덱스의 위치는 변수 i에 저장된다.
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

// size : value의 크기, indexSize : indexTable의 크기
IndexTable* createIndexTable(int value[], int size, int indexSize) {
	IndexTable* pReturn = NULL;
	int i = 0;
	int ratio = 0;

	if (size <= 0 || indexSize <= 0) {
		printf("인덱스 크기 및 배열의 크기는 0보다 커야합니다\n");
		return NULL;
	}

	ratio = size / indexSize;
	if (size % indexSize > 0)
		ratio = ratio + 1;

	pReturn = new IndexTable[indexSize];
	if (pReturn == NULL) {
		printf("오류, 메모리할당 in createIndexTable()\n");
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