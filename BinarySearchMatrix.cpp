#include<iostream>
using namespace std;


int main(){
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int start = 0, end = 8, mid, row, col, target;
    cout<<"What do you want to search: ";
    cin>>target;
    while(start<=end){
        mid = (start+end)/2;
        row = mid/3;
        col = mid%3;
        if(arr[row][col] == target){
            cout<<"Element found at: arr["<< row <<","<< col<<"]";
            break;
        }else if(arr[row][col] < target){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
}
