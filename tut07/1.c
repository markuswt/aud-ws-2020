#include <stdio.h>
#include <stdlib.h>


typedef struct element *list;
struct element {int value;  list next;};

typedef struct node *tree;
struct node {int key; tree left, right;};


// 1a
tree createNode(int n, tree l, tree r) {
    tree t = (tree) malloc(sizeof(struct node));
    (*t).key = n;
    (*t).left = l;
    (*t).right = r;
    return t;
}


// 1b
void insertl(tree *t, int n) {
    tree new = (tree) malloc(sizeof(struct node));
    (*new).key = n;
    (*new).left = NULL;
    (*new).right = NULL;

    while (*t != NULL) t = &(**t).left;
    *t = new;
}

// 1b
void insertl2(tree *t, int n) {
    tree new = (tree) malloc(sizeof(struct node));
    (*new).key = n;
    (*new).left = NULL;
    (*new).right = NULL;

    if (*t == NULL) *t = new;
    else {
        tree c = *t;
        while ((*c).left != NULL) c = (*c).left;
        (*c).left = new;
    }
}


// 1c
int leafprod(tree t) {
    int p = 1;
    if (t != NULL) {
        if ((*t).left == NULL && (*t).right == NULL) p *= (*t).key;
        else {
            p *= leafprod((*t).left);
            p *= leafprod((*t).right);
        }
    }
    return p;
}


// 1d
void defol(tree *t) {
    if (*t == NULL) return;
    if ((**t).left == NULL && (**t).right == NULL) {
        free(*t);
        *t = NULL;
    }
    else {
        defol(&(**t).left);
        defol(&(**t).right);
    }
}


// siehe tut06
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

// siehe tut06
void printList(list l) {
    printf("[");
    while (l != NULL) {
        printf("%d", (*l).value);
        l = (*l).next;
        // don't print comma after last element
        if (l != NULL) printf(", ");
    }
    printf("]\n");
}

void treeToListRec(tree t, list* l) {
    if (t != NULL) {
        treeToListRec((*t).left, l);
        if ((*t).key % 2 == 0) append(l, (*t).key);
        treeToListRec((*t).right, l);
    }
}

// 1e
list treeToList(tree t) {
    list l = NULL;
    treeToListRec(t, &l);
    return l;
}


int count(int k, tree t) {
    int c = 0;
    if (t != NULL) {
        if ((*t).key == k) c += 1;
        c += count(k, (*t).left);
        c += count(k, (*t).right);
    }
    return c;
}

// 1f
tree baz(tree s, tree t) {
    if (s == NULL) return NULL;
    return createNode(
        count((*s).key, t), 
        baz((*s).left, t), 
        baz((*s).right, t));
}


int main() {
    // 1a
    tree example1 = createNode(4,
        createNode(5, 
            NULL, 
            NULL),
        createNode(2, 
            createNode(0, 
                NULL, 
                NULL), 
            NULL));

    tree example2 = createNode(2,
        createNode(4, 
            NULL, 
            NULL),
        createNode(6,
            NULL,
            NULL));
    
    printList(treeToList(example2));
    printf("%d\n", leafprod(example2));

    insertl(&example2, 4);
    insertl2(&example2, 10);
    printList(treeToList(example2));
    printf("%d\n", leafprod(example2));

    defol(&example2);
    printList(treeToList(example2));
    printf("%d\n", leafprod(example2));

    printList(treeToList(baz(example1, example2)));
}
