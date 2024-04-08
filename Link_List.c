//
// Created by pyu on 2024/4/8.
//

#include "Link_List.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;
//初始化单链表
Node *InitList() {
    Node *L = (Node *) malloc(sizeof(Node));
    if (!L) {
        return NULL;
    }
    L->next = NULL;
    L->data = 0;
    return L;
}
//在单链表后面插入一个元素e
int InsertList(Node *L, int e) {
    Node *LNode = (Node *) malloc(sizeof(Node));
    if (!LNode) {
        return 0;
    }
    while (L->next) L = L->next;
    L->next = LNode;
    LNode->data = e;
    LNode->next = NULL;
    return 1;
}
//删除单链表中元素值为e的节点
int DeleteList(Node *L, int e) {
    while (L->next){
        if(L->next->data == e){
            Node *p = L->next;
            L->next = p->next;
            free(p);
            return 1;
        }
        L = L->next;
    }
    return 0;
}
//查找一个元素的位置
int SearchList(Node *L, int e){
    int index = 0;
    while (L){
        if(L->data == e) return index;
        index++;
        L = L->next;
    }
    return 0;
}

//销毁单链表
int DestroyList(Node *L){
    if(L->next) DestroyList(L->next);;
    //printf("已经释放节点%d\n",L->data);
    free(L);
    return 1;
}

//打印单链表
int printList(Node *L) {
    if (L == NULL) {
        return 0;
    }
    //跳过头节点
    L = L->next;
    while (L) {
        printf("%d  ", L->data);
        L = L->next;
    }
    printf("\n");
    return 1;
}


int main() {
    Node *L = InitList();
    InsertList(L, 5);
    InsertList(L, 6);
    InsertList(L, 2);
    InsertList(L, 8);
    InsertList(L, 7);
    InsertList(L, 10);
    InsertList(L, 4);
    InsertList(L, 9);
    DeleteList(L,6);
    printf("查找到元素 %d 的位置为 %d\n",7, SearchList(L,7));
    //DeleteList(L,5);
    printList(L);
    DestroyList(L);
    return 0;
}

