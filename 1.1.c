#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int case_h(int number, int *res, bool found){
    int i = 1;
    int k = 0;
    for (; i < 101; i++){
        if (i % number == 0){
            res[k] = i;
            k++;
            found = 1;
        }
    }
    return k+1;
}

bool case_p(int number){
    int i = 0;
    if (0 < number < 2){
        return 0;
    }
    if (number > 1){
        int kor = (int)(pow(number, 0.5)) + 1;
        for(i; i < kor; i++){
            if (number%i==0){
                return 1;
            }
        }
        return 0;
    }
}

int case_s(int number, int* res){
    
}

int main(){
    while(1){
        printf("Enter the number:\n");
        int number = 0;
        scanf("%d", &number);
        printf("%d\n", number);
        printf("Enter the flag:\n");
        char flag[2];
        scanf("%s", flag);
        printf("%d\n", number);
        if (flag[0] != '-' && flag[0] != '/'){
            printf("Wrong input. Try again.\n");
            continue;
        }
        int *res = (int *)malloc(100 * sizeof(int));
        if (res == NULL){
            printf("Memory error\n");
            exit(1);
        }
        bool found = 0;
        int size = 0;
        int i = 0;
        if (flag[1] == 'h'){
            size = case_h(number, res, found);
            if (found){
                for (; i < size - 1; i++){
                    printf("%d", res[i]);
                }
                printf("\n");
            }else {
                printf("Numbers were not found\n");
            }
        }
        if (flag[1] == 'p'){
            if (case_p(number)){
                printf("The number %d is prime\n", number);
            }else{
                printf("The number %d is not prime\n", number);
            }
        }
        if (flag[1] == 's'){

        }
    }
}