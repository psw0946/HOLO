#include <iostream>
using namespace std;

void shellInsertionSort(int value[], int start, int end, int interval);
void printArray(int value[], int count);
void shellSort(int value[], int count) {
	int i = 0, interval = 0;
	
	// 초기 간격(interval)은 자료 개수의 1/2로 설정한다.
	interval = count / 2;
	while (interval >= 1) {
		// 간격이 1이 될 때까지 루프를 돈다.
		for (i = 0; i < interval; i++)
			// 주어진 간격 interval로 삽입 정렬을 실행한다.
			// 삽입 정렬 함수에 간격 interval 조건을 추가한 함수 shellInsertionSort()를 호출한다.
			shellInsertionSort(value, i, count - 1, interval);
		
		printf("Interval - %d, ", interval);
		printArray(value, count);

		interval /= 2;
	}
}

void shellInsertionSort(int value[], int start, int end, int interval) {
	int i = 0;
	int item = 0, index = 0;
	
	// 기존 정렬된 부분집합의 제일 뒷자리부터 시작.
	for (i = start + interval; i <= end; i = i + interval) { // 정렬의 범위가 start + interval 부터 end까지이다. 또한, 간격을 이용하여 정렬 대상을 선정한다.
		item = value[i];
		index = i - interval; // 삽입 정렬의 키 값과 위치를 초기화시킨다.

		while ((index >= start) && item < value[index]) {
			value[index + interval] = value[index];
			index -= interval;
		}

		value[index + interval] = item; // 최종적으로 찾은 위치에 정렬할 자료를 삽입한다.
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