#include <iostream>
using namespace std;

#define MAX_SIZE 1000 // 배열의 최대 크기
#define MAX_NUM 10000 // 배열 안 원소로서 수의 최대 크기

int main() {
	int N; // 배열의 길이 (N <= MAX_SIZE)
	int A[MAX_SIZE + 1]; // 정렬 전 배열
	int B[MAX_SIZE + 1]; // 정렬 후 배열
	int count[MAX_NUM + 1]; // 각 숫자가 몇 개인지에 대한 배열
	int countSum[MAX_NUM + 1]; // 숫자 개수의 누적합을 담은 배열

	scanf("%d", &N);

	for (int i = 0; i <= N; i++)
		count[i] = 0;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		count[A[i]]++; // 숫자 등장 횟수 카운트
	}

	countSum[0] = count[0];
	for (int i = 1; i <= MAX_NUM; i++)
		countSum[i] = countSum[i - 1] + count[i];

	for (int i = N; i >= 1; i--) {
		B[countSum[A[i]]] = A[i];
		countSum[A[i]]--;
	}

	for (int i = 1; i <= N; i++)
		printf("%d ", B[i]);

	return 0;
}