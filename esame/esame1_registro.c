/* ESAME 1 - Registro studenti
 *
 * Il file "esame/studenti.txt" contiene un studente per riga: nome matricola media
 * (es. "Anna 1001 27.5"). Al massimo MAX studenti.
 *
 * Scrivi un programma che, usando una struct Studente e le funzioni sotto:
 *  1. carica gli studenti dal file in un array (restituisce quanti ne ha letti,
 *     oppure -1 se il file non si apre)
 *  2. stampa l'elenco
 *  3. stampa la media della classe e lo studente con la media piu' alta
 *  4. scrive su "promossi.txt" gli studenti con media >= 18, uno per riga,
 *     nello stesso formato del file di ingresso; stampa quanti sono stati scritti
 *
 * Prototipi obbligatori:
 *   int    carica(const char *percorso, struct Studente v[], int max);
 *   void   stampa_studente(const struct Studente *s);
 *   double media_classe(const struct Studente v[], int n);
 *   int    indice_migliore(const struct Studente v[], int n);
 *   int    salva_promossi(const char *percorso, const struct Studente v[], int n);
 *
 * Extra: aggiungi una funzione che ordina l'array per media decrescente.
 */
#include <stdio.h>

#define MAX 100

struct Studente {
    // TODO
};

// TODO: prototipi

int main(void) {
    // TODO
    return 0;
}

// TODO: definizioni
