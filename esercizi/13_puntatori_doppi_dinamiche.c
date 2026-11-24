/* ESERCIZIO 13 - Puntatori doppi e strutture dinamiche
 *
 * PARTE 1 - Array dinamico
 *  A) Leggi n da tastiera, alloca con malloc un array di n interi
 *     (controlla che malloc non restituisca NULL), riempilo con i quadrati
 *     1, 4, 9, ... e stampalo.
 *  B) Raddoppia la dimensione con realloc (usa un puntatore temporaneo!),
 *     riempi le nuove posizioni continuando la serie e stampa tutto.
 *  C) free e puntatore a NULL.
 *
 * PARTE 2 - Puntatore doppio come parametro
 *  D) int alloca_array(int **v, int n): alloca n interi e fa puntare *v al
 *     blocco. Restituisce 1 se ok, 0 se malloc fallisce (e *v resta NULL).
 *     Nel main: int *a = NULL; alloca_array(&a, 5); ...
 *     Domanda: perche' con "int *v" come parametro NON funzionerebbe?
 *  E) void dimezza(int **v, int *n): toglie la seconda meta' dell'array con
 *     realloc, aggiornando sia *v sia *n.
 *
 * PARTE 3 - Matrice dinamica
 *  F) int **crea_matrice(int righe, int colonne): alloca un array di
 *     'righe' puntatori e per ognuno un array di 'colonne' interi, tutti a 0.
 *  G) void stampa_matrice(int **m, int righe, int colonne)
 *  H) void libera_matrice(int **m, int righe): libera PRIMA le righe,
 *     POI il vettore di puntatori.
 *  Prova: matrice 3x4 con m[i][j] = i * j.
 *
 * PARTE 4 - Lista concatenata
 *  struct Nodo { int dato; struct Nodo *next; };
 *  I) void inserisci_testa(struct Nodo **testa, int dato)
 *  J) void inserisci_coda(struct Nodo **testa, int dato)
 *     (suggerimento: scorri finche' (*testa) != NULL usando un Nodo **)
 *  K) void stampa_lista(const struct Nodo *testa)   ->  3 -> 7 -> 9 -> NULL
 *  L) int cerca(const struct Nodo *testa, int dato) ->  1 se presente
 *  M) int rimuovi(struct Nodo **testa, int dato)    ->  toglie la prima
 *     occorrenza (free del nodo!), 1 se rimosso
 *  N) void libera_lista(struct Nodo **testa)  (salva next PRIMA del free)
 *
 *  Nel main: inserisci 3 numeri in testa e 2 in coda, stampa, cerca, rimuovi
 *  uno in mezzo, stampa, libera.
 *
 * PARTE 5 - Sfida (scomponi tu, vedi esercizio 12)
 *  O) Leggi da tastiera parole fino a "fine" (senza sapere quante sono) e
 *     salvale in un char **parole che cresce con realloc; ogni parola e' una
 *     copia allocata (malloc + strcpy). Poi stampale in ordine inverso e
 *     libera tutto.
 *
 * Controllo errori: compila con  gcc -g -fsanitize=address -Wall -Wextra
 * (se disponibile) per scoprire leak e accessi fuori dai limiti.
 */
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
    // TODO

    return 0;
}

// TODO: definizioni
