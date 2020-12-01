void palindrom1(char feld[], int l, int* korrekt) {
    int i = 0;
    l = l − 1;
    *korrekt = 1;
    while (i < l / 2 && (*korrekt)) {
        (*korrekt) = feld[i] == feld[l];
        i = i + 1;
        l = l - 1;
    }
}
