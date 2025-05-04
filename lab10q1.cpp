#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int dppostion(vector<int>& u) {
    unordered_map<int,int> s;
    int total = -1;
    for(int i = u.size()-1; i >= 0; i--) {
        if(s[u[i]] != 0) {
            s[u[i]] = s[u[i]] + 1;
            total = i;
            break;
        } else {
            s[u[i]] = 1;
        }
    }
    return total + 1;  
}

int main() {
    int testCases;
    cout << "Enter the number of test cases: ";
    cin >> testCases;
    
    while(testCases--) {
        int n;
        cout << "\nEnter the size of vector: ";
        cin >> n;
        
        vector<int> u(n);
        cout << "Enter " << n << " elements: ";
        for(int i = 0; i < n; i++) {
            cin >> u[i];
        }
        
        int result = dppostion(u);
        if(result == 0) {
            cout << "No duplicates found in the vector." << endl;
        } else {
            cout << "First duplicate found at position: " << result << endl;
        }
    }
    
    return 0;
}