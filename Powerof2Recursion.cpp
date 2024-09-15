#include<iostream>
using namespace std;

int Powerof2(int n){
    if(n == 1){
        return 2;
    }
    else{
        return 2*Powerof2(n-1);
    }
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<Powerof2(n);
}
