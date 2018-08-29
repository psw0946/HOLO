#include "arrayheap.h"
#include <string.h>
#include <iostream>

ArrayMaxHeap* ArrayMaxHeap::createArrayMaxHeap(int maxElementCount) {
	ArrayMaxHeap *pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {
		pReturn = new ArrayMaxHeap();
		if (pReturn != NULL) {
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = new Node[maxElementCount + 1]; // ��ġ �ε��� 0���� ������� ����.

			if (pReturn->pElement == NULL) {
				printf("�޸� �Ҵ� ����2, createArrayList()\n");
				delete pReturn;
				return NULL;
			}

			memset(pReturn->pElement, 0, sizeof(Node)*(maxElementCount + 1));
		}
		else {
			printf("�޸� �Ҵ� ����, createArrayList()\n");
		}
	}
	else {
		printf("�ִ� ���� ������ 0���� Ŀ�� �մϴ�.\n");
	}

	return pReturn;
}

void ArrayMaxHeap::insertMaxHeapAH(Node element) {
	int i = 0;

	if (this != NULL) {
		if (this->currentElementCount == this->maxElementCount) {
			printf("������ ���� á���ϴ�. [%d], insertMaxHeapAH()\n", this->maxElementCount);
			return;
		}

		this->currentElementCount++;
		i = this->currentElementCount;
		while ((i != 1) && (element.key > this->pElement[i / 2].key)) {
			// �θ� ���� Ű �� ���ϸ鼭 �̵�
			this->pElement[i] = this->pElement[i / 2];
			i /= 2;
		}
		this->pElement[i] = element;
	}
}

// ��ȯ�Ǵ� ��� Node�� �޸𸮸� �Ҵ��Ͽ� �����ϱ� ������, ��ȯ�� ����� ����� ���� �������� �ݵ�� �޸𸮸� �������Ѿ� �Ѵ�.
Node* ArrayMaxHeap::deleteMaxHeapAH() {
	Node* pReturn = NULL;
	Node* pTemp = NULL;

	int i = 0;
	int parent = 0, child = 0;

	if (this != NULL && this->currentElementCount > 0) {
		pReturn = new Node();
		if (pReturn == NULL) {
			printf("�޸� �Ҵ� ����, deleteMaxHeapAH()\n");
			return NULL;
		}
		*pReturn = this->pElement[1]; // ��Ʈ ��尡 ��ȯ�Ǵ� ���. ��ȯ�Ǵ� ����� ������ ���� ��Ʈ ����� ���� ����

		i = this->currentElementCount; // ������ ���� ������ ��ġ �ε���
		pTemp = &(this->pElement[i]); // ������ ���� ������ ��带 ����Ŵ.
		this->currentElementCount--;

		// ������ ���۵Ǵ� ���� ��Ʈ ���(�ε��� 1)�� ��Ʈ ����� ���� �ڽ� ���(�ε��� 2)
		parent = 1;
		child = 2;
		while (child <= this->currentElementCount) {
			// ������ ���� ������ ��ġ�� �ִ� ��带 ���� ������ ����
			if ((child < this->currentElementCount) && this->pElement[child].key < this->pElement[child + 1].key) {
				// ���� �ڽ� ��庸�� ������ �ڽ� ����� Ű ���� �� ũ�ٸ�,
				// ������ �ڽ� ��尡 �� ����� �ǵ��� ��ġ �ε��� child�� �����Ѵ�.
				child++;
			}
			if (pTemp->key >= this->pElement[child].key) {
				// �ռ� ������ ������ ���� ������ ���� ���� ����� Ű ���� ��
				// ����, ������ ����� Ű ���� ���� ��� ���� �� ũ�ų� ���ٸ�, ������ ���� ���´�.
				// �ٷ� �� ��ġ���� �����ϸ� �ȴ�.
				break;
			}
			this->pElement[parent] = this->pElement[child];
			parent = child;
			child *= 2;
		}
		this->pElement[parent] = *pTemp;
	}

	return pReturn;
}

void ArrayMaxHeap::deleteArrayMaxHeap() {
	if (this != NULL) {
		if (this->pElement != NULL) {
			delete this->pElement;
		}
		delete this;
	}
}