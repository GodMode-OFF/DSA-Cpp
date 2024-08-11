#include<iostream>
using namespace std;


int main(){
    int arr[6] = {1,5,2,4,6,6};
    for(int i = 0; i < 6 - 1; i++){
            if(arr[i]>arr[i+1]){
                int secx;
                secx = arr[j];
                arr[j] = arr[i];
                arr[i] = secx;
                
            }
    }
}
