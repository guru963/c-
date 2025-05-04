//Deleting the index value unless they are smaller than del vector
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
vector<int> del_creation(int del_value,vector<int>&v);
int num_of_winners(vector<int>&v,vector<int>&winner);
int main(){
    cout<<"Enter the number of testcases";
    int test_case;
    cin>>test_case;
    for(int j=0;j<test_case;j++){
        int del_value;
        cin>>del_value;
        int num;
        cin>>num;
        vector<int> v;
        del_creation(del_value,v);
        sort(v.begin(),v.end());
        
        for(int i=0;i<num;i++){
            int range;
            cin>>range;
            vector<int> winner(range);
            for(int i=0;i<range;i++){
                winner[i]=i;
            }
            int result=num_of_winners(v,winner);
            cout<<result<<" ";

        }
        cout<<" "<<endl;
    }
    
}
//Creation of delete vector
vector<int> del_creation(int del_value,vector<int>&v){
    for(int i=0;i<del_value;i++){
        int data;
        cin>>data;
        v.push_back(data);

    }
    return v;
}
//Deleting until the size is smaller than the first index of delete vector
int num_of_winners(vector<int>&v,vector<int>&winner){
    int range=winner.size();
    while(range>=v[0]){
        int deletions=0;
        for(auto it:v){
            int pos=it-1;
            if(pos>=range)break;
            deletions++;

        }
        range=range-deletions;
    }
    return range;
}
