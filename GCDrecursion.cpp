#include <iostream>
using namespace std;

int GCD(int n, int m){
    if(m==0){
        return n;
    }else{
        return GCD(m, n%m);
    }
}

int main() {
    int j, k;
    cout << "Enter the value of j and k : ";
    cin >> j >> k;
    cout<<GCD(j,k);
    return 0;
}
