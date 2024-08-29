#include <stdio.h>

void inversions (int a[], int start, int mid, int end, int * count)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    int b[end + 1];
    while (i <= mid && j <= end)
    {
        if (a[j] < a[i])
        {
            b[k] = a[j];
            j++;
            * count += mid + 1 - i;
        }
        else
        {
            b[k] = a[i];
            i++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int p = start; p <= end; p++)
    {
        a[p] = b[p];
    }
}

void mergeSort (int a[], int start, int end, int * count)
{
    if (start < end)
    {
        int mid = start + ((end - start) / 2);
        mergeSort(a, start, mid, count);
        mergeSort(a, mid + 1, end, count);
        inversions(a, start, mid, end, count);
    }
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
    int count = 0;
    mergeSort (a, 0, n - 1, &count);
    printf("The number of inversions in the given array are %d.\n", count);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}