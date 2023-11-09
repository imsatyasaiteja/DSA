#include<stdio.h>
#include<stdlib.h>
int n;

// NODE STRUCTURE :
typedef struct node
{
    int val;
    sll *next;
} sll;

// CREATE NODE :
sll* create_node(sll *p)
{
    p = (sll*)malloc(sizeof(sll));
    p->val = 0;
    p->next = NULL;

    return p;
}

// MAIN :
int main()
{
    printf(" Enter the number of values (n) : ");
    scanf("%d",&n);

    sll *head;
    sll *temp = create_node(temp);
    head = temp;

    
}
