#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
    int testCases;
    cout << "Enter number of test cases: ";
    cin >> testCases;
    
    while(testCases--) {
        int si;
        cout << "\nEnter number of words per person (si): ";
        cin >> si;
        
        vector<string> v;
        cout << "Enter " << 3*si << " words (3 persons with " << si << " words each):\n";
        for(int i = 0; i < 3*si; i++) {
            string word;
            cin >> word;
            v.push_back(word);
        }
        
        // Your original logic (unchanged)
        int arr[3] = {0,0,0};
        unordered_map<string,vector<int>> s;
        
        for(int i = 0; i < v.size(); i++) {
            if(s[v[i]].size() != 0) {
                s[v[i]].push_back(i/si + 1);  // i/si gives person group (0,1,2)
            } else {
                s[v[i]].push_back(i/si + 1);  // +1 makes it (1,2,3)
            }
        }
        
        for(auto it : s) {
            if(it.second.size() == 1) {
                arr[it.second[0]-1] += 3;
            }
            if(it.second.size() == 2) {
                arr[it.second[0]-1] += 1;
                arr[it.second[1]-1] += 1;
            }
        }
        
        cout << "Scores for persons 1, 2, 3: ";
        for(int i = 0; i < 3; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}