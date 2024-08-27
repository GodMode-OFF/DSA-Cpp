#include<iostream>
using namespace std;

int num(char ch) {
    if (ch == 'I') {
        return 1;
    } else if (ch == 'V') {
        return 5;
    } else if (ch == 'X') {
        return 10;
    } else if (ch == 'L') {
        return 50;
    } else if (ch == 'C') {
        return 100;
    } else if (ch == 'D') {
        return 500;
    } else{
        return 1000;
    } 
}

int main(){
    string str = "XLIII";
    int sum=0;
    for(int i = 0; i < str.size() - 1; i++){
        if(num(str[i]) < num(str[i+1])){
            sum -= num(str[i]);
        }else{
            sum += num(str[i]);
        }
    }
    sum += num(str[str.size() - 1]);
    cout<<sum;
    return 0;
}
