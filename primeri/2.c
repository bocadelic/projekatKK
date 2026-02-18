#include <stdio.h>

int main() {
    int n = 1000;
    int arr[1000];
    int x = 7, y = 3, z = 0;
    
    for (int i = 0; i < (5*x - 2*y); i++) {
        z += y*x;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i * (x + y + z); 
    }

    printf("arr[0] = %d, arr[n-1] = %d\n", arr[0], arr[n-1]);
    return 0;
}
