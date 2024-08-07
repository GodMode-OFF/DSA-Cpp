#include <iostream>
using namespace std;

int main() {
    int a;
    cout<<"Print number of rows: ";
    cin>>a;
    
    for(int i=1;i<=a;i++){
        for(int j=1; j<=i;j++){
            cout<<"*";
        }
        for(int j=1; j<=2*a-2*i ; j++){
            cout<< " ";
        }
        for(int j=1; j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=a-1;i>=1;i--){
        for(int j=1; j<=i;j++){
            cout<<"*";
        }
        for(int j=1; j<=2*a-2*i ; j++){
            cout<< " ";
        }
        for(int j=1; j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
