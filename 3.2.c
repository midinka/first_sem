#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUMBER_IS_NOT_VALID -1

int factorial(int n){
    int i = 1;
    int res = 1;
    for (;n > 0; n--, i++){
        res *= i;
    }
    return res;
}

int find_quantity(int k, int l){
    return factorial(k)/factorial(l)/factorial(k - l);
}

int* search(int k, int l, int *res, int size){
    int count = 0;
    int i = 0;
    int end;
    int n;
    int num = (1 << k - 1) - 1;
    int last_num = 1 << (k - 1);
    for(; i < size; i++){
        res[i] = 0;
    }
    i = 0;
    if (k <= 0 || l <= 0 || l > k){
        perror("Не делайте так больше, пожалуйста!!\n");
        exit(NUMBER_IS_NOT_VALID);
    }

    l--;

    for(; num > 0; num--){
        n = num;
        while (n != 0){
            end = n & 1;
            if (end == 1)
                count++;
            n >>= 1;
        }
        if (count == l){
            res[i] = -num;
            i++;
        }
        count = 0;
    }
    
    l++;
    num = 1;

    for (; num < last_num; num++){
        n = num;
        while (n != 0){
            end = n & 1;
            if (end == 1)
                count++;
            n >>= 1;
        }

        if (count == l){
            res[i] = num;
            i++;
        }
        count = 0;
    }
    return res;
}

int *finding_duplicate_one(int k, int l){
    int size = find_quantity(k, l);
    int count = 0, i = 0, rem, n, num = (1 << k-1)-1, last_num = 1 << (k-1);
    int *res = (int *)malloc(size * sizeof(int));
    for(; i < size; i++){
        res[i] = 0;
    }
    i = 0;
    if (k <= 0 || l <= 0 || l > k){
        perror("Не делайте так больше, пожалуйста!!\n");
        exit(NUMBER_IS_NOT_VALID);
    }

    for(; i < l - 1; i++){
        res[0] -= 1 << (k - i - 2);
    }

    i = 1;
    num = 1;

    for (; num < last_num; num++){
        n = num;
        while (n != 0){
            rem = n & 1;
            if (rem == 1)
            {
                count++;
            }
            else
            {
                if (count > 0) 
                {count =0; break;}

            }
            n >>= 1;
        }
        if (count == l){
            res[i] = num;
            i++;
        }

        count = 0;
    }
    return res;
}

void print_and_free_res(int *res, int size){
    for (int i = 0; i < size; i++){
        if (res[i] == 0)
            break;
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);
}

int main(){
    int k, l;
    printf("Напишите количество бит: ");
    while (scanf("%d", &k) == 0){
        printf("Wrong input\n");
        while(getchar()!='\n');
    }
    printf("Напишите количество единиц: ");
    while (scanf("%d", &l) == 0){
        printf("Wrong input\n");
        while(getchar()!='\n');
    }
    if (l > k){
        perror("Количество единиц должно быть меньше количества бит!!!!\n");
        exit(1);
    }
    int size = find_quantity(k, l);
    int *res = (int *)malloc(size * sizeof(int));

    printf("Числа, содержащие %d бит и ровно %d единиц:\n", k, l);
    print_and_free_res(search(k, l, res, size), size);
    printf("Числа, содержащие %d бит и ровно %d подряд идущих единиц:\n", k, l);
    print_and_free_res(finding_duplicate_one(k, l), size);
    return 0;
}

