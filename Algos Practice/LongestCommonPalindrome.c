#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max (int a, int b)
{
    return (a > b) ? a : b;
}

char * LCS (char s1[], char s2[])
{
    int m = strlen (s1);
    int n = strlen (s2);
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1]; 
            }
            else
            {
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf ("\n");
    }
    int maxLen = dp[m][n];
    char * LongestCommonPalindrome = (char *)malloc((maxLen + 1) * sizeof(char));
    int i = m;
    int j = n;
    int index = maxLen;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            LongestCommonPalindrome[--index] = s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    LongestCommonPalindrome[maxLen] = '\0';
    return LongestCommonPalindrome;
}

int main()
{
    char s1[100];
    char s2[100];
    printf("Enter the string: ");
    scanf("%s", s1);
    int l1 = strlen (s1);
    for (int i = 0; i < l1; i++)
    {
        s2[i] = s1[l1 - i - 1];
    }
    s2[l1] = '\0';
    printf("The given strings are\n%s\n%s\n", s1, s2);
    char * LongestCommonPalindrome = LCS (s1, s2);
    int l = strlen (LongestCommonPalindrome);
    if (l > 0)
    {
        printf("The length of the Longest Common Palindrome is %d\n", l);
        printf("%s is the Longest Common Palindrome.", LongestCommonPalindrome);
    }
    else
    {
        printf("The is no palindrome in the string.");
    }
    free (LongestCommonPalindrome);
    return 0;
}