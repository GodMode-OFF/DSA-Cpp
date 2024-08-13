#include <iostream>
using namespace std;
int main(){
    int arr[100];
    int size;
    int key;
    int start = 0;
    int flag = 0;
    int index = 0;
    int first = -1;
    int last = -1;
    
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
            end = mid - 1;
            first = mid;
        } else if (arr[mid] > key) {
            end = mid - 1; 
        } else {
            start = mid + 1;  
        }
    }
        start = 0;
        end = size-1;
        while (start <= end) {
        int mid = (start + end) / 2; 
        if (arr[mid] == key) {
            start = mid + 1;
            last = mid;
        } else if (arr[mid] > key) {
            end = mid - 1; 
        } else {
            start = mid + 1;  
        }
    }
    
    
    cout<< first<<" and "<<last;
}
