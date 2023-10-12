#include <stdio.h>

void swap(int* num1, int* num2) {
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
void sort(int arr[],int length) {
	int min;
	int tmp;
	for (int i = 0; i < length; i++) {
		min = i;
		tmp = arr[i];
		for (int j = i; j < length; j++) {
			if (tmp > arr[j]) {
				tmp = arr[j];
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
	}
}
int main() {
	int array[5] = {5,4,1,2,3};
	int length = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < length; i++) {
		printf("%d: %d\n", (i+1), array[i]);
	}
	sort(array, length);
	for (int i = 0; i < length; i++) {
		printf("%d: %d\n", (i + 1), array[i]);
	}
	return 0;
}