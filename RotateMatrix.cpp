#include<iostream>
using namespace std;


int main(){
    int arr1[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 3; j++){
            swap(arr1[i][j], arr1[j][i]);
            }
        cout<<"\n";
        }
    for(int i = 0; i < 3; i++){
        int start = 0 , end = 2;
        while(start<end){
            swap(arr1[i][start], arr1[i][end]);
            start++;
            end--;
        }
    }

    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<arr1[i][j]<<"\t";
             
        }cout<<"\n";
    }
}
