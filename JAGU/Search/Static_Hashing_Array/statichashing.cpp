#include <iostream>
#include <string.h>
#include "statichashing.h"
using namespace std;

HashTable* createHashTable(int bucketSize) {
	HashTable *pReturn = NULL;
	int i = 0;
	// �ؽ� ���̺� ũ�� �˻�
	if (bucketSize <= 0) {
		printf("��Ŷ ũ��� 0���� Ŀ�� �մϴ�.\n");
		return NULL;
	}
	pReturn = new HashTable();
	if (pReturn != NULL) {
		pReturn->currentElementCount = 0;
		pReturn->bucketSize = bucketSize;
		pReturn->pElement = NULL;
	}
	else {
		printf("����, ù ��° �޸� �Ҵ�, createHashTable()\n");
		return NULL;
	}
	pReturn->pElement = new HashElement[bucketSize];
	if (pReturn->pElement != NULL) {
		memset(pReturn->pElement, 0, sizeof(HashElement) * bucketSize);
	}
	else {
		if (pReturn != NULL)
			free(pReturn);
		printf("����, �� ��° �޸� �Ҵ�, createHashTable()\n");
		return NULL;
	}
	return pReturn;
}

// ����������� ���.
int addElementSHT(HashTable* pHashTable, HashElement element) {
	int ret = FALSE;
	HashElement *pElement = NULL;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1; // �浹 �߻� �ÿ� Ű ���� ������ ���� ���(���� �����)
	if (pHashTable == NULL) {
		printf("����, NULL-�ؽ� ���̺��Դϴ�.\n");
		return ret;
	}
	bucketIndex = hashFunction(element.key, pHashTable->bucketSize);
	if (bucketIndex < 0 || bucketIndex >= pHashTable->bucketSize) {
		printf("����, �߸��� �ؽ� ���̺� �ּҰ� ���Ǿ����ϴ�, addSHT()\n");
		return ret;
	}
	tempIndex = bucketIndex;
	do {
		pElement = &(pHashTable->pElement[tempIndex]);
		// �� ��Ŷ���� Ȥ�� ���Ǿ��ٰ� ������ ��Ŷ���� ����.
		if (isEmptyOrDeletedBucket(pElement) == TRUE) {
			/*
			 * (Case 1) ���� �� ��Ŷ Ȥ�� ������ ��Ŷ�� �����, �ش� �ּҿ� �ڷḦ �����ϰ� �����Ѵ�.
			 *			(���������� �ڷᰡ �߰��� ���)
			 */
			pHashTable->pElement[tempIndex] = element;
			pHashTable->pElement[tempIndex].status = USED;
			ret = TRUE;
			break;
		}
		else {
			if (strcmp(pElement->key, element.key) == 0) {
				/*
				 * (Case 2-1) ���� �ּҿ� �˻� Ű�� ������ Ű�� ������ �ڷᰡ �ִ� ���
				 */
				printf("����, �ߺ��� Ű-[%s], addSHT()\n", element.key);
				ret = FALSE;
				break;
			}
			else {
				/*
				 * (Case 2-2) ���� �ּҿ� �˻� Ű�� �ٸ� Ű�� ���� �ڷᰡ ����� ��� (�浹�� �߻��� ���)
				 *			  ���⼭�� ���� �����(Linear Probing)�� ����ϱ� ������, ���� �ּ� tempIndex�� ��� inc ���� �����ش�.
				 */
				tempIndex = (tempIndex + inc) % pHashTable->bucketSize;
				if (tempIndex == bucketIndex) {
					/*
					 * ��, ���� ������ ��Ŷ�� �ּ�(tempIndex)�� �ؽ� �Լ��� ó�� ���� �ּ�(bucketIndex)�� ���ٸ�
					 * �ؽ� ���̺��� ���� ��Ŷ�� ���� ���. ��, ��Ŷ�� �� �� ������.
					 * (���ο� �ڷ� ���忡 ������ ���)
					 */
					printf("����, �ؽ� ���̺��� ���� á���ϴ�, addSHT()\n");
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
	// �����÷ο�(overflow)�� ����(minus) ���� �߻����� �ʵ��� �ϱ� ���� unsigned int�� ���
	unsigned int ret = 0;

	// ȣ���� ��� ���. ���ڿ��� ���ڷ� ��ȯ.
	while (*pKey != '\0') {
		ret = (ret * 31) + (*pKey);
		*pKey++;
	}

	return ret;
}

int isEmptyOrDeletedBucket(HashElement* pElement) {
	int ret = FALSE;

	// �� ��� ��� ���ο� �ڷ��� ������ ����
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
		printf("����, NULL-�ؽ� ���̺��Դϴ�.\n");
		return NULL;
	}
	bucketIndex = hashFunction(key, pHashTable->bucketSize);
	if (bucketIndex < 0) {
		printf("����, �߸��� �ؽ� ���̺� �ּҰ� ���Ǿ����ϴ�, addSHT()\n");
		return NULL;
	}
	tempIndex = bucketIndex;
	do {
		pElement = &(pHashTable->pElement[tempIndex]);
		if (isEmptyBucket(pElement) == TRUE) {
			/*
			 * (Case 1) �� ��Ŷ�� ���
			 *			(�˻��� ������ ���)
			 */
			printf("�˻� ����, �˻�Ű-[%s]�� �������� �ʽ��ϴ�, searchHT()\n", key);
			pReturn = NULL;
			break;
		}
		else {
			if (pElement->status == USED && strcmp(pElement->key, key) == 0) {
				/*
				 * (Case 2-1) ���� �ּҿ� �˻� Ű�� ������ Ű�� ������ �ڷᰡ �ִ� ��� (�˻� ����)
				 */
				pReturn = pElement;
				break;
			}
			else {
				/*
				 * (Case 2-2) �浹 ������ �ٸ� ��ġ�� ����� �ڷᰡ ������ �˻�
				 */
				tempIndex = (tempIndex + 1) % pHashTable->bucketSize;
				if (tempIndex == bucketIndex) {
					/*
					 * ��, ���� ������ ��Ŷ�� �ּ�(tempIndex)�� �ؽ� �Լ��� ó�� ���� �ּ�(bucketIndex)��
					 * ���ٸ� �ؽ� ���̺��� ��� ��Ŷ�� ���� �˻��� ���̹Ƿ� �˻��� ������ ���
					 */
					printf("�˻� ����, �˻�Ű-[%s]�� �������� �ʽ��ϴ�, searchHT()\n", key);
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
			 * �˻� ������ ���, �ش� ��Ŷ�� ���¸� 'DELETED'�� �����ϰ� ��Ŷ�� ����� ������ �ʱ�ȭ
			 */
			pElement->status = DELETED;
			pElement->key[0] = '\0';
			pElement->value = 0;
			ret = TRUE;
		}
		else {
			printf("���� ����, �˻�Ű-[%s]�� �������� �ʽ��ϴ�, deleteElementHT()\n", key);
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