//функция дается изначально
//уравнение функции передается в функцию как параметр
//найдем корень на интервале [0;1] уравнения x^3-3*x+1=0 с точностью 10^-3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double foo(double l, double r, double e){
    double c;
    if (pow(l,3) - 3*l + 1 == 0) return l;
    if (pow(r,3) - 3*r + 1 == 0) return r;
    while ((r - l) > e){
        c = (l + r) / 2.;
        if (pow(c,3) - 3.*c + 1. < 0.){
            r = c;
        }else {
            l = c;
        }
    }
    return (l + r) / 2.;
}

void main(){
    double l = 0.;
    double r = 1.;
    double e = 0.001;
    printf("%lf", foo(l, r, e));
}