// Floyd-Warshall Algorithm in C++
#include<bits/stdc++.h>

using namespace std;

#define INF 999

void printPath(vector<vector<int> > path, int v, int u, vector<int>& P)
{
    if (path[v][u] == v)
        return;

    printPath(path, v, path[v][u], P);
    cout << path[v][u] << "->";
    P.push_back(path[v][u]);
}

void printDiff(vector<vector<int> > cost, vector<int>& P)
{
    int Diff = 0;
    for (int i = 0; i < P.size()-1; i++)
    {
        Diff += cost.at(P[i]).at(P[i+1]);
    }
    cout << "Difficulty:" << Diff << endl;
    P.clear();
}

void printSolution(vector<vector<int> > cost, vector<vector<int> > path, int nV)
{
    vector<int> P;
    for (int v = 0; v < nV; v++)
    {
        for (int u = 0; u < nV; u++)
        {
            if (u != v && path.at(v).at(u) != -1)
            {
                cout << "Path(" << v << "," << u << "):" << v << "->";
                P.push_back(v);
                printPath(path, v, u, P);
                cout << u << endl;
                P.push_back(u);
                printDiff(cost, P);
            }
        }
    }
}

void printCentrality(vector<vector<int> > cost, int nV)
{
    float Centrality;
    for (int j = 0; j < nV; j++)
    {
        for (int i = 0; i < nV; i++)
        {
            if (i == j)
                continue;
            if (cost.at(i).at(j) == INF)
                continue;
            // cout << (float)1 / cost.at(i).at(j)<< " ";
            Centrality += (float)1 / cost.at(i).at(j);
        }
        // cout << endl;
        cout << "Centrality(" << j << "):";
        cout << fixed;
        cout << setprecision(3);
        cout << Centrality << endl;
        Centrality = 0;
    }
}

void floydWarshall(vector<vector<int> > adjMatrix, int nV)
{
    vector<vector<int> > cost(nV, vector<int>(nV));
    vector<vector<int> > path(nV, vector<int>(nV));
    vector<vector<vector<int> > > P(nV,vector<vector<int> >(nV,vector<int>(nV)));
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
                if (!P.at(v).at(u).at(0))
                    P.at(v).at(u).at(0) = path.at(v).at(u);
                else
                    P.at(v).at(u).push_back(path.at(v).at(u));

            }

            if (cost.at(v).at(v) < 0) // Detect negative loop
            {
                cout << "Negative Weight Cycle Found!!";
                return;
            }
        }
    }
    cout << "Print path" << endl;
    for (int v = 0; v < nV; v++)
    {
        for (int u = 0; u < nV; u++)
        {
            cout << path.at(v).at(u) << "\t";
        }
        cout << endl;
    }
    cout << "Print cost" << endl;
    for (int v = 0; v < nV; v++)
    {
        for (int u = 0; u < nV; u++)
        {
            cout << cost.at(v).at(u) << "\t";
        }
        cout << endl;
    }
    cout << "Print P" << endl;
    for (int v = 0; v < nV; v++)
    {
        for (int u = 0; u < nV; u++)
        {
            for (int i = 0; i < P.at(v).at(u).size(); i++)
                cout << P.at(v).at(u).at(i) << "/";
            cout << "\t";
        }
        cout << endl;
    }
    printSolution(cost, path, nV);
    printCentrality(cost, nV);
}

int main()
{
    int nV, value;
    cin >> nV;
    vector<int> P;
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

    floydWarshall(graph, nV);
}