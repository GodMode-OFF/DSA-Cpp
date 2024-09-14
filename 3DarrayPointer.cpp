#include<iostream>
using namespace std;

int main(){
    int l, b, h;
    cout<<"Enter Lenght, Breadth and Height of your 3D array: ";
    cin >> l >> b >> h;
    int ***ptr = new int **[l];
    
    for(int i = 0; i < l; i++){
        ptr[i] = new int *[b];
        for(int j = 0; j < b; j++){
            ptr[i][j] = new int [h];
        }
    }
}
