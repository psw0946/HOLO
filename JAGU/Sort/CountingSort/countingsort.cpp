#include <iostream>
using namespace std;

#define MAX_SIZE 1000 // �迭�� �ִ� ũ��
#define MAX_NUM 10000 // �迭 �� ���ҷμ� ���� �ִ� ũ��

int main() {
	int N; // �迭�� ���� (N <= MAX_SIZE)
	int A[MAX_SIZE + 1]; // ���� �� �迭
	int B[MAX_SIZE + 1]; // ���� �� �迭
	int count[MAX_NUM + 1]; // �� ���ڰ� �� �������� ���� �迭
	int countSum[MAX_NUM + 1]; // ���� ������ �������� ���� �迭

	scanf("%d", &N);

	for (int i = 0; i <= N; i++)
		count[i] = 0;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		count[A[i]]++; // ���� ���� Ƚ�� ī��Ʈ
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