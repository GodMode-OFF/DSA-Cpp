#include<iostream>
#include<vector>
using namespace std;


int main(){
    int first = 0;
    string s = "leEtcode";
    string ans;
    vector<int>lower(26);
    vector<int>upper(26);
    
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
    lower[s[i] - 'a']++;
    s[i] = '#';
} else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
    upper[s[i] - 'A']++;
    s[i] = '#';
}

    }
    for(int i = 0; i < 26; i++){
        while(upper[i]){
            ans += 'A' + i;
            upper[i]--;
        }
        while(lower[i]){
            ans += 'a' + i;
            lower[i]--;
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#'){
            s[i] = ans[first];
            first++;
        }
    }cout<<s;
}
