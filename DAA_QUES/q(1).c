/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 26 MAY 2022
    QUESTION 1(a), MATRIX CHAIN MULTIPLICATION
*/

#include <stdio.h>
#define M 10
#define I 999999

int i, j, l, k, q;
int z = 1;

void main()
{
    int n, P[M];

    printf(" Enter the number of matrices you are going to multiply : ");
    scanf("%d",&n);

    printf("\n Enter the dimensions of all these arrays : \n");
    for (int i = 0; i <= n; i++)
    {
        printf(" P[%d] : ", i);
        scanf("%d",&P[i]);
    }

    int m[n][n];                                                        
    int s[n][n];                                                        

    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;                                                    
    }                                                                   

    for (l = 2; l <= n; l++)                                            // l, the chain length starts from 2 because to multiply we atleast need two matices 
    {
        for (i = 1; i <= (n - (l - 1)); i++)                            // Here it is n-(l-1) because few matrices at the last cannot form a 'l' length chain 
        {
            j = i + (l - 1);                                            
            m[i][j] = I;                                                
            
            for (k = i; k < j; k++)                                     // for a kth matrix in between Ai and Aj
            {
                q = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\n The minimum number of matrix multiplications is given by m[%d][%d] = %d",1,n, m[1][n]);
    printf("\n The parenthesis is at %d", s[1][n]);
}