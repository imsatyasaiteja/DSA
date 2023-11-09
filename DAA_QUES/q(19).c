/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 22 FEBRUARY 2022
    QUESTION 3(a), C PROGRAM TO CREATE, INSERT, SEARCH, DELETE NODES IN A BST
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// FUNCTION DECLARATIONS :
struct node *search(struct node *node, int x);
struct node *insert(struct node *node, int x);
struct node *delete (struct node *root, int x);
void inorder(struct node *root);

// Main function :
void main()
{
    int a, x;
    struct node *root = NULL;
    printf("\n 1) Insert an element into BST\n 2) Delete an element from the BST\n 3) Search an element in BST\n 4) Exit\n");
    while (1)
    {
        printf("\n Enter your choice : ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf(" Enter the value you want to insert : ");
            scanf("%d",&x);
            root = insert(root, x);
            printf("\n");
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf(" Enter the value you want to delete : ");
            scanf("%d",&x);
            root = delete (root, x);
            printf("\n");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf(" Enter the value to search : ");
            scanf("%d",&x);
            search(root, x);
            break;
        case 4:
            printf("\n PROGRAM TERMINATED \n");
            exit(0);
            break;
        default:
            printf("\n Please enter a valid input \n");
            break;
        }
    }
}

// CREATE FUNCTION :
struct node *create(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// INORDER TRAVERSAL FUNCTION :
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d -> ", root->data);
        inorder(root->right);
    }
}

// INSERT FUNCTION :
struct node *insert(struct node *node, int x)
{
    if(node == NULL)
        return create(x);

    if(x < node->data)
        node->left = insert(node->left, x);
    else 
        node->right = insert(node->right, x);
    return node;
}

// SEARCH FUNCTION :
struct node *search(struct node *node, int x)
{
    if(node == NULL)
        printf("\n %d, NOT FOUND! \n",x);
    else if(node->data == x)
    {
        printf("\n MATCH FOUND! \n");
    }
    else if(x < node->data)
    {
        search(node->left, x);
    }
    else if(x > node->data)
    {
        search(node->right, x);
    }
    return 0;
}

// MINIMUM VALUE FUNCTION :
struct node *minValue(struct node *node)
{
    struct node *value = node;

    while (value && value->left != NULL)
        value = value->left;

    return value;
}

// DELETING A NODE :
struct node *delete(struct node *root, int x)
{   
    // If tree is empty : 
    if (root == NULL)
        return root;

    // Finding the node to be deleted :
    if (x < root->data)
        root->left = delete(root->left, x);
    else if (x > root->data)
        root->right = delete(root->right, x);
    else
    {   // If the node has only one child or no child :
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children :
        struct node *temp = minValue(root->right);

        root->data = temp->data;

        root->right = delete(root->right, temp->data);
    }
    return root;
}

