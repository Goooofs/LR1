#include <istream>
#include <time.h>

void ShiftLeft_k(int* a, int n, int p, int k) // Сдвиг влево с p позиции на k элементов
{
	for (int i = p; i < n - k; i++) a[i] = a[i + k];
}

int main()
{
	int n = 20, a[100], max = 0, min = 10000, k1, k2, k, l, sum = 0;

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		a[i] = rand() % 30;
		printf("%d  ", a[i]);
	}

	printf("\n\n");

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				ShiftLeft_k(a, n, j, 1);
				n--;
				j--;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}

	printf("\n\n");

	for (int i = 0; i < n; i++) {
		if (max < a[i]) max = a[i];
		if (min > a[i]) min = a[i];
		if (a[i] == max) k1 = i;
		if (a[i] == min) k2 = i;
	}

	printf("max = %d, index = %d\nmin = %d, index = %d\n\n", max, k1, min ,k2);

	if (k1 < k2) k = k1, l = k2;
	else k = k2, l = k1;

	for (int i = k; i <= l; i++) {
		sum += a[i];
	}

	printf("summa = %d\n", sum);

	return 0;
}

