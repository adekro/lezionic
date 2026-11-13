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
    char copia[100];
    char altra[100];

    /* A) lettura di una riga intera */
    printf("Scrivi una frase: ");
    if (fgets(frase, sizeof(frase), stdin) == NULL) return 1;
    rimuovi_newline(frase);
    printf("Frase: \"%s\" (%zu caratteri)\n", frase, strlen(frase));

    /* B) copia e maiuscolo */
    strcpy(copia, frase);          // ok: copia ha la stessa dimensione di frase
    maiuscolo(copia);
    printf("Maiuscolo: %s\n", copia);

    /* C) concatenazione sicura */
    char saluto[120] = "Ciao, ";
    strncat(saluto, frase, sizeof(saluto) - strlen(saluto) - 1);
    printf("%s\n", saluto);

    /* D) inversione in place */
    strcpy(copia, frase);
    inverti(copia);
    printf("Invertita: %s\n", copia);

    /* E) ricerche */
    char *p = strchr(frase, 'a');
    if (p != NULL) {
        printf("Prima 'a' in posizione %d\n", (int)(p - frase));
    } else {
        printf("Nessuna 'a'\n");
    }

    printf("Sottostringa da cercare: ");
    if (fgets(altra, sizeof(altra), stdin) == NULL) return 1;
    rimuovi_newline(altra);
    p = strstr(frase, altra);
    if (p != NULL) {
        printf("\"%s\" trovata in posizione %d\n", altra, (int)(p - frase));
    } else {
        printf("\"%s\" non trovata\n", altra);
    }

    /* F) parole */
    printf("Parole: %d\n", conta_parole(frase));

    /* G) capitalizza */
    strcpy(copia, frase);
    capitalizza(copia);
    printf("Capitalizzata: %s\n", copia);

    /* H) conversioni e confronto */
    char numero[] = "1234";
    int n = atoi(numero);
    char buf[20];
    snprintf(buf, sizeof(buf), "%d", n * 2);
    printf("atoi(\"%s\") = %d, doppio come stringa: \"%s\"\n", numero, n, buf);

    char a[] = "mela", b[] = "pera";
    int r = strcmp(a, b);          // <0: a prima di b, 0: uguali, >0: a dopo b
    if (r < 0)      printf("%s viene prima di %s\n", a, b);
    else if (r > 0) printf("%s viene dopo %s\n", a, b);
    else            printf("uguali\n");

    return 0;
}

void rimuovi_newline(char *s) {
    s[strcspn(s, "\n")] = '\0';   // strcspn = posizione del primo '\n' (o del '\0' se non c'e')
}

void maiuscolo(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = (char)toupper((unsigned char)s[i]);
    }
}

void inverti(char *s) {
    int len = (int)strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

int conta_parole(const char *s) {
    int n = 0, dentro = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isspace((unsigned char)s[i])) {
            dentro = 0;
        } else if (!dentro) {
            dentro = 1;
            n++;
        }
    }
    return n;
}

void capitalizza(char *s) {
    int inizio_parola = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isspace((unsigned char)s[i])) {
            inizio_parola = 1;
        } else {
            s[i] = (char)(inizio_parola ? toupper((unsigned char)s[i])
                                        : tolower((unsigned char)s[i]));
            inizio_parola = 0;
        }
    }
}
