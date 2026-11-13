#include <stdio.h>

#define NUM 3

struct Studente {
    char nome[30];
    int matricola;
    double media;
};

void stampa_studente(const struct Studente *s);

int main(void) {
    struct Studente classe[NUM];

    /* A) lettura */
    for (int i = 0; i < NUM; i++) {
        printf("Studente %d - nome matricola media: ", i + 1);
        scanf("%29s %d %lf", classe[i].nome, &classe[i].matricola, &classe[i].media);
    }

    /* C) stampa tutti */
    printf("\nElenco:\n");
    for (int i = 0; i < NUM; i++) {
        stampa_studente(&classe[i]);
    }

    /* D) media piu' alta */
    int best = 0;
    for (int i = 1; i < NUM; i++) {
        if (classe[i].media > classe[best].media) best = i;
    }
    printf("\nMigliore: ");
    stampa_studente(&classe[best]);

    /* E) media delle medie */
    double tot = 0;
    for (int i = 0; i < NUM; i++) tot += classe[i].media;
    printf("Media delle medie: %.2f\n", tot / NUM);

    return 0;
}

/* B) con puntatore a struct si usa -> al posto del punto */
void stampa_studente(const struct Studente *s) {
    printf("%s (matr. %d) - media %.2f\n", s->nome, s->matricola, s->media);
}
