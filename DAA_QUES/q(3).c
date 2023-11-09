/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 27 MAY 2022
    QUESTION 2
*/

#include<stdio.h>
#include<string.h>

int main()
{
    int A[30], n;
    printf(" Enter the number of integers you want to insert in the array : ");     
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        printf(" A[%d] : ", i);
        scanf("%d",&A[i]);
    }

    int z;
    int max = A[1];                                                           // The first element is stored as maximum value initially
    int k = 1;                                                                // variable k is used to run the while loop till last index 
    int a = 0;                                                                // variable a is used to store index of max during while loop
    int c = 0;                                                                // variable c counts the number of jumps
    
    while (k < n)
    {   
        for(z=k+1; z <= A[k]+k; z++)                                                
        {   
            if(A[z]+z >= max)                                                  // Here we are checking max with A[z]+z because in some cases 
            { max = A[z];                                                      // a large value may be stored in small index position
              a = z;
              
              if (A[z] == 0)
              {
                  printf("\n Jump is not possible, cannot move further");
                  return 0;
              }
            }        
        }

        k = a;
        max = A[k+1];
        c++;

        if (k > n)
        {
            k = n;
        }

        printf("\n Jump %d occurred, reached index %d",c,k);
    }

    printf("\n\n The minimum number of jumps required to reach the end is %d",c);
    return 0;
}

/*

A = [4, 3, 1, 1, 2, 3, 2, 1, 1, 4]
i = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]

A[i] + i is maximum

*/