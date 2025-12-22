//5. Double Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node *prev, *next;
} Node;

Node* push_back(Node *head, int v);
Node* insert_after(Node *head, int key, int v);
Node* delete_value(Node *head, int key);
void print_forward(Node *head);
void free_list(Node *head);

int main(void){
    Node *h=NULL;
    h=push_back(h,1);
    h=push_back(h,3);
    h=insert_after(h,1,2);
    h=delete_value(h,3);
    print_forward(h);
    free_list(h);
    return 0;
}

Node* push_back(Node *head, int v){
    Node *n=(Node*)malloc(sizeof(Node));
    n->v=v; n->next=NULL; n->prev=NULL;
    if(!head) return n;
    Node *t=head;
    while(t->next) t=t->next;
    t->next=n; n->prev=t;
    return head;
}

Node* insert_after(Node *head, int key, int v){
    for(Node *t=head; t; t=t->next){
        if(t->v==key){
            Node *n=(Node*)malloc(sizeof(Node));
            n->v=v;
            n->next=t->next;
            n->prev=t;
            if(t->next) t->next->prev=n;
            t->next=n;
            break;
        }
    }
    return head;
}

Node* delete_value(Node *head, int key){
    Node *t=head;
    while(t && t->v!=key) t=t->next;
    if(!t) return head;
    if(t->prev) t->prev->next=t->next;
    else head=t->next;
    if(t->next) t->next->prev=t->prev;
    free(t);
    return head;
}

void print_forward(Node *head){
    for(Node *t=head; t; t=t->next) printf("%d ", t->v);
    printf("\n");
}

void free_list(Node *head){
    while(head){ Node *n=head->next; free(head); head=n; }
}
