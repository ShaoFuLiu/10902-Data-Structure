#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include<fstream>

using namespace std;

int main()
{
    // ifstream readFile("./13162_sampleIn.txt");
    vector<string> t, a, b, c;
    string m;
    char N, L, R, S;
    stringstream ss0, ss1, ss2, ss3, sS, sN;
    int s0, s1, s2, s3, Terms;
    int num = 0;
    int line = 10000;

    cin >> N;

    t.push_back(line);
    ss0 << t[0];
    ss0 >> s0;

    for (int n = 0; n < s0; n++)
    {
      cin >> L >> R;
      getline(cin, line);
      a.push_back(line);
      ss1 << a[n][2];
      ss1 >> s1;
      stack<int> slot[s1];
      int Ans = 0;

      for (int l = 0; l < s1; l++)
      {
        cin >> S;
        getline(S, line);
        b.push_back(line);
        ss2 << a[n][0];
        ss2 >> s2;

        for (int r = 0; r < s2+1; r++)
        {
          ss3 << b[l+num][r*2];
          ss3 >> s3;

          slot[l].push(s3);
          ss3.str("");
          ss3.clear();
        }
        // cout << endl;
      }

      for (int p = 0; p < s2; p++)
      {
        string ansS = "";

        for (int q = 0; q < s1; q++)
        {
          sS << slot[q].top();
          sS >> S;
          ansS += S;
          // cout << ansS  << "\n";
          slot[q].pop();
          sS.str("");
          sS.clear();
        }
        sN << ansS;
        sN >> Terms;
        // cout << Terms << "+\t";
        Ans += Terms;
        sN.str("");
        sN.clear();
      }
      cout << Ans << endl;
      num += s1;
      ss1.str("");
      ss1.clear();
      ss2.str("");
      ss2.clear();
    }
    return 0;
}