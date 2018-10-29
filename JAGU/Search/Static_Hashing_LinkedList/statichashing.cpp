#include <iostream>
#include <string.h>
#include "statichashing.h"
using namespace std;

HashTable* createHashTable(int bucketSize) {
	HashTable *pReturn = NULL;
	int i = 0, j = 0;
	if (bucketSize < 1) {
		printf("버켓 크기는 0보다 커야 합니다.\n");
		return NULL;
	}

	pReturn = new HashTable();
	if (pReturn == NULL) {
		printf("오류, 첫 번째 메모리 할당, createHashTable()\n");
		return NULL;
	}
	memset(pReturn, 0, sizeof(HashTable));
	pReturn->bucketSize = bucketSize;
	pReturn->ppElement = new LinkedList*[bucketSize];

	if (pReturn->ppElement != NULL) {
		memset(pReturn->ppElement, 0, sizeof(LinkedList*) * bucketSize);
		for (i = 0; i < bucketSize; i++) {
			pReturn->ppElement[i] = createLinkedList();
			if (pReturn->ppElement[i] == NULL) {
				for (j = 0; j < i - 1; j++) {
					if (pReturn->ppElement[j] != NULL)
						delete pReturn->ppElement[j];
				}
				if (pReturn->ppElement != NULL)
					delete pReturn->ppElement;
				if (pReturn != NULL)
					delete pReturn;
				return NULL;
			}
		}
	}
	else {
		if (pReturn != NULL)
			delete pReturn;
		printf("오류, 두 번째 메모리 할당, createHashTable()\n");
		return NULL;
	}
	
	return pReturn;
}

int addLLElementLast(LinkedList *pList, HashElement element) {
	Node node = { 0, };
	if (pList == NULL)
		return FALSE;
	node.data = element;
	return addLLElement(pList, getLinkedListLength(pList), node);
}

int addSHT(HashTable* pHashTable, HashElement element) {
	int ret = FALSE;
	LinkedList* pList = NULL;
	if (pHashTable != NULL) {
		pList = searchBucket(pHashTable, element.key);
		if (pList != NULL) {
			addLLElementLast(pList, element);
			pHashTable->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("오류, 잘못된 해시 테이블 주소가 계산되었습니다, addSHT()\n");
		}
	}

	return ret;
}

LinkedList* searchBucket(HashTable* pHashTable, char* key) {
	LinkedList* pReturn = NULL;
	int bucketIndex = 0;

	if (pHashTable != NULL) {
		bucketIndex = hashFunction(key, pHashTable->bucketSize);
		if (bucketIndex >= 0) {
			pReturn = pHashTable->ppElement[bucketIndex];
		}
		else {
			printf("오류, 잘못된 해시 테이블 주소가 계산되었습니다, searchHT()\n");
		}
	}

	return pReturn;
}

HashElement* searchHT(HashTable* pHashTable, char* key) {
	HashElement* pReturn = NULL;
	LinkedList* pList = NULL;
	int position = 0;

	pList = searchBucket(pHashTable, key);
	if (pList != NULL) {
		pReturn = searchSlot(pList, key, &position);
	}

	return pReturn;
}

HashElement* searchSlot(LinkedList* pList, char* key, int* pPosition) {
	HashElement* pReturn = NULL;
	HashElement* pElement = NULL;
	Node* pNode = NULL;
	int position = 0;
	if (pList != NULL && pPosition != NULL) {
		pNode = getLLElement(pList, 0);
		while (pNode != NULL) {
			if (strcmp(pNode->data.key, key) == 0) {
				pReturn = &(pNode->data);
				*pPosition = position;
				break;
			}
			pNode = pNode->pLink;
			position++;
		}
		if (pReturn == NULL) {
			printf("검색 실패, 검색키-[%s]는 존재하지 않습니다, searchHT()\n", key);
		}
	}

	return pReturn;
}

int deleteElementHT(HashTable *pHashTable, char* key) {
	int ret = FALSE;

	HashElement *pElement = NULL;
	LinkedList* pList = NULL;
	int position = 0;
	pList = searchBucket(pHashTable, key);
	if (pList != NULL) {
		pElement = searchSlot(pList, key, &position);
		if (pElement != NULL) {
			removeLLElement(pList, position);
			pHashTable->currentElementCount--;
			ret = TRUE;
		}
	}

	return ret;
}

int hashFunction(char *pKey, int bucketSize) {
	int ret = -1;
	unsigned int temp_key = 0;
	if (pKey == NULL)
		return ret;
	temp_key = stringToInt(pKey);
	if (bucketSize > 0)
		ret = temp_key % bucketSize;
	return ret;
}

unsigned int stringToInt(char *pKey) {
	unsigned int ret = 0;
	while (*pKey != '\0') {
		ret = (ret * 31) + (*pKey);
		*pKey++;
	}
	if (ret < 0) {
		ret = ret * (-1);
	}
	return ret;
}

void deleteHashTable(HashTable* pHashTable) {
	int i = 0;
	if (pHashTable == NULL)
		return;
	for (i = 0; i < pHashTable->bucketSize; i++) {
		deleteLinkedList(pHashTable->ppElement[i]);
	}
	delete pHashTable->ppElement;
	delete pHashTable;
}

void displayHashTable(HashTable *pHashTable) {
	int i = 0, j = 0;
	int slotSize = 0;
	LinkedList *pList = NULL;
	Node *pNode = NULL;
	HashElement *pElement = NULL;
	if (pHashTable == NULL)
		return;
	for (i = 0; i < pHashTable->bucketSize; i++) {
		printf("[%d], ", i);
		pList = pHashTable->ppElement[i];
		slotSize = getLinkedListLength(pList);
		if (slotSize == 0) {
			printf("Empty\n");
		}
		else {
			for (j = 0; j < slotSize; j++) {
				pNode = getLLElement(pList, j);
				if (pNode != NULL) {
					pElement = &(pNode->data);
					printf("(%s, %d) ", pElement->key, pElement->value);
				}
			}
			printf("\n");
		}
	}
}