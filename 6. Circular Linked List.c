//6. Circular Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node *next;
} Node;

Node* circ_push_back(Node *tail, int v);
Node* circ_insert_after(Node *tail, int key, int v);
Node* circ_delete(Node *tail, int key);
void circ_print(Node *tail);
void circ_free(Node *tail);

int main(void){
    Node *tail=NULL;
    tail=circ_push_back(tail,1);
    tail=circ_push_back(tail,3);
    tail=circ_insert_after(tail,1,2);
    circ_print(tail);
    tail=circ_delete(tail,2);
    circ_print(tail);
    circ_free(tail);
    return 0;
}

Node* circ_push_back(Node *tail, int v){
    Node *n=(Node*)malloc(sizeof(Node));
    n->v=v;
    if(!tail){
        n->next=n;
        return n;
    }
    n->next=tail->next;
    tail->next=n;
    return n;
}

Node* circ_insert_after(Node *tail, int key, int v){
    if(!tail) return NULL;
    Node *cur=tail->next;
    do{
        if(cur->v==key){
            Node *n=(Node*)malloc(sizeof(Node));
            n->v=v;
            n->next=cur->next;
            cur->next=n;
            if(cur==tail) tail=n;
            break;
        }
        cur=cur->next;
    }while(cur!=tail->next);
    return tail;
}

Node* circ_delete(Node *tail, int key){
    if(!tail) return NULL;
    Node *prev=tail, *cur=tail->next;
    do{
        if(cur->v==key){
            if(cur==prev){
                free(cur);
                return NULL;
            }
            prev->next=cur->next;
            if(cur==tail) tail=prev;
            free(cur);
            return tail;
        }
        prev=cur; cur=cur->next;
    }while(cur!=tail->next);
    return tail;
}

void circ_print(Node *tail){
    if(!tail){ printf("(bos)\n"); return; }
    Node *cur=tail->next;
    do{
        printf("%d ", cur->v);
        cur=cur->next;
    }while(cur!=tail->next);
    printf("\n");
}

void circ_free(Node *tail){
    if(!tail) return;
    Node *head=tail->next;
    tail->next=NULL;
    while(head){ Node *n=head->next; free(head); head=n; }
}
