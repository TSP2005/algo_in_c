#include <stdio.h>

int max (int a, int b)
{
    return (a > b) ? a : b;
}

int maxSubarraySum(int n, int a[])
{
    int MSF = a[0];
    int MSA = a[0];
    for (int i = 1; i < n; i++)
    {
        MSF = max(a[i], MSF + a[i]);
        MSA = max(MSA, MSF);
    }
    return MSA;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("the given array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int maxSum = maxSubarraySum(n, a);
    printf("The maximum contiguous subarray sum is: %d", maxSum);
}