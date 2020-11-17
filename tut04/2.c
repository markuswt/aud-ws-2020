#include <stdio.h>

int main() {
    int turn = 1;
    int matches;
    printf("Wie viele Streichhoelzer sind vorhanden?\n");
    scanf("%d", &matches);

    while(matches > 0) {
        if (turn) {
            // Zug des Computers
            matches -= 3;
            turn = 0;
        }
        else {
            // Zug des Menschen
            printf("%d Streichhoelzer verbleiben\n", matches);
            int n = 0;
            while (n <= 0 || n > 3) {
                printf("Wollen sie 1, 2 oder 3 Streichhoelzer ziehen?\n");
                scanf("%d", &n);
            }
            matches -= n;
            turn = 1;
        }
    }

    if (turn) {
        printf("Computer gewinnt!\n");
    }
    else {
        printf("Mensch gewinnt!\n");
    }
}
