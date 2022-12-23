#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
/*
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

void search(int k, int l, int *res, int size, bool *status){
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
        *status = 1;
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
    return;
}

void finding_duplicate_one(int k, int l, int *res, int size, bool *status){
    int count = 0, i = 0, rem, n, num = (1 << k-1)-1, last_num = 1 << (k-1);
    for(; i < size; i++){
        res[i] = 0;
    }
    i = 0;
    if (k <= 0 || l <= 0 || l > k){
        *status = 1;       
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
            if (rem == 1){
                count++;
            }
            else{
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
    return;
}

int main(){
    int k, l;
    bool *status;
    printf("The quantity of bits: ");
    while (scanf("%d", &k) == 0){
        printf("Wrong input. Enter a number:\n");
        while(getchar()!='\n');
    }
    printf("The quantity of units: ");
    while (scanf("%d", &l) == 0){
        printf("Wrong input. Enter a number:\n");
        while(getchar()!='\n');
    }
    if (l > k){
        printf("The quantity of units must be less than the quantity of bits!\n");
        return 1;
    }

    int size1 = find_quantity(k, l);
    int size2 = find_quantity(k-l+1, 1);
    int *res1 = (int *)malloc(size1 * sizeof(int));
    int *res2 = (int *)malloc(size2 * sizeof(int));
    if (res1 == NULL || res2 == NULL) {
        printf("Problems with memory allocation\n");
        return 1;
    }

    search(k, l, res1, size1, status);
    if (*status == 1){
        printf("Error. Wrong input!\n");
        return 1;
    }
    printf("Numbers with %d bits and %d units:\n", k, l);
    int i = 0;
    for (; i < size1; i++){
        printf("%d ", res1[i]);
    }
    finding_duplicate_one(k, l, res2, size2, status);
    if (*status == 1){
        printf("Error. Wrong input!\n");
        return 1;
    }
    printf("\nNumbers with %d bits and %d repeating units:\n", k, l);
    i = 0;
    for (; i < size2; i++){
        printf("%d ", res2[i]);
    }
    free(res1);
    free(res2);
    return 0;
}
*/

//Напишите количество единиц: 3
//Числа, содержащие 6 бит и ровно 3 единиц:
//-24 -20 -18 -17 -12 -10 -9 -6 -5 -3 7 11 13 14 19 21 22 25 26 28 
//Числа, содержащие 6 бит и ровно 3 подряд идущих единиц:
//-24 7 14 28




// 1.3 функция f не доделана - done
// 1.4 содержит прямой код
// ost:  9, 10

//в 10 проверка на переполнение в определителе
//в 1.9 исправить магию
//1.4 добавить 2 строчки от димы
//2.10 сс больше 10
#include <stdio.h>
int main()
{
        int m, f, i=2;
        printf("Enter:");
        scanf("%d",&m);
        while(m!=1)
        {
            f=0;
            while(m%i==0)
            {
                f=1;
                m/=i;
            }
            if(f)
                printf("%d ", i);
            i++;
        }
        return 0;
}