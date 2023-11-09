/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 4 JUNE 2022
    QUESTION 5(i), A FUNCTION THAT TAKES DISTINCT CHARACTERS IN A TEXT FILE AND CALCULATES THEIR FREQUENCY 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 30
#define N 128

int F[M];
char S[M][N];
char X[N];
int i, j, n;

// DRIVER CODE :
int main()
{
    char S[M][N];
    char fname[N];
    FILE *file = NULL;
    int e = 0;
    int tot = 0;

    printf("\n\n Read the file and store the lines into an array : \n");
    printf("------------------------------------------------------\n");
    printf(" Input the filename to be opened : ");
    scanf("%s",fname);

    file = fopen(fname, "r");

    while(fgets(S[e], N, file))
    {
        S[e][strlen(S[e]) - 1] = '\0';
        e++;
    }

    tot = e;

    if (file == NULL)
    {
        printf(" Error!");
        exit(1);
    }

    printf("\n The content in '%s' file is :\n\n",fname);
    for (i = 0; i < tot; ++i)
    {
        printf(" %s\n", S[i]);
    }

    for (i = 0; i < tot; i++)
    {
        strcat(X, S[i]);
    }


    int g = strlen(X);

    // This loop removes the characters that occur more than once and stores their frequency in F[]
    for (i = 0; i < g; i++)
    {
        if (X[i] != ' ')
        {
            F[i] = 1;
            for (j = i + 1; j < g; j++)
            {
                if (X[i] == X[j] && X[i] != ' ' && X[i] != '\0')
                {
                    F[i]++;
                    X[j] = ' ';
                }
            }
        }
    }

    // This loop removes all the spaces and symbols in the sentence and brings all distinct characters together
    for (i = 0; i < g; i++)
    {
        while (X[i] == ' ' || X[i] == '.' || X[i] == ',')
        {
            for (j = i; j < g; j++)
            {
                X[j] = X[j + 1];
                F[j] = F[j + 1];
            }
        }
    }

    g = strlen(X);

    printf("\n Our final array that we convert to huffman code is : %s", X);
    printf("\n Now the frequency of each character is : ");

    for (i = 0; i < g; i++)
    {
        printf("\n %c is (%d) ", X[i], F[i]);
    }

    return 0;
}