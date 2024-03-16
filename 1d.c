// Not able to pass the 2D array as a parameter
#include<stdio.h>
void Read(int *p[], int n, int m){
    printf("\nEnter the elements:");
    for(int i=0; i<n; i++){
        for(int  j=0; j<m; j++){
        scanf("%d",*((p+i)+j));
    }
}
}
void Display(int *p[], int n, int m){
    for(int i=0; i<n; i++){
        for(int  j=0; j<m; j++){
        printf("%d\t",(*p+i+j));
    }
    printf("\n");
}
printf("\n");
}
/*void Reverse(int *p, int n){
    int temp;
    for(int i=0; i<= n/2 ; i++){
        temp = *(p+i);
        *(p+i) = *(p+n-i-1);
        *(p+n-i-1) = temp; 
    }
}*/
void main(){
    int n,m;
    printf("Enter the size of array:\n");
    scanf("%d%d",&n,&m);
    int a[n][m];
    int *p[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            p[i][j] = &a[i][j];
        }
    }
    Read(p,n,m);
    Display(p,n,m);
    //Reverse(p,n);
    Display(p,n,m);
}