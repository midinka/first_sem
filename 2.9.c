#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// 888000000000
// 000000000888
// 000000000565
// 001231312785
// 1321'\0'0000

int char_to_int(char c){
    if(c < 48 || c > 57) return 0;
    return c - 48;
}

char int_to_char(int num){
    if(num/10 > 0) return 0;
    return num + 48;
}

char* shift(char* array, int fase, int size){
    char* res = (char*)malloc(size);
    int i = fase;
    int j = size-1;
    for(;i >= 0; i--, j--){
        res[j] = array[i];
    }
    for(; j >=0; j--){
        res[j] = '0';
    }
    return res;
}

int task(unsigned int base, unsigned int num_of_params, ...){

    char** nums_in_ascii = (char**)malloc(sizeof(char*)* num_of_params);
    int i , j;
    for(i = 0; i < num_of_params; i++){
        nums_in_ascii[i] = (char*)malloc(32);
        for(j = 0; j < 32; j++){
            nums_in_ascii[i][j] = '\0';
        }
    }


    va_list factor;         //указатель va_list
    va_start(factor, num_of_params);    // устанавливаем указатель
    for(i=0;i<num_of_params; i++)
    {
        int fase = 0;
        itoa(va_arg(factor, int), nums_in_ascii[i], 10);
        for(j = 31; j >= 0; j --){
            if(nums_in_ascii[i][j] != '\0'){
                nums_in_ascii[i] = shift(nums_in_ascii[i], j, 32);
                break;
            }
        }
    }
    va_end(factor); // завершаем обработку параметров

    char result[33];//
    result[32] = '\0';
    int extra = 0;
    int sum;
    int flag = 1;
    int fase;

    for(i = 31; i >= 0; i--){
        sum = 0;
        for(j = 0; j < num_of_params; j++){
            char c = nums_in_ascii[j][i];          
            sum += char_to_int(nums_in_ascii[j][i]);
        }
        sum+=extra;
        result[i] = int_to_char(sum%base);
        extra = sum/base;
    }
    return atoi(result);
}




int main(){

    int n = task(10, 3, 1000, 19, 101);
    printf("%d",n);
}