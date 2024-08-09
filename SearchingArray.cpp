#include <iostream>
using namespace std;


int main() {
    int arr[100];
    int size, searched;
    
    cout<<"Enter the number of elements you want: ";
    cin>>size;
    cout<<"Enter the elements: ";
    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }
    cout<<"Which element do you want to search: ";
    cin>> searched;
    for(int i = 0; i<size; i++){
        if (arr[i]==searched){
            cout<<"Element exists at "<< i <<" index";
            break;
        }
    }
    cout<< "\n";
    return 0;
}
