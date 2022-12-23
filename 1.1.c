#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define UINTMAX 4294967295
#define SIZE 33

typedef unsigned int UINT;

int stepen(int a, int b){
    if (b == 0) return 1;
    if (b == 1) return a;
    int pow = a;
    while (b > 1){
        a *= pow;
        b--;
    }
    return a;
}

void case_h(UINT var){
    int tmp = var;
    while (var <= 100){
        printf("%u ", var);
        var+=tmp;
    }
    printf("\n");
}

void case_p(UINT var){
    int root = sqrt(var);
    int i = 2;
    for (; i <= root; i++){
        if (var % i == 0) {
            printf("Number is not prime\n");
            return;
        }
    }
    printf("Number is prime\n");

}

char* my_itoa(int var, char* var_in_ascii, int base){
    char r;
    char *pb = var_in_ascii + SIZE - 1;
    *pb--=0;
    while (var){
        r = var%base;
        *pb--=r>9?r-10+'A':r+'0';
        var/=base;
    }
    return pb+1;
}


void case_s(UINT var){
    char var_in_ascii[33];
    char *ptr = my_itoa(var, var_in_ascii, 10);
    int i;
    for (i = 0; i < 10; i++) {
        if (*(ptr+i) == 0) break;
        printf("%c ", *(ptr+i));
    }
    printf("\n");


}

void case_e(UINT var){
    if (var > 10){
        printf("Number is not correct. Please enter number <= 10\n");
        return;
    }
    int i, j;
    for (i = 1; i < 11; i++){
        printf("-------%d-------\n", i);
        for (j = 1; j <= var; j++){
            int res = stepen(i, j);
            printf("%d^%d = %9d\n", i, j, res);
        }
    }
}

void case_a(UINT var){
    int i = 1;
    int sum = 0;
    while (var > 0){
        sum += i;
        i++;
        var--;
    }
    printf("%d\n", sum);
}

void case_f(UINT var){
    int i = 1;
    UINT factorial = 1;
    while (var > 0 && factorial < UINTMAX){
        factorial *= i;
        i++;
        var--;
    }
    printf("%d\n", factorial);
}

int main(int argc, char *argv[]){
    if (argc == 1){
        printf("Invalid quantity of parametrs\n");
    }
    UINT var = 1;
    var = atoi(argv[1]);
    if (var <= 0 ){
        printf("Wrong value. Try again\n");
        return 1;
    }
    char flag[3];
    strcpy(flag, argv[2]);
    if (strcmp(flag, "/h") == 0 || strcmp(flag, "-h") == 0) {
        case_h(var);
    }else if (!strcmp(argv[2], "/p") || !strcmp(argv[2], "-p")) {
        case_p(var);
    }else if (!strcmp(argv[2], "/s") || !strcmp(argv[2], "-s")) {
        case_s(var);
    }else if (!strcmp(argv[2], "/e") || !strcmp(argv[2], "-e")){
        case_e(var);
    }else if (!strcmp(argv[2], "/a") || !strcmp(argv[2], "-a")){
        case_a(var);
    }else if (!strcmp(argv[2], "/f") || !strcmp(argv[2], "-f")){
        case_f(var);
    }else{
        printf("Wrong flag. Try again\n");
        return 1;
    }

}
