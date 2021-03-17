#include <iostream> 
#include <stdio.h>
#include <string.h>

using namespace std; 

int main () 
{ 
    char input[100000]; 
    cin.getline(input,100000);

    for (int i=0; i<strlen(input); i++) 
        if ( input[i] == ' ' )
        {
            cout << endl;
        }
        else
        {
            cout << input[i];
            if ( i == strlen(input)-1 )
            {
                cout << endl;
            }
        }
        
    return 0;
} 