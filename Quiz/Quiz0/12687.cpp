#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Rsum(int K, vector<int> Values, vector<int> Weights, int SumV, int SumW, int i, vector<int> &SumWs)
{
    int New_SumV = SumV + Values[i];
    int New_SumW = SumW + Weights[i];

    if (i == Values.size())
    {
        return 0;
    }

    if (New_SumV < K)
    {
        Rsum(K, Values, Weights, New_SumV, New_SumW, i+1, SumWs);
    }

    else if(New_SumV >= K)
    {
        SumWs.push_back(New_SumW);
        if (i < Values.size())
        {
            Rsum(K, Values, Weights, SumV, SumW, i+1, SumWs);
        }
    }
}

int main()
{
    int N; // Number of items
    int K; // How much weight can the bag hold
    vector<int> Values; // Store all item's value
    vector<int> Weights; // Store all item's weight
    vector<int> SumWs;
    cin >> N >> K;
    // number of items / value limit
    // while(cin >> N >> K)
    // {
    if (N <= 0)
    {
        cout << "Error" << endl;
        //break;
        return 0;
    }
    if (K == 0)
    {
        cout << "0" << endl;
        //break;
        return 0;
    }

    for (int i=0; i<N; i++)
    {
        int Vi; // Item's value
        int Wi; // Item's weight
        cin >> Vi >> Wi;
        Values.push_back(Vi);
        Weights.push_back(Wi);
    }

    for (int i=0; i<Values.size(); i++) // Use recursive sum
    {
        int SumV = Values[i];
        int SumW = Weights[i];
        if (SumV >= K)
        {
           SumWs.push_back(SumW);
           continue;
        }
        Rsum(K, Values, Weights, SumV, SumW, i+1, SumWs);
    }

    int min = *min_element(SumWs.begin(), SumWs.end()); // Find min value of SumWs
    cout << min << '\n'  << endl;
    SumWs.clear();
    //}
    return 0;
}