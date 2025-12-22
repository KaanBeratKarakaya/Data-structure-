//3. Shunting Yard
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100]; int top=-1;

void push(char x) { stack[++top]=x; }
char pop() { return (top==-1)?-1:stack[top--]; }

int oncelik(char c)
{
    if(c=='(') return 0;
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

int main() {
    char s[]="a+b*(c^d-e)"; char x;
    printf("Sonuc: ");
    
    for(int i=0; i<strlen(s); i++) {
        if(isalnum(s[i])) printf("%c",s[i]);
        else if(s[i]=='(') push(s[i]);
        else if(s[i]==')') {
            while((x=pop())!='(') printf("%c",x);
        } else {
            while(top!=-1 && oncelik(stack[top])>=oncelik(s[i]))
                printf("%c",pop());
            push(s[i]);
        }
    }
    while(top!=-1) printf("%c",pop());
    return 0;
}
