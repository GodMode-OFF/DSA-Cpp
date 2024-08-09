#include <iostream>
using namespace std;
    
    
char CapsLock(char &a){
    a = a - 32;
    return a;
}
    
int main() {
    char letter;
    cout<<"Enter a letter to capitalise: ";
    cin>>letter;
    cout<< CapsLock(letter);
    return 0;
}
