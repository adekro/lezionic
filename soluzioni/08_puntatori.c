#include <stdio.h>

void scambia(int *a, int *b);
void scambia_sbagliata(int a, int b);
void min_max(int v[], int n, int *min, int *max);
void raddoppia(int v[], int n);

int main(void) {
    /* A) basi */
    int x = 5;
    int *p = &x;
    printf("x = %d, &x = %p, p = %p, *p = %d\n", x, (void *)&x, (void *)p, *p);
    *p = 99;
    printf("dopo *p = 99, x = %d  (p punta a x, quindi scrivere in *p modifica x)\n", x);

    /* B) scambio */
    int a = 1, b = 2;
    scambia_sbagliata(a, b);
    printf("dopo scambia_sbagliata: a=%d b=%d (invariati: lavora su copie)\n", a, b);
    scambia(&a, &b);
    printf("dopo scambia:           a=%d b=%d\n", a, b);

    /* C) min e max */
    int v[] = {4, -2, 9, 0, 7};
    int n = sizeof(v) / sizeof(v[0]);
    int min, max;
    min_max(v, n, &min, &max);
    printf("min = %d, max = %d\n", min, max);

    /* D) raddoppia */
    raddoppia(v, n);
    printf("raddoppiato: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n(l'array e' passato come puntatore al primo elemento: la funzione scrive nell'originale)\n");

    return 0;
}

void scambia(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void scambia_sbagliata(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void min_max(int v[], int n, int *min, int *max) {
    *min = v[0];
    *max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < *min) *min = v[i];
        if (v[i] > *max) *max = v[i];
    }
}

void raddoppia(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] *= 2;
    }
}
