#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define E 0.000001

void case_e1(int l){
    double n = 1;
    double an = pow((1 + 1/n), n);
    double an1 = pow((1 + 1/(n+1)), (n+1));
    while (E < fabs(an1 - an)){
        n++;
        an = an1;
        an1 = pow((1 + 1/(n+1)), (n+1));
    }
    printf("%lf\n", an);

}

double factorial(double n){
    double i = 1;
    double res = 1;
    for (;n > 0; n--, i++){
        res *= i;
    }
    return res;
}

void case_e2(int l){
    double n = 0;
    double sum;
    double an = (1 / factorial(n));
    double an1 = (1 / factorial(n + 1));
    while (fabs(an1 - an) > E){
        an = an1;
        n++;
        an1 = (1 / factorial(n + 1));
        sum += an1;
    }
    printf("%lf\n", sum);

}

void case_e3(int len){
    double r = 3;
    double l = 0;
    double c;
    while ((r - l) > E){
        c = (l + r) / 2;
        if ((log(c) - 1) * (log(r) - 1) < 0){
            l = c;
        }else {
            r = c;
        }
    }
    printf("%lf", (l + r) / 2);
}

void case_pi1(int l){
    double n = 1;
    double an = (pow((pow(2,n) * factorial(n)), 4)) / (n*pow(factorial(2*n), 2));
    double an1 = (pow((pow(2,(n + 1)) * factorial(n+1)), 4)) / ((n+1)*pow(factorial(2*(n+1)), 2));
    while (E < fabs(an1 - an)){
        n++;
        an = an1;
        an1 = (pow((pow(2,(n + 1)) * factorial(n+1)), 4)) / ((n+1)*pow(factorial(2*(n+1)), 2));   
    }
    printf("%lf\n", an);
}

/*void case_pi2(int l){
    double n = 1;
    double an = ((pow((-1), (n - 1))) / (2*n - 1));
    double an1 = (pow((-1), n)) / (2*(n+1) - 1);
    double sum = an;
    while ((fabs(an1) - fabs(an)) > 0.0){
        n++;
        an = an1;
        an1 = ((pow((-1), (n -1))) / (2*n - 1));
        sum += an1;
    }
    printf("%lf\n", 4 * sum);

}*/

void case_pi2(int l){
    int n = 1;
    double an = ((pow((-1), (n - 1))) / (2*n - 1));
    double an1 = (pow((-1), n)) / (2*(n+1) - 1);
    double sum = an;
    while (fabs(fabs(an1) - fabs(an)) > E){
        sum+=an1;
        an = an1;
        n++;
        an1 = ((pow((-1), (n))) / (2*(n+1) - 1));
    }
    printf("%lf\n",  4 * sum);

}

void case_pi3(int length){
    double r = 6.;
    double l = 1.;
    double c;
    while ((r - l) > E){
        c = (l + r) / 2.;
        if (((cos(c) + 1) * (cos(r) + 1)) < 0){
            l = c;
        }else {
            r = c;
        }
    }
    printf("%lf", (l + r) / 2);
}

void main(){
    char what;
    int l;
    printf("...\n");
    scanf("%c", &what);
    if (what == 'e'){
        case_e1(5);
        case_e2(5);
        case_e3(5);
    }else if (what == 'p'){
        case_pi1(5);
        case_pi2(5);
        case_pi3(5);
    }
}