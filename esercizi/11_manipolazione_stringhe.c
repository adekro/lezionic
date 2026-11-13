/* ESERCIZIO 11 - Manipolazione di stringhe
 *
 * Traccia: leggi una frase CON spazi (usa fgets, non scanf %s) e:
 *  A) togli il '\n' finale che fgets lascia nel buffer: void rimuovi_newline(char *s)
 *     (suggerimento: strcspn)
 *  B) copiala in un secondo array con strcpy e trasformala tutta in maiuscolo:
 *     void maiuscolo(char *s)  (toupper di <ctype.h>)
 *  C) costruisci "Ciao, <frase>" partendo da un array che contiene "Ciao, "
 *     e usando strncat (senza sforare la dimensione dell'array!)
 *  D) inverti una copia della frase "in place", senza array di appoggio:
 *     void inverti(char *s)
 *  E) leggi una seconda stringa e cerca: la prima 'a' con strchr e la
 *     sottostringa con strstr; stampa la POSIZIONE (indice) in cui le trovi,
 *     oppure "non trovata". Suggerimento: posizione = puntatore_trovato - inizio_stringa
 *  F) conta le parole della frase (separate da uno o piu' spazi):
 *     int conta_parole(const char *s)
 *  G) metti la prima lettera di ogni parola maiuscola e le altre minuscole:
 *     void capitalizza(char *s)     ("cIAO mONDO bello" -> "Ciao Mondo Bello")
 *  H) conversioni: da stringa a int con atoi, da int a stringa con snprintf;
 *     confronta due parole con strcmp e di' quale viene prima in ordine alfabetico.
 *
 * Ricorda: ogni stringa deve avere spazio per il '\0' finale.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void rimuovi_newline(char *s);
void maiuscolo(char *s);
void inverti(char *s);
int conta_parole(const char *s);
void capitalizza(char *s);

int main(void) {
    char frase[100];

    // TODO

    return 0;
}

// TODO: definizioni
