#include <iostream>
using namespace std;

template <typename T>
void printArray(T value[], int count);

template <typename T>
void bubbleSort(T value[], int count) {
	int i = 0, j = 0;
	int temp = 0;

	for (i = count - 1; i >= 0; i--) {
		for (j = 1; j <= i; j++) {
			if (value[j - 1] > value[j]) {
				temp = value[j - 1];
				value[j - 1] = value[j];
				value[j] = temp;
			}
		}
		printf("Step-%d, ", count - i);
		printArray(value, count);
	}

}

int main() {
	int values[] = { 80, 50, 70, 10, 60, 20, 40, 30 };

	printf("Before Sort\n");
	printArray(values, 8);

	bubbleSort(values, 8);

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