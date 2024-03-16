#include<stdio.h>
void read(){
    printf("\nEnter the size of array: ");
    scanf("%d",&size);
    array = (int*)malloc(size * sizeof(int));
    printf("\nEnter the elements:");
    for(int i = 0; i < )
}
void main(){
    int choice;int size;
    int *array;
    printf("Menu\n1.Read\n2.Insert by position\n3.Delete by key\n4.Search by position\n5.Reverse the contents\n6.Exit");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: read(&T);break;
            case 2: display(&T);break;
            case 3: update(&T);display(&T);break;
            case 4: printf("\nEnter time T1:");read(&T1);printf("\nEnter time T2:");read(&T2);add(&T1,&T2,&T3);display(&T3);break;
            case 5: break;
            case 6: printf("\nThank You\n");exit(0);
            default: printf("\nInvalid Choice\n");
        }
    }
    while(choice);
}
