#include <stdio.h>

int main() {
    int n = 100;
    int arr[100];
    int a = 2, b = 3;

    for (int i = 0; i < n; i++) {
        arr[i] = i * (a + b) + (a * b);
    }

    printf("arr[0] = %d, arr[n-1] = %d\n", arr[0], arr[n-1]);
    return 0;
}
