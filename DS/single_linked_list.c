#include<stdio.h>
#include<stdlib.h>
int n;

// LINKED LIST NODE :
struct node
{
    int val;
    struct node *next;
};

// CREATE NODE :
struct node *create_node(struct node *p)
{
    p = (struct node*)malloc(sizeof(struct node));
    p->val = 0;
    p->next = NULL;

    return p;
}

// USER INPUT :
void main()
{
    int n;
    struct node *head;
    struct node *temp;

    printf(" Enter the number of values (n) : ");
    scanf("%d",&n);

    temp = create_node(temp);
    head = temp;

    for (int i = 0; i < n; i++)
    {
        printf(" Index (%d) : ", i);
        scanf("%d",&temp->val);
        temp->next = create_node(temp->next);
        temp = temp->next;
    }

    printf("\n");

    temp = head;
    for (int i = 0; i < n; i++)
    {
        printf(" |%d|%d| -->", temp->val, &temp->next);
        temp = temp->next;
    }

    return;
}
