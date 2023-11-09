/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 27 MAY 2022
    QUESTION 1(b), FIND THE LONGEST COMMON SUBSEQUENCE OF TWO STRINGS
*/

#include <stdio.h>
#include <string.h>
#define M 30

int m, n, C[M][M];
char X[M], Y[M], A[M];

// LCS MATRIX FORMATION :
void lcsMatrix(int i, int j)
{
    for (i = 1; i <= m; i++)
    {
        C[i][0] = 0;                                                    // It is zero because, lcs can't be obtained when any one of the strings is empty 
    }

    for (j = 0; j <= n; j++)
    {
        C[0][j] = 0;                                                    
    }

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])                                   // Here X[i-1], Y[j-1] because indexing of strings by default start from 0
            {
                C[i][j] = 1 + C[i - 1][j - 1];                          
            }                                                           

            else                                                        
            {
                if (C[i][j - 1] >= C[i - 1][j])                         
                {
                    C[i][j] = C[i][j - 1];                              
                }
                else
                {
                    C[i][j] = C[i - 1][j];                              
                }
            }
        }
    }

}

// LCS PRINT :
void lcs()
{
    int I = C[m][n];                                   
    char O[I];                                          
    O[I] = '\0';                                        // Indexing starts from 0, so the last value of O is made as NULL

    int i = m, j = n;                                  

    while(i>0 && j>0)
    {
        if(X[i-1] == Y[j-1])                            
        {
            O[I - 1] = X[i - 1];                        // here I-1, i-1 because indexing starts from 0
            i--;
            j--;
            I--;
        }
        else if(C[i-1][j] >= C[i][j-1])
        {
            i--;                                        
        }
        else
        {
            j--;
        }
    }

    printf("\n LCS : %s", O);
}

// MAIN FUNCTION :
void main()
{
    int i, j;
    printf("\n Enter a sequence in the string X : ");
    scanf("%s", &X);
    m = strlen(X);
    printf("\n Enter a sequence in the string Y : ");
    scanf("%s", &Y);
    n = strlen(Y);

    lcsMatrix(m, n);

    printf("\n The Lcs matrix is as follows : \n\n");
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf(" %d", C[i][j]);
        }
        printf("\n");
    }

    lcs();
}
