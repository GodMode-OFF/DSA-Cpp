#include<iostream>
using namespace std;

int LinearSearch(int arr[], int target, int index){
    if(index == -1){
        return -1;
    }
    if(arr[index] == target){
        return index;
    }
    return LinearSearch(arr, target, index - 1);
}


int main(){
    int arr[5] = {1,2,3,4,5};
    int target = 6;
    cout<<LinearSearch(arr, target, 4);
    
}
