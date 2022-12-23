#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define LENGTH_INT 10

int to_decimal(char *num_ch, int base){
    int i = 0;
    int len = strlen(num_ch);
    int res = 0;
    for(; i < len; i++){
        char tmp[] = {num_ch[i], '\0'};
        res += atoi(tmp) * pow(base, len-i-1);
    }
    return res;
}

int main(){
    FILE *fi = fopen("task1.6.txt", "r");
    FILE *fout = fopen("task1.6.out.txt", "w");
    if (fi == NULL){
        printf("Problems with files\n");
        return -1;
    }
    if (fout == NULL){
        printf("!!!!!!!");
        return -1;
    }
    
    while (!feof(fi)){

        int num, i;
        fscanf(fi, "%d", &num);
        char num_ch[LENGTH_INT];
        itoa(num, num_ch, 10);
        int base = 1;
        for(i = 0; num_ch[i] != '\0'; i++){
            char tmp[] = {num_ch[i], '\0'};
            if (atoi(tmp) > base){
                base = atoi(tmp);
            }
        }
        base++;
        fprintf(fout, "%d %d %d\n", num, base, to_decimal(num_ch, base));
    }

    fclose(fi);
    fclose(fout);
    return 0;
}