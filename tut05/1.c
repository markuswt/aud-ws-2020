#include <stdio.h>

int ack(int x, int y) {
    if (x < 0 || y < 0) {
        return -1;
    }
    if (x == 0) {
        return y + 1;
    }
    if (y == 0) {
        return ack(x-1, 1);
    }
    return ack(x-1, ack(x, y-1));
}

int main() {
    printf("%d\n", ack(1, 1));
    printf("%d\n", ack(2, 2));
    printf("%d\n", ack(2, 3));
}
