#include <stdio.h>

int main(void) {
    int a, b;

    printf("Inserisci a e b: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Input non valido\n");
        return 1;
    }

    printf("Somma:       %d\n", a + b);
    printf("Differenza:  %d\n", a - b);
    printf("Prodotto:    %d\n", a * b);

    // ATTENZIONE: con b = 0 il programma va in crash (divisione per zero).
    // Si risolve nell'esercizio 03.
    printf("Div. intera: %d\n", a / b);
    printf("Resto:       %d\n", a % b);

    // Basta che un operando sia double perche' la divisione abbia i decimali.
    printf("Div. reale:  %.2f\n", (double)a / b);

    return 0;
}
