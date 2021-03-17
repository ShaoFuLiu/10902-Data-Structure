#include <iostream>
#include <algorithm>
#include <Polynomial.h>

using namespace std;

int main(void)
{
    int degree = 3;
    Polynomial A, B, C;
    A.degree = degree; B.degree = degree; C.degree = degree;
    for (int i = 0; i <= degree; i++)
    {
        A.coef[i] = i;
        B.coef[i] = i;
    }

    C = A.Add(B);

    for (int i = 0; i <= degree; i++)
    {
        cout << A.coef[i] << "+" << B.coef[i] << "\t=\t" << C.coef[i] << endl;
    }
}
