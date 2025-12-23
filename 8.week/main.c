#include <stdio.h>

void basaEkle(int a[], int *n, int x) {
    int i;
    for (i = *n; i > 0; i--)
        a[i] = a[i - 1];
    a[0] = x;
    (*n)++;
}

void sonaEkle(int a[], int *n, int x) {
    a[*n] = x;
    (*n)++;
}

void arayaEkle(int a[], int *n, int x, int pos) {
    int i;
    for (i = *n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = x;
    (*n)++;
}

void bastanSil(int a[], int *n) {
    int i;
    for (i = 0; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void sondanSil(int *n) {
    (*n)--;
}

void aradanSil(int a[], int *n, int pos) {
    int i;
    for (i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
}

int main() {
    int a[100] = {10, 20, 30, 40, 50};
    int n = 5;
    int i;

    basaEkle(a, &n, 5);
    sonaEkle(a, &n, 60);
    arayaEkle(a, &n, 35, 3);
    bastanSil(a, &n);
    sondanSil(&n);
    aradanSil(a, &n, 2);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
