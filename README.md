# Corso base di C

Cartella con esercizi per un universitario alle prime armi con il C.

```
lezionic/
├── README.md        <- questo file (setup e come compilare)
├── teoria.md        <- spiegazione degli argomenti, uno per esercizio
├── esercizi/        <- tracce con lo scheletro da completare (per lo studente)
└── soluzioni/       <- soluzioni commentate (per te)
```

## Ordine consigliato

| # | Argomento | Concetti |
|---|-----------|----------|
| 01 | Ciao mondo | `#include`, `main`, `printf` |
| 02 | Variabili e input | tipi, `scanf`, operatori, divisione intera |
| 03 | Condizioni | `if/else`, operatori logici |
| 04 | Cicli | `for`, `while` |
| 05 | Array | indici, scorrimento, massimo, inversione |
| 06 | Stringhe | `char[]`, `'\0'`, `<string.h>` |
| 07 | Funzioni | prototipi, parametri, valore di ritorno |
| 08 | Puntatori | `&`, `*`, passaggio per riferimento |
| 09 | Struct | tipi composti, array di struct |
| 10 | File | `fopen`, `fprintf`, `fscanf`, `fgets`, `fclose` |
| 11 | Manipolazione stringhe | `fgets`, `strcpy/strcat/strstr/strtok`, `ctype.h`, `atoi`, `snprintf` |
| 12 | Scomposizione in sottoproblemi | metodo capire/dividere/nominare/testare/ricomporre, funzioni piccole |
| 13 | Puntatori doppi e strutture dinamiche | `malloc/realloc/free`, `int **`, matrici dinamiche, liste concatenate |

In più, la cartella `esame/` contiene 4 esercizi in stile esame che combinano gli argomenti (vedi `esame/README.md`).

## 1. Installare il compilatore (Windows)

Su questo PC **non c'è nessun compilatore C** (gcc/clang/cl non trovati). Il modo più semplice:

```powershell
winget install --id BrechtSanders.WinLibs.POSIX.UCRT -e
```

Chiudi e riapri il terminale (o VS Code), poi verifica:

```powershell
gcc --version
```

Alternative: MSYS2 (`winget install MSYS2.MSYS2`, poi `pacman -S mingw-w64-ucrt-x86_64-gcc`) oppure
WSL (`wsl --install`, poi `sudo apt install gcc`).

## 2. Compilare ed eseguire

Dalla cartella `lezionic`:

```powershell
gcc -Wall -Wextra -std=c11 esercizi\01_ciao.c -o 01_ciao.exe
.\01_ciao.exe
```

- `-Wall -Wextra` attiva gli avvisi: **fate leggere gli avvisi allo studente**, insegnano molto.
- `-std=c11` fissa lo standard.
- `-o nome.exe` è il file eseguibile prodotto.
- Per esercizi con `math.h` (non ne usiamo) servirebbe `-lm`.

Per debug: `gcc -g -Wall -Wextra -std=c11 ...` e poi `gdb`.

### Compilare tutte le soluzioni in un colpo (per verificarle)

```powershell
New-Item -ItemType Directory -Force build | Out-Null
Get-ChildItem soluzioni\*.c | ForEach-Object {
    gcc -Wall -Wextra -std=c11 $_.FullName -o ("build\" + $_.BaseName + ".exe")
}
```

### Note pratiche

- Se l'output di `scanf` / `printf` sembra "in ritardo" in alcuni terminali, è normale buffering: non toccare niente.
- Le soluzioni sono state scritte senza poterle compilare qui (manca il compilatore): lancia il comando
  sopra come primo controllo e dimmi se qualcosa non compila.
