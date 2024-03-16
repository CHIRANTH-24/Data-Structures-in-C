//Create two pointer called PS1 and PS2 to two strings, Read the contents
// using pointers and also write a function StrCat (PS1, PS2) which
// concatenates second string to the end of first string using pointers PS1
// and PS2.
//Segmentation Fault
#include<stdio.h>
void StrCat(char* PS1, char* PS2){
    while(*PS2 != '\0'){
        PS1++;
        while (*PS1 !='\0')
        {
            *PS1 = *PS2;
            PS1++;
            PS2++;
        }
        
    }
}
void main(){
    char *PS1;
    char *PS2;
    printf("Enter the String S1:");
    scanf("%s",PS1);
    printf("Enter the String S2:");
    scanf("%s",PS2);
    StrCat(PS1,PS2);
    printf("%s",PS1);
}