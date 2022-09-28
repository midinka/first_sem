#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 10 

void separate(char *data, char *str, char *flag){
    int i = 0;
    int j = 0;
    for (; data[i] != ' ' && data[i] != '\n'; i++){
        str[i] = data[i];
    }
    i++;
    for (;data[i] != '\0' && data[i] != '\n'; i++, j++){
        flag[j] = data[i];
    }
    if (data[i] == '\0') return;
}

int case_l(char *str){
    int count = 0;
    while (*str != '\0'){
        count++;
        str++;
    }
    return count;

}

void case_r(char *str, char *reversestr){
    int count = 0;
    while (*str != '\0'){
        count++;
        str++;
    }
    str--;
    for(int i = 0; i < count; i++){
        reversestr[i] = *str;
        str--;
    }
    reversestr[count] = '\0';

}

void case_u(char *str, char *new, int lenght){
    int i = 0;
    for (;i < lenght; i++){
        if (i % 2 != 0){
            if ('a' <= str[i] && str[i] <= 'z') {
                new[i] = str[i] + 'A' - 'a';
            }
        }else {
            new[i] = str[i];
        }
    }
    new[lenght] = '\0';
}


bool is_number(char c){
    return (c >= '0' && c <= '9');
}

bool is_alpha(char c){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void case_n(char *str, char *new, int lenght){
    int i = 0;
    int j = 0; // для перемщения по массиву letter
    int k = 0; //для перемещения по массиву other
    int c_letter = 0;
    int c_other = 0;
    char letter[lenght];
    char other[lenght];
    for (; i < lenght; i++){
        if (is_number(str[i])){
            *new = str[i];
            new++;
        }else if (is_alpha(str[i])){
            letter[j] = str[i];
            j++;
            c_letter++;
        }else {
            other[k] = str[i];
            k++;
            c_other++;
        }
    }

    i = 0;
    for(; i < c_letter; i++){
        *new = letter[i];
        new++;
    }

    i = 0;
    for(; i < c_other; i++){
        *new = other[i];
        new++;
    }
    *new = '\0';

}

void case_c(char *str, char *str2, char *new){
    int i = 0;
    while (str[i] != '\0'){
        *new = str[i];
        i++;
        new++;
    }
    i = 0;
    while (str2[i] != '\0'){
        *new = str2[i];
        i++;
        new++;
    }
    *new = '\0';
}

void main(){
    char data[N];
    char str[N];
    char flag[2];
    gets(data);
    separate(data, str, flag);
    int lenght = case_l(str);
    if (flag == "-l"){
        case_l(str);
    }else if (flag == "-r"){
        char reversestr[N];
        case_r(str, reversestr);
        printf("%s", reversestr);
    }else if(flag[1] == 'u'){
        char new[lenght];
        case_u(str, new, lenght);
        printf("%s", new);
    }else if(flag[1] == 'n'){
        char new[lenght];
        case_n(str, new, lenght);
        printf("%s", new); 
    }else if(flag[1] == 'c'){
        char str2[N];
        char new[2*N];
        printf("Enter the second string\n");
        scanf("%s", str2);
        case_c(str, str2, new);
        printf("%s", new);
    }


    



}