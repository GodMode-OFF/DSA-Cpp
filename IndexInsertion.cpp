#include <iostream>
using namespace std;
int main(){
    int arr[100];
    int size, key, start = 0, flag = 0;
    
    cout<<"Enter the number of elements you want: ";
    cin>> size;
    cout<<"Enter the elements: ";
    for(int i=0; i < size; i++){
        cin>>arr[i];
    }
    int end = size-1;
    cout<<"Enter the element you want to search: ";
    cin>>key;
    
    while (start <= end) {
        int mid = (start + end) / 2; 
        if (arr[mid] == key) {
            cout << "Element is present at index: " << mid;
            flag = 1;
            break;
        } else if (arr[mid] > key) {
            end = mid - 1; 
        } else {
            start = mid + 1;  
        }if(start==end){
            cout<<"Element belongs at index: "<< end+1;
            
        }
    }
}
