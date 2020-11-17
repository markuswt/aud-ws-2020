#include <stdio.h>

int main() {
    int n;
    printf("Bitte eine Zahl eingeben:\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", i*j);
        }
        printf("\n");
    }
}
