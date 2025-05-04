#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;

string processString(const string& input) {
    stack<char> s;

    for (char ch : input) {
        if (ch == '+') {
            if (!s.empty()) {
                s.pop(); 
            }
        } else {
            s.push(ch); 
        }
    }
    string result;
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}