#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    stringstream s1;
    int N;//代表有幾行
    int i1;//用來存放string轉成int的資料
    while(cin>>N)
    {
      cin.ignore();
      string line;//讀入每行的資料
      for(int i=0;i<N;i++)
      {
         getline(cin,line);//讀入每行的資料
         int sum=0;//計算總和
         s1.clear();//清除緩存
         s1<<line;
         //也可以使用s1.str(line);
         //還可以寫成line=s1.str();
         while(true)
         {
           s1>>i1;
           if(s1.fail()) break;//確認stringstream有正常流出，沒有代表空了
           sum+=i1;//把每個轉換成int的數字都丟入sum累加
         }
         cout<<sum<<endl;
      }
    }
}