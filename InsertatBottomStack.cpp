#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>S1;
    stack<int>S2;
    int x;
    cout<<"Enter the number you want to insert at the beginning of stack: ";
    cin>> x;
    while(!S1.empty()){
        S2.push(S1.top());
        S1.pop();
    }
    S1.push(x);
    while(!S2.empty()){
        S1.push(S2.top());
        S2.pop();
    }

}
