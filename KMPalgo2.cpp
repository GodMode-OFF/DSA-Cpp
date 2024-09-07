#include<iostream>
using namespace std;
#include<vector>


int main(){
    string s;
    cout<<"Enter your string: ";
    cin>> s;
    vector<int>lps(s.size(), 0);
    int pre = 0, suf = 1;
    
    while(suf < s.size()){
        if(s[pre] == s[suf]){
            lps[suf] = pre + 1;
            suf++;
            pre++;
        }
        else{
            if(s[pre] == 0){
                lps[suf] = 0;
                suf++;
            }
            else{
                suf = lps[pre - 1];
            }
        }
    }
    cout<<"The LPS is: " << lps[s.size() - 1];
}
