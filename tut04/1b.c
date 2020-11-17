#include <stdio.h>

int main() {
    int n;
    printf("Bitte eine Zahl eingeben:\n");
    scanf("%d", &n);
    int m = 1;
    for (int i = n; i > 1; i--) {
        m *= i;
    }
    printf("%d! = %d\n", n, m);
}
