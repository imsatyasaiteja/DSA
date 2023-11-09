/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 29 MAY 2022
    QUESTION 3
*/

#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    int ans = (a > b) ? a : b;
    return ans;
}

int min(int a, int b)
{
    int ans = (a < b) ? a : b;
    return ans;
}

int solvepuzzle(int n, int k)
{

    int N[n + 1][k + 1];                                                 // n+1, k+1 because 0 eggs and 0 floors also may be a possibility
    int i, j, x;

    for (i = 0; i <= k; i++)
        N[0][i] = 0;                                                     // if we have 0 eggs
    for (i = 0; i <= k; i++)
        N[1][i] = i;                                                     // if we have 1 egg
    for (j = 0; j <= n; j++)
        N[j][0] = 0;                                                     // in floor is 0

    for (i = 2; i <= n; i++)
    {
        for (j = 1; j <= k; j++)
        {
            int minimum = INT_MAX;                                       // minimum is assigned infinity

            for (x = 1; x <= j; x++)
            {    
                minimum = min(minimum, (1  + max(N[i][j - x], N[i - 1][x - 1])));      
            }
            N[i][j] = minimum;
        }
    }

    printf("\nArray : \n\n");

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= k; j++)
        {
            printf("%d ",N[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber of trials in the worst case is :\n");

    return N[n][k];
}

int main()
{
    int e;
    int f; 

    printf("\nNumber of eggs : ");
    scanf("%d",&e);

    printf("\nNumber of floors : ");
    scanf("%d",&f);

    printf("%d",solvepuzzle(e, f));

    return 0;
}
