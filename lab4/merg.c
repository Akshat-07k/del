#include <stdio.h>
int size = 0;

void merge(int arr[], int temp[], int low1, int up1, int low2, int up2, int *comp) // Soprting here
{
    int i = low1;
    int j = low2;
    int k = low1;

    while ((i <= up1) && (j <= up2))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];

        else
            temp[k++] = arr[j++];
        (*comp)++;
    }
    while (i <= up1)
    {

        (*comp)++;
        temp[k++] = arr[i++];
    }

    while (j <= up2)
    {
        (*comp)++;
        temp[k++] = arr[j++];
    }

    // for (int i = low1; i <= up2; i++)
    //     arr[i] = temp[i];
}

void merg_sort(int arr[], int low, int up, int *comp) // Dividing here
{
    int mid;
    int temp[size];

    if (low < up)
    {
        mid = (low + up) / 2;
        merg_sort(arr, low, mid, comp);
        merg_sort(arr, mid + 1, up, comp);

        merge(arr, temp, low, mid, mid + 1, up, comp);
        // copyfun(arr, temp, low, up);
        for (int i = low; i <= up; i++)
            arr[i] = temp[i];
    }
}

int main()
{
    int n;
    printf(" Enter numnber of data : ");
    scanf(" %d", &n);
    size = n;
    int comp = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    merg_sort(arr, 0, n - 1, &comp);

    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
    printf("\n %d", comp);
    return 0;
}