#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

float  Rsum(float *A, const int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else return (Rsum(A, n-1) + A[n-1]);
}

int main() 
{ 
  

    // Declare an array of doubles to be allocated on the stack
    int size = 5;
    float numbers[size] {0};

    // Assign a new value to the first element
    numbers[0] = 1;

    // Assign a value to each subsequent element
    // (numbers[1] is the second element in the array.)
    for (size_t i = 1; i < size; i++)
    {
        numbers[i] = numbers[i-1] + 1;
    }


    float a = Rsum(numbers, size);
    cout << a << endl;

    return 0;
 }