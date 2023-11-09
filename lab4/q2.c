#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
int part(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (pivot >= arr[i] && i < high)
            i++;
        while (pivot <= arr[j])
            j--;
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
        else
            i++;
    }
    swap(&arr[low], &arr[j]);
    return j;
}
int *quick(int arr[], int p, int q)
{
    if (p >= q)
        return arr;
    else
    {
        int m = part(arr, p, q);

        for (int i = 0; i < 5; i++)
            printf(" %d ", arr[i]);
        printf(" : %d \n", m);

        quick(arr, p, m - 1);
        quick(arr, m + 1, q);
        return arr;
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int *ans = (int *)malloc(sizeof(int) * 5);
    ans = quick(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ", arr[i]);
    }
    return 0;
}