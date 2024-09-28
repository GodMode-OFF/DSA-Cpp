#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char>S;
    string str = "hello";
    int n = str.size();
    for(int i = 0; i < n; i++){
        S.push(str[i]);
    }
    for(int i = 0; i < n; i++){
        str[i] = S.top();
        S.pop();
    }
    cout<<str;
}
