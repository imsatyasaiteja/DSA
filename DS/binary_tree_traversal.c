#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool x;
int n = 0;

// NODE :
struct node
{
    int val;
    struct node *left;
    struct node *right;
};

struct node *root;
struct node *insert_left(struct node *p);
struct node *insert_right(struct node *p);

// CREATE NODE :
struct node *create_node(struct node *p)
{
    p = (struct node *)malloc(sizeof(struct node));
    p->val = 0;
    p->left = NULL;
    p->right = NULL;

    return p;
}

// INSERT LEFT CHILD :
struct node *insert_left(struct node *p)
{
    p = create_node(p);
    printf(" value : ");
    scanf("%d",&p->val);

    printf(" Does '%d' have left child ? ",p->val);
    scanf("%d",&x);

    if (x == 1)
    {
        p->left = insert_left(p->left);
        n++;
    }

    printf(" Does '%d' have right child ? ",p->val);
    scanf("%d",&x);

    if (x == 1)
    {
        p->right = insert_right(p->right);
        n++;
    }

    return p;
}

// INSERT RIGHT CHILD ;
struct node *insert_right(struct node *p)
{
    p = create_node(p);
    printf(" value : ");
    scanf("%d",&p->val);

    printf(" Does '%d' have left child ? ",p->val);
    scanf("%d",&x);

    if (x == 1)
    {
        p-> left = insert_left(p->left);
        n++;
    }

    printf(" Does '%d' have right child ? ",p->val);
    scanf("%d",&x);

    if (x == 1)
    {
        p->right= insert_right(p->right);
        n++;
    }

    return p;
}

// INORDER :
void inorder(struct node *p)
{   
    if(p->left != NULL)
    {
        inorder(p->left);
        printf(" %d -->",p->val);  
    }

    if (p->left == NULL && p->right != NULL)
    {
        printf(" %d -->",p->val);
    }

    if (p->right != NULL)
    {
        inorder(p->right);
    }

    if(p->left == NULL  && p->right == NULL)
    {
        printf(" %d -->", p->val);
    }

    return;
}

// PRE ORDER :
void preorder(struct node *p)
{
    printf(" %d -->", p->val);

    if (p->left != NULL)
    {
        preorder(p->left);
    }

    if (p->right != NULL)
    {
        preorder(p->right);
    }

    return;
}

// POST ORDER :


// MAIN :
void main()
{
    struct node *p;
    printf("\n TYPE '1' FOR YES AND '0' FOR NO, TO RESPOND ");
    printf("\n ------------------------------------------- \n");

    root = create_node(root);
    printf(" Enter the root value : ");
    scanf("%d",&root->val);

    printf(" Does '%d' have left child ? ",root->val);
    scanf("%d",&x);

    if (x == 1)
    {
        root->left = insert_left(root->left);
        n++;
    }

    printf(" Does '%d' have right child ? ",root->val);
    scanf("%d",&x);

    if (x == 1)
    {
        root->right = insert_right(root->right);
        n++;
    }

    p = root;

    printf("\n Inorder traversal : ");
    inorder(p);
    printf("\n Preorder traversal : ");
    preorder(p);

    return;
}

