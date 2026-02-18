#include <stdio.h>

int main() {
    int n = 100;
    int sum = 0;
    int a = 5, b = 10;

    for (int i = 0; i < n * a; i++) {
        if (i % 2 == 0) {
            sum += (a + b) * i;
        } else {
            sum += (a - b) * (i + 1); 
        }
    }

    printf("%d\n", sum);
    return 0;
}
