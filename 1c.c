#include<stdio.h>
void Read(int *p, int n){
    printf("\nEnter the elements:");
    for(int i=0; i<n; i++){
        scanf("%d",(p+i));
    }
}
void Display(int *p, int n){
    for(int i=0; i<n; i++){
        printf("%d\t",*(p+i));
    }
    printf("\n");
}
void Reverse(int *p, int n){
    int temp;
    for(int i=0; i<= n/2 ; i++){
        temp = *(p+i);
        *(p+i) = *(p+n-i-1);
        *(p+n-i-1) = temp; 
    }
}
void main(){
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int a[n];
    int *p;
    p = a;
    Read(p,n);
    Display(p,n);
    Reverse(p,n);
    Display(p,n);
}