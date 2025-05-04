//For removing the + symnbol and adjacent left letters 
#include <iostream>
#include <stack>
#include<algorithm>
#include "lab7header.h"
using namespace std;



int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    string output = processString(input);
    cout << "Processed output: " << output << endl;

    return 0;
}
