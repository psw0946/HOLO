#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printArray(int value[], int count);
// radix�� ���(10�����̸� 10, 2�����̸� 2), digit�� ���ڵ� �� �ִ� �ڸ�(100�̸� 3, 99�� 2 ..)
void radixSort(int value[], int count, int radix, int digit) {
	int i = 0, bucket = 0, d = 0, factor = 1;
	vector<queue<int>> queue(radix);

	// �� �ڸ������� ������ ���鼭 �й� �� ���� ������ ����
	for (d = 0; d < digit; d++) {
		for (i = 0; i < count; i++) {
			int data = value[i];
			queue[(data / factor) % radix].push(data);
		}
		i = 0;

		// �ڷ��� �й谡 �Ϸ�� ����, �� ��Ŷ���� ������ ���鼭 �ڷḦ ������ �̸� ����
		for (bucket = 0; bucket < radix; bucket++) {
			while (!queue[bucket].empty()) {
				int data = queue[bucket].back();
				value[i] = data;
				i++;
				queue[bucket].pop();
			}
		}
		printf("Digit - %d, ", factor);
		printArray(value, count);
		factor *= radix;
	}
}

int main() {
	int a[6] = { 31, 20, 5, 45, 56, 23 };
	radixSort(a, 6, 10, 2);
	return 0;
}

void printArray(int value[], int count) {
	int i = 0;
	for (i = 0; i < count; i++) {
		cout << value[i] << " ";
	}
	printf("\n");
}

// �ð����⵵ : �ڸ����� d�� �� O(d*n).
//				���� 32��Ʈ �������� d�ڸ����� 10������ ����� �ش��ϱ� ������ ���������� ȿ���� O(n)