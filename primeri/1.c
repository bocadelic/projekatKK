#include <stdio.h>

int main() {
    int n = 100;
    int sum = 0;
    int a = 5, b = 10;

    for (int i = 0; i < n; i++) {
        sum += a + b;
    }

    printf("Sum = %d\n", sum);
    return 0;
}

