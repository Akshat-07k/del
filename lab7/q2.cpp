#include <bits/stdc++.h>
using namespace std;

int fun(vector<vector<int>> &dp, string &t1, string &t2, int a, int b)
{

    // base case
    if (a == t1.size() || b == t2.size())
        return 0;

    if (t1[a] == t2[b])
    {
        return 1 + fun(dp, t1, t2, a + 1, b + 1);
    }
    else if (t1[a] != t2[b])
    {

        if (dp[a][b] == -1)
        {
            dp[a][b] = max(fun(dp, t1, t2, a + 1, b), fun(dp, t1, t2, a, b + 1));
        }
    }

    return dp[a][b];
}

int main()
{
    string t1, t2;
    cin >> t1 >> t2;

    vector<vector<int>> dp(t1.size(), vector<int>(t1.size(), -1));
    cout << fun(dp, t1, t2, 0, 0);
    return 0;
}
