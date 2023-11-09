/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 25 FEBRUARY 2022
    QUESTION 4, C PROGRAM TO IMPLEMENT A STACK USING AN ARRAY
*/

#include <stdio.h>
#include <stdlib.h>
#define M 10

int stack[M];
int i = -1;

// ISEMPTYSTACK FUNCTION :

int IsEmptyStack() {
    printf(" Could not delete data, Stack is already empty.\n");
    return 0;
}

// ISFULLSTACK FUNCTION :

int IsFullStack() {
    printf(" Could not insert data, Stack Overflowed.\n");
    return 0;
}

// PUSH FUNCTION :

void push(int data) {
    if(i >= M - 1)
    {   IsFullStack(); }
    else { 
    stack[i++] = data;
    printf("\n Data is pushed successfully \n");
    }
    return;
}

// POP FUNCTION :

int pop() { 
    if(i == -1)
        IsEmptyStack();
    else
    return stack[i--];
}

// TOP FUNCTION :

int top()
{  return stack[i-1];                                                          // Here we are seeing stack[i-1] because when we pushed an element
}                                                                              // in push function, value of "i" got incremented

// SIZE FUNCTION : 

int Size()
{
    int size;
    size = i+1;                                                                // Here size is equal to i+1 because we started it from i = -1 and
    return size;                                                               // also the value of "i" got incremented in push function previously
}

// MAIN FUNCTION :

int main()
{
    int a, data;

    while (1)
    {   printf("\n 1) Insert\n 2) Remove\n 3) See top element\n 4) See size of stack\n 5) Exit\n");
        printf("\n Enter any number between 1 to 5 to access the following options : ");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            printf(" Enter the number you want to insert in the stack : ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            printf("\n Top element %d is removed \n", stack[i]);
            break;

        case 3:
            top();
            printf("\n Top element is : %d \n", top());
            break;

        case 4:
            Size();
            printf("\n The number of elements in the stack is : %d \n", Size());
            break;

        case 5:
            printf("\n PROGRAM TERMINATED \n");
            return 0;
            break;

        default:
            printf("\n Please enter a valid input \n");
            break;
        }
    }
}
