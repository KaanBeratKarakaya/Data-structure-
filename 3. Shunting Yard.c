//3. Shunting Yard
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 512

typedef struct { char x[MAX]; int top; } Stack;
void st_init(Stack *s){ s->top=-1; }
int st_empty(Stack *s){ return s->top<0; }
char st_peek(Stack *s){ return s->x[s->top]; }
void st_push(Stack *s,char v){ s->x[++s->top]=v; }
char st_pop(Stack *s){ return s->x[s->top--]; }

int prec(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}
int right_assoc(char op){ return op=='^'; }

int main(void){
    char in[MAX] = "3+4*(2-1)";
    char out[MAX] = {0};
    Stack ops; st_init(&ops);

    int j=0;
    for(int i=0; in[i]; i++){
        char c=in[i];
        if(isspace((unsigned char)c)) continue;

        if(isdigit((unsigned char)c)){
            out[j++]=c;
            out[j++]=' ';
        } else if(c=='('){
            st_push(&ops,c);
        } else if(c==')'){
            while(!st_empty(&ops) && st_peek(&ops)!='('){
                out[j++]=st_pop(&ops); out[j++]=' ';
            }
            if(!st_empty(&ops) && st_peek(&ops)=='(') st_pop(&ops);
        } else {
            while(!st_empty(&ops) && st_peek(&ops)!='('){
                char t=st_peek(&ops);
                int p1=prec(c), p2=prec(t);
                if(p2>p1 || (p2==p1 && !right_assoc(c))){
                    out[j++]=st_pop(&ops); out[j++]=' ';
                } else break;
            }
            st_push(&ops,c);
        }
    }
    while(!st_empty(&ops)){
        char t=st_pop(&ops);
        if(t!='('){ out[j++]=t; out[j++]=' '; }
    }
    out[j]=0;
    puts(out);
    return 0;
}
