#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

struct Employee{
    unsigned int ID;
    char NAME[20];
    char SURNAME[30];
    float SALARY;
};

int quantity_of_people(FILE *file){
    int count = 0;
    char cymbol;
    while ((cymbol = fgetc(file)) != EOF){
        if (cymbol == '\n'){
            count++;
            //++count;
        }
    }
    fseek(file, 0, SEEK_SET);
}

void read_file(FILE *file, struct Employee *employee, int q){
    int i = 0;
    for (; i < q; i++){
        if (fscanf(file, "%d %s %s %f \n", employee[i].ID, employee[i].NAME, employee[i].SURNAME, employee[i].SALARY) == 4){
            if(isdigit(employee[i].ID) && isdigit(employee[i].SALARY)){
                //??????????
            }
        }else{
            //?????????
        }
    }
    return;
}

void case_a(struct Employee *employee, int q){
    struct Employee buf;
    int i = 0;
    for (; i < q; i++)
}

int main(int argc, char *argv[]){
    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL){
        printf("Wrong filepath.\n");
        return 1;
    }
    FILE *fout = fopen("3.3_out", "w");
    if (fout == NULL){
        printf("Wrong filepath.\n");
        return 1;
    }
    int q = quantity_of_people(fin);
    struct Employee *employee = (struct Employee*)malloc(q * sizeof(struct Employee));
    read_file(fin, employee, q);
    if (argv[2][0] == '-' || argv[2][0] == '/'){
        if (argv[2][1] == 'a'){

        }else if (argv[2][1] == 'd'){

        }else {
            printf("Wrong flag input./n");
        }
    }else{
        printf("Wrong flag input.\n");
    }

    fclose(fin);
    fclose(fout);
    free(employee);
}

