#include <stdio.h>

#define MAX 50

void scambia(int *a, int *b);
void min_max(const int v[], int n, int *min, int *max);
double media(const int v[], int n);
int e_primo(int x);
int conta_primi(const int v[], int n);
void ordina(int v[], int n);

int main(void) {
    int v[MAX];
    int n;

    do {
        printf("Quanti numeri (1-%d)? ", MAX);
        if (scanf("%d", &n) != 1) {
            printf("Input non valido\n");
            return 1;
        }
    } while (n < 1 || n > MAX);

    printf("Inserisci %d interi: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int min, max;
    min_max(v, n, &min, &max);
    double m = media(v, n);
    int primi = conta_primi(v, n);
    ordina(v, n);

    printf("Ordinato:");
    for (int i = 0; i < n; i++) printf(" %d", v[i]);
    printf("\n");
    printf("Min = %d, Max = %d, Media = %.2f, Primi = %d\n", min, max, m, primi);

    FILE *f = fopen("risultati.txt", "w");
    if (f == NULL) {
        perror("risultati.txt");
        return 1;
    }
    fprintf(f, "Ordinato:");
    for (int i = 0; i < n; i++) fprintf(f, " %d", v[i]);
    fprintf(f, "\nMin: %d\nMax: %d\nMedia: %.2f\nPrimi: %d\n", min, max, m, primi);
    fclose(f);
    printf("Risultati scritti su risultati.txt\n");

    return 0;
}

void scambia(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void min_max(const int v[], int n, int *min, int *max) {
    *min = v[0];
    *max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < *min) *min = v[i];
        if (v[i] > *max) *max = v[i];
    }
}

double media(const int v[], int n) {
    int somma = 0;
    for (int i = 0; i < n; i++) somma += v[i];
    return (double)somma / n;
}

int e_primo(int x) {
    if (x < 2) return 0;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) return 0;
    }
    return 1;
}

int conta_primi(const int v[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (e_primo(v[i])) count++;
    }
    return count;
}

void ordina(int v[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        for (int i = 0; i < n - 1 - pass; i++) {
            if (v[i] > v[i + 1]) {
                scambia(&v[i], &v[i + 1]);
            }
        }
    }
}
