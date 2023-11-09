#include <stdio.h>

int main()
{
    int a = 0;//0, -2147483648
    if (a == -a) {
        printf("Hello World!");
    }
    else {
        printf("Goodbye World!");
    }

    return 0;
}