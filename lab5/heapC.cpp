#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int age;
    int weight;
};
void heapMin(int arr[], int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[largest])
        largest = left;
    if (right < n && arr[right] < arr[largest])
        largest = right;
    if (i != largest)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // swap(arr[i], arr[largest]);
        heapMin(arr, largest, n);
    }
}
void heapify(int arr[], int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[largest])
        largest = left;
    if (right < n && arr[right] < arr[largest])
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
void heap1(int arr[], int n, int choice)
{
    // printf("heap");
    if (choice == 1)
    {
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

    else
    {
        for (int i = (n / 2); i >= 0; i--)
        {
            heapMin(arr, i, n);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            // swap(arr[0], arr[i]);
            heapMin(arr, 0, i);
        }
    }
}

int main()
{
    int n;
    cout << " Enter numb3r of student";
    cin >> n;
    Student S[n];

    cout << "enter age " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i].age;
    }

    cout << "enter weight " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i].weight;
    }

    // heap1(arr, n, 2);

    while (1)
    {
        int choice;
        cin >> choice;
        if (choice == -1)
            break;

        else if (choice == 1)
        {
            int arr[n];
            for (int i = 0; i < n; i++)
            {

                arr[i] = S[i].age;
            }
            heap1(arr, n, 1);
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            cout << endl;
        }
        else if (choice == 2)
        {
            int arr[n];
            for (int i = 0; i < n; i++)
            {

                arr[i] = S[i].age;
            }
            heap1(arr, n, 2);
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            cout << endl;
        }
    }
    return 0;
}