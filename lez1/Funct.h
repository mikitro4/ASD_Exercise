//
// Created by 4miki on 06/03/2024.
//

#ifndef LEZ1_FUNCT_H
#define LEZ1_FUNCT_H

///direttive di pre-processing
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
///fine direttive di pre-processing

///dichiarazione macro
#define DIM_NOME 31
///fine dichiarazione macro

///dichiarazione nuovi tipi
typedef enum {
    ORDINATO, CASUALE, INVERSO, PARZ_ORDINATO
} Schema;
///fine dichiarazione nuovi tipi

///inizio firme subroutines lezione 1
int *generaArray(int *array, int dimensione, Schema schema);

int *selectionSort(int *array, int dim);

void selectionSortInv(int *array, int dim);

void scambia(int *a, int *b);

void tempoExecution(clock_t inizio, clock_t fine);

int ricercaBanale(int array[], int dim, int valore);

int ricercaBinariaIter(int array[], int dim, int valore);

int ricBinRic(int array[], int valore, int primo, int ultimo);
///fine firme subroutines lezione 1

///inizio firme subroutines lezione 2
void selectionSortRec(int *array, int dim, int start);

int findMin(int *array, int minPos, int start, int dim);
///fine firme subroutines lezione 2

///inizio firme subroutines lezione 3
int *insuccesso(char *pat);

int KMP_match(char *stringa, char *pat);
///fine firme subroutines lezione 3

#endif //LEZ1_FUNCT_H
