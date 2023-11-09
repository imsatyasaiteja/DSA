#include<stdio.h>
#include<string.h>
#define N 100

char s[N], p1[N], p2[N], p3[N];

void rep(int n1, int n2)
{
    char *p = strstr(s, p1);
    if(p)
    {
        printf("Given pattern '%s' exists in s[N]\n",p1);
    }
    else
    {
        printf("Pattern '%s' doesnot exist in s[N], so no change\n",p1);
        return;
    }
    
    while (p = strstr(s, p1))
    {
        strcpy(p3, p2);
        strcat(p3, p);
        strcpy(p, p3);
        int n = strlen(p);

        for (int i = n2; i < n; i++)
        {
            if(i+n1 > n)
            {
                p[i] = '\0';
            }
            else
            {
                p[i] = p[i + n1];
            }
        }
    }
    printf("s[N] : %s",s);

}

void main()
{   
    printf("Program that replaces a pattern in a sentence with another\n");
    printf("Enter a sentence s[N] : ");
    scanf("%[^\n]",&s);
    printf("Enter a pattern in the sentence p1[N] : ");
    scanf("%s",&p1);
    printf("Enter the word you want to replace p2[N] : ");
    scanf("%s",&p2);

    int n1 = strlen(p1);
    int n2 = strlen(p2);

    rep(n1, n2);

    return;
}