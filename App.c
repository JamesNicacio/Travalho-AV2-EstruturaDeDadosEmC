#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("vetor[%d]::%d\n", i, array[i]);
  }
  printf("\n");
}

// perform the bubble sort
void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        
        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
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

    // for (int i = 0; i < 100; i++){
    //     printf("vetor[%d]::%d\n", i, vetor[i]);
    // }
    int size = sizeof(vetor) / sizeof(vetor[0]);

    printArray(vetor, size);
    printf("total iteracoes::%d\n", totalIteracoes);





    printf("\n=====BEGIN BUBBLE SORT=====\n");
    bubbleSort(vetor, size);

    printArray(vetor, size);
    
    printf("\n=====END BUBBLE SORT=====");
    char end;
    scanf("%s", end);



    printf("Length of array: %d\n", (int)( sizeof(vetor) / sizeof(vetor[0]) ));


    
    return 0;
}
