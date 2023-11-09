#include<stdio.h>
#include<stdlib.h>
int n;

// NODE STRUCTURE :
struct node
{
    int val;
    struct node *next;
    struct node *prev;
};

// CREATE NODE :
struct node *create_node(struct node *p)
{
    p = (struct node *)malloc(sizeof(struct node));
    p->val = 0;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

// MAIN :
void main()
{
    struct node *temp;
    struct node *head;

    temp = create_node(temp);
    head = temp;

    printf("Enter the number of values (n) : ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf(" Index (%d) : ", i);
        scanf("%d",&temp->val);
        temp->next = create_node(temp->next);
        temp->prev = temp;
        temp = temp->next;
    }

    printf("\n");

    temp = head;
    for (int i = 0; i < n; i++)
    {
        printf(" |%d|%d|%d| <==>",temp->prev,temp->val,temp->next);
        temp = temp->next;
    }

    return;
}
