# Esercizi in stile esame

Quattro esercizi che combinano più argomenti (il 4 è il più "da stringhe"). Gli studenti partono dai file in `esame/` (traccia + scheletro);
le soluzioni sono in `esame/soluzioni/`. I file dati di esempio sono in `esame/`.

| Esame | Tema | Riprende gli esercizi |
|-------|------|----------------------|
| 1 | Registro studenti da file | 05 array, 07 funzioni, 09 struct, 10 file |
| 2 | Analisi di un testo | 04 cicli, 06 stringhe, 07 funzioni, 10 file |
| 3 | Statistiche e ordinamento | 05 array, 07 funzioni, 08 puntatori, 10 file |
| 4 | Pulizia di una rubrica (stringhe: `strtok`, validazione, normalizzazione) | 06/11 stringhe, 07 funzioni, 09 struct, 10 file |

Compila e lancia **dalla cartella `lezionic`** (i percorsi dei file dati sono relativi a lì):

```powershell
gcc -Wall -Wextra -std=c11 esame\soluzioni\esame1_registro.c -o esame1.exe
.\esame1.exe
```

Idea di valutazione (30 punti ciascuno): compila senza warning (5), lettura/scrittura file corretta con controllo di
`fopen` (8), funzioni richieste con i prototipi dati (9), correttezza dei risultati (8).
