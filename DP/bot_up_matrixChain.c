#include <stdio.h>
#define M 10

int P[M] = {1, 2, 1, 4, 1};
int i, j, l, n, k, q;
int z = 1;

void main()
{
    while (P[z] != '\0')
    {  z = z + 1; }                                                  // We are counting the number of elements in the array P[M]
    
    n = z - 1;

    int m[n][n];                                                     // Matrix m[][] is the minimum number of multiplications and s[][] stores
    int s[n][n];                                                     // the index separation at which minimum number of multiplications occur

    for (i = 1; i <= n; i++)
    {  m[i][i] = 0; }                                                // In a single matrix, multiplications do not occur 
    

    for (l = 2; l <= n; l++)                                         // 'l' is the chain length
    {
        for (i = 1; i <= (n - (l - 1)); i++)                           // 
        {
            j = i + (l - 1);
            m[i][j] = 276447231;                                     // m[i][j] is assigned to infinity
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k+1][j] + P[i - 1]*P[k]*P[j];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            printf(" %d", m[x][y]);
        }
        printf("\n");
    }
    
    printf("\n The value of m is : %d", m[i][j]);
    printf("\n The value of s is : %d", s[i][j]);
}