#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>


int char_to_int(char c){
    if(!(('0' <= c && c <= '9') || ('A'<= c && c <= 'F'))){
        return 0;
    }
    int res = 0;
    res = isdigit(c)?c-'0':c-'A'+10;
    return res;
}

char int_to_char(int num, int base){
    char res;
    int r = num%base;
    res = r>9? r-10+'A' : r+'0';
    return res;
}


char* task(unsigned int base, unsigned int num_of_params, ...){
    char* result;
    char** nums_in_ascii = (char**)malloc(sizeof(char*)* num_of_params);
    if (*nums_in_ascii == NULL){
        result = NULL;
        return result;
    }
    int i , j;

    va_list factor;         
    va_start(factor, num_of_params);   
    int maxlen = 0; 
    for(i=0;i<num_of_params; i++)
    {
        int fase = 0;
        nums_in_ascii[i] = va_arg(factor, char*);
        maxlen = strlen(nums_in_ascii[i]) > maxlen ? strlen(nums_in_ascii[i]) : maxlen;
    }
    for (i = 0; i < num_of_params; i++){
        char* temp_str = (char*)malloc(maxlen + num_of_params);
        if (temp_str == NULL){
            result = NULL;
            return result;
        }
        for (j = 0; j < maxlen + num_of_params; j++){
            temp_str[j] = 0;
        }
        temp_str[j] = '\0';

        int len = strlen(nums_in_ascii[i]);

        for (j = 0; j < len; j++){
            temp_str[maxlen + num_of_params - 1 - len + j] = nums_in_ascii[i][j];
        }

        nums_in_ascii[i] = temp_str;
    }

    
    va_end(factor); 
    int res_len = maxlen + num_of_params;
    result = (char*)malloc(res_len); 
    if (result == NULL){
        return result;
    }
    result[res_len-1] = '\0';
    int extra = 0;
    int sum;
    int flag = 1;

    for(i = res_len-2; i >= 0; i--){
        sum = 0;
        for(j = 0; j < num_of_params; j++){
            char c = nums_in_ascii[j][i];
            int S = char_to_int(c);
            sum += S;
        }
        sum+=extra;
        int a = sum%base;
        char Z = int_to_char(a, base);
        result[i] = Z;
        extra = sum/base;
    }



    char* newres = (char*)malloc(res_len);
    j = 0;
    for(i = 0; i < res_len; i++){
        if (result[i] != '0') break;
    }
    for(i; i < res_len; i++){
        newres[j] = result[i];
        j++;
    }
    free(result);
    return newres;
}




int main(){
    char* n = task(16, 2, "FFFFFFFFFFFFF", "1");
    if (n == NULL){
        printf("Problems with memory\n");
        return -1;
    }
    printf("%s\n",n);
    free(n);
    return 0;
}