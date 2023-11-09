#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Approcah
/*
           (3)----(1)
          /        |
         /         |
   ---> (0)        |
         \         |
          \        |
           (2)----(4)

    first Create a adjacent List then
        - use queue to traverse it
        - also maintain a visited map/vector;
*/

class Graph
{
public:
    map<int, list<int>> adj;
    vector<int> visited;

    void create()
    {
        int n;
        printf(" Enter number of edges\n");
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    void display()
    {
        for (auto i : adj)
        {
            cout << i.first << " ->  ";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }

    void BFS()
    {
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cout << front << " ";
            visited.push_back(front);

            for (auto i : adj.find(front)->second)
            {
                if (find(visited.begin(), visited.end(), i) == visited.end())
                {
                    q.push(i);
                    visited.push_back(i);
                }
                else
                {
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.create();
    g.display();
    g.BFS();

    return 0;
}