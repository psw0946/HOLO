#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printArray(int value[], int count);
// radix는 기수(10진수이면 10, 2진수이면 2), digit은 숫자들 중 최대 자리(100이면 3, 99면 2 ..)
void radixSort(int value[], int count, int radix, int digit) {
	int i = 0, bucket = 0, d = 0, factor = 1;
	vector<queue<int>> queue(radix);

	// 각 자릿수별로 루프를 돌면서 분배 및 저장 연산을 실행
	for (d = 0; d < digit; d++) {
		for (i = 0; i < count; i++) {
			int data = value[i];
			queue[(data / factor) % radix].push(data);
		}
		i = 0;

		// 자료의 분배가 완료된 다음, 각 버킷별로 루프를 돌면서 자료를 꺼내어 이를 저장
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

// 시간복잡도 : 자릿수가 d일 때 O(d*n).
//				보통 32비트 기준으로 d자릿수가 10정도의 상수에 해당하기 때문에 실질적으로 효율성 O(n)