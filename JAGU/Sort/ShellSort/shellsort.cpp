#include <iostream>
using namespace std;

void shellInsertionSort(int value[], int start, int end, int interval);
void printArray(int value[], int count);
void shellSort(int value[], int count) {
	int i = 0, interval = 0;
	
	// �ʱ� ����(interval)�� �ڷ� ������ 1/2�� �����Ѵ�.
	interval = count / 2;
	while (interval >= 1) {
		// ������ 1�� �� ������ ������ ����.
		for (i = 0; i < interval; i++)
			// �־��� ���� interval�� ���� ������ �����Ѵ�.
			// ���� ���� �Լ��� ���� interval ������ �߰��� �Լ� shellInsertionSort()�� ȣ���Ѵ�.
			shellInsertionSort(value, i, count - 1, interval);
		
		printf("Interval - %d, ", interval);
		printArray(value, count);

		interval /= 2;
	}
}

void shellInsertionSort(int value[], int start, int end, int interval) {
	int i = 0;
	int item = 0, index = 0;
	
	// ���� ���ĵ� �κ������� ���� ���ڸ����� ����.
	for (i = start + interval; i <= end; i = i + interval) { // ������ ������ start + interval ���� end�����̴�. ����, ������ �̿��Ͽ� ���� ����� �����Ѵ�.
		item = value[i];
		index = i - interval; // ���� ������ Ű ���� ��ġ�� �ʱ�ȭ��Ų��.

		while ((index >= start) && item < value[index]) {
			value[index + interval] = value[index];
			index -= interval;
		}

		value[index + interval] = item; // ���������� ã�� ��ġ�� ������ �ڷḦ �����Ѵ�.
	}
}

int main() {
	int a[5] = { 10, 5, 32, 49, 26 };
	shellSort(a, 5);
	printArray(a, 5);
	return 0;
}

void printArray(int value[], int count) {
	int i = 0;
	for (i = 0; i < count; i++) {
		cout << value[i] << " ";
	}
	printf("\n");
}