#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct {
    int *data;
    int length;
    int size;
}Linear_Table;

int init_Linear_table(Linear_Table *L , int size){
    L->data = (int*)malloc(size * sizeof(int));
    L->size = size;
    L->length = 0;
    for(int i = 0 ; i < size ; i++) {
        L->data[i] = 0;
    }
    return 1;
}

void print_Linear_Table(Linear_Table L){
    printf("当前线性表的数据为:");
    for(int i = 0 ; i < L.length ; i++){
        printf("%d  ", L.data[i]);
    }
    printf("\n");
    printf("长度为:%d\n", L.length);
    printf("线性表大小为:%d\n",L.size);
}

void Increase_Size(Linear_Table *L, int size){
    int *new_data = (int*)malloc((L->size+size) * sizeof(int));
    int i;
    for(i = 0 ; i < L->size ; i++){
        new_data[i] = L->data[i];
    }
    for(;i < (L->size+size) ; i++){
        new_data[i] = 0;
    }
    free(L->data);
    L->data = new_data;
    L->size+=size;
}


int main(){
    Linear_Table L;
    init_Linear_table(&L,10);
    Increase_Size(&L,20);
    print_Linear_Table(L);
}

