#include <cstdlib>
#include <iostream>
#include <stddef.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void solve()
{
    int n, x, y, a, b;
    double dist = 0.0;

    cin >> n;
    vector<int> Xarr, Yarr;
    for (int i = 0; i < 2*n; i++)
    {
        cin >> a >> b;
        if (a == 0)
            Yarr.push_back(abs(b));
        if (b == 0)
            Xarr.push_back(abs(a));
    }

    sort(Xarr.begin(), Xarr.end());
    sort(Yarr.begin(), Yarr.end());

    // for (int i = 0; i < Xarr.size(); i++)
    // {
    //     cout << Xarr[i] << ", " << Yarr[i] << endl;
    // }

    for (int i = 0; i < Xarr.size(); i++)
    {
        dist += sqrt((pow(Xarr[i],2) + pow(Yarr[i],2)));
    }


    cout << dist << endl;
}

int main()
{
    // add this line of  code at the beginning of you main function
    std::cout << std::fixed << std::setprecision(8);

    // Implement your code below
    int T;
    std::cin >> T;

    // Handle multiple cases
    while (T--) {
        // use the funtion to read input, process data, and output answers.
        solve();
    }
    return 0;
}