#include <stdio.h>
#include <ctype.h>
#include<math.h>
float stk[100];
struct stack{
char stack[20];
int top;
char result[20];
int topr;
}s;
void push(char x){
s.stack[++s.top] = x;
}
int pop(){
return s.stack[s.top--];
}
void pushres(char x){
s.result[++s.topr] = x;
}
int priority(char x){
if (x=='(') return 0;
else if (x=='+' || x=='-') return 1;
else if (x=='/' || x=='*') return 2;
else if (x=='^' || x=='$') return 3;
}
void infixtopost(){
char exp[20], *e, x;
printf("Enter infix expression>> ");
scanf("%s",exp);
e = exp;
while(*e!='\0'){
if (isalnum(*e)) pushres(*e);
else if (*e=='(') push(*e);
else if (*e==')'){
while((x=pop())!='(') pushres(x);
}
else{
while (priority(s.stack[s.top])>=priority(*e)) pushres(pop());
push(*e);
}
e++;
}
while(s.top>=0){
pushres(pop());
}
printf("Postfix expression>> ");
for(int i=0; i<=s.topr; i++){
printf("%c", s.result[i]);
}
s.top=-1;
s.topr=-1;
printf("\n");
}
void postevaluate()
{
        char *e;
        int index=-1;
        float n1,n2,n3;
        e=s.result ;
        while(*e!='\0')
            {
                if(*e>='0' && *e<='9'){
                stk[++index]=*e-'0';
                }
                else
                {
                n1=stk[index--];
                n2=stk[index--];
                switch(*e)
                {
                case '+':n3=n2+n1;
                        break;
                case '-':n3=n2-n1;
                break;
                case '*':n3=n2*n1;
                break;
                case '/':n3=n2/n1;
                break;
                // case '^':n3=pow(n2,n1);
                // break;
                }
                stk[++index]=n3;
                }
            e++;
            }
        printf("%f",stk[index]);
        }
void main()
{
int choice;
s.top= s.topr = -1;
for(;;)
{
printf("\nenter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:infixtopost();
break;
case 2:postevaluate();
break;
default:printf("invalid choice\n");
}
}
}
