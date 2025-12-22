//5. Double Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next, *prev;
};

void ekle(struct Node** head, int val)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = (*head);
    new_node->prev = NULL;

    if((*head) != NULL)
        (*head)->prev = new_node;

    (*head) = new_node;
}

int main()
{
    struct Node* head = NULL;
    ekle(&head, 10);
    ekle(&head, 20);
    ekle(&head, 30);

    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
