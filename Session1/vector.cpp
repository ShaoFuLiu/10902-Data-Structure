#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 
  
int main() 
{ 
    // Get the vector 
    vector<int> a = { 1, 45, 54, 71, 76, 12 }; 
  
    // Print the vector 
    cout << "Vector: "; 
    for (int i = 0; i < a.size(); i++) 
        cout << a[i] << " "; 
    cout << endl; 
  
    // Find the max element 
    cout << "\nMax Element = "
         << *max_element(a.begin(), a.end()) << endl; 
    return 0; 
} 