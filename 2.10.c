#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 1024

#define MAX(x, y) x>y ? x:y

int char_to_int(char c){
    if(c < 48 || c > 57) return 0;
    return c - 48;
}

int denominator(char *num_in_str){
    int i = 0;
    int j = 0;
    char den[5];
    while (num_in_str[i] != '/'){
        i++;
    }
    i++;
    while (num_in_str[i] != '\0'){
//        if(isalpha(num_in_str[i])){
//            den[j] = char_to_int(num_in_str[i]);
//            i++;
//            j++;
//        }else {
            den[j] = num_in_str[i];
            i++;
            j++;
//        }
    }
    den[j++] = '\0';
    int res = atoi(den);
    return res;
}

int *prost_del(int num, int *array){
    int f, i = 2, j = 0;
    while(num != 1){
        f = 0;
        while(num % i == 0){
            f = 1;
            num /= i;
        }
        if(f){
            array[j] = i;
            j++;
        }
        i++;
    }
    return array;  
}

void task_10(int count, int base, ...){
    char **array = (char**)malloc(sizeof(char *) * count);
    int i = 0;
    va_list ptr;
    va_start(ptr, base);
    int *denominators = (int *)malloc(sizeof(int) * count);

    for (; i < count; i++){
        array[i] = (char *)malloc(sizeof(char) * LENGTH);
        strcpy(array[i], va_arg(ptr, char*));
        denominators[i] = denominator(array[i]);
    }
    
    int j = 0;
    bool flag = 0;
    for (i = 0; i < count; i++){
        int buf1[8];
        for (int k = 0; k < 8; k++){
            buf1[k] = 0;
        }
        prost_del(denominators[i], buf1);
        for (j = 0; buf1[j] != 0; j++){
            if (base % buf1[j] != 0){
                printf("%s has no final representation in %d base\n", array[i], base);
                flag = 1;
            }
        }
        if (!flag) printf("%s has final representation in %d base\n", array[i], base);
    }

}

//2 3 7 - num
//2 5 - base

int main(){
    task_10(3, 2, "10/11", "10/100", "1/10");
    return 0;
}