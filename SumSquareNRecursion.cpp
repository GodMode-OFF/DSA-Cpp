#include<iostream>
using namespace std;

int SumSquareN(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n*n + SumSquareN(n-1);
    }
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<SumSquareN(n);
}
