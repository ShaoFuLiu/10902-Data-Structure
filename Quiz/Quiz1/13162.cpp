#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<fstream>

using namespace std;

int main()
{
  const int size = 100;
  int N;
  int S;
  int L;
  int R;
  int number;
  int num;
  char elem[size];
  string sum;
  stringstream ss;

  // string line;
  // ifstream readFile("./13162_sampleIn.txt");

  for (int n = 0; n < N; n++)
  {
    int max = 0;
    int maxS = 0;
    stack<int> slot[N];

    number = 0;

    cin >> L >> R;

    for (int r = 0; r < R; r++)
    {
      cin >> S;
      if (S > max)
        max = S;
      else
        max = max;

      for (int l = 0; l < L; l++)
      {
        cin.getline(elem, 100);
        slot[S].push(elem);
      }
    }
    cout << max << endl;

    for (int s = 0; s < max+1; s++)
    {
      if (maxS <  slot[s].size())
        maxS = slot[s].size();
      else
        maxS = maxS;
    }

    for (int s = 0; s < max+1; s++)
    {
      if (slot[s].size() != maxS)
      {
        for (int i = 0; i < maxS-slot[s].size(); i++)
          slot[s].push("0");
      }
    }

    for (int len = 0; len < L; len++)
    {
      sum.clear();
      for (int s = 0; s < max+1; s++)
      {
        if (slot[s].empty())
        {
          sum.append("0");
        }
        else
        {
          sum.append(slot[s].top());
          slot[s].pop();
        }
        // cout << sum << endl;
      }
      ss << sum;
      ss >> num;
      cout << num << endl;
      number += num;
      ss.str("");
      ss.clear();
    }
    cout << "\n" << number << endl;
  }
  return 0;
}