/* SOLUZIONE 12 - Scomporre un problema in sottoproblemi
 *
 * Nota per chi insegna: far notare che i main sono corti e si leggono
 * come la lista dei passi. Ogni funzione e' testabile da sola.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* ---------------- PARTE 1 ---------------- */
int    leggi_voti(int v[], int max);
double media(const int v[], int n);
int    massimo(const int v[], int n);
int    conta_sufficienti(const int v[], int n);

/* ---------------- PARTE 2 ----------------
 * Scomposizione:
 *   e_primo(x)           -> 1/0, dipende SOLO da x (non da n!)
 *   stampa_primi(n)      -> ciclo 2..n, usa e_primo, conta e va a capo
 * L'"a capo ogni 10" sta nel ciclo, non in e_primo: e_primo non stampa nulla.
 */
int e_primo(int x);
int stampa_primi(int n);

/* ---------------- PARTE 3 ----------------
 * Piano:
 *   1. rimuovi_newline   : fgets lascia '\n'
 *   2. normalizza        : copia in un buffer solo le lettere, in minuscolo
 *   3. e_palindroma      : confronta primo/ultimo, secondo/penultimo...
 *   4. main: leggi -> pulisci -> normalizza -> e_palindroma -> stampa
 * e_palindroma lavora su una stringa GIA' pulita: non sa nulla di spazi.
 */
void rimuovi_newline(char *s);
void normalizza(const char *src, char *dst);
int  e_palindroma(const char *s);

int main(void) {
    /* PARTE 1 */
    int voti[30];
    int n = leggi_voti(voti, 30);
    if (n > 0) {
        printf("Media: %.2f\n", media(voti, n));
        printf("Massimo: %d\n", massimo(voti, n));
        printf("Sufficienti: %d\n", conta_sufficienti(voti, n));
    }

    /* PARTE 2 */
    int limite;
    printf("Stampa i primi fino a: ");
    scanf("%d", &limite);
    int tot = stampa_primi(limite);
    printf("Totale: %d\n", tot);

    /* PARTE 3 */
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} /* svuota il '\n' lasciato da scanf */
    char frase[200], pulita[200];
    printf("Frase: ");
    fgets(frase, sizeof frase, stdin);
    rimuovi_newline(frase);
    normalizza(frase, pulita);
    printf(e_palindroma(pulita) ? "Palindroma\n" : "Non palindroma\n");

    return 0;
}

/* ---- Parte 1 ---- */
int leggi_voti(int v[], int max) {
    int n;
    printf("Quanti voti (max %d)? ", max);
    if (scanf("%d", &n) != 1 || n < 1) return 0;
    if (n > max) n = max;
    for (int i = 0; i < n; i++) {
        do {
            printf("Voto %d (0-30): ", i + 1);
            if (scanf("%d", &v[i]) != 1) return i;
        } while (v[i] < 0 || v[i] > 30);
    }
    return n;
}

double media(const int v[], int n) {
    int somma = 0;
    for (int i = 0; i < n; i++) somma += v[i];
    return (double)somma / n;   /* cast: altrimenti divisione intera */
}

int massimo(const int v[], int n) {
    int m = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > m) m = v[i];
    return m;
}

int conta_sufficienti(const int v[], int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (v[i] >= 18) c++;
    return c;
}

/* ---- Parte 2 ---- */
int e_primo(int x) {
    if (x < 2) return 0;
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0) return 0;
    return 1;
}

int stampa_primi(int n) {
    int stampati = 0;
    for (int x = 2; x <= n; x++) {
        if (e_primo(x)) {
            printf("%5d", x);
            stampati++;
            if (stampati % 10 == 0) printf("\n");
        }
    }
    if (stampati % 10 != 0) printf("\n");
    return stampati;
}

/* ---- Parte 3 ---- */
void rimuovi_newline(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

void normalizza(const char *src, char *dst) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (isalpha((unsigned char)src[i]))
            dst[j++] = (char)tolower((unsigned char)src[i]);
    }
    dst[j] = '\0';
}

int e_palindroma(const char *s) {
    int i = 0, j = (int)strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
