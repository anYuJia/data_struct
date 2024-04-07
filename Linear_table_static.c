#include <stdio.h>
#define MAXSIZE 10

typedef struct{
    int data[MAXSIZE];
    int length;
}Linear_table;

int init_Linear_Table(Linear_table *L){
    for(int i = 0 ; i < MAXSIZE ; i++){
        L->data[i] = 0;
    }
    L->length = 0;
    return 1;
};
int print_Linear_Table(Linear_table L){
    printf("当前线性表的值为：");
    for(int i = 0 ; i < L.length ; i++){
        printf("%d  ",L.data[i]);
    }
    printf("\t");
    printf("长度为%2d\n",L.length);
    return 1;
}
int insert_Linear_Table(Linear_table *L, int num, int e){
    if (num > L->length+1){
        printf("插入的位置超出了数组长度！\n");
        return 0;
    }
    if (L->length == MAXSIZE){
        printf("数组已经插满了！\n");
        return 0;
    }
    for (int i = 0 ; i <= L->length ; i++){
        if(i == num - 1){
            for(int j = L->length ; j > i ; j--){
                L->data[j] = L->data[j-1];
            }
            L->data[i] = e;
            L->length++;
            return 1;
        }
    }
    return 0;
}

int delete_Linear_Table(Linear_table *L, int e){
    for (int i = 0 ; i < L->length ; i++) {
        if (e == L->data[i]) {
            for( int j = i ; j < L->length-1 ;j++) {
                L->data[j] = L->data[j+1];
            }
            L->length--;
            return i+1;
        }
    }
    return 0;
}

int main(){
    Linear_table L;
    init_Linear_Table(&L);
    print_Linear_Table(L);
    insert_Linear_Table(&L,1,33);
    print_Linear_Table(L);
    insert_Linear_Table(&L,2,90);
    print_Linear_Table(L);
    insert_Linear_Table(&L,3,5);
    print_Linear_Table(L);
    insert_Linear_Table(&L,4,31);
    print_Linear_Table(L);
    insert_Linear_Table(&L,2,203);
    print_Linear_Table(L);
    int num = delete_Linear_Table(&L,90);
    printf("被删除元素的序号为%d\n",num);
    print_Linear_Table(L);
}