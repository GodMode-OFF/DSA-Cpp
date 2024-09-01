//KMP Algo
//still dk how to solve this
#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int>lps(s.size(),0);
    int pre = 0, suf = 1;
    
    
    while(suf < s.size()){
        if(s[suf] == s[pre]){
            lps[suf] = pre + 1;
        }
        
    }
    
    
    return 0;
}
