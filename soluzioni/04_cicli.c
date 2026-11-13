#include <stdio.h>

int main(void) {
    int n;

    printf("Inserisci n (positivo): ");
    scanf("%d", &n);

    /* A) tabellina */
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    /* B) somma 1..n */
    int somma = 0;
    for (int i = 1; i <= n; i++) {
        somma += i;
    }
    printf("Somma 1..%d = %d\n", n, somma);

    /* C) fattoriale: con int sfora gia' a 13!, con long long a 21! */
    long long fatt = 1;
    for (int i = 2; i <= n; i++) {
        fatt *= i;
    }
    printf("%d! = %lld\n", n, fatt);

    /* D) triangolo */
    for (int riga = 1; riga <= n; riga++) {
        for (int k = 0; k < riga; k++) {
            printf("*");
        }
        printf("\n");
    }

    /* E) somma finche' non arriva 0 */
    int x, tot = 0;
    printf("Inserisci numeri (0 per finire): ");
    scanf("%d", &x);
    while (x != 0) {
        tot += x;
        scanf("%d", &x);
    }
    printf("Totale = %d\n", tot);

    return 0;
}
