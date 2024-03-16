#include<stdio.h>
void main(){
    int a[5];
    int *p;
    p = a;
    printf("Enter the elements:\n");
    for(int i = 0; i< 5; i++){
        scanf("%d",(p+i));
    }
    printf("\nArray Elements:\n");
    for(int i=0; i<5; i++){
        printf("%d",*(p+i));
    }
    printf("\nArray Elements in reverse order:\n");
    for(int i=4; i>=0; i--){
        printf("%d",*(p+i));
    }
}