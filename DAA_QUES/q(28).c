#include<stdio.h>
#include<stdlib.h>
#define L 10

int main()
{
    char *f;
    printf("Program that creates an array of size 10 using malloc function\n");
    f = (char*)malloc(L * sizeof(char));

    printf("Enter the characters in array : \n");
    for (int i = 0; i < L; i++)
    {
        printf("f[%d] : ",i);
        scanf(" %c",&f[i]);
    }
    printf("The array is : ");
    printf("%s",f);
}