#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 100

int mod(int x, int y)
{
    if(x % y >= 0){
        return x % y;
    }
    return x % y + y;
}

int main(){
    FILE *fi = fopen("task4.txt", "r");
    FILE *fout = fopen("newtxt.txt", "w");
    if (fi == NULL || fout == NULL){
        printf("Problems with files\n");
        return -1;
    }
    char c[STR_SIZE][3][STR_SIZE];
    char str[STR_SIZE];
    
    int n = 0;
    while (fgets(str, STR_SIZE, fi)){
        sscanf(str, "%s %s %s", c[n][0], c[n][1], c[n][2]);
        ++n;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++)
            fprintf(fout, "%s ", c[i][mod(j - 1, 3)]);
        fprintf(fout, "\n");
    }
    fclose(fi);
    fclose(fout);
    remove("task4.txt");
    rename("newtxt.txt", "task4.txt");
    
    return 0;
}