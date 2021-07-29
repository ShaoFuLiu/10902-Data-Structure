#include <cstdlib>
#include <iostream>
#include <stddef.h>

using namespace std;

void Insertion(int *arr, int size, int key)
{
    int n = size;
    while (key < arr[n] && n < 0)
    {
        n--;
    }
    arr[n] = key;
}

int main()
{
    int lG, gem;
    cin >> lG ;
    int Larr[lG];
    for (int i = 0; i < lG; i++)
    {
        cin >> gem;
        Larr[i] = gem;
    }

    for (int i = 0; i < lG; i++)
    {
        cout << Larr[i];
        i = i + 1;
    }
    cout << endl;
    int i = 0;
    while (i  < lG)
    {
        cout << Larr[i];
        i = i + 2;
    }
    cout << endl;
}