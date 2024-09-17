#include<iostream>
using namespace std;


string reverse(string &str, int start, int end){
    if(start >= end){
        return str;
    }
    else{
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        return reverse(str, start + 1, end - 1);
    }
}


int main(){
    string str = "hello";
    cout<<reverse(str, 0, 4);
    
    
}
