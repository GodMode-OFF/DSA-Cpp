#include <iostream>
using namespace std;
int main(){
    int arr[100];
    int size;
    cout<<"Enter the number of elements you want: ";
    cin>> size;
    cout<<"Enter the elements: ";
    for(int i=0; i < size; i++){
        cin>>arr[i];
    }
    cout<<"Sorting the elements..."<<" \n";
    for(int i=1; i<size; i++){
        for(int j=i; j>0; j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j], arr[j-1]);
            }else{
                break;
            }
        }
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}
