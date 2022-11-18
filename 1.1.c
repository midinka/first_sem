#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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
    while (var <= 100){
        printf("%u ", var);
        var+=var;
    }
    printf("\n");
}

void case_p(UINT var){
    int root = sqrt(var);
    int i = 2;
    for (; i <= root + 1; i++){
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

void main(){
    bool start = true;
    while (start) {
        UINT var = 1;
        printf("Введите целое положительное число и следующий из флагов:\n-h -кратные числа в пределах 100\n-p - проверка на простоту\n-s - раздел на отдельный цифры\n-e - возвести 1-10 в степени 1-n\n-a - сумма всех чисел от 1 до n\n-f - факториал числа\nДля выхода введите любое число и через пробел 'q'.\n");
        scanf("%u", &var);
        if (var <= 0 ){
            printf("Wrong value. Try again:\n");
            continue;
        }
        char po = getchar();
        char flag = getchar();
        char b = getchar();
        if (flag == 'q'){
            break;
        }
        if (flag == '/' || flag == '-'){
            if (b == 'h') {
                case_h(var);
            }else if (b == 'p') {
                case_p(var);
            }else if (b == 's') {
                case_s(var);
            }else if (b == 'e'){
                case_e(var);
            }else if (b == 'a'){
                case_a(var);
            }else if (b == 'f'){
                case_f(var);
            }else{
                printf("Wrong flag. Try again:\n");
            }
        }else {
            printf("Wrong flag. Try again:\n");
        }
    }
    
}