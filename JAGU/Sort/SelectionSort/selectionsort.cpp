#include <iostream>
using namespace std;

template <typename T>
void printArray(T value[], int count);

template <typename T>
void selectionSort(T value[], int count) {
	int i = 0, j = 0;
	int min = 0, temp = 0;

	// 전체 자료 개수보다 1 적은 횟수(count - 1)만큼 루프를 돈다.
	// 정렬의 마지막에 남은 자료는 최대 자료이기 때문에 추가적인 정렬이 필요 없다.
	for (i = 0; i < count - 1; i++) {
		// (정렬되지 않은 자료들 중) 최솟값의 위치(min)를 초기화 시킨다.
		min = i;
		for (j = i + 1; j < count; j++) {
			// 정렬되지 않은 자료들을 대상으로 가장 작은 키 값을 찾는다.
			if (value[j] < value[min]) {
				min = j;
			}
		}
		temp = value[i];
		value[i] = value[min];
		value[min] = temp;

		printf("Step-%d, ", i + 1);
		printArray(value, count);
	}
}

int main() {
	int values[] = { 80, 50, 70, 10, 60, 20, 40, 30 };

	printf("Before Sort\n");
	printArray(values, 8);

	selectionSort(values, 8);

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