#include <stdio.h>
#include <stdlib.h>

int minimum(int a, int b){
    if (a == b) return a;
    if (a < b) return a;
    return b;
}

int *foo(int *A, int *B, int sizeA, int sizeB, int sizeC){
    int i = 0;
    int *C;
    C = malloc(sizeof(int)*sizeC);
    for (; i < sizeC; i++){
        *C = *A + *B;
        C++;
        A++;
        B++;
    }
    for(int j = 0; j < sizeC; j++){
        C--;
    }
    return C;
}


int main(){
    int *arrA;
    int *arrB;
    int *arrC;
    int *tmp;
    int sizeA = 0;
    int sizeB = 0;
    printf("Enter the size of array A\n");
    scanf("%d", &sizeA);
    arrA = (int *)malloc(sizeof(int)*sizeA);
    printf("Enter the size of array B\n");
    scanf("%d", &sizeB);
    arrB = (int *)malloc(sizeof(int)*sizeB);
    int i = 0;
    printf("Enter %d elements for array A\n", sizeA);

    for (;i < sizeA; i++){
        scanf("%d", &arrA[i]);
    }
    i = 0;
    printf("Enter %d elements for array B\n", sizeB);
    for (;i < sizeB; i++){
        scanf("%d", &arrB[i]);
    }
    
    int sizeC = minimum(sizeA, sizeB);
    


    arrC = foo(arrA, arrB, sizeA, sizeB, sizeC);
    i = 0;
    tmp = arrC;
    printf("Your new array:\n");
    for (;i < sizeC; i++){
        printf("%d ", *tmp);
        tmp++;
    }
    free(arrC);
    free(arrB);
    free(arrA);

}