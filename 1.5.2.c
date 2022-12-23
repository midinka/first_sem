#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 3
#define MAX_LEN_FILE 50

int main(int argc, char *argv[]){

    FILE *fout = fopen("filefor5task.txt", "w");
    if (fout == NULL){
        return -2;
    }
    if (!strcmp(argv[1], "-fi")){
        FILE *fi = fopen(argv[2], "r");
        //FILE *fi = fopen("forflagfi.txt", "r");
        if (fi == NULL){
            fclose(fout);
            printf("Could not open file");
            return -1;
        } 
        char **buf = (char **)malloc(N * sizeof(char *));
        
        if (buf == NULL){
            fclose(fi);
            fclose(fout);
            return -3;
        }
        int i = 0;
        while (!feof(fi)){

            for(i = 0;i < N; i++){
                buf[i] = (char *)malloc(MAX_LEN_FILE);
                if (buf[i] == NULL){
                    fclose(fi);
                    fclose(fout);
                    return -4;
                }
                fgets(buf[i], MAX_LEN_FILE, fi);
                //fscanf(fi, "%s")
                printf("%s\n", buf[i]);

                if (buf[i][strlen(buf[i]) - 1] == '\n'){
                    buf[i][strlen(buf[i]) - 1] = '\0';
                }
            }
        }
        char cymbol;
        
        for (i = 0; i < N; i++){           
            FILE *fforcopy = fopen(buf[i], "r");
            if (fforcopy == NULL){
                printf("Problems with opening files\n");
                return -1;
            }
            while ((!feof(fforcopy))){
                cymbol = fgetc(fforcopy);
                if(cymbol == '\377') continue;
                fputc(cymbol, fout);       
            }

            fclose(fforcopy);
        }
        fclose(fi);

    }else if(!strcmp(argv[1], "-cin")){
        int i = 0;
        char **buf = (char **)malloc(N * sizeof(char *));
        if (buf == NULL) {
            fclose(fout);
            return -1;
        }
        for(i = 0;i < N; i++){
                buf[i] = (char *)malloc(MAX_LEN_FILE);
                scanf("%s", buf[i]);
        }
        char cymbol;
        for (i = 0; i < N; i++){
            FILE *fforcopy = fopen(buf[i], "r");
            while ((!feof(fforcopy))){
                cymbol = fgetc(fforcopy);
                if(cymbol == '\377') continue;
                fputc(cymbol, fout);       
            }
            fclose(fforcopy);
        }
        for (i = 0; i < N; i++){
            free(buf[i]);
        }
        free(buf);

    }else if(!strcmp(argv[1], "-arg")){
        char cymbol;
        int i;

        for (i = 0; i < N; i++){
            FILE *fforcopy = fopen(argv[i+2], "r");
            while ((!feof(fforcopy))){
                cymbol = fgetc(fforcopy);
                if(cymbol == '\377') continue;
                fputc(cymbol, fout);       
            }
            fclose(fforcopy);
        }
    }


    fclose(fout);
    return 0;
}