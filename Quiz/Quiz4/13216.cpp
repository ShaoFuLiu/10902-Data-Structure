// Floyd-Warshall Algorithm in C++
#include<bits/stdc++.h>

using namespace std;

#define INF 999

void printDiff(vector<vector<int> > cost, int v, int u)
{
    int Diff = 0;
    Diff = cost.at(v).at(u);
    if (Diff == INF)
        cout << "Cost(" << v << "," << u << "):No Service" << endl;
    else
        cout << "Cost(" << v << "," << u << "):" << Diff << endl;
}

void printSolution(vector<vector<int> > cost, vector<vector<int> > path, int nV, vector<int> Sou, vector<int> Tar)
{
    int v, u;

    for (int i = 0; i < Sou.size(); i++)
    {
        v = Sou.at(i);
        u = Tar.at(i);
        printDiff(cost, v, u);
    }
}

void floydWarshall(vector<vector<int> > adjMatrix, int nV, vector<int> Sou, vector<int> Tar)
{
    vector<vector<int> > cost(nV, vector<int>(nV));
    vector<vector<int> > path(nV, vector<int>(nV));

    for (int v = 0; v < nV; v++)
    {
        for (int u = 0; u < nV; u++)
        {
            cost.at(v).at(u) = adjMatrix.at(v).at(u);

            if (v == u)
                path.at(v).at(u) = 0;
            else if (cost.at(v).at(u) != INF)
                path.at(v).at(u) = v;
            else
                path.at(v).at(u) = -1;
        }
    }

    for (int k = 0; k < nV; k++)
    {
        for (int v = 0; v < nV; v++)
        {
            for (int u = 0; u < nV; u++)
            {
                if (v == u || u == k || v == k)
                    continue;
                if (cost.at(v).at(k) != INF && cost.at(k).at(u) != INF
                    && cost.at(v).at(k) + cost.at(k).at(u) < cost.at(v).at(u))
                {
                    cost.at(v).at(u) = cost.at(v).at(k) + cost.at(k).at(u);
                    path.at(v).at(u) = path.at(k).at(u);
                }
            }

            if (cost.at(v).at(v) < 0) // Detect negative loop
            {
                cout << "Negative Weight Cycle Found!!";
                return;
            }
        }
    }

    printSolution(cost, path, nV, Sou, Tar);
}

int main()
{
    int T, nV, Q, value;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> nV;
        cin >> Q;
        vector<int> P, Sou, Tar;
        vector<vector<int> > graph(nV, vector<int>(nV));
        for(int i = 0; i < nV; i++)
        {
            for(int j = 0; j < nV; j++)
            {
                cin >> value;
                if (i == j)
                    graph.at(i).at(j) = 0;
                else if (value == 0)
                    graph.at(i).at(j) = INF;
                else
                    graph.at(i).at(j) = value;
            }
        }

        int source, target;
        for (int j = 0; j < Q; j++)
        {
            cin >> source >> target;
            Sou.push_back(source);
            Tar.push_back(target);
        }

        cout << "Testcase" << i+1 << endl;
        floydWarshall(graph, nV, Sou, Tar);
        Sou.clear();
        Tar.clear();
    }
}