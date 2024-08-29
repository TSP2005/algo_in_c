#include <stdio.h>
#include <limits.h>

int binary_search (int v, int a[], int start, int end)  
{
    if (start == end)
    {
        if (v == a[start])
            return 1;
        return 0;
    }
    else if (start < end)
    {
        int mid = start + ((end - start) / 2);
        if (a[mid] == v)
        {
            return 1;
        }
        else if (a[mid] > v)
        {
            return binary_search(v, a, start, mid - 1);
        }
        else
        {
            return binary_search(v, a, mid + 1, end);
        }
    }
}

int findCommonElements (int c[], int a[], int b[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (binary_search(a[i], b, 0, n - 1))
        {
            c[count] = a[i];
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    printf("Enter the size of the arrays: ");
    scanf("%d", &n);
    int a[n], b[n], c[n];
    printf("Enter the elements of the array 1 (sorted): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the elements of the array 2 (sorted): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("the given array 1 is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("the given array 2 is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    int count = findCommonElements(c, a, b, n);
    printf("The commom elements are: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}