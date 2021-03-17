#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 
  
int main()
{
    int N; // Number of items
    int K; // How much weight can the bag hold
    vector<int> Values; // Store all item's value
    vector<int> Weights; // Store all item's weight

    cout << "number of items/weight upper bound" << endl;
    cin >> N >> K;

    for (int i=0; i<N; i++)
    {
        int Vi; // Item's value
        int Wi; // Item's weight
        cout << "value/weight" << endl;
        cin >> Vi >> Wi;
        if (Wi < K)
        {
            Values.push_back(Vi); 
            Weights.push_back(Wi);
        }
        else
        {
            continue;
        }  
    }
    //cout << Values[1] << endl;
    vector<int> SumVs;

    for (int i=0; i<Values.size(); i++)
    {
        cout << i << endl;
        int SumW = 0;
        int SumV = 0;

        for (int j=0; j<Values.size()-i-1; j++)
        {
            SumW = Weights[i] + Weights[j]; //Use recursive sum (Note)
            SumV = Values[i] + Values[j];
        }
    }

    int max = *max_element(SumVs.begin(), SumVs.end()); // Find max value of SumV
    cout << "The maximun value of this round is = " << max << endl;

    return 0;
}