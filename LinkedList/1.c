#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // if(newNode == NULL){
    //     printf("Memory allocation failed\n");
    //     exit(1); // Exit the program with an error code
    // }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

struct Node *insertAtBeginning(struct Node *head, int data)
{

    struct Node *new_node = createNode(data);

    new_node->next = head;
    head = new_node;

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = head;
    struct Node *new_node = createNode(data);
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return head;
}

struct Node *insertInBetween(struct Node *head, int data, int pos)
{
    struct Node *ptr = head;
    struct Node *new_node = createNode(data);

    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;

    return head;
}

struct Node *deletionAtStart(struct Node *head)
{
    struct Node *temp;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node *deletionAtEnd(struct Node *head)
{
    struct Node *temp;
    struct Node *ptr = head;
    struct Node *curr = head;
    int cnt = 0;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
        cnt++;
    }
    for(int i=1;i<cnt;i++){
        curr = curr -> next;
    }
    temp = ptr -> next;
    curr -> next = NULL;
    free(temp);
    return head;
}

void traversal(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL \n");
}

int main()
{
    struct Node *head = createNode(6);

    traversal(head);
    head = insertAtBeginning(head, 0);
    traversal(head);
    head = insertAtEnd(head, 8);
    traversal(head);
    head = insertAtEnd(head, 14);
    traversal(head);
    head = insertAtEnd(head, 16);
    traversal(head);
    head = insertInBetween(head, 10, 4);
    traversal(head);
    head = insertInBetween(head, 12, 5);
    traversal(head);
    head = deletionAtStart(head);
    traversal(head);
    head = deletionAtEnd(head);
    traversal(head);

    return 0;
}