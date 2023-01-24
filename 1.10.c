#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIAP_VAL 10
#define MIN_DIAP_VAL -10

#define MAX_DIAP_SIZE 10
#define MIN_DIAP_SIZE 1


struct Matrix{
    int **matrix;
    int row;
    int col;
    bool stat;
};

struct Matrix generate_matrix(int row, int col, bool* ){
    struct Matrix mat;
    int **matrix = (int **)malloc(row * sizeof(int *));
    if (!matrix) {
        mat.stat = 1;
        return mat;
    }
    int i = 0;
    for(;i < row; i++){
        matrix[i] = (int *)malloc(col * sizeof(int));
        if(!matrix[i]){
            //free
            mat.stat = 1;
            return mat;
        }
        int j = 0;
        for(;j < col; j++){
            matrix[i][j] = rand() % (MAX_DIAP_VAL - MIN_DIAP_VAL + 1) + MIN_DIAP_VAL;
        }
    }
    mat.matrix = matrix;
    mat.row = row;
    mat.col = col;
    mat.stat = 0;
    return mat;

}

/*struct Matrix generate_single_matrix(int row, int col){
    int **matrix = (int **)malloc(row * sizeof(int *));
    int i = 0;
    for(;i < row; i++){
        matrix[i] = (int *)malloc(col * sizeof(int));
        int j = 0;
        for(;j < col; j++){
            matrix[i][j] = 0;
            if(i == j) matrix[i][i] = 1;
        }
    }
    struct Matrix mat;
    mat.matrix = matrix;
    mat.row = row;
    mat.col = col;
    return mat;

}*/

struct Matrix mult_matrix(struct Matrix mat1, struct Matrix mat2){
    struct Matrix res;
    if (mat1.col != mat2.row){
        res.matrix = NULL;
        return res;
    }
    int res_row = mat1.row;
    int res_col = mat2.col;
    res.matrix = (int **)malloc(res_row * sizeof(int *));
    int i = 0;
    for(;i < res_row; i++){
        res.matrix[i] = (int*)malloc(res_col * sizeof(int));
        int j = 0;
        for(;j < res_col; j++){
            res.matrix[i][j] = 0;
            int k = 0;
            for(;k < mat1.col; k++){
                res.matrix[i][j] += mat1.matrix[i][k] * mat2.matrix[k][j];
            }
        }
    }
    res.col = res_col;
    res.row = res_row;
    return res;
}

void printMat(struct Matrix m){
    int i,j;
    for(i = 0; i < m.row; i++){
        for(j = 0; j < m.col; j++){
            printf("%d ", m.matrix[i][j]);
        }
        printf("\n ");
    }
    printf("--------------------------\n");
}

void freeMatr(struct Matrix m){
    for (int i = 0; i < m.row;i++){
        free(m.matrix[i]);
    }
    free(m.matrix);
}

void GetMatr(struct Matrix mat, int i, int j, int **p){
    int ki, kj, di, dj;
    di = 0;
    int m = mat.col;
    for(ki = 0; ki < m - 1; ki++){
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj < m - 1; kj++){
            if (kj == j) dj = 1;
            p[ki][kj] = mat.matrix[ki + di][kj + dj];
        }
    }
}

int det(struct Matrix mat){
    int m = mat.row;
    if (mat.col != mat.row){
        printf("The matrix isn't square\n");
        return 0;
    }
    int i = 0, j = 0, k = 1, d = 0, n = m - 1;
    if (m == 1){
        d = mat.matrix[0][0];
        return d;
    }
    if (m == 2){
        d = mat.matrix[0][0] * mat.matrix[1][1] - (mat.matrix[1][0] * mat.matrix[0][1]);
        return d;
    }
    struct Matrix pe;
    int **p;
    p = malloc(sizeof(int*) * m);
    pe.matrix = p;
    pe.row = pe.col = n;
    for (i = 0; i < m; i++){
        p[i] = malloc(sizeof(int) * m);
    }
    if (m > 2){
        for(i = 0; i < m; i++){
            GetMatr(mat, i, 0, p);
            d = d +  k * mat.matrix[i][0] * det(pe);
            k = -k;
        }
    }
    return d;
}

int main(){
    srand(time(NULL));
    int row = rand() % (MAX_DIAP_SIZE - MIN_DIAP_SIZE + 1) + MIN_DIAP_SIZE;
    int col = rand() % (MAX_DIAP_SIZE - MIN_DIAP_SIZE + 1) + MIN_DIAP_SIZE;
    if (row>10 || row<1 || col>10 || col<1){
        printf("Wrong input\n");
        return -1;
    }
    struct Matrix a = generate_matrix(row, col);
    struct Matrix b = generate_matrix(row, col);
    if (a.stat == 1 || b.stat == 1){
        printf("Problems with memory\n");
        return 1;
    }
    struct Matrix c = mult_matrix(a, b);
    
    printMat(a);
    printMat(b);
    if (c.matrix != NULL){
        printMat(c);
    }else{
        printf("Matrixes can't be multiplied\n");
    }
    int d = det(c);
    printf("%d", d);
    freeMatr(a);
    freeMatr(b);
    freeMatr(c);

    


    return 0;
}