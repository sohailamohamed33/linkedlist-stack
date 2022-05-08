#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct node *next;
}node;
typedef struct
{
   node *top;
} stack;
stack *initialize ()
{
    stack*s=malloc(sizeof(stack));
    s->top=NULL;
}
node *newnode(int x)
{
    node *n=malloc(sizeof(node));
    n->data=x;
    n->next=NULL;
    return n;
}
int isempty (stack *s)
{
    if(s->top==NULL)
        return 1;
    else
        return 0;
}
void push(stack*s,int x)
{
    node *n=newnode(x);
    n->next=s->top;
    s->top=n;
}
int pop(stack*s)
{
    int x=s->top->data;
    node*temp=s->top;
    s->top= temp->next;
    free(temp);
    return x;
}

int main()
{
    stack*s=initialize();
    push(s,7);
    push(s,9);
    push(s,5);
    while (!isempty(s))
    {
        int y=pop(s);
        printf("%d",y);
    }
    return 0;
}
