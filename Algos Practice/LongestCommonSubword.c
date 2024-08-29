#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * LongestCommon(char s1[], char s2[])
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
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int maxLen = 0;
    int endIndex = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[i][j] > maxLen)
            {
                maxLen = dp[i][j];
                endIndex = i - 1;
            }
        }
    }
    char * LongestCommonSubword = (char *)malloc ((maxLen + 1) * sizeof(char));
    int startIndex = endIndex - maxLen + 1;
    for (int i = startIndex; i <= endIndex; i++)
    {
        LongestCommonSubword[i - startIndex] = s1[i];
    }
    LongestCommonSubword[maxLen] = '\0';
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf ("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return LongestCommonSubword;
}

int main()
{
    char s1[100];
    char s2[100];
    printf("Enter the 2 strings: ");
    scanf("%s %s", s1, s2);
    printf ("The given strings are\n%s\n%s\n", s1, s2);
    char * LongestCommonSubword = LongestCommon(s1, s2);
    if (strlen (LongestCommonSubword) > 0)
    {
        printf ("The longest common subword is %s\nIts length is %d", LongestCommonSubword, strlen (LongestCommonSubword));
    }
    else
    {
        printf ("A common subword doesn't exist");
    }
    free (LongestCommonSubword);
}