//6. Circular Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int main() {
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));

    n1->data=5; n1->next=n2;
    n2->data=10; n2->next=n3;
    n3->data=15; n3->next=n1; 

    struct Node* temp = n1;
    int i=0;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
        i++;
    } while(temp!=n1 && i<6);
    
    return 0;
}
