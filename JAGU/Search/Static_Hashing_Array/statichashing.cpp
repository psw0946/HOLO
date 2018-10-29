#include <iostream>
#include <string.h>
#include "statichashing.h"
using namespace std;

HashTable* createHashTable(int bucketSize) {
	HashTable *pReturn = NULL;
	int i = 0;
	// 해싱 테이블 크기 검사
	if (bucketSize <= 0) {
		printf("버킷 크기는 0보다 커야 합니다.\n");
		return NULL;
	}
	pReturn = new HashTable();
	if (pReturn != NULL) {
		pReturn->currentElementCount = 0;
		pReturn->bucketSize = bucketSize;
		pReturn->pElement = NULL;
	}
	else {
		printf("오류, 첫 번째 메모리 할당, createHashTable()\n");
		return NULL;
	}
	pReturn->pElement = new HashElement[bucketSize];
	if (pReturn->pElement != NULL) {
		memset(pReturn->pElement, 0, sizeof(HashElement) * bucketSize);
	}
	else {
		if (pReturn != NULL)
			free(pReturn);
		printf("오류, 두 번째 메모리 할당, createHashTable()\n");
		return NULL;
	}
	return pReturn;
}

// 선형조사법을 사용.
int addElementSHT(HashTable* pHashTable, HashElement element) {
	int ret = FALSE;
	HashElement *pElement = NULL;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1; // 충돌 발생 시에 키 값의 증가를 위해 사용(선형 조사법)
	if (pHashTable == NULL) {
		printf("오류, NULL-해시 테이블입니다.\n");
		return ret;
	}
	bucketIndex = hashFunction(element.key, pHashTable->bucketSize);
	if (bucketIndex < 0 || bucketIndex >= pHashTable->bucketSize) {
		printf("오류, 잘못된 해쉬 테이블 주소가 계산되었습니다, addSHT()\n");
		return ret;
	}
	tempIndex = bucketIndex;
	do {
		pElement = &(pHashTable->pElement[tempIndex]);
		// 빈 버킷인지 혹은 사용되었다가 삭제된 버킷인지 점검.
		if (isEmptyOrDeletedBucket(pElement) == TRUE) {
			/*
			 * (Case 1) 만약 빈 버킷 혹은 삭제된 버킷인 경우라면, 해당 주소에 자료를 저장하고 종료한다.
			 *			(정상적으로 자료가 추가된 경우)
			 */
			pHashTable->pElement[tempIndex] = element;
			pHashTable->pElement[tempIndex].status = USED;
			ret = TRUE;
			break;
		}
		else {
			if (strcmp(pElement->key, element.key) == 0) {
				/*
				 * (Case 2-1) 현재 주소에 검색 키와 동일한 키를 가지는 자료가 있는 경우
				 */
				printf("오류, 중복된 키-[%s], addSHT()\n", element.key);
				ret = FALSE;
				break;
			}
			else {
				/*
				 * (Case 2-2) 현재 주소에 검색 키와 다른 키를 가진 자료가 저장된 경우 (충돌이 발생한 경우)
				 *			  여기서는 선형 조사법(Linear Probing)을 사용하기 때문에, 기존 주소 tempIndex에 상수 inc 값을 더해준다.
				 */
				tempIndex = (tempIndex + inc) % pHashTable->bucketSize;
				if (tempIndex == bucketIndex) {
					/*
					 * 단, 새로 구해진 버킷의 주소(tempIndex)가 해싱 함수로 처음 계산된 주소(bucketIndex)와 같다면
					 * 해시 테이블의 남은 버킷이 없는 경우. 즉, 버킷이 꽉 찬 상태임.
					 * (새로운 자료 저장에 실패한 경우)
					 */
					printf("오류, 해쉬 테이블이 가득 찼습니다, addSHT()\n");
					ret = FALSE;
					break;
				}
			}
		}
	} while (tempIndex != bucketIndex);
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
	// 오버플로우(overflow)로 음수(minus) 값이 발생하지 않도록 하기 위해 unsigned int를 사용
	unsigned int ret = 0;

	// 호너의 방법 사용. 문자열을 숫자로 변환.
	while (*pKey != '\0') {
		ret = (ret * 31) + (*pKey);
		*pKey++;
	}

	return ret;
}

int isEmptyOrDeletedBucket(HashElement* pElement) {
	int ret = FALSE;

	// 두 경우 모두 새로운 자료의 저장이 가능
	if (pElement != NULL) {
		if (pElement->status == EMPTY || pElement->status == DELETED) {
			return true;
		}
	}

	return ret;
}

HashElement* searchHT(HashTable* pHashTable, char* key) {
	HashElement* pReturn = NULL;
	HashElement* pElement = NULL;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1;
	if (pHashTable == NULL) {
		printf("오류, NULL-해시 테이블입니다.\n");
		return NULL;
	}
	bucketIndex = hashFunction(key, pHashTable->bucketSize);
	if (bucketIndex < 0) {
		printf("오류, 잘못된 해시 테이블 주소가 계산되었습니다, addSHT()\n");
		return NULL;
	}
	tempIndex = bucketIndex;
	do {
		pElement = &(pHashTable->pElement[tempIndex]);
		if (isEmptyBucket(pElement) == TRUE) {
			/*
			 * (Case 1) 빈 버킷인 경우
			 *			(검색에 실패한 경우)
			 */
			printf("검색 실패, 검색키-[%s]는 존재하지 않습니다, searchHT()\n", key);
			pReturn = NULL;
			break;
		}
		else {
			if (pElement->status == USED && strcmp(pElement->key, key) == 0) {
				/*
				 * (Case 2-1) 현재 주소에 검색 키와 동일한 키를 가지는 자료가 있는 경우 (검색 성공)
				 */
				pReturn = pElement;
				break;
			}
			else {
				/*
				 * (Case 2-2) 충돌 때문에 다른 위치에 저장된 자료가 없는지 검사
				 */
				tempIndex = (tempIndex + 1) % pHashTable->bucketSize;
				if (tempIndex == bucketIndex) {
					/*
					 * 단, 새로 구해진 버킷의 주소(tempIndex)가 해싱 함수로 처음 계산된 주소(bucketIndex)와
					 * 같다면 해시 테이블의 모든 버킷에 대해 검사한 것이므로 검색에 실패한 경우
					 */
					printf("검색 실패, 검색키-[%s]는 존재하지 않습니다, searchHT()\n", key);
					pReturn = NULL;
					break;
				}
			}
		}
	} while (tempIndex != bucketIndex);
	return pReturn;
}

int isEmptyBucket(HashElement* pElement) {
	int ret = FALSE;

	if (pElement != NULL) {
		if (pElement->status == EMPTY) {
			ret = TRUE;
		}
	}

	return ret;
}

int deleteElementHT(HashTable* pHashTable, char* key) {
	int ret = FALSE;
	HashElement *pElement = NULL;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1;

	if (pHashTable != NULL) {
		pElement = searchHT(pHashTable, key);
		if (pElement != NULL) {
			/*
			 * 검색 성공의 경우, 해당 버킷의 상태를 'DELETED'로 변경하고 버킷에 저장된 내용을 초기화
			 */
			pElement->status = DELETED;
			pElement->key[0] = '\0';
			pElement->value = 0;
			ret = TRUE;
		}
		else {
			printf("삭제 실패, 검색키-[%s]는 존재하지 않습니다, deleteElementHT()\n", key);
		}
	}

	return ret;
}

int getElementCountHT(HashTable* pHashTable) {
	if (pHashTable == NULL)
		return -1;
	return pHashTable->currentElementCount;
}

void displayHashTable(HashTable* pHashTable) {
	int i = 0, j = 0;
	int bucketIndex = 0;

	HashElement *pElement = NULL;
	if (pHashTable == NULL) 
		return;

	printf("---------------------------------\n");

	for (i = 0; i < pHashTable->bucketSize; i++) {
		printf("[%d], ", i);
		pElement = &(pHashTable->pElement[i]);
		if (pElement->key[0] != '\0') {
			bucketIndex = hashFunction(pElement->key, pHashTable->bucketSize);
			printf("%s, (%d->%d), [%d]\n", pElement->key, bucketIndex, i, pElement->value);
		}
		else {
			printf("Empty\n");
		}
	}

	printf("---------------------------------\n");
}

void deleteHashTable(HashTable* pHashTable) {
	if (pHashTable == NULL)
		return;
	if (pHashTable->pElement != NULL)
		delete pHashTable->pElement;
	delete pHashTable;
}