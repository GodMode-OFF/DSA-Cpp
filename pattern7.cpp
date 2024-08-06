#include <iostream>
using namespace std;
int a;

int main() {
    cout<<"Enter how many rows you want: ";
    cin>>a;
    for(int i = 1; i<=a; i++){
        for(int j = a; j>=i; j--){
            cout<< " ";
        }
        for(int k = 1; k<=i; k++){
            cout<<"*";
        }
        cout<<"\n";
    }

    return 0;
}
