#include<stdio.h>
void main(){
    int x;
    int *p1 = &x;
    int **p2 = &p1;
    int ***p3 = &p2;
    printf("Enter the value:");
    scanf("%d",&x);
    printf("\np1 points to : %d",*p1);
    printf("\np2 points to : %d",**p2);
    printf("\np3 points to : %d\n",***p3);
}

