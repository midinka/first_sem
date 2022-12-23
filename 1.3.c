#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    char flag;
    FILE *fin, *fout;
    char file_out_name[50] = "out_";
    if (argv[1][0] == '-' || argv[1][0] == '/'){
        if (argv[1][1] == 'n'){
            flag = argv[1][2];
            strcpy(file_out_name, argv[3]);
        }else {
            flag = argv[1][1];
            strcat(file_out_name, argv[2]);
        }
    }else {
        printf("Wrong flag\n");
        fclose(fin);
        return -1;
    }
    fin = fopen(argv[2], "r");
    if (fin == NULL){
        printf("Wrong file\n");
        fclose(fin);
        return -1;
    }
    fout = fopen(file_out_name, "w");
    if (fout == NULL){
        printf("Couldn't create a new file\n");
        fclose(fin);
        return -1;
    }

    switch(flag){
        int count, strnum;
        char cymbol;
        case 'd':
            while ((cymbol = fgetc(fin)) != EOF){
                if (!isdigit(cymbol)){
                    fputc(cymbol, fout);
                }
            } 
            break;
        case 'i':
           count = 0;
           strnum = 1;
           while ((cymbol = fgetc(fin)) != EOF){
                if (cymbol == '\n'){
                    fprintf(fout, "%d letters in %d string\n", count, strnum);
                    strnum++;
                    count = 0;
                }
                if (isalpha(cymbol)){
                    count++;
                }
            }
            break; 
        case 's':
            count = 0;
            strnum = 1;
            while ((cymbol = fgetc(fin)) != EOF){
                if (cymbol == '\n'){
                    fprintf(fout, "%d letters in %d string\n", count, strnum);
                    strnum++;
                    count = 0;
                }
                if (!isalnum(cymbol) || cymbol != ' '){
                    count++;
                }
            }
            break; 
        case 'a':
            while ((cymbol = fgetc(fin)) != EOF){
                if (cymbol == '\n'){
                    fputc('\n', fout);
                }else if(!isdigit(cymbol)){
                    fprintf(fout, "(%d)", cymbol);
                }else{
                    fprintf(fout, "%c", cymbol);
                }
            }
            break;
        case 'f':
            count = 0;
            while (!feof(fin)){
                while((cymbol = fgetc(fin)) != EOF && !isspace(cymbol)){
                    if (isupper(cymbol) && (count % 2 == 0)){
                        fprintf(fout, "%c", tolower(cymbol));
                    }else if (count % 5 == 0){
                        fprintf(fout, "%d", cymbol);
                    }else {
                        fprintf(fout, "%c", cymbol);
                    }
                }
                fputc(' ', fout);
                count++;
            }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}