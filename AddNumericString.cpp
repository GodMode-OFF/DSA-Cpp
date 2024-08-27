#include<iostream>
#include<string>
using namespace std;


int main(){
    string ans;
    string s1 = "1231123";
    string s2 =   "21412";
    int index1 = s1.size() - 1, index2 = s2.size() - 1, sum = 0, carry = 0;
    while(index2 >= 0){
        sum = (s1[index1] - '0') + (s2[index2] - '0') + carry;
        carry = sum/10;
        char c = '0' + sum%10;
        ans += c;
        index2--;
        index1--;
    }
    while(index1 >= 0){
        sum = (s1[index1] - '0');
        char c = '0' + sum%10;
        ans += c;
        index1--;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
    return 0;
}
