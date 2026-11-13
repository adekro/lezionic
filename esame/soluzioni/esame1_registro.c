#include <stdio.h>

#define MAX 100

struct Studente {
    char nome[30];
    int matricola;
    double media;
};

int carica(const char *percorso, struct Studente v[], int max);
void stampa_studente(const struct Studente *s);
double media_classe(const struct Studente v[], int n);
int indice_migliore(const struct Studente v[], int n);
int salva_promossi(const char *percorso, const struct Studente v[], int n);
void ordina_per_media(struct Studente v[], int n);

int main(void) {
    struct Studente classe[MAX];

    int n = carica("esame/studenti.txt", classe, MAX);
    if (n < 0) {
        printf("Impossibile aprire esame/studenti.txt (lanci da lezionic?)\n");
        return 1;
    }
    if (n == 0) {
        printf("Nessuno studente nel file\n");
        return 0;
    }

    printf("Studenti letti: %d\n", n);
    for (int i = 0; i < n; i++) {
        stampa_studente(&classe[i]);
    }

    printf("Media della classe: %.2f\n", media_classe(classe, n));
    printf("Migliore: ");
    stampa_studente(&classe[indice_migliore(classe, n)]);

    int promossi = salva_promossi("promossi.txt", classe, n);
    if (promossi < 0) {
        printf("Errore nella scrittura di promossi.txt\n");
        return 1;
    }
    printf("Scritti %d promossi su promossi.txt\n", promossi);

    /* Extra */
    ordina_per_media(classe, n);
    printf("\nClassifica:\n");
    for (int i = 0; i < n; i++) {
        stampa_studente(&classe[i]);
    }

    return 0;
}

int carica(const char *percorso, struct Studente v[], int max) {
    FILE *f = fopen(percorso, "r");
    if (f == NULL) return -1;

    int n = 0;
    while (n < max &&
           fscanf(f, "%29s %d %lf", v[n].nome, &v[n].matricola, &v[n].media) == 3) {
        n++;
    }
    fclose(f);
    return n;
}

void stampa_studente(const struct Studente *s) {
    printf("%-10s matr. %d  media %.2f\n", s->nome, s->matricola, s->media);
}

double media_classe(const struct Studente v[], int n) {
    double tot = 0;
    for (int i = 0; i < n; i++) tot += v[i].media;
    return tot / n;
}

int indice_migliore(const struct Studente v[], int n) {
    int best = 0;
    for (int i = 1; i < n; i++) {
        if (v[i].media > v[best].media) best = i;
    }
    return best;
}

int salva_promossi(const char *percorso, const struct Studente v[], int n) {
    FILE *f = fopen(percorso, "w");
    if (f == NULL) return -1;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].media >= 18) {
            fprintf(f, "%s %d %.1f\n", v[i].nome, v[i].matricola, v[i].media);
            count++;
        }
    }
    fclose(f);
    return count;
}

/* Extra: bubble sort decrescente sulle struct (si scambiano struct intere) */
void ordina_per_media(struct Studente v[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        for (int i = 0; i < n - 1 - pass; i++) {
            if (v[i].media < v[i + 1].media) {
                struct Studente tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;
            }
        }
    }
}
