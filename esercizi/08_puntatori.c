/* ESERCIZIO 08 - Puntatori
 *
 * Traccia:
 *  A) Dichiara int x = 5 e int *p = &x. Stampa x, &x, p, *p. Poi fai *p = 99
 *     e stampa x: cosa e' successo? (Per stampare un indirizzo: printf("%p", (void *)p);)
 *  B) Scrivi void scambia(int *a, int *b) che scambia i valori di due variabili.
 *     Prova prima una versione "sbagliata" con parametri passati per valore
 *     (void scambia_sbagliata(int a, int b)) e osserva che nel main non cambia nulla.
 *  C) Scrivi void min_max(int v[], int n, int *min, int *max) che restituisce
 *     minimo e massimo di un array tramite i puntatori (una funzione C non puo'
 *     ritornare due valori con return).
 *  D) Scrivi void raddoppia(int v[], int n) che raddoppia ogni elemento dell'array.
 *     Perche' l'array nel main risulta modificato senza usare &?
 */
#include <stdio.h>

void scambia(int *a, int *b);
void scambia_sbagliata(int a, int b);
void min_max(int v[], int n, int *min, int *max);
void raddoppia(int v[], int n);

int main(void) {
    // TODO

    return 0;
}

// TODO: definizioni delle funzioni
