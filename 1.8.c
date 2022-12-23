#include <stdio.h>
#include <limits.h>
#include <math.h>

#define SIZE 128

int main(){
    FILE *fi = fopen("filefortask1.8.txt", "r");
    if (fi == NULL){
        printf("Problems with file\n");
        return -1;
    }
    int array1[SIZE];
    int i = 0;
    int count_even = 0;
    while (fscanf(fi, "%d", array1 + i) != EOF){
        if (array1[i] % 2 == 0) count_even++;
        i++;
    }
    char flag;
    printf("Enter the flag:\n");
    scanf("%c", &flag);
    if (flag == 'a'){
        int j = 0;
        int array2[SIZE/2];
        printf("New array:\n");
        for(i = 1; j < SIZE/2; i+=2){
            array2[j] = array1[i];
            printf("%d ", array2[j]);
            j++;
        }
    }else if(flag == 'b'){
        int array2[count_even];
        int j = 0;
        printf("New array:\n");
        for(i = 0; i < SIZE; i++){
            if (array1[i] % 2 == 0){
                array2[j] = array1[i];
                printf("%d ", array2[j]); 
            }
        }

    }else if(flag == 'c'){
        int index = 0;
        int i = 0;
        int maximum = 0;
        int max_index = 0;
        printf("Enter an index:\n");
        while ((int)scanf("%d", &index) != 1){
            printf("Wrong input\n");
            while(getchar()!='\n');
        }
        for(; i < SIZE; i++){
            if (abs(array1[i] - array1[index]) > maximum){
                maximum = abs(array1[i] - array1[index]);
                max_index = i;
            }
        }  
        int array2[1];
        array2[0] = array1[max_index];
        printf("The answer is: %d", array2[0]);    
    }else if(flag == 'd'){
        int index = 0;
        int i = 0;
        int sum = 0;
        printf("Enter an index:\n");
        while ((int)scanf("%d", &index) != 1){
            printf("Wrong input\n");
            while(getchar()!='\n');
        }
        for(; i < index; i++){
            sum += array1[i];
        }  
        int array2[1];
        array2[0] = sum;
        printf("The answer is: %d", array2[0]);
    }else if(flag == 'e'){
        int index = 0;
        int i = 0;
        int sum = 0;
        printf("Enter an index:\n");
        while ((int)scanf("%d", &index) != 1){
            printf("Wrong input\n");
            while(getchar()!='\n');
        }
        for(; i < SIZE; i++){
            if (array1[i] < array1[index]){
                sum+= array1[i];
            }
        }  
        int array2[1];
        array2[0] = sum;
        printf("The answer is: %d", array2[0]);  
    }


    return 0;
}