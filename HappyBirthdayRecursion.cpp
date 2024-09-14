#include<iostream>
using namespace std;


int HappyBirthday(int n){
    if(n==0){
        cout<<"Happy birthday!!!";
        return 1;
    }else{
        cout<< n << " days left for birthday"<< "\n";
        return HappyBirthday(n-1);
    }
}

int main(){
    int n;
    cout<<"How many days left for birthday? ";
    cin>>n;
    HappyBirthday(n);
}
