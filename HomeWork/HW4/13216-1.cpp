// Floyd-Warshall Algorithm in C++
#include<bits/stdc++.h>

using namespace std;

#define INF 999

int main()
{
    int nV, value;
    cin >> nV;
    vector<int> P;
    vector<vector<int> > graph(nV, vector<int>(nV));
    if (!graph.at(1).at(2))
    {
        cout << "empty" << endl;
    }
}