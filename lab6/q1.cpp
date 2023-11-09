#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;

    vector<int> w, p;
    vector<double> ratio;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        p.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        w.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        double temp = ((1.0) * (p[i])) / w[i];
        ratio.push_back(temp);
    }
    int cap;
    cout << " Enter capacity : ";
    cin >> cap;
    cout << endl;

    // sorting
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                swap(ratio[j], ratio[j + 1]);
                swap(p[j], p[j + 1]);
                swap(w[j], w[j + 1]);
            }
        }
    }

    // displaying input
    cout << "------Data Input ------" << endl;
    cout << "pr we ratio" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " " << w[i] << " " << ratio[i] << endl;
    }
    int k = 0;
    double profit = 0;
    while (1)
    {

        if (cap == 0)
            break;

        if (w[k] <= cap)
        {
            cap -= w[k];
            profit = profit + p[k];
            k++;
        }
        else
        {
            profit = profit + ratio[k] * cap;
            break;
        }
    }

    cout << " Total profit: " << profit << endl;

    return 0;
}