#include<iostream>
#include<stl>
using namespace std;

int main(){
    stack<int>st;
    while(k--){
        st.push(q.front());
        q.pop();
    }
    int n = q.size();
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(n--){
        q.push(q.front());
        q.pop();
    }
}
