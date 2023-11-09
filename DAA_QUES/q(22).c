#include<stdio.h>
int f[] = {3, 6, 3, 4, 6, 1, 8, 9, 6, 9, 9, 6, 4};

void occ(int n)
{
    int k[n];
    for (int i = 0; i < n; i++)
    {
        k[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        k[f[i]]++;
    }


    for (int i = 0; i < n; i++)
    {
        if(k[i] != '\0')
        {
            printf(" %d\t -> \t%d\n",i,k[i]);
        }
    }

    

    return;
}

void main()
{
    int n = sizeof(f)/4;

    printf("Program to find number of occurences of each element in an array\n");

    printf("Distinct -> Occurence\n");
    occ(n);

    return;
}