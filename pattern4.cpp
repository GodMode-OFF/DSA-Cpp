#include <iostream>
using namespace std;
char abb = 'a';

int main() {
    for(int i = 1; i<=5; i++){
        for(int j = 1; j<=5; j++){
            cout<<abb << " ";
        }
        abb++;
        cout<<"\n";
    }
}
