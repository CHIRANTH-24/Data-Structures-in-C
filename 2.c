/*
b) Define a structure called Time containing 3 integer members (Hour, Minute, Second). Develop a menu driven program to perform the following by writing separate function for each operation.
a) Read (T) :To read time b) Display (T):To display time c) update(T):To Update time d) Add (T1, T2) : Add two time variables.
Update function increments the time by one second and returns the new time (if the increment results in 60 seconds, then the second member is set to zero and minute member is incremented by one. If the result is 60 minutes, the minute member is set to zero and the hour member is incremented by one. Finally, when the hour becomes 24, Time should be reset to zero. While adding two time variables, normalize the resultant time value as in the case of update function. Note: Illustrate the use of pointer to pass time variable to different functions.
*/
#include<stdio.h>
#include<stdlib.h>
struct Time{
    int Hour;
    int Minute;
    int Second;
};

void read(struct Time* T){
    printf("\nEnter the time in Hours:Min:Sec format:");
    scanf("%d%d%d",&(T->Hour),&(T->Minute),&(T->Second));
}
void display(struct Time* T){
    printf("\nTime in H:M:S is %d : %d : %d",T->Hour,T->Minute,T->Second);
}
void update(struct Time* T){
    T -> Second++;
    if(T -> Second > 59) {T ->Minute++; T-> Second = 0;}
    if(T -> Minute > 59) {T ->Hour++; T-> Minute = 0;}
    if(T -> Hour >= 24) {T->Hour = T -> Minute = T ->Second = 0;}
    printf("\nUpdated time\t");
     
}
void add(struct Time* T1, struct Time* T2,struct Time* T3){
    T3-> Hour = T1 ->Hour + T2 -> Hour;
    T3-> Minute = T1 ->Minute + T2 -> Minute;
    T3-> Second = T1 ->Second + T2 -> Second;
    if(T3 -> Second > 59) {T3 ->Minute++; T3-> Second = T3-> Second -60;}
    if(T3 -> Minute > 59) {T3 ->Hour++; T3-> Minute = T3-> Minute - 60;}
    if(T3 -> Hour >= 24) {T3->Hour = T3 -> Minute = T3 ->Second = 0;}
}
void main(){
    int choice;
    struct Time T,T1,T2,T3;
    printf("Menu\n1.Read\n2.Display\n3.Update\n4.Add\n5.Exit");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: read(&T);break;
            case 2: display(&T);break;
            case 3: update(&T);display(&T);break;
            case 4: printf("\nEnter time T1:");read(&T1);printf("\nEnter time T2:");read(&T2);add(&T1,&T2,&T3);display(&T3);break;
            case 5: printf("\nThank You\n");exit(0);
            default: printf("\nInvalid Choice\n");
        }
    }
    while(choice);
}
