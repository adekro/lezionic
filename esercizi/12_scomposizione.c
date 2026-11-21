/* ESERCIZIO 12 - Scomporre un problema in sottoproblemi
 *
 * METODO (da applicare SEMPRE, prima di scrivere codice):
 *   1. CAPIRE    : cosa entra? cosa deve uscire? fai un esempio a mano.
 *   2. DIVIDERE  : scrivi a parole i passi ("prima..., poi..., infine...").
 *   3. NOMINARE  : ogni passo diventa una funzione con un nome-verbo,
 *                  input (parametri) e output (return) chiari.
 *   4. RISOLVERE : implementa e TESTA una funzione alla volta (con main di prova).
 *   5. RICOMPORRE: il main deve leggersi come la lista dei passi del punto 2.
 *
 * Regola d'oro: una funzione fa UNA cosa. Se per descriverla ti serve
 * una "e" ("legge E calcola E stampa") spezzala.
 *
 * Gli esercizi sono in ordine di autonomia crescente:
 *   PARTE 1: ti do io le funzioni, tu le implementi.
 *   PARTE 2: ti do io solo i passi, tu scrivi i prototipi.
 *   PARTE 3: scomponi tu da zero.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* ------------------------------------------------------------------
 * PARTE 1 - Statistiche sui voti  (scomposizione GUIDATA)
 *
 * Problema: leggi n voti (max 30, tra 0 e 30) e stampa media, voto
 * massimo e quanti sono sufficienti (>= 18).
 *
 * Scomposizione gia' fatta per te:
 *   leggi_voti    -> riempie l'array, restituisce quanti ne ha letti
 *   media         -> media dei valori
 *   massimo       -> valore piu' alto
 *   conta_sufficienti -> quanti voti >= 18
 * Il main sara' solo: leggi, poi 3 chiamate, poi printf.
 * ------------------------------------------------------------------ */
int    leggi_voti(int v[], int max);
double media(const int v[], int n);
int    massimo(const int v[], int n);
int    conta_sufficienti(const int v[], int n);

/* ------------------------------------------------------------------
 * PARTE 2 - Numeri primi  (scomposizione SEMI-GUIDATA)
 *
 * Problema: leggi un intero n e stampa tutti i numeri primi da 2 a n,
 * 10 per riga, poi scrivi quanti sono.
 *
 * Passi (i prototipi li scrivi tu):
 *   a) dire se UN numero e' primo            (serve un'unica risposta si/no)
 *   b) per ogni numero da 2 a n, se e' primo  stamparlo e contarlo
 *   c) andare a capo ogni 10 numeri stampati
 *
 * Domande-guida:
 *   - Il passo (a) ha bisogno di sapere di n? Di cosa ha bisogno davvero?
 *   - Chi decide se andare a capo: la funzione del passo (a) o il ciclo?
 *   - Puoi testare (a) da solo con 1, 2, 9, 13, 49?
 * ------------------------------------------------------------------ */
// TODO: prototipi

/* ------------------------------------------------------------------
 * PARTE 3 - Frase palindroma  (scomposizione AUTONOMA)
 *
 * Problema: leggi una frase (fgets) e di' se e' palindroma ignorando
 * spazi, punteggiatura e maiuscole/minuscole.
 *   "Etna, anta" -> si'     "I topi non avevano nipoti" -> si'
 *   "Ciao mondo" -> no
 *
 * Non ti do nessun suggerimento sulle funzioni. Prima di scrivere
 * codice rispondi (in un commento qui sotto):
 *   1. Quali passi servono per trasformare la frase in qualcosa di
 *      facile da confrontare?
 *   2. Quale funzione che hai gia' scritto (es. 11) puoi riusare?
 *   3. Cosa significa "palindroma" quando la stringa e' gia' pulita?
 *   4. Che input/output ha ogni funzione?
 *
 * Poi implementa e testa ogni funzione separatamente.
 * ------------------------------------------------------------------ */
// TODO: il tuo piano a parole


/* ------------------------------------------------------------------
 * BONUS - Allenamento "solo a parole" (non serve codice)
 * Per ognuno scrivi la lista dei sottoproblemi con firma delle funzioni:
 *   a) Dato un numero, stampare le sue cifre in ordine inverso e dire
 *      se la somma delle cifre e' pari.
 *   b) Un registro di studenti (struct) da file: stampare il migliore
 *      e la media della classe.
 *   c) Una tabellina n x m formattata con intestazioni.
 * ------------------------------------------------------------------ */

int main(void) {
    // TODO: PARTE 1 (il main = lista dei passi)
    // TODO: PARTE 2
    // TODO: PARTE 3
    return 0;
}

// TODO: definizioni
