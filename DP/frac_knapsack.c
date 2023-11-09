#include<stdio.h>
int N;

int main()
{
    int i,j, temp;
    float P[N],W[N],R[N], m, p;
    printf(" Enter the number of items : ");
    scanf("%d",&N);
    
    for(i = 1; i <= N; i++)
    {
        printf(" Enter the profit of P[%d] : ", i);
        scanf("%d",&P[i]);
        printf("\n Enter the weight of W[%d] : ", i);
        scanf("%d",&W[i]);
    }

    for(i = 1; i <= N; i++)
    {
        R[i] = P[i]/W[i];
    }

    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (R[i] < R[j])
            {
                temp = R[i];
                R[i] = R[j];
                R[j] = temp;
            }
        }
    }

    for (i = 1; i <= N; i++)
    {
        if(m>0 && W[i]<=m)
        {
            m = m - W[i];
            p = p + P[i];
        }
        else
        {
            break;
        }
    }

    if(m>0)
    [
        p = p+P[i]m
    ]
}
