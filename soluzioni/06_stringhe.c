#include <stdio.h>
#include <string.h>

int main(void) {
    char parola[50];
    char altra[50];

    printf("Inserisci una parola: ");
    scanf("%49s", parola);

    /* A) lunghezza a mano */
    int len = 0;
    while (parola[len] != '\0') {
        len++;
    }
    printf("Lunghezza (a mano): %d, strlen: %zu\n", len, strlen(parola));

    /* B) vocali */
    int vocali = 0;
    for (int i = 0; i < len; i++) {
        char c = parola[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vocali++;
        }
    }
    printf("Vocali: %d\n", vocali);

    /* C) al contrario */
    printf("Al contrario: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", parola[i]);
    }
    printf("\n");

    /* D) palindroma: confronto primo con ultimo, secondo col penultimo... */
    int palindroma = 1;
    for (int i = 0; i < len / 2; i++) {
        if (parola[i] != parola[len - 1 - i]) {
            palindroma = 0;
            break;
        }
    }
    printf("%s palindroma\n", palindroma ? "E'" : "NON e'");

    /* E) confronto con una seconda parola */
    printf("Inserisci un'altra parola: ");
    scanf("%49s", altra);
    if (strcmp(parola, altra) == 0) {
        printf("Uguali\n");
    } else {
        printf("Diverse\n");
    }

    return 0;
}
