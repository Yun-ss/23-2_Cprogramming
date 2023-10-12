#include <stdio.h>

int main() {
	int a = 3;
	int* ptr1 = &a;
	char b = 'b';
	char* ptr2 = &b;

	printf("%d\n", ptr1);
	printf("%d\n", sizeof(ptr1));
	printf("%d\n", ptr2);
	printf("%d\n", sizeof(ptr2));
	return 0;
}