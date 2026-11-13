#include <stdio.h>

#define N 5

int main(void) {
    int v[N];

    printf("Inserisci %d interi: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    /* A) stampa */
    printf("Array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    /* B) somma e media */
    int somma = 0;
    for (int i = 0; i < N; i++) {
        somma += v[i];
    }
    printf("Somma = %d, media = %.2f\n", somma, (double)somma / N);

    /* C) massimo e posizione */
    int max = v[0], pos = 0;
    for (int i = 1; i < N; i++) {
        if (v[i] > max) {
            max = v[i];
            pos = i;
        }
    }
    printf("Massimo = %d in posizione %d\n", max, pos);

    /* D) al contrario */
    printf("Al contrario: ");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", v[i]);
    }
    printf("\n");

    /* E) pari */
    int pari = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] % 2 == 0) pari++;
    }
    printf("Elementi pari: %d\n", pari);

    return 0;
}
