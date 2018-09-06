#include <iostream>
using namespace std;

template <typename T>
void printArray(T value[], int count);

template <typename T>
void insertionSort(T value[], int count) {
	int i = 0, j = 0;
	int temp = 0;

	for (int i = 1; i < count; i++) {
		temp = value[i];
		j = i;
		while ((j > 0) && value[j - 1] > temp) {
			value[j] = value[j - 1];
			j--;
		}
		value[j] = temp;

		printf("Step-%d, ", i);
		printArray(value, count);
	}
}

int main() {
	int values[] = { 80, 50, 70, 10, 60, 20, 40, 30 };

	printf("Before Sort\n");
	printArray(values, 8);

	insertionSort(values, 8);

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