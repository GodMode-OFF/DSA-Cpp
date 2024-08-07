
#include <iostream>
using namespace std;

int main() {
    int a;
    cout<<"Print number of rows: ";
    cin>>a;
    
    for(int i=1;i<=a;i++){
        for(int j=1; j<=(a-i);j++){
            cout<<" ";
        }
        for(int j=1; j<=(2*i - 1); j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    
    return 0;
}
