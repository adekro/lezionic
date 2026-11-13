#include <stdio.h>

int main(void) {
    int n;

    /* Parte A */
    printf("Parte A - inserisci un intero: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("positivo\n");
    } else if (n < 0) {
        printf("negativo\n");
    } else {
        printf("zero\n");
    }

    if (n % 2 == 0) {
        printf("pari\n");
    } else {
        printf("dispari\n");
    }

    /* Parte B */
    int a, b, c;
    printf("Parte B - inserisci tre interi: ");
    scanf("%d %d %d", &a, &b, &c);

    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    printf("Il maggiore e' %d\n", max);

    /* Parte C */
    printf("Parte C - inserisci a e b: ");
    scanf("%d %d", &a, &b);

    if (b == 0) {
        printf("Divisione impossibile\n");
    } else {
        printf("%d / %d = %.3f\n", a, b, (double)a / b);
    }

    return 0;
}
