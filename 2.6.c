#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>


void find_str(int count, char *string, ...){
    va_list v;
    va_start(v, string);
    int size_str = strlen(string);
    int i = size_str;
    char *tmp = string;
    printf("------------------------\n");
    while (count > 0){
        int count_symbol = 0;
        char* filename = va_arg(v, char*);
        FILE *fi = fopen(filename, "r");
        if (!fi){
            printf("Wrong file\n");
            continue;
        }
        char cymbol;
        bool found = false;
        while (!feof(fi)){
            while ((cymbol = fgetc(fi)) == *tmp){
                count_symbol++;
                tmp++;
                i--;
                if (i == 0){
                    printf("The word ~%s~ is in the file %s starting with %d symbol\n", string, filename, count_symbol - size_str + 1);
                    found = true;
                    break;
                }
            }
            count_symbol++;
            i = size_str;
            tmp = string;
        }
        if (!found) printf("The word ~%s~ wasn't found in file %c\n", string, filename);
        printf("------------------------\n");
        fclose(fi);
        count--;
    }
}

void main(){
    int count = 0;
    char *string = "hello";
    printf("Enter the quantity of file:\n");
    scanf("%d", &count);
    find_str(count, string, "test.txt", "test2.txt", "test3.txt");
}