#include<iostream>
using namespace std;

int main(){
    int arr[6] = {4,5,0,1,2,3};
    int end = 5, start = 0, key, ans;
    cout<<"Enter the element you want to search: ";
    cin>> key;
    
    while(start<=end){
        int mid = (start + end)/2;
        if(key==arr[mid]){
            cout<<"Got the key at: "<< mid;
            break;
        }else if(arr[mid]>=arr[start]){
            if(key<=arr[mid] && key>=arr[start]){
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }else if(arr[mid]<arr[0]){
            if(key>=arr[mid] && key<=arr[start]){
                start = mid + 1;
            }else{
                end = mid-1;
            }
        }
    }
}

