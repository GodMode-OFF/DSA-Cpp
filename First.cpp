#include<iostream>
using namespace std;


int main(){
    cout<<"Printing Prime Numbers";
    int n;
    cin>>n;
    if(n<2){
        cout<<"Not a prime";
        return 0;
    }else{
        for(int i=2;i<=n;i++){
            if(n%i==0){
                cout<<"Not a prime";
                return 0;
            }
        }
        cout<<"Prime Number";
        return 0;
    }
}