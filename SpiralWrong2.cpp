#include<iostream>
#include<vector>
using namespace std;


int main(){     
    int right = 0, left = 3, top = 0, bottom = 3;
int matrix[4][4] = {
    {1,  2,  3,  4},
    {5,  6,  7,  8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};


    for(int i = 0; i < 4; i++){
        if(top < 2){
            for(int j = i; j < 4 - i; j++){
                cout<<matrix[top][j];
                }
        }top++;
        if(left > 1){
            for(int j = i + 1; j < 4 - i; j++){
                cout<<matrix[j][left];
            }
        }left--;
        if(bottom > 1){
            for(int j = 2 - i; j >= i - 0; j--){
                cout<<matrix[bottom][j];
            }
        }bottom--;
        if(right < 1){
            for(int j = 2; j >= 1; j--){
                cout<<matrix[j][right];
           }
        }right++;
    }
}
