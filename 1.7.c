#include <stdio.h>
#include <stdlib.h>
#define SIZE 5



int main(){
    int arr[SIZE];
    int i = 0;
    printf("Array:\n");
    for(;i < SIZE; i++){
        arr[i] = rand();
        printf("%d ", arr[i]);
    }
    printf("\n");
    int max_val = 0;
    int index_max = -1;
    int min_val = INT_MAX;
    int index_min = -1;
    for(i = 0; i < SIZE; i++){
        if (arr[i] > max_val){
            max_val = arr[i];
            index_max = i;
        }
        if (arr[i] < min_val){
            min_val = arr[i];
            index_min = i;
        }
    }
    printf("Min el: %d\nMax el: %d\n", arr[index_min], arr[index_max]);
    int tmp = min_val;
    arr[index_max] = min_val;
    arr[index_min] = max_val;
    printf("New array:\n");
    for(i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}