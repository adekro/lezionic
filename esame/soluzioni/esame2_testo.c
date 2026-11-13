#include <stdio.h>
#include <string.h>

int lunghezza(const char *s);
int conta_vocali(const char *s);
int e_palindroma(const char *s);
int conta_iniziale(const char *percorso, char lettera);

int main(void) {
    FILE *f = fopen("esame/testo.txt", "r");
    if (f == NULL) {
        perror("esame/testo.txt");
        return 1;
    }

    char parola[50];
    char piu_lunga[50] = "";
    char palindrome[50][50];   // fino a 50 parole palindrome
    int n_pal = 0;
    int parole = 0, vocali = 0;

    while (fscanf(f, "%49s", parola) == 1) {
        parole++;
        vocali += conta_vocali(parola);

        if (lunghezza(parola) > lunghezza(piu_lunga)) {
            strcpy(piu_lunga, parola);
        }
        if (lunghezza(parola) >= 2 && e_palindroma(parola) && n_pal < 50) {
            strcpy(palindrome[n_pal], parola);
            n_pal++;
        }
    }
    fclose(f);

    /* Stesso report su due destinazioni: stdout e file */
    FILE *out = fopen("report.txt", "w");
    if (out == NULL) {
        perror("report.txt");
        return 1;
    }
    FILE *dest[2] = {stdout, out};
    for (int d = 0; d < 2; d++) {
        fprintf(dest[d], "Parole: %d\n", parole);
        fprintf(dest[d], "Vocali: %d\n", vocali);
        fprintf(dest[d], "Parola piu' lunga: %s (%d lettere)\n", piu_lunga, lunghezza(piu_lunga));
        fprintf(dest[d], "Palindrome (%d):", n_pal);
        for (int i = 0; i < n_pal; i++) {
            fprintf(dest[d], " %s", palindrome[i]);
        }
        fprintf(dest[d], "\n");
    }
    fclose(out);

    /* Extra */
    char c;
    printf("Lettera iniziale da cercare: ");
    scanf(" %c", &c);
    printf("Parole che iniziano per '%c': %d\n", c, conta_iniziale("esame/testo.txt", c));

    return 0;
}

int lunghezza(const char *s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

int conta_vocali(const char *s) {
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') n++;
    }
    return n;
}

int e_palindroma(const char *s) {
    int len = lunghezza(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) return 0;
    }
    return 1;
}

int conta_iniziale(const char *percorso, char lettera) {
    FILE *f = fopen(percorso, "r");
    if (f == NULL) return 0;

    char parola[50];
    int n = 0;
    while (fscanf(f, "%49s", parola) == 1) {
        if (parola[0] == lettera) n++;
    }
    fclose(f);
    return n;
}
