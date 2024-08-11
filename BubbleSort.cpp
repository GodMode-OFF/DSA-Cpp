#include<iostream>
using namespace std;


int main(){
    int arr[6] = {5,4,3,2,1,6};
    for(int i = 0; i < 6 - 1; i++){
        for(int j = 0; j<5; j++){
            if(arr[j]>arr[j+1]){
                int secx;
                secx = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = secx;
            }}}
    cout << "Array elements: ";
    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}
