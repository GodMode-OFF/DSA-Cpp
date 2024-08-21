#include<iostream>
#include<vector>
using namespace std;


int main(){     
    int right = 0, left = 0, top = 0, bottom = 0;
    int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

    for(int i = 0; i < 3; i++){
        if(top == 0){
        for(int j = 0; j < 3; j++){
            cout<<matrix[top][j];
        }}top++;
        if(left==0){
        for(int j = 1; j < 3; j++){
            cout<<matrix[j][2];
        }}left++;
        if(bottom==0){
            for(int j = 1; j >= 0; j--){
            cout<<matrix[2][j];
        }}bottom++;
        if(right==0){
            for(int j = 0; j <= 1; j++){
            cout<<matrix[1][j];
        }}right++;
    }
}
