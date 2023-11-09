#include<stdio.h>
#include<string.h>
#define M 30

int m, n, C[M][M];
char X[M], Y[M], A[M];
void lcs(int i,int j);

void main()
{
    int i, j;
    printf("\n Enter a sequence in the string X : ");
    scanf("%s",&X);
    m = strlen(X);
    printf("\n Enter a sequence in the string Y : ");
    scanf("%s", &Y);
    n = strlen(Y);

    lcs(m, n);

    printf("\n The Lcs matrix is as follows : \n\n");
    for (i = 0; i <= m; i++)
    {   for (j = 0; j <= n; j++)
        {
            printf(" %d", C[i][j]);
        }
        printf("\n");
    }
      
}

void lcs(int i,int j)
{
    for (i = 1; i <= m; i++)
    {   C[i][0] = 0; }
    for (j = 0; j <= n; j++)
    {   C[0][j] = 0; }

    for (i = 1; i <= m; i++)
    {    for (j = 1; j <= n; j++)
        {   if (X[i-1] == Y[j-1])                                       // Here X[i-1], Y[j-1] because indices of strings start from 0
            {
                C[i][j] = 1 + C[i-1][j-1] ;
            }
            else
            {   if(C[i][j-1] >= C[i-1][j])
                {
                    C[i][j] = C[i][j-1];
                }
                else
                {
                    C[i][j] = C[i-1][j];
                }
            }
        }
    }
}

