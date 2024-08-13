#include<iostream>
using namespace std;


int main(){
    int start = 0, mid, end = 8;
    int arr[9] = {1,2,3,6,5,4,3,2,1};
    while(start<=end){
        mid = (start+end)/2;
        if((mid == 0 || arr[mid] > arr[mid-1]) && (mid == 8 || arr[mid] > arr[mid+1])){
            cout<<"Found the shit "<<arr[mid];
            break;
        }else if(arr[mid] < arr[mid-1]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    
    
}
