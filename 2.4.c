#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

double gmean(int count, ...){
    int i = 0;
    double res = 1.0;
    va_list l;
    va_start(l, count);
    for (; i < count; i++){
        res *= va_arg(l, double);
    }
    va_end(l);
    return (pow(res, 1./count));
}

double power(double a, int b){
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b > 1){
        return (a * power(a, b-1));
    }
    if (b == -1) return (1./a);
    if (b < -1){
        return (1. / power(a, (-b)));
    }
}

void main(){
    /*while (1){
        char flag;
        int count = 0;
        double *buf = NULL;
        printf("If you want to find geometry mean - enter 'GM'\nIf you want to raise a number to a power - enter 'P'\n");
        scanf("%c", &flag);
        if (flag == 'GM'){
            printf("How many numbers do you want to find geometry mean of?\n");
            scanf("%d", &count);
            buf = malloc(sizeof(double) * count);
            if (buf == NULL){
                printf("Memory allocation error\n");
                break;
            }
            buf[0] = count;
            for (int i = 1; i < count; i++){
                scanf("%lf", &buf[i]);
            }
            int i = 0;
            for (; i < count; i++){

            }
        }else if (flag == 'P'){

        }else {
            printf("Wrong input\n");
            continue;
        }
    }*/
    printf("%lf\n", gmean(3, 2., 4., 8.));
    printf("%lf\n", power(5., -2));
}