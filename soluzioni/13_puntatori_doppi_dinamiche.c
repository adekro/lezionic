/* SOLUZIONE 13 - Puntatori doppi e strutture dinamiche */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
    int dato;
    struct Nodo *next;
};

int  alloca_array(int **v, int n);
void dimezza(int **v, int *n);
int **crea_matrice(int righe, int colonne);
void stampa_matrice(int **m, int righe, int colonne);
void libera_matrice(int **m, int righe);
void inserisci_testa(struct Nodo **testa, int dato);
void inserisci_coda(struct Nodo **testa, int dato);
void stampa_lista(const struct Nodo *testa);
int  cerca(const struct Nodo *testa, int dato);
int  rimuovi(struct Nodo **testa, int dato);
void libera_lista(struct Nodo **testa);

int main(void) {
    /* ---- PARTE 1 ---- */
    int n;
    printf("Quanti elementi? ");
    if (scanf("%d", &n) != 1 || n < 1) return 1;

    int *v = malloc(n * sizeof *v);
    if (v == NULL) { perror("malloc"); return 1; }
    for (int i = 0; i < n; i++) v[i] = (i + 1) * (i + 1);
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");

    int *tmp = realloc(v, 2 * n * sizeof *v);   /* tmp: se fallisce v e' ancora valido */
    if (tmp == NULL) { free(v); perror("realloc"); return 1; }
    v = tmp;
    for (int i = n; i < 2 * n; i++) v[i] = (i + 1) * (i + 1);
    for (int i = 0; i < 2 * n; i++) printf("%d ", v[i]);
    printf("\n");
    free(v);
    v = NULL;

    /* ---- PARTE 2 ---- */
    int *a = NULL;
    int na = 6;
    if (!alloca_array(&a, na)) return 1;
    for (int i = 0; i < na; i++) a[i] = i * 10;
    dimezza(&a, &na);
    for (int i = 0; i < na; i++) printf("%d ", a[i]);
    printf("(n=%d)\n", na);
    free(a);
    /* Con "int *v" come parametro la funzione riceverebbe una COPIA del
     * puntatore: assegnare alla copia non cambierebbe 'a' nel main. */

    /* ---- PARTE 3 ---- */
    int **m = crea_matrice(3, 4);
    if (m == NULL) return 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            m[i][j] = i * j;
    stampa_matrice(m, 3, 4);
    libera_matrice(m, 3);

    /* ---- PARTE 4 ---- */
    struct Nodo *lista = NULL;
    inserisci_testa(&lista, 7);
    inserisci_testa(&lista, 3);
    inserisci_testa(&lista, 1);
    inserisci_coda(&lista, 9);
    inserisci_coda(&lista, 11);
    stampa_lista(lista);                       /* 1 -> 3 -> 7 -> 9 -> 11 -> NULL */
    printf("cerca 9: %d, cerca 4: %d\n", cerca(lista, 9), cerca(lista, 4));
    rimuovi(&lista, 7);
    rimuovi(&lista, 1);                        /* caso testa */
    stampa_lista(lista);                       /* 3 -> 9 -> 11 -> NULL */
    libera_lista(&lista);

    /* ---- PARTE 5 (sfida) ---- */
    char **parole = NULL;
    int np = 0, cap = 0;
    char buf[100];
    printf("Parole (\"fine\" per terminare):\n");
    while (scanf("%99s", buf) == 1 && strcmp(buf, "fine") != 0) {
        if (np == cap) {
            cap = (cap == 0) ? 2 : cap * 2;
            char **t = realloc(parole, cap * sizeof *parole);
            if (t == NULL) { perror("realloc"); break; }
            parole = t;
        }
        parole[np] = malloc(strlen(buf) + 1);   /* +1 per il '\0' */
        if (parole[np] == NULL) { perror("malloc"); break; }
        strcpy(parole[np], buf);
        np++;
    }
    for (int i = np - 1; i >= 0; i--) printf("%s\n", parole[i]);
    for (int i = 0; i < np; i++) free(parole[i]);
    free(parole);

    return 0;
}

/* ---- Parte 2 ---- */
int alloca_array(int **v, int n) {
    *v = malloc(n * sizeof **v);
    return *v != NULL;
}

void dimezza(int **v, int *n) {
    int nuovo = *n / 2;
    if (nuovo < 1) nuovo = 1;
    int *t = realloc(*v, nuovo * sizeof **v);
    if (t != NULL) {          /* se fallisce, il blocco grande resta valido */
        *v = t;
        *n = nuovo;
    }
}

/* ---- Parte 3 ---- */
int **crea_matrice(int righe, int colonne) {
    int **m = malloc(righe * sizeof *m);
    if (m == NULL) return NULL;
    for (int i = 0; i < righe; i++) {
        m[i] = calloc(colonne, sizeof **m);    /* calloc = malloc + tutto a 0 */
        if (m[i] == NULL) {                    /* rollback delle righe gia' fatte */
            libera_matrice(m, i);
            return NULL;
        }
    }
    return m;
}

void stampa_matrice(int **m, int righe, int colonne) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) printf("%4d", m[i][j]);
        printf("\n");
    }
}

void libera_matrice(int **m, int righe) {
    for (int i = 0; i < righe; i++) free(m[i]);   /* prima le righe... */
    free(m);                                       /* ...poi il vettore */
}

/* ---- Parte 4 ---- */
static struct Nodo *nuovo_nodo(int dato) {
    struct Nodo *n = malloc(sizeof *n);
    if (n != NULL) {
        n->dato = dato;
        n->next = NULL;
    }
    return n;
}

void inserisci_testa(struct Nodo **testa, int dato) {
    struct Nodo *n = nuovo_nodo(dato);
    if (n == NULL) return;
    n->next = *testa;
    *testa = n;                 /* per questo serve il doppio puntatore */
}

void inserisci_coda(struct Nodo **testa, int dato) {
    struct Nodo *n = nuovo_nodo(dato);
    if (n == NULL) return;
    while (*testa != NULL)          /* testa ora e' "il puntatore da riscrivere" */
        testa = &(*testa)->next;
    *testa = n;                     /* funziona anche a lista vuota */
}

void stampa_lista(const struct Nodo *testa) {
    for (const struct Nodo *p = testa; p != NULL; p = p->next)
        printf("%d -> ", p->dato);
    printf("NULL\n");
}

int cerca(const struct Nodo *testa, int dato) {
    for (const struct Nodo *p = testa; p != NULL; p = p->next)
        if (p->dato == dato) return 1;
    return 0;
}

int rimuovi(struct Nodo **testa, int dato) {
    while (*testa != NULL) {
        if ((*testa)->dato == dato) {
            struct Nodo *da_togliere = *testa;
            *testa = da_togliere->next;        /* "salta" il nodo, testa o centro uguale */
            free(da_togliere);
            return 1;
        }
        testa = &(*testa)->next;
    }
    return 0;
}

void libera_lista(struct Nodo **testa) {
    struct Nodo *p = *testa;
    while (p != NULL) {
        struct Nodo *succ = p->next;   /* salva next PRIMA del free */
        free(p);
        p = succ;
    }
    *testa = NULL;
}
