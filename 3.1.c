#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *head;
    int size;
};

struct Array convert(int num, int r, int *buf){
    int i = 0;
    for(;num > 0; i++){
        buf[i] = num ^ ((num >> r) << r);
        num = num >> r;
    }
    struct Array array;
    array.head = buf;
    array.size = i;
    return array;
}

int main(){
    int num;
    int r;
    printf("Enter number:\n");
    while (scanf("%d", &num) == 0){
        printf("Wrong input\n");
        while(getchar()!='\n');
    }
    printf("Enter r:\n");
    while (scanf("%d", &r) == 0 || r < 1 || r > 5){
        printf("Wrong input\n");
        while(getchar()!='\n');
    }
    int *buf = malloc(sizeof(int) * BUFSIZ);
    if (buf == NULL) {
        printf("Problems with memory allocation\n");
        return 1;
    }
    printf("%d in %d = ", num, 1 << r);
    struct Array array = convert(num, r, buf);
    int i = array.size - 1;
    for (; i >= 0; i--){
        printf("%d", array.head[i]);

    }
    printf("\n");
    free(buf);

}