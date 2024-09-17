#include<iostream>
using namespace std;

bool Palindrome(string str, int start, int end){
    if(start >= end){
        return 1;
    }
    if(str[start] != str[end]){
        return 0;
    }
    else{
        return Palindrome(str, start + 1, end - 1);
    }
}


int main(){
    string str = "noon";
    cout<<Palindrome(str, 0, str.size() - 1);   
}
