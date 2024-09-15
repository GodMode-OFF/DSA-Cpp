#include<iostream>
using namespace std;


void recursion(int n){
    if(n==1){
        cout<<n<<"\n";
        return;
    }
    else{
        recursion(n-1);
        cout<<n<<"\n";
    }
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    recursion(n);
}
