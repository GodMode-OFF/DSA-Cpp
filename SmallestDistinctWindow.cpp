#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>count(256, 0);
    string s;
    cout<<"Enter your string: ";
    cin>>s;
    int first = 0, second = 0, len = s.size(), diff = 0;
    
    for(int i = 0; i < s.size(); i++){
        if(count[s[i]] == 0){
            count[s[i]]++;
            diff++;
        }
    }
    for(int i = 0; i < 256; i++){
        count[i] = 0;
    }
    
    while(second < s.size()){
        while(diff){
            if(count[s[second]] == 0){
                diff--;
            }
            count[s[second]]++;
            second++;
        }
        len = min(len, second - first);
        
        while(diff != 1){
            count[s[first]]--;
            len = min(len, second - first);
            if(count[s[first]] == 0){
                diff++;
            }
            first++;
        }
    }
    cout<<len;  
}
