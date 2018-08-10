#include <iostream>
#include "arraylist.h"

template <typename T>
ArrayList<T>* ArrayList<T> :: createArrayList(int maxElementCount) {
	ArrayList<T> *pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) { // �Է� �Ķ���� ��ȿ�� ����
		pReturn = new ArrayList<T>(); // �޸� �Ҵ� == (ArrayList<T> *)malloc(sizeof(ArrayList<T>));

		if (pReturn != NULL) { // �޸� �Ҵ� ����
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else {
			printf("�޸� �Ҵ� ����... createArrayList()\n");
			return NULL;
		}
	}
	else {
		printf("�ִ� ���� ������ 0���� Ŀ�� �մϴ�.\n");
		return NULL;
	}
	
	pReturn->pElement = new T[maxElementCount]; // (T *)malloc(sizeof(T)*maxElementCount);

	if (pReturn->pElement == NULL) { // ���Ҹ� �����ϴ� �迭 �޸� �Ҵ� �� ����
		printf("���� �迭 �޸� �Ҵ� ����... createArrayList()\n");
		delete pReturn; // == free(pReturn)
		return NULL;
	}
	// memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);

	return pReturn;
}

template <typename T>
int ArrayList<T>::addALElement(int position, T element) {
	int ret = FALSE;
	int i = 0;

	// �Է� �Ķ���Ϳ� ���� ��ȿ�� ����
	if (this != NULL) { // �޸� NULL ����
		if (isArrayListFull() != TRUE) { // �迭�� ���ο� ���� �߰� ���� ����
			if (position >= 0 && position <= this->currentElementCount) { // �߰��Ϸ��� ��ġ�� �ε���
				for (i = this->currentElementCount - 1; i >= position; i--) {
					this->pElement[i + 1] = this->pElement[i]; // ���� ���ҵ��� ���������� �� ĭ�� �̵���Ű��
				}
				this->pElement[position] = element; // ���ο� ���� �߰� (�� ����)
				this->currentElementCount++;
				ret = TRUE;
			}
			else {
				printf("��ġ �ε��� [%d] ���� �ʰ�, addALElement()\n", position);
			}
		}
		else {
			printf("����Ʈ �뷮 �ʰ� [%d]/[%d]\n", position, this->maxElementCount);
		}
	}
	return ret;
}

template <typename T>
int ArrayList<T>::removeALElement(int position) {
	int ret = FALSE;
	int i = 0;

	// �Է� �Ķ���Ϳ� ���� ��ȿ�� ����
	if (this != NULL) { // �޸� NULL ����
		if (position >= 0 && position < this->currentElementCount) { // �����Ϸ��� ��ġ�� �ε���
			for (i = position; i < this->currentElementCount - 1; i++) {
				this->pElement[i] = this->pElement[i + 1]; // ���� ���ҵ��� �������� �� ĭ�� �̵�
			}
			this->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("��ġ �ε��� [%d] ���� �ʰ�, removeALElement()\n", position);
		}
	}

	return ret;
}

template <typename T>
T ArrayList<T>::getALElement(int position) {
	T* pReturn = NULL;
	
	// �Է� �Ķ���Ϳ� ���� ��ȿ�� ����
	if (this != NULL) { // �޸� NULL ����
		if (position >= 0 && position < getArrayListLength()) {
			pReturn = &(this->pElement[position]);
		}
		else {
			printf("��ġ �ε��� [%d] ���� �ʰ�, getALElement()\n", position);
		}
	}

	return *pReturn;
}

template <typename T>
void ArrayList<T>::displayArrayList() {
	int i = 0;
	if (this != NULL) {
		printf("�ִ� ���� ����: %d\n", this->maxElementCount);
		printf("���� ���� ����: %d\n", this->currentElementCount);

		for (i = 0; i < this->currentElementCount; i++) {
			printf("[%d], %d\n", i, getALElement(i));
		} // ���� ����� ������ ���� ���

		i = this->currentElementCount;
		for (; i < this->maxElementCount; i++) {
			printf("[%d], Empty\n", i);
		}
	}
	else {
		printf("ArrayList is NULL\n");
	}
}

template <typename T>
int ArrayList<T>::isArrayListFull() {
	int ret = FALSE;

	if (this != NULL) {
		if (this->currentElementCount == this->maxElementCount) {
			ret = TRUE;
		}
	}
	
	return ret;
}

template <typename T>
int ArrayList<T>::getArrayListLength() {
	int ret = 0;

	if (this != NULL) {
		ret = this->currentElementCount;
	}

	return ret;
}

template <typename T>
void ArrayList<T>::deleteArrayList() {
	int i = 0;
	if (this != NULL) {
		delete this->pElement;
		delete this;
	}
}

template <typename T>
int ArrayList<T>::addALElementFirst(int element) {
	int position = 0;
	return addALElement(position, element);
}

template <typename T>
int ArrayList<T>::addALElementLast(int element) {
	int ret = FALSE;
	int position = 0;
	if (this != NULL) {
		position = getArrayListLength(this);
		ret = addALElement(this, position, element);
	}
	return ret;
}