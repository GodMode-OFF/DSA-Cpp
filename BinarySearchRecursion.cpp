#include<iostream>
using namespace std;

int BinarySearch(int arr[], int target, int start, int end){
    int mid = (start + end) / 2;
    if(start > end){
        return -1;
    }
    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] < target){
        return BinarySearch(arr, target, mid + 1, end);
    }else{
        return BinarySearch(arr, target, start, mid - 1);
    }
}


int main(){
    int arr[5] = {1,2,3,4,5};
    int target = 2;
    cout<<BinarySearch(arr, target, 0, 4);
    
}
