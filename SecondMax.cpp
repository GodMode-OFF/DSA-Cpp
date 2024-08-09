
#include <iostream>
using namespace std;


int main() {
    int arr[100];
    int size, max = -20000, max2 = -20000 ;
    
    cout<<"Enter the number of elements you want: ";
    cin>>size;
    cout<<"Enter the elements: ";
    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }
    
    
    for(int i=0; i<size; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    cout<< "\n";
    for(int i=0; i<size; i++){
        if(arr[i]>max2 && arr[i] != max){
            max2 = arr[i];
        }}
    cout<< max2;
    
    return 0;
}
