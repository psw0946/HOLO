#include <iostream>
using namespace std;

template <typename T>
int parititon(T value[], int start, int end);
template <typename T>
void printArray(T value[], int count);

template <typename T>
void quickSort(T value[], int start, int end) {
	int pivot = 0;
	if (start < end) {
		pivot = partition(value, start, end);
		quickSort(value, start, pivot - 1);
		quickSort(value, pivot + 1, end);
	}
}

template <typename T>
int partition(T value[], int start, int end) {
	int pivot = 0;
	int temp = 0, left = 0, right = 0;

	// Left와 Right 및 피봇의 위치를 초기화 시킨다.
	// 여기서는 피봇의 초기 위치가 Right와 동일하다.
	left = start;
	right = end;
	pivot = end;

	while (left < right) {
		while ((value[left] < value[pivot]) && (left < right)) {
			left++;
		}
		while ((value[right] >= value[pivot]) && (left < right)) {
			right--;
		}

		if (left < right) {
			temp = value[left];
			value[left] = value[right];
			value[right] = temp;

			printf("start-[%d], end-[%d], pivot-[%d], in-loop\n", start, end, value[pivot]);
		}
	}

	temp = value[pivot];
	value[pivot] = value[right];
	value[right] = temp;

	printf("start-[%d], end-[%d], pivot-[%d], out-loop\n", start, end, value[right]);

	return right;
}

int main() {
	int values[] = { 80, 50, 70, 10, 60, 20, 40, 30 };

	printf("Before Sort\n");
	printArray(values, 8);

	quickSort(values, 0, 7);

	printf("\nAfter Sort\n");
	printArray(values, 8);

	return 0;
}

template <typename T>
void printArray(T value[], int count) {
	int i = 0;
	for (i = 0; i < count; i++) {
		cout << value[i] << " ";
	}
	printf("\n");
}