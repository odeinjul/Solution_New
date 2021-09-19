#include <stdio.h>
typedef int ElemType;
typedef int Status;
typedef struct node{
    ElemType data;
    struct node;
}*Link, *Position;
typedef struct {
    Link head, tail;
    int len
}LinkList;
Position LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType)){
    ;
}
void helper(LinkList L, ElemType del){
    while(LocateElem(L, del, cmp))
        ;
}
void deleted(LinkList L, Link &p){
    front = Prior(L, p);
}
void cmp(ElemType a, ElemType b){
    return a == b;
}
int main(){
    return 0;
}