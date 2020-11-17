#include <stdio.h>

int main() {
    int n, m;
    printf("Bitte zwei Zahlen eingeben:\n");
    scanf("%d", &m);
    scanf("%d", &n);
    if (n <= m) {
        printf("Max: %d\n", m);
    }
    else {
        printf("Max: %d\n", n);
    }
}
