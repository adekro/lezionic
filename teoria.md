# Teoria essenziale del C

Promemoria rapido, un paragrafo per esercizio.

## 01 – Struttura di un programma

```c
#include <stdio.h>        // include le funzioni di input/output

int main(void) {          // il programma parte da qui
    printf("Ciao\n");     // \n = vai a capo
    return 0;             // 0 = tutto ok
}
```

- Il C è **compilato**: il codice sorgente `.c` diventa un eseguibile; gli errori si vedono in fase di compilazione.
- Ogni istruzione finisce con `;`. Le graffe `{ }` delimitano i blocchi.
- `printf` usa segnaposto: `%d` int, `%f` float/double, `%c` char, `%s` stringa.

## 02 – Variabili e input

| Tipo | Contenuto | printf | scanf |
|------|-----------|--------|-------|
| `int` | intero | `%d` | `%d` |
| `double` | decimale | `%f` | `%lf` (!) |
| `char` | un carattere | `%c` | ` %c` (spazio prima) |

- `scanf("%d", &n);` — serve la **`&`**: scanf deve sapere *dove* scrivere. (Il perché si capisce all'esercizio 08.)
- `scanf` restituisce quanti valori ha letto: controllarlo è buona pratica.
- **Divisione intera**: `7 / 2` vale `3`, non `3.5`. Per avere decimali almeno un operando deve essere `double`: `7 / 2.0`.
- `%` è il resto: `7 % 2` vale `1`.
- Le variabili locali **non sono inizializzate**: contengono spazzatura finché non assegni un valore.

## 03 – Condizioni

```c
if (x > 0) { ... } else if (x < 0) { ... } else { ... }
```

- Confronti: `== != < > <= >=`. Logici: `&&` (e), `||` (o), `!` (non).
- **Errore classico**: `if (x = 5)` assegna invece di confrontare. Il compilatore con `-Wall` avvisa.
- In C non esiste il tipo booleano "storico": `0` è falso, qualunque altro valore è vero. (`<stdbool.h>` aggiunge `bool`.)

## 04 – Cicli

```c
for (int i = 0; i < n; i++) { ... }   // conto noto
while (condizione) { ... }            // finché vale
do { ... } while (condizione);        // almeno una volta
```

- `i++` equivale a `i = i + 1`.
- `break` esce dal ciclo, `continue` salta all'iterazione successiva.
- Attenzione al **ciclo infinito** (condizione che non cambia mai) e agli errori "di uno" (`<` vs `<=`).

## 05 – Array

```c
int v[5];                 // 5 interi: indici da 0 a 4
int w[3] = {10, 20, 30};
```

- Gli indici partono da **0**. L'ultimo elemento di `v[N]` è `v[N-1]`.
- **Il C non controlla i limiti**: scrivere in `v[5]` compila ma è comportamento indefinito (crash o dati corrotti). È la causa di moltissimi bug.
- Un array non conosce la propria lunghezza: bisogna tenerla in una costante o variabile (`#define N 5`).

## 06 – Stringhe

Una stringa è un array di `char` **terminato da `'\0'`**.

```c
char nome[20] = "Luca";    // in memoria: 'L','u','c','a','\0', ...
```

- Serve spazio per il terminatore: "Luca" occupa 5 byte.
- Leggere: `scanf("%19s", nome);` (senza `&` perché un array "decade" in indirizzo; il `19` evita overflow). `%s` si ferma al primo spazio.
- Non si confrontano con `==` né si copiano con `=`. Si usa `<string.h>`: `strlen`, `strcmp` (restituisce 0 se uguali), `strcpy`.
- Differenza: `'a'` è un char, `"a"` è una stringa (2 byte: `'a'`, `'\0'`).

## 07 – Funzioni

```c
int somma(int a, int b);        // prototipo (dichiarazione)

int main(void) { printf("%d", somma(2, 3)); return 0; }

int somma(int a, int b) {       // definizione
    return a + b;
}
```

- Il C passa i parametri **per valore**: la funzione lavora su una *copia*.
- `void` = non restituisce nulla.
- Il compilatore legge dall'alto: una funzione va dichiarata (prototipo) prima di usarla.

## 08 – Puntatori

Un puntatore è una variabile che contiene un **indirizzo di memoria**.

```c
int x = 5;
int *p = &x;     // p contiene l'indirizzo di x
*p = 10;         // scrive 10 in x (dereferenziazione)
```

- `&x` = "indirizzo di x"; `*p` = "il valore a cui punta p".
- Serve per far modificare alla funzione le variabili del chiamante (es. `swap`, e quindi anche `scanf`).
- Un array passato a una funzione è in realtà un puntatore al primo elemento: per questo la funzione può modificarlo e per questo serve passare anche la lunghezza.
- Mai usare un puntatore non inizializzato o `NULL` con `*`.

## 09 – Struct

```c
struct Studente {
    char nome[30];
    int  matricola;
    double media;
};

struct Studente s = {"Anna", 1234, 27.5};
printf("%s\n", s.nome);          // accesso con il punto
```

- Raggruppa dati di tipi diversi in un unico tipo.
- Con un puntatore a struct si usa la freccia: `p->media`.
- Si possono fare array di struct come per qualsiasi tipo.

## 10 – File

```c
FILE *f = fopen("dati.txt", "r");      // apre il file
if (f == NULL) { perror("dati.txt"); return 1; }   // SEMPRE controllare
...
fclose(f);                             // SEMPRE chiudere
```

| Modo | Significato |
|------|-------------|
| `"r"` | lettura (il file deve esistere) |
| `"w"` | scrittura, **cancella** il contenuto se esiste |
| `"a"` | append, scrive in fondo |

- Funzioni gemelle di quelle già viste, con la `f` davanti e il file come primo argomento: `fprintf(f, ...)`, `fscanf(f, ...)`.
- `fgets(buf, dimensione, f)` legge una riga intera (spazi inclusi) e restituisce `NULL` a fine file. Tiene il `'\n'` finale.
- `fscanf` restituisce quanti valori ha letto: `while (fscanf(f, "%d", &x) == 1)` legge fino alla fine.
- **Errore classico**: `while (!feof(f))` produce un'iterazione di troppo; meglio controllare il valore di ritorno della lettura.
- I percorsi relativi partono dalla cartella da cui si **lancia** il programma, non da dove sta il `.c`.
- Il file di testo si può aprire con il Blocco note per verificare cosa è stato scritto.

## 11 – Manipolazione di stringhe

Funzioni di `<string.h>`:

| Funzione | Cosa fa |
|----------|---------|
| `strlen(s)` | lunghezza (senza il `'\0'`) |
| `strcpy(dst, src)` | copia `src` in `dst` (`dst` deve essere abbastanza grande!) |
| `strcat(dst, src)` / `strncat(dst, src, n)` | accoda `src` a `dst`; `strncat` aggiunge al massimo `n` caratteri |
| `strcmp(a, b)` | `0` uguali, `<0` se `a` viene prima di `b`, `>0` dopo |
| `strchr(s, c)` / `strrchr(s, c)` | primo / ultimo carattere `c`, o `NULL` |
| `strstr(s, sub)` | prima occorrenza della sottostringa, o `NULL` |
| `strcspn(s, "\n")` | posizione del primo carattere del secondo argomento |
| `strtok(s, sep)` | spezza in token (la prima volta `s`, poi `NULL`); **modifica** `s` |

Funzioni di `<ctype.h>` (lavorano su un carattere): `toupper`, `tolower`, `isdigit`, `isalpha`, `isspace`. Meglio chiamarle con il cast `(unsigned char)c`.

Da `<stdlib.h>` / `<stdio.h>`: `atoi("123")` converte stringa → int; `snprintf(buf, dimensione, "%d", n)` fa il contrario (e in generale formatta qualunque cosa dentro una stringa).

- `fgets(buf, sizeof(buf), stdin)` legge una riga intera **con gli spazi** (al contrario di `scanf("%s")`), ma lascia il `'\n'`: si toglie con `buf[strcspn(buf, "\n")] = '\0';`.
- Le funzioni che ritornano un puntatore (`strchr`, `strstr`) permettono di ottenere l'**indice**: `p - s`.
- Il rischio principale è il **buffer overflow**: `strcpy`/`strcat` non controllano le dimensioni, quindi scegli sempre i buffer abbastanza grandi o usa le varianti con limite (`strncat`, `snprintf`).
- Con `strcpy(dst, src)`: `dst` deve essere un array, non una stringa letterale (`char *s = "ciao"` non è modificabile).

## 13 – Puntatori doppi e strutture dinamiche

**Memoria dinamica** (`<stdlib.h>`): si chiede memoria a runtime, nello *heap*.

```c
int *v = malloc(n * sizeof *v);        // n interi, NON inizializzati
if (v == NULL) { /* memoria finita */ }
v = realloc(v, 2 * n * sizeof *v);     // ridimensiona (v puo' cambiare indirizzo!)
free(v);                               // SEMPRE liberare, una volta sola
v = NULL;                              // evita usi dopo il free
```

- Ogni `malloc` ha il suo `free`. Memoria non liberata = *memory leak*; `free` due volte o uso dopo il `free` = comportamento indefinito.
- `realloc`: salva il risultato in un puntatore temporaneo, altrimenti se fallisce (`NULL`) perdi il vecchio blocco.

**Puntatore doppio** (`int **pp`): contiene l'indirizzo di *un altro puntatore*.

```c
int x = 5;
int *p = &x;
int **pp = &p;
**pp = 10;        // *pp e' p, **pp e' x
```

Due usi tipici:
1. **Far modificare un puntatore a una funzione**: come `swap` serve `&x` per cambiare un `int`, per cambiare un `int *` serve `int **`.
   ```c
   void alloca(int **v, int n) { *v = malloc(n * sizeof **v); }
   ...
   int *a = NULL;
   alloca(&a, 10);      // ora a punta al nuovo blocco
   ```
2. **Array di puntatori / matrici dinamiche**: `char **righe` e' un array di stringhe, `int **m` una matrice con righe allocate una a una (si libera in ordine inverso: prima ogni riga, poi il vettore di righe).

**Lista concatenata**: ogni nodo contiene il dato e un puntatore al nodo successivo.

```c
struct Nodo {
    int dato;
    struct Nodo *next;     // NULL = fine lista
};
```

- Inserimento in testa: `nuovo->next = testa; testa = nuovo;` ma `testa` cambia, quindi la funzione riceve `struct Nodo **testa`.
- Scorrimento: `for (struct Nodo *p = testa; p != NULL; p = p->next)`.
- Rimozione: serve il nodo *precedente* (o un `Nodo **` che punta al puntatore da riscrivere) e poi `free` del nodo staccato.
- Liberare la lista: salva `next` **prima** del `free` del nodo corrente.
- Vantaggio rispetto all'array: inserire/togliere non sposta gli altri elementi; svantaggio: niente accesso diretto `v[i]`.
