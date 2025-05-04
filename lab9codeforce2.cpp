include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
vector<int> create(int range,vector<int>&v);
pair<int,int> maxi(vector<int>&v);
vector<int> strength(vector<int>&v,int max_1,int max_2);
void display(vector<int>&v);

int main(){
    int test_case;
    cin>>test_case;
    for(int i=0;i<test_case;i++){
        int range;
        cin>>range;
        vector<int> v;
        create(range,v);
        pair<int,int> maxs=maxi(v);
        v=strength(v,maxs.first,maxs.second);
        display(v);
    }

}
//Creation of vector
vector<int> create(int range,vector<int>&v){
    for(int i=0;i<range;i++){
        int data;
        cin>>data;
        v.push_back(data);
    }
    return v;
}
//Find max_one and max_second
pair<int,int> maxi(vector<int>&v){
    int max_1=-1;
    int max_2=-1;
    for(int i=0;i<v.size();i++ ){
        if(v[i]>max_1){
            max_1=v[i];
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i]>max_2 && v[i]<max_1){
            max_2=v[i];
        }
    }
    return {max_1,max_2};
}
//Finding the strength
vector<int> strength(vector<int>&v,int max_1,int max_2){
    if(max_2==-1){
        return vector<int>(v.size(),0);
    }
    for(int i=0;i<v.size();i++){
        if(v[i]<max_1){
            v[i]=v[i]-max_1;
        }else{
            v[i]=v[i]-max_2;
        }
    }
    return v;
}
//Printing the new vector
void display(vector<int>&v){
    for(auto it:v){
        cout<<it<<" ";
    }
}