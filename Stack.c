#include<stdio.h>
struct stack{
    int top;
    int* stk;
    int size;
}S;
// struct stack typedef Stack;
void push(int ele){
    // if(S.size - 1 > S.top ){
        S.top++;
        *(S.stk + S.top) = ele;
    }

void main(){
    int ele;
    S.size = 10;
    S.top = -1;
    printf("Enter the ele:");
    scanf("%d",&ele);
    push(ele);
    for(int i=S.top; i>= 0; i--){
        printf("Stack is:");
        printf("%d",*(S.stk + i));
    }
}