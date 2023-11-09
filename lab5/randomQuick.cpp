#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// int count = 0;
int divide(vector<int> &v, int low, int high, int &count)
{

    int pivot = v[low];
    int i = low, j = high;
    while (i < j)
    {
        // i++;
        // j--;
        while (v[i] <= pivot && i < high)
        {
            count++;
            i++;
        }
        while (v[j] >= pivot && j > low)
        {
            j--;
            count++;
        }
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(v[low], v[j]);
    return j;
}

void quick(vector<int> &v, int l, int h, int &count, vector<int> &visit)
{
    if (l < h)
    {
        // cout << "*";
        int r = rand() % (v.size()); // this is for pivot altering
        if (visit[r] == 0)
            swap(v[r], v[l]);
        int pivot = divide(v, l, h, count);
        visit[pivot] = 1;
        quick(v, l, pivot, count, visit);
        quick(v, pivot + 1, h, count, visit);
    }
}

int main()
{
    int count = 0;
    int n;
    scanf("%d", &n);
    vector<int> visit(n, 0); // visited array/vector
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &v[i]);

    quick(v, 0, n - 1, count, visit);
    cout << endl
         << count;
    for (auto i : v)
        cout << i << " ";
    return 0;
}