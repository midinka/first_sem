#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>


bool task1(int n, ...){
    va_list v;
    va_start(v, n);
    if (n < 3){
        return false;
    }
    int flag = 0;
    int x[n];
    int y[n];
    int i = 0;
    for (; i < n; i++){
        x[i] = va_arg(v, int);
        y[i] = va_arg(v, int);
    }
    i = 0;
    for (; i < n; i++){
        if (((x[(i+1)%n] - x[i%n]) * (y[(i+2)%n] - y[(i+1)%n]) - (x[(i+2)%n] - x[(i+1)%n]) * (y[(i+1)%n] - y[i%n])) < 0){
            if (flag > 0) return false;
            flag = -1; 
        }else {
            if (flag < 0) return false;
            flag = 1;
        }
    }
    return true;

}

int task2(int x, int n, ...){
    va_list v;
    va_start(v, n);
    int res = va_arg(v, int);
    while (n > 0){
        res = res*x + va_arg(v, int);
        n--;
    }
    return res;
}

void main(){
    printf("%d\n", task1(5, 0, 2, 2, 4, 4, 2, 3, 1, 1, 1));
    printf("%d\n", task2(5, 2, 2, -3, 8));
}

