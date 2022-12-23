#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 3
#define MAX_LEN_FILE 50

int main(int argc, char *argv[]){
    FILE *fout = fopen("filefor5task.txt", "w");
    if (strcmp(argv[1], "-fi")){
        printf("Hello world1\n");
        FILE *fi = fopen(argv[2], "r");
        printf("Hello world2\n");
        //FILE *fi = fopen("forflagfi.txt", "r");
        if (fi == NULL) return -1;
        char **buf = (char **)malloc(N * sizeof(char *));
        
        if (buf == NULL) return -1;
        int i = 0;
        while (!feof(fi)){

            for(i = 0;i < N; i++){
                buf[i] = (char *)malloc(MAX_LEN_FILE);
                fgets(buf[i], MAX_LEN_FILE, fi);
                //fscanf(fi, "%s")
                printf("%s\n", buf[i]);

                if (buf[i][strlen(buf[i]) - 1] == '\n'){
                    buf[i][strlen(buf[i]) - 1] = '\0';
                }
            }
        }
        printf("Hello world3\n");
        char cymbol;
        
        for (i = 0; i < N; i++){           
            FILE *fforcopy = fopen(buf[i], "r");
            if (fforcopy == NULL){
                printf("Problems with opening files\n");
                return -1;
            }
            while ((!feof(fforcopy))){
                cymbol = fgetc(fforcopy);
                fputc(cymbol, fout);       
            }

            fclose(fforcopy);
        }
        fclose(fi);

    }else if(strcmp(argv[1], "-cin")){
        int i = 0;
        char **buf = (char **)malloc(N * sizeof(char *));
        if (buf == NULL) return -1;
        for(i = 0;i < N; i++){
                buf[i] = (char *)malloc(MAX_LEN_FILE);
                scanf("%s", buf[i]);
        }
        char cymbol;
        for (i = 0; i < N; i++){
            FILE *fforcopy = fopen(buf[i], "r");
            while ((!feof(fforcopy))){
                cymbol = fgetc(fforcopy);
                fputc(cymbol, fout);       
            }
            fclose(fforcopy);
        }

    }else if(strcmp(argv[1], "-arg")){
        int i = 0;
        int j = 2;
        char **buf = (char **)malloc(N * sizeof(char *));
        if (buf == NULL) return -1;
        for(; i < N; i++, j++){
            buf[i] = (char *)malloc(MAX_LEN_FILE);
            buf[i] = argv[j];
        }
        char cymbol;
        for (i = 0; i < N; i++){
            FILE *fforcopy = fopen(buf[i], "r");
            while ((!feof(fforcopy))){
                cymbol = fgetc(fforcopy);
                fputc(cymbol, fout);       
            }
            fclose(fforcopy);
        }
    }


    fclose(fout);
    return 0;
}