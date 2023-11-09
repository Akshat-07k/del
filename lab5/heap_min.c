#include <stdio.h>
void heapify(int arr[], int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (i != largest)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}
void heap(int arr[], int n)
{
    // printf("heap");
    for (int i = (n / 2); i >= 0; i--)
    {
        heapify(arr, i, n);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        // swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    heap(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    heap(arr, n);
}