#include <stdio.h>
#include <math.h>
#define MAX(x, y) x>y ? x:y

void case_q(float *array){
    float a = array[0];
    float b = array[1];
    float c = array[2];
    if(a == 0 ){
        if(b == 0) {
            if(c == 0) {
                printf("x - any number\n");
            }else {
                printf("No roots\n");
            }
        }else {
            printf ("x = %g\n", -c/b);
        }
    }else {
        float d, x1, x2;
        d = b * b - 4 * a * c;
        if(d < 0){
            printf("No roots\n");
        }else {
            if(d == 0) {
                printf("x = %g\n", -b/(2*a));
            }else {
                printf("x1 = %g, x2 = %g\n",(-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a));
            }
        }
    }
}

void case_m(float *array){
    int a = (int) array[0];
    int b = (int) array[1];
    if (a == 0 || b == 0){
        printf("Wrong input\n");
        return;
    }
    if (a % b == 0) {
        printf("%d is multiple of %d\n", a, b);
    }else {
        printf("Not multiple\n");
    }
}

void case_t(float *array){
    float a = array[0];
    float b = array[1];
    float c = array[2];
    if (a <= 0 || b <= 0 || c <= 0){
        printf("Wrong input\n");
        return;
    }
    float temp1 = MAX(a,b);
    float temp2 = MAX(b, c);
    float gipotenuza = MAX(temp1, temp2);
    if (gipotenuza == a){
        if (gipotenuza*gipotenuza == b*b + c*c){
            printf("Triangle is right\n");
            return;
        }
    }else if (gipotenuza == b){
        if (gipotenuza*gipotenuza == a*a + c*c){
            printf("Triangle is right\n");
            return;
        }
    }
    else if (gipotenuza == c){
        if (gipotenuza*gipotenuza == a*a + b*b){
            printf("Triangle is right\n");
            return;
        }
    }
    printf("Triangle is not right\n");
    
}

void main(){
    while (1){
        float array[3];
        char flag[2];
        printf("Enter flag\n");
        scanf("%s", flag);
        scanf("%*[^\n]");
        if (flag[0] == 'q') break;
        if (flag[0] == '-' || flag[0] == '/'){
            if (flag[1] == 'q'){
                int i = 0;
                for (; i < 3; i++){
                scanf("%f", &array[i]);
            }    
            case_q(array); 
            }else if (flag[1] == 'm'){
                int i = 0;
                for (; i < 2; i++){
                scanf("%f", &array[i]);
            }    
            case_m(array);        
            }else if (flag[1] == 't'){
                int i = 0;
                for (; i < 3; i++){
                scanf("%f", &array[i]);
            }    
            case_t(array);
            }
        }
    }
}