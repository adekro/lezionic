#include <stdio.h>

int main(void) {
    FILE *f;

    /* A) scrittura */
    f = fopen("numeri.txt", "w");
    if (f == NULL) {
        perror("numeri.txt");
        return 1;
    }
    printf("Inserisci 5 interi: ");
    for (int i = 0; i < 5; i++) {
        int x;
        scanf("%d", &x);
        fprintf(f, "%d\n", x);
    }
    fclose(f);   // chiudere garantisce che i dati siano davvero scritti su disco

    /* B) lettura con fscanf */
    f = fopen("numeri.txt", "r");
    if (f == NULL) {
        perror("numeri.txt");
        return 1;
    }
    int x, n = 0, somma = 0;
    while (fscanf(f, "%d", &x) == 1) {   // 1 = ha letto un valore; EOF/0 = fine o errore
        somma += x;
        n++;
    }
    fclose(f);
    if (n > 0) {
        printf("Letti %d numeri, somma = %d, media = %.2f\n", n, somma, (double)somma / n);
    }

    /* C) append */
    f = fopen("numeri.txt", "a");
    if (f == NULL) {
        perror("numeri.txt");
        return 1;
    }
    fprintf(f, "somma: %d\n", somma);
    fclose(f);

    /* D) riga per riga con fgets */
    f = fopen("numeri.txt", "r");
    if (f == NULL) {
        perror("numeri.txt");
        return 1;
    }
    char riga[100];
    int num_riga = 1;
    while (fgets(riga, sizeof(riga), f) != NULL) {
        printf("%d: %s", num_riga, riga);   // fgets mantiene il '\n' finale
        num_riga++;
    }
    fclose(f);

    /* E) file inesistente */
    f = fopen("non_esiste.txt", "r");
    if (f == NULL) {
        perror("non_esiste.txt");
    } else {
        fclose(f);
    }

    return 0;
}
