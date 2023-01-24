#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

#define SIZE 30

int main() {
    char num[SIZE];
    char maxmod[SIZE];
    int base = 0;
    int res = 0;
    int max = INT_MIN;
    int sign = 1;
    int tmp = 0;
    printf("Enter base\n");
    scanf("%d",&base);
    if(base < 2 || base > 36){
        printf("Wrong input\n");
        return -1;
    }
    printf("Enter numbers. To stop enter 'Stop'\n");
    while(strcmp(num,"Stop")){
        scanf("%s",num);
        tmp++;
        if(!strcmp(num,"Stop") && tmp == 1){
            printf("You didn't enter numbers\n");
            return -1;
        }
        if(num[0] == '-')
            sign--;
        char *pb = num-sign;
        while(*++pb){
            if(((isdigit(*pb) && *pb - '0' >=base) || (isalpha(*pb) && (*pb - 'A' + 10 >=base))) && strcmp(num,"Stop")){
                printf("Incorrect input!\n");
                return -1;
            }
            res = res*base + (isdigit(*pb) ? *pb - '0' : *pb - 'A' + 10);
            }
            if((res > max) && strcmp(num,"Stop")){
                max=res;
                strcpy(maxmod,num);
        }
        res = 0;
    }

    printf("Maximal number is %s\n",maxmod); //макс по модулю
    char fin[SIZE];
    for(int i = 9; i <= 36; i+=9){
        int r;
        base = i;
        int tmp = max;
        int j = 0;
        while(tmp){
            r = tmp % base;
            fin[j] = (r > 9) ? (r - 10 + 'A') : (r + '0');
            tmp /= base;
            j++;
        }
            printf("Maximal number(%s) in %d", maxmod, base);
            printf(" : ");
            for (int n = j - 1; n >= 0; n--){
                printf("%c", fin[n]);
            }
            printf("\n");
    }

        return 0;
}