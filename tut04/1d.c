#include <stdio.h>

int main() {
    for (int i = 2; i <= 1000; i++) {
        int prim = 1;
        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) {
                prim = 0;
                break;
            }
        }
        if (prim) {
            printf("%d\n", i);
        }
    }
}
