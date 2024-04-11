///direttive di pre-processing
#include "Funct.h"
///fine direttive di pre-processing

#define DIM 50000

#define N_RICETTE 4

///dichiarazione nuovi tipi

typedef struct {
    char nome[DIM_NOME];
    double tempo;
    int difficolta;
} Ricetta;
///fine dichiarazione nuovi tipi

///firme subroutines
Ricetta *selectionSortRicette(Ricetta *array, int dim);

void scambiaRicetta(Ricetta *a, Ricetta *b);

void stampaRicette(Ricetta *array, int dim);
///fine firme subroutines

int main() {
    /*generazione del seed*/
    srand(time(NULL));

    ///esercizio 1_0
    /*int dim;
    printf("Inserisci la dimensione dell'array:");
    scanf("%d", &dim);

    int *array = NULL;
    array = generaArray(array, dim, PARZ_ORDINATO);

    for (int i = 0; i < dim; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");*/

    ///esercizio 1_1
    /*clock_t start = clock();
    array = selectionSort(array, dim);
    clock_t end = clock();
    tempoExecution(start, end);*/
    /*for (int i = 0; i < dim; i++) {
        printf("%d ", array[i]);
    }*/

    ///esercizio 1_2
    /*Ricetta ricette[N_RICETTE] = {
            {"Pasta al vongole",  20, 3},
            {"Pasta al mandorle", 30, 5},
            {"Pasta al pesce",    60, 7},
            {"Pasta al carciofi", 30, 2}};


    printf("\n\nprima:\n");
    stampaRicette(ricette, N_RICETTE);

    clock_t inizio = clock();
    Ricetta *ricetteOrdinate = selectionSortRicette(ricette, N_RICETTE);
    clock_t fine = clock();

    printf("\n\ndopo:\n");
    stampaRicette(ricetteOrdinate, N_RICETTE);

    tempoExecution(inizio, fine);*/

    ///esercizio 1_3
    /*int valoreDaCercare, position;
    printf("\n\nInserisci il valore da cercare:");
    scanf("%d", &valoreDaCercare);
    clock_t start = clock();
    position= ricercaBanale(array, dim, valoreDaCercare);
    clock_t end = clock();
    printf("\n\nIl valore %d si trova in posizione %d", valoreDaCercare, position);
    tempoExecution(start, end);*/

    ///esercizio 1_4
    /*int arrayOrd[DIM];
    for (int i = 0; i < DIM; ++i) {
        arrayOrd[i] = i;
    }*/

    /*int valoreDaCercare;
    printf("\n\nInserisci il valore da cercare:");
    scanf("%d", &valoreDaCercare);
    clock_t start = clock();
    int position = ricercaBinariaIter(arrayOrd, DIM, valoreDaCercare);
    clock_t end = clock();
    printf("\n\nIl valore %d si trova in posizione %d", valoreDaCercare, position);
    tempoExecution(start, end);*/

    ///esercizio 1_5
    /*clock_t start = clock();
    int position = ricBinRic(arrayOrd, valoreDaCercare, 0, DIM - 1);
    clock_t end = clock();
    printf("\n\nIl valore %d si trova in posizione %d", valoreDaCercare, position);
    tempoExecution(start, end);*/


    ///LEZIONE 2
    ///esercizio 2_1
    /*int *array= NULL;
    array = generaArray(array, 500000, CASUALE);
    clock_t start = clock();
    selectionSortRec(array, 500000, 0);
    clock_t end = clock();
    tempoExecution(start, end);*/

    ///LEZIONE 4
    ///esercizio 4_1 e 4_2
    /*char pat[] = "abcdef";
    char stringa[]="pqrstuvabcdefghijklmno";
    clock_t start = clock();
    printf("\n\n%d", KMP_match(stringa, pat));
    clock_t end = clock();
    tempoExecution(start, end);*/

    ///LEZIONE

    return 0;
}

Ricetta *selectionSortRicette(Ricetta *array, int dim) {
    int min;
    for (int i = 0; i < dim - 1; ++i) {
        min = i;
        for (int j = i + 1; j < dim; ++j) {
            if (array[j].tempo < array[min].tempo) {
                min = j;
            } else if (array[j].tempo == array[min].tempo && array[j].difficolta < array[min].difficolta) {
                min = j;
            }
        }
        scambiaRicetta(&array[min], &array[i]);
    }
    return array;
}

void scambiaRicetta(Ricetta *a, Ricetta *b) {
    Ricetta temp = *a;
    *a = *b;
    *b = temp;
}

void stampaRicette(Ricetta *array, int dim) {
    for (int i = 0; i < dim; i++) {
        printf("%s %lf %d\n", array[i].nome, array[i].tempo, array[i].difficolta);
    }
}