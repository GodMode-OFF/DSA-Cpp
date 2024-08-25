#include<iostream>
#include<vector>
using namespace std;

int main(){
    string temp;
    vector<string> ans(10);
    int index = 0, count = 0;
    string s = "myself2 me1 i4 and3";
    
    while(index < s.size()){
        if(s[index] == ' '){
            int pos = temp[temp.size() - 1] - '0';
            temp.pop_back();
            ans[pos - 1] = temp;
            temp.clear();
            count++;
            index++;
        } else {
            temp += s[index];
            index++;
        }
    }
    int pos = temp[temp.size() - 1] - '0';
    temp.pop_back();
    ans[pos - 1] = temp;
    count++;

    for(int i = 0; i < count; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
