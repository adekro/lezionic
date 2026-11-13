/* ESAME 4 - Pulizia di una rubrica
 *
 * Il file "esame/contatti.txt" ha un contatto per riga, nel formato
 *     nome cognome;email;telefono
 * (campi separati da ';'; il nome contiene spazi e le maiuscole sono casuali,
 *  es. "mario ROSSI;mario.rossi@email.it;3331234567").
 *
 * Scrivi un programma che legge il file riga per riga (fgets), separa i campi
 * con strtok, e per ogni contatto:
 *  1. normalizza il nome: prima lettera di ogni parola maiuscola, le altre minuscole
 *     ("mario ROSSI" -> "Mario Rossi")
 *  2. valida l'email: esattamente una '@', non all'inizio, e almeno un '.' dopo
 *     la '@' che non sia subito dopo la '@' e non sia l'ultimo carattere
 *  3. valida il telefono: esattamente 10 caratteri, tutti cifre
 *  4. genera lo username: iniziale del nome + cognome, tutto minuscolo
 *     ("Mario Rossi" -> "mrossi"); il cognome e' l'ultima parola del nome
 *
 * I contatti validi vanno su "contatti_ok.txt" nel formato
 *     nome;username;email;telefono
 * Per gli altri stampa a video il nome e il motivo dello scarto.
 * Alla fine stampa quanti contatti sono validi e quanti scartati.
 *
 * Usa una struct Contatto e questi prototipi:
 *   void normalizza_nome(char *nome);
 *   int  valida_email(const char *email);     // 1 valida, 0 no
 *   int  valida_telefono(const char *tel);    // 1 valido, 0 no
 *   void genera_username(const char *nome, char *username);
 *
 * Note: strtok MODIFICA la riga che analizza; sostituisce ogni ';' con '\0'.
 * Ricordati di togliere il '\n' di fgets prima. Se una riga ha meno di 3 campi,
 * scartala come "formato errato".
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Contatto {
    // TODO
};

// TODO: prototipi

int main(void) {
    // TODO
    return 0;
}

// TODO: definizioni
