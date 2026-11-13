#include <stdio.h>

int massimo(int a, int b);
int potenza(int base, int exp);
int e_primo(int n);
void stampa_primi(int limite);

int main(void) {
    int a, b, limite;

    printf("Inserisci due interi: ");
    scanf("%d %d", &a, &b);
    printf("Massimo: %d\n", massimo(a, b));

    if (b >= 0) {
        printf("%d^%d = %d\n", a, b, potenza(a, b));
    }

    printf("Inserisci un limite: ");
    scanf("%d", &limite);
    printf("Primi fino a %d: ", limite);
    stampa_primi(limite);

    return 0;
}

int massimo(int a, int b) {
    return (a > b) ? a : b;
}

int potenza(int base, int exp) {
    int r = 1;
    for (int i = 0; i < exp; i++) {
        r *= base;
    }
    return r;
}

int e_primo(int n) {
    if (n < 2) return 0;
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) return 0;
    }
    return 1;
}

void stampa_primi(int limite) {
    for (int i = 2; i <= limite; i++) {
        if (e_primo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
