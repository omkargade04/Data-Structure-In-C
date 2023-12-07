#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct  node* next;
};

int isEmpty(struct node* top){
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct node* top){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        return 1;
    }else{
        return 0;
    }
}

struct node* push(struct node* top, int x){
    if(isFull(top)){
        printf("Stack Overfloe \n");
        return top;
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = x;
    new_node -> next = top;
    top = new_node;

    return top;
}

int pop(struct node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow \n");
    }else{
        int val = (*top) -> data;
        struct node* temp = *top;
        *top = (*top) -> next;
        free(temp);
        return val;
    }
}

void traversal(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL \n");
}

int main(){
    struct node* top = NULL;
    top = push(top, 4);
    top = push(top, 2);
    int e = pop(&top);
    printf("Pop : %d\n", e);
    traversal(top);

    return 0;
}