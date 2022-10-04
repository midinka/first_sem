#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define INT_NULL -10000


int* find_max(int* array, int size) {
    int* max = array;

    for (; size > 0; size--) {
        if ((*array) > (*max)) {
            max = array;
        }
        array++;
    }
    return max;
}

int* find_min(int* array, int size) {
    int* min = array;

    for (; size > 0; size--) {
        if ((*array) < (*min)) {
            min = array;
        }
        array++;
    }
    return min;
}

void exchange_min_max(int* min, int* max) {
    int temp = *min;
    *min = *max;
    *max = temp;
}



bool delete_in_array(int *cymbol, int *end){
    int *cur = cymbol;
    cymbol++;
    bool delete = false;
    while (cymbol <= end){
        if(*cur == *cymbol){
            *cymbol = INT_NULL;
            delete = 1;
        }
        cymbol++;
    }
    if (delete) *cur = INT_NULL;
    return delete;
}

int *uniq_el(int *array, int size){
    int *new = malloc(size * sizeof(int));
    int i = 0;
    for(; i < size; i++){
        new[i] = array[i];
    }
    int *end = new + (size-1);
    int *res = malloc(size * sizeof(int));
    int j = 0;
    for(i = 0; i < size; i++){
        if (new[i] != INT_NULL){
            if (!delete_in_array(new+i, end)){
                res[j] = new[i];
                j++;
            }
        }
    }
    res[j] = INT_NULL;
    return res;
}


void main() {
    int l, r;
    int* array;
    char act;
    printf("Press 1 to exchange min and max in an array\nPress 2 to find uniq elements in an array\n");
    scanf("%c", &act);
    
    printf("Enter a left boarder of range:\n");
    scanf("%d", &l);
    printf("Enter a right boarder of range:\n");
    scanf("%d", &r);

    int size = r - l + 1;
    array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation error\n");
    }

    srand(time(NULL));
    int i = 0;
    for (; i < size; i++) {
        array[i] = rand() % (r - l + 1) + l;
    }
    printf("Your array:\n");
    for (i = 0; i < size; i++) {
        printf("%d  ", array[i]);
    }

    printf("\n");
    if (act == '1'){
        int* max = find_max(array, size);
        printf("max: %d\n", *max);
        int* min = find_min(array, size);
        printf("min: %d\n", *min);
        exchange_min_max(min, max);
        printf("New array:\n");
        for (i = 0; i < size; i++) {
            printf("%d  ", array[i]);
        }
        printf("\n");
    }
    if (act == '2'){
        int *res = uniq_el(array, size);
        printf("New array of uniq elements:\n");
        while(*res != INT_NULL){
            printf("%d  ", *res);
            res++;
        }
    }
}