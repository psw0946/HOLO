#include <iostream>
using namespace std;

void merge(int value[], int buffer[], int start, int middle, int end);
void printArray(int value[], int count);
void mergeSort(int value[], int buffer[], int start, int end) {
	int middle = 0;
	if (start < end) {
		middle = (start + end) / 2;
		mergeSort(value, buffer, start, middle);
		mergeSort(value, buffer, middle + 1, end);
		merge(value, buffer, start, middle, end);
	}
}

void merge(int value[], int buffer[], int start, int middle, int end) {
	int i = 0, j = 0, k = 0, t = 0;
	i = start; // 첫 번째 부분집합의 원소를 가리키는 인덱스
	j = middle + 1; // 두 번째 부분집합의 원소를 가리키는 인덱스
	k = start; // 결과 버퍼의 현재 위치를 가리키는 인덱스

	while (i <= middle && j <= end) {
		if (value[i] <= value[j]) {
			buffer[k] = value[i];
			i++;
		}
		else {
			buffer[k] = value[j];
			j++;
		}
		k++;
	}
	while (i <= middle)
		buffer[k++] = value[i++];
	while (j <= end)
		buffer[k++] = value[j++];

	for (t = start; t <= end; t++)
		value[t] = buffer[t];
	printf("start - %d, middle - %d, end - %d, ", start, middle, end);
	for (t = start; t <= end; t++)
		printf("%d ", value[t]);
	printf("\n");
}

int main() {
	int a[5] = { 10, 50, 30, 20, 40 };
	int buffer[5];
	mergeSort(a, buffer, 0, 4);
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