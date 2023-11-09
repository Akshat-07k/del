#include <stdio.h>

void mer(int arr[], int l, int mid, int h, int ans[])
{
    int i = l, k = l, j = mid + 1;
    while ((i <= mid) && (j <= h))
    {
        if (arr[i] <= arr[j])
        {
            ans[k] = arr[i++];
            // cout<<" "<<ans[k];
            printf(" %d-", ans[k]);
            // k++;
        }
        else
        {
            ans[k] = arr[j++];
            // cout<<" "<<ans[k];
            printf(" %d-", ans[k]);
            k++;
        }
    }
    while (i < mid)
    {
        ans[k] = arr[i++];
        printf(" %d", ans[k]);
        k++;
    }
    while (j < h)
    {
        ans[k] = arr[j++];
        printf(" %d", ans[k]);
        k++;
    }
}
void merge(int arr[], int l, int h, int ans[])
{

    if (l < h)
    {
        int mid = (l + h) / 2;
        merge(arr, l, mid, ans);
        merge(arr, mid + 1, h, ans);

        mer(arr, l, mid, h, ans);
    }
}

int main()
{
    int n;
    scanf(" %d", &n);
    int arr[n];
    int ans[n];
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);
    merge(arr, 0, n - 1, ans);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf(" %d ", ans[i]);
    return 0;
}