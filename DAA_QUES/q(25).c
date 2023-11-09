#include<stdio.h>
#include<string.h>
#define N 30

char f[N], w;
char *ptr;

void occ(int n)
{
    for (int i = 0; i < n; i++)
    {   
        while(f[i] == *ptr)
        {
            for (int j = i; j < n; j++)
            {
                f[j] = f[j + 1];
            }
        }
    }
}

void main()
{   
    int n;
    

    printf("Program that will read a line and delete a all occurrences of a particular word from it\n");
    printf("Enter the line : ");
    scanf("%[^\n]",&f);

    printf("Enter the letter you want to delete : ");
    scanf(" %c",&w);

    n = strlen(f);
    ptr = &w;

    occ(n);

    printf("%s",f);
}