/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 27 FEBRUARY 2022
    QUESTION 3(b), C PROGRAM WITH A FILE SEARCH UTILITY FUNCTION 
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
#define M 128
int j = 1;

struct node *newNode;
struct node *root;

// FUNCTION DECLARATIONS :
void insert();
struct node *create();
void construct();
struct node *search(struct node *root, char word[N]);
void inorder(struct node *root);

struct node
{   char data[N];
    int n;
    int o;
    struct node *left;
    struct node *right;
};

// MAIN FUNCTION :
void main()
{
    char word[N];

    struct node *fnode;

    construct();
    printf(" This program extracts each word from a text file and saves it to a BST \n");
    printf(" Enter a word you want to search in the file : ");
    scanf("%s",&word[N]);
    fnode = search(root, word);

    printf(" The number of times this word occurred is %d and the line numbers are %d", root->o, root->n);
    return;
}

// CREATE NODE FUNCTION :
struct node *create(struct node *p, char *token)
{
    p = (struct node *)malloc(sizeof(struct node));
    p->n = j;
    p->o = 1;
    strcpy(p->data, token);
    p->left = p->right = NULL;
    return p;
}

// BST CONSTRUCT FUNCTION :
void construct()
{
    char line[N][M];

    FILE *file;
    file = fopen("C://Cp/M_Satyasaiteja/M_Satyasaiteja_3(b)/file.txt", "r");

    if (file == NULL)
    {
        printf(" Error!");
        exit(1);
    }

    while(fgets(line[j], M , file))
    {
        char *token = strtok(line[j], " ");
        root = create(root, token);

        while (token != NULL)
        {
            printf(" %s\n", token);
            token = strtok(NULL, " ");
            newNode = create(newNode, token);
            insert(root, newNode);
        };

        line[j][strlen(line[j]) - 1] = '\0';
        j++;
    };
    
    fclose(file);

}

// SEARCH FUNCTION :
struct node *search(struct node *root, char word[N])
{
    if (root == NULL)
    { printf("\n %s, NOT FOUND! \n", word[N]); }

    if (root->data == word)
    { printf("\n MATCH FOUND! \n");
      return root;
    }
    else if (word < root->data)
    {   return search(root->left, word); }
    else
    {   return search(root->right, word); }

}

// BST INSERT FUNCTION :
void insert(struct node *root, struct node * newNode)
{
    struct node *temp, *parent;
    temp = root;
    while (temp != NULL)
    {
        parent = temp;
        int c1 = strcmp(temp->data, newNode->data);
        if(c1<0)
        {  temp = temp->left; }
        else if(c1>0)
        {  temp = temp->right; }
    }

    int c2 = strcmp(parent->data, newNode->data);

    if(c2<0)
    { parent->left = newNode; }
    else if(c2>0)
    { parent->right = newNode; }

}

// INORDER TRAVERSAL
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %s -> ", root->data);
        inorder(root->right);
    }
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

// Struct to represent a node in the BST
typedef struct Node 
{
  char word[MAX_WORD_LEN + 1]; // Word stored in the node
  int count; // Number of occurrences of the word in the text file
  struct LineNumberNode* lineNumbers; // Linked list to store line numbers where the word appears
  struct Node* left; // Pointer to left child
  struct Node* right; // Pointer to right child
} Node;

// Struct to represent a node in the linked list of line numbers
typedef struct LineNumberNode 
{
  int lineNumber; // Line number where the word appears
  int count; // Number of occurrences of the word in this line number
  struct LineNumberNode* next; // Pointer to the next node in the linked list
} LineNumberNode;

// Function prototypes
Node* insert(Node* root, char* word, int lineNumber);
void search(Node* root, char* word);
LineNumberNode* insertLineNumber(LineNumberNode* head, int lineNumber);
void freeTree(Node* root);

int main() {
  // Open the text file for reading
  FILE* fp = fopen("file.txt", "r");
  if (fp == NULL) {
    perror("Error opening text file");
    return 1;
  }

  char word[MAX_WORD_LEN + 1];
  int lineNumber = 1;
  Node* root = NULL; // Initialize root of BST to NULL

  // Read the text file word by word, insert each word into the BST, and store the line number
  while (fscanf(fp, "%s", word) == 1) {
    root = insert(root, word, lineNumber);
    if (getc(fp) == '\n') {
      // Increment the line number if we reach a new line
      lineNumber++;
    }
  }

  // Close the text file
  fclose(fp);

  // Prompt the user to enter a word to search for
  printf("Enter a word to search for: ");
  scanf("%s", word);

  // Search for the word in the BST and print the number of occurrences and line numbers where it appears
  search(root, word);

  // Free the memory allocated for the BST
  freeTree(root);

  return 0;
}

// Function to insert a word into the BST
Node* insert(Node* root, char* word, int lineNumber) {
  if (root == NULL) {
    // Create a new node if the BST is empty
    root = (Node*)malloc(sizeof(Node));
    strcpy(root->word, word);
    root->count = 1;
    root->lineNumbers = insertLineNumber(root->lineNumbers, lineNumber);
    root->left = NULL;
    root->right = NULL;
  } else if (strcmp(word, root->word) < 0) {
