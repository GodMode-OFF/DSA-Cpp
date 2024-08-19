#include<iostream>
#include<vector>
using namespace std;


int main(){
    int inp;
    vector<int>v;
    char answer = 'y';
    while(answer == 'y'){
        cout<<"Enter a number to push in: ";
        cin>>inp;
        v.push_back(inp);
        cout<<"Do you want to Push more numbers in? (y/n): ";
        cin>>answer;
    }
    for(auto i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    cout<<v.capacity()<<"\n";
    cout<<v.size();
    
}
