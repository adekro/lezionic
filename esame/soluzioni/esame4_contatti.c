#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Contatto {
    char nome[50];
    char username[50];
    char email[60];
    char tel[20];
};

void normalizza_nome(char *nome);
int valida_email(const char *email);
int valida_telefono(const char *tel);
void genera_username(const char *nome, char *username);

int main(void) {
    FILE *in = fopen("esame/contatti.txt", "r");
    if (in == NULL) {
        perror("esame/contatti.txt");
        return 1;
    }
    FILE *out = fopen("contatti_ok.txt", "w");
    if (out == NULL) {
        perror("contatti_ok.txt");
        fclose(in);
        return 1;
    }

    char riga[200];
    int validi = 0, scartati = 0;

    while (fgets(riga, sizeof(riga), in) != NULL) {
        riga[strcspn(riga, "\n")] = '\0';
        if (riga[0] == '\0') continue;           // riga vuota

        /* strtok: la prima chiamata riceve la stringa, le successive NULL */
        char *t_nome = strtok(riga, ";");
        char *t_email = strtok(NULL, ";");
        char *t_tel = strtok(NULL, ";");

        if (t_nome == NULL || t_email == NULL || t_tel == NULL) {
            printf("Scartato: \"%s\" - formato errato\n", riga);
            scartati++;
            continue;
        }

        struct Contatto c;
        snprintf(c.nome, sizeof(c.nome), "%s", t_nome);
        snprintf(c.email, sizeof(c.email), "%s", t_email);
        snprintf(c.tel, sizeof(c.tel), "%s", t_tel);
        normalizza_nome(c.nome);

        if (!valida_email(c.email)) {
            printf("Scartato: %s - email non valida (%s)\n", c.nome, c.email);
            scartati++;
        } else if (!valida_telefono(c.tel)) {
            printf("Scartato: %s - telefono non valido (%s)\n", c.nome, c.tel);
            scartati++;
        } else {
            genera_username(c.nome, c.username);
            fprintf(out, "%s;%s;%s;%s\n", c.nome, c.username, c.email, c.tel);
            validi++;
        }
    }

    fclose(in);
    fclose(out);
    printf("Validi: %d, scartati: %d\n", validi, scartati);
    return 0;
}

void normalizza_nome(char *nome) {
    int inizio_parola = 1;
    for (int i = 0; nome[i] != '\0'; i++) {
        if (isspace((unsigned char)nome[i])) {
            inizio_parola = 1;
        } else {
            nome[i] = (char)(inizio_parola ? toupper((unsigned char)nome[i])
                                           : tolower((unsigned char)nome[i]));
            inizio_parola = 0;
        }
    }
}

int valida_email(const char *email) {
    int chiocciole = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') chiocciole++;
    }
    if (chiocciole != 1) return 0;

    const char *at = strchr(email, '@');
    if (at == email) return 0;                    // '@' all'inizio

    const char *punto = strchr(at, '.');          // primo '.' dopo la '@'
    if (punto == NULL) return 0;
    if (punto == at + 1) return 0;                // subito dopo la '@'
    if (punto[1] == '\0') return 0;               // ultimo carattere
    return 1;
}

int valida_telefono(const char *tel) {
    if (strlen(tel) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (!isdigit((unsigned char)tel[i])) return 0;
    }
    return 1;
}

void genera_username(const char *nome, char *username) {
    /* cognome = ultima parola; se non ci sono spazi e' l'intero nome */
    const char *spazio = strrchr(nome, ' ');
    const char *cognome = (spazio != NULL) ? spazio + 1 : nome;

    int k = 0;
    username[k++] = (char)tolower((unsigned char)nome[0]);
    for (int i = 0; cognome[i] != '\0'; i++) {
        username[k++] = (char)tolower((unsigned char)cognome[i]);
    }
    username[k] = '\0';
}
