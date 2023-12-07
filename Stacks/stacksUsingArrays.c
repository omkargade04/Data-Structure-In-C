#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int push(struct Stack *ptr, int data)
{
    {
        if (ptr->top == ptr->size - 1)
        {
            printf("Stack Overflow \n");
            return 0;
        }
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

int pop(struct Stack *ptr)
{

    if (ptr->top < 0)
    {
        printf("Stack Underflow \n");
        return -1;
    }
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int getTop(struct Stack *ptr)
{
    int arrInd = ptr->top;
    if (arrInd < 0)
    {
        printf("Stack Underflow \n");
        return 0;
    }
    int val = ptr->arr[arrInd];
    return val;
}

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // struct Stack s;
    // s.size = 5;
    // s.top = -1;
    // s.arr = (int*)malloc(s.size * sizeof(int));

    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));

    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 5);
    push(s, 5);
    push(s, 5);
    push(s, 5);
    push(s, 5);
    int val = getTop(s);
    printf("%d \n", val);

    if (isEmpty(s))
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack is not empty");
    }

    return 0;
}