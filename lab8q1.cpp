#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<int> hightower(vector<int>&v){
    sort(v.begin()+1,v.end());
    
    int i=1;
    for(int j=0;j<v.size();j++){
        if(v[j]>v[0]){
            i=j;
            break;
        }
    }
    
    while(i<v.size()){
        v[i]=v[i]-1;
        v[0]=v[0]+1;  
        if(v[i]<=v[0]){
            i++;
            while(i < v.size() && v[i]<=v[0]){
                i++;
            }
        }
    }
    return v;
}

int main(){
    int t;
    cin >> t; 
    
    while(t--){
        int n;
        cin >> n; 
        
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i]; 
        }
        
        vector<int> result = hightower(v);
        cout << result[0] << endl;
    }
    
    return 0;
}