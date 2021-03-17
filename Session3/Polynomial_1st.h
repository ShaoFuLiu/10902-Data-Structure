#include <iostream>
#include <algorithm>

using namespace std;

class Polynomial
{
    private:

    public:
        // Basic element
        static constexpr int degree_max = 10;
        int degree; // degree <= degree_max
        float coef[degree_max+1];

        // Return sum of *this and poly
        Polynomial Add(Polynomial b)
        {
            Polynomial c;
            cout << this->degree << endl;
            for (int i = 0; i <= this->degree; i++)
            {
                c.coef[i] = this->coef[i] + b.coef[i];
            }
            return c;
        }

        // Return multiplication of *this and poly
         Polynomial Mult(Polynomial b)
         {
            Polynomial c;
            for (int i = 0; i <= degree; i++)
            {
                for (j = 0; j <= degree; j++)
                {
                    c.coef
                }
            }
         }
        // Return the evaluation result
        // float Eval(float f );
    private:
};

