#include <stdio.h>
#include <stdlib.h>


typedef struct element* list;
struct element {int value; list next;};


void print_list(list l) {
    printf("[");
    while (l != NULL) {
        printf("%d", (*l).value);
        l = (*l).next;
        // don't print comma after last element
        if (l != NULL) printf(", ");
    }
    printf("]\n");
}


void append(list* lp, int n) {
    list new = (list) malloc(sizeof(struct element));
    (*new).value = n;
    (*new).next = NULL;

    // insert new element at first position if list is empty
    if (*lp == NULL) *lp = new;
    else {
        list l = *lp;
        while ((*l).next != NULL) l = (*l).next;
        (*l).next = new;
    }
}


int sum(list l) {
    int s = 0;
    while (l != NULL) {
        s += (*l).value;
        l = (*l).next;
    }
    return s;
}


void rm_evens(list* lp) {
    while (*lp != NULL) {
        if ((**lp).value % 2 == 0) {
            list tmp = *lp;
            *lp = (**lp).next;
            free(tmp);
        }
        // lp points to the next field of the "previous" element
        // *lp points to the current element
        else lp = &(**lp).next;
    }
}


list odds(list lp) {
    list l = NULL;
    while (lp != NULL) {
        int n = (*lp).value;
        if (n % 2 == 1) append(&l, n);
        lp = (*lp).next;
    }
    return l;
}


int main() {
    list l = NULL;
    append(&l, 4);
    append(&l, 3);
    append(&l, 2);
    append(&l, 1);
    append(&l, 0);

    printf("List: ");
    print_list(l);

    printf("Sum: %d\n", sum(l));

    printf("Newly constructed list of odd numbers: ");
    print_list(odds(l));

    rm_evens(&l);
    printf("Modified list of odd numbers: ");
    print_list(l);
}
