//
// Created by 4miki on 06/03/2024.
//

#include "Funct.h"

///inizio subroutines lezione 1

/**
 * @brief Genera un array di interi random
 * @param array array da generare
 * @param dimensione dimensione dell'array
 * @return array generato
 */
int *generaArray(int *array, int dimensione, Schema schema) {
    array = (int *) malloc(dimensione * sizeof(int));
    if (array == NULL) {
        printf("Errore nell'allocazione della memoria");
        exit(1);
    }
    switch (schema) {
        case ORDINATO:
            for (int i = 0; i < dimensione; ++i) {
                array[i] = i;
            }
            break;
        case CASUALE:
            for (int i = 0; i < dimensione; ++i) {
                array[i] = rand() % 100;
            }
            break;
        case INVERSO:
            for (int i = 0; i < dimensione; ++i) {
                array[i] = dimensione - i;
            }
            break;
        case PARZ_ORDINATO:
            for (int i = 0; i < dimensione / 2; ++i) {
                array[i] = i;
            }
            for (int i = dimensione / 2; i < dimensione; ++i) {
                array[i] = rand() % 100;
            }
            break;
    }
    return array;
}

/**
 * @brief Ordina un array di interi in modo crescente
 * @param array array da ordinare
 * @param dim dimensione dell'array
 * @return array ordinato
 */
int *selectionSort(int *array, int dim) {
    int min;
    for (int i = 0; i < dim - 1; ++i) {
        min = i;
        for (int j = i + 1; j < dim; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        scambia(&array[min], &array[i]);
    }
    return array;
}

/**
 * @brief Ordina un array di interi in modo decrescente
 * @param array array da ordinare
 * @param dim dimensione dell'array
 * @return array ordinato
 */
void selectionSortInv(int *array, int dim) {
    int max;
    for (int i = 0; i < dim - 1; ++i) {
        max = i;
        for (int j = i + 1; j < dim; ++j) {
            if (array[j] > array[max]) {
                max = j;
            }
        }
        scambia(&array[max], &array[i]);
    }
}

/**
 * @brief Scambia due interi
 * @param a primo intero
 * @param b secondo intero
 */
void scambia(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Calcola il tempo di esecuzione di un'operazione
 * @param inizio inizio dell'operazione
 * @param fine fine dell'operazione
 */
void tempoExecution(clock_t inizio, clock_t fine) {
    printf("\n\nTempo impiegato: %lf secondi\n", (double) (fine - inizio) / CLOCKS_PER_SEC);
}

/**
 * @brief Ricerca banale di un valore in un array
 * @param array array in cui cercare
 * @param dim dimensione dell'array
 * @param valore valore da cercare
 * @return posizione del valore cercato
 */
int ricercaBanale(int array[], int dim, int valore) {
    for (int i = 0; i < dim; ++i) {
        if (valore == array[i]) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Ricerca binaria iterativa di un valore in un array
 * @param array array in cui cercare
 * @param dim dimensione dell'array
 * @param valore valore da cercare
 * @return posizione del valore cercato
 */
int ricercaBinariaIter(int array[], int dim, int valore) {
    int primo = 0;
    int ultimo = dim - 1;
    while (primo <= ultimo) {
        int mezzo = (primo + ultimo) / 2;
        if (valore < array[mezzo]) {
            ultimo = mezzo - 1;
        } else if (valore == array[mezzo]) {
            return mezzo;
        } else {
            primo = mezzo + 1;
        }
    }
    return -1;
}

/**
 * @brief Ricerca binaria ricorsiva di un valore in un array
 * @param array array in cui cercare
 * @param valore valore da cercare
 * @param primo primo indice dell'array
 * @param ultimo ultimo indice dell'array
 * @return posizione del valore cercato
 */
int ricBinRic(int array[], int valore, int primo, int ultimo) {
    if (primo > ultimo) {
        return -1;
    }
    int mezzo = (primo + ultimo) / 2;
    if (array[mezzo] == valore) {
        return mezzo;
    } else if (array[mezzo] < valore) {
        return ricBinRic(array, valore, mezzo + 1, ultimo);
    } else {
        return ricBinRic(array, valore, primo, mezzo - 1);
    }
}

///fine subroutines lezione 1

///inizio subroutines lezione 2
/**
 * @brief Ordina un array di interi in modo crescente in modo ricorsivo
 * @param array array da ordinare
 * @param dim dimensione dell'array
 * @param start indice di partenza
 */
void selectionSortRec(int *array, int dim, int start) {
    if (start >= dim - 1) {
        return;
    }
    int minIndex = findMin(array, start, start + 1, dim);
    scambia(&array[start], &array[minIndex]);
    selectionSortRec(array, dim, start + 1);
}

/**
 * @brief Trova il minimo di un array di interi
 * @param array array in cui cercare
 * @param minPos posizione del minimo
 * @param start indice di partenza
 * @param dim dimensione dell'array
 * @return posizione del minimo
 */
int findMin(int *array, int minPos, int start, int dim) {
    if (start == dim) {
        return minPos;
    }
    if (array[start] < array[minPos]) {
        minPos = start;
    }
    return findMin(array, minPos, start + 1, dim);
}
///fine subroutines lezione 2

///inizio subroutines lezione 3
/**
 * @brief Calcola l'insuccesso di un pattern
 * @param pat pattern da analizzare
 * @return insuccesso
 */
int *insuccesso(char *pat) {
    int n = strlen(pat);
    int *insucc = (int *) malloc(n * sizeof(int));
    if (insucc == NULL) {
        printf("Errore nell'allocazione della memoria");
        exit(EXIT_FAILURE);
    }
    insucc[0] = -1;

    //analisi prefissi
    for (int j = 1; j < n; ++j) {
        int i = insucc[j - 1];
        while (pat[j] != pat[i + 1] && i >= 0) {
            i = insucc[i];
        }
        if (pat[j] == pat[i + 1]) {
            insucc[j] = i + 1;
        } else {
            insucc[j] = -1;
        }
    }
    return insucc;
}

/**
 * @brief Cerca un pattern in una stringa
 * @param stringa stringa in cui cercare
 * @param pat pattern da cercare
 * @return posizione del pattern
 */
int KMP_match(char *stringa, char *pat) {
    int *insucc = insuccesso(pat);
    int i = 0, j = 0, lenS = strlen(stringa), lenP = strlen(pat);
    while (i < lenS && j < lenP) {
        if (stringa[i] == pat[j]) {
            i++;
            j++;
        } else if (j == 0) {
            i++;
        } else {
            j = insucc[j - 1] + 1;
        }
    }
    free(insucc);
    if (j == lenP) {
        return i - lenP;
    } else {
        return -1;
    }
}

///fine subroutines lezione 3