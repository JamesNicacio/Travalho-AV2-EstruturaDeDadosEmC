#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void copyArray(int array[], int arrayCopy[], int size){
    for (int i = 0; i < size; i++) {     
        arrayCopy[i] = array[i];     
    }    
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("vetor[%d]::%d\n", i, array[i]);
  }
  printf("\n");
}

// perform the bubble sort
void bubbleSort(int array[], int size) {
    int comparacoes = 0;
    int swaps = 0;
    // loop to access each array element
    for (int step = 0; step < size - 1; ++step) {
        // loop to compare array elements
        for (int i = 0; i < size - step - 1; ++i) {
            comparacoes++;
            // compare two adjacent elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1]) {
                swaps++;
                // swapping occurs if elements
                // are not in the intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    printf("comparacoes::%d || swaps::%d", comparacoes, swaps);
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
    int comparacoes = 0;
    int swaps = 0;
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            comparacoes++;
            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx]){
                min_idx = i;
                swaps++;
            }
        }
        // put min at the correct position
        swap(&array[min_idx], &array[step]);
    }
    printf("comparacoes::%d || swaps::%d", comparacoes, swaps);
}

void insertionSort(int array[], int size) {
    int comparacoes = 0;
    int swaps = 0;

    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0) {
            comparacoes++;

            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
        swaps++;

    }
    printf("comparacoes::%d || swaps::%d", comparacoes, swaps);
}


int main(int argc, char const *argv[]){
    int vetor[100];
    srand(time(NULL));   // Initialization, should only be called once.

    // Returns a pseudo-random integer between 0 and RAND_MAX.
    // random int between 0 and 19
    // int r = rand() % 20;
    int contains = 0;
    int totalIteracoes = 0;

    for (int i = 0; i < 100;){
        totalIteracoes++;
        // int r = rand() % 20;
        // vetor[i] = r;
        // printf("vetor[%d]::%d\n", i, vetor[i]);
        
        // primeira inserção
        if (i == 0){
        vetor[i] = rand() % 1000;
        i++;
        } else{
            int r = rand() % 1000;
            // checar comparação dos elementos
            for (int j = 0; j < i; j++){
                if (r == vetor[j]){
                    contains = 1;
                }
            }
            // checar se comparação de elementos tem algum repetido ou não
            if (contains == 0){
                vetor[i] = r;
                i++;
            } else{
                contains = 0;
            }
            
            
        }
        

    }

    int size = sizeof(vetor) / sizeof(vetor[0]);

    // printArray(vetor, size);
    printf("total iteracoes::%d\n", totalIteracoes);

    int vetorBubble[100];
    copyArray(vetor, vetorBubble, size);
    int vetorSelection[100];
    copyArray(vetor, vetorSelection, size);
    int vetorInsertion[100];
    copyArray(vetor, vetorInsertion, size);
//===============================================================================================
//===========================BUBBLE SORT=========================================================
//===============================================================================================

    printf("\n=====BEGIN BUBBLE SORT=====\n");
    bubbleSort(vetorBubble, size);
    // printArray(vetorBubble, size);
    printf("\n=====END BUBBLE SORT=====\n");

    // scanf("%s", getchar());

    // medir quantidade de elementos dentro de um array
    // printf("Length of array: %d\n", (int)( sizeof(vetor) / sizeof(vetor[0]) ));

//===============================================================================================
//===========================SELECTION SORT======================================================
//===============================================================================================
    printf("\n=====BEGIN SELECTION SORT=====\n");
    selectionSort(vetorSelection, size);
    // printArray(vetorSelection, size);
    printf("\n=====END SELECTION SORT=====\n");


//===============================================================================================
//===========================INSERTION SORT======================================================
//===============================================================================================
    printf("\n=====BEGIN INSERTION SORT=====\n");
    insertionSort(vetorInsertion, size);
    // printArray(vetorInsertion, size);
    printf("\n=====END INSERTION SORT=====\n");


    printf("Digite qualquer coisa p/ finalizar\n");
    char end;
    scanf("%s", end);

    
    return 0;
}
