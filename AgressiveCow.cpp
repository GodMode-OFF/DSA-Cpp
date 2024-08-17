#include <iostream>
using namespace std;
int main(){
    int arr[5] = {1,2,4,8,9};
    int size = 5, start = 1, end = 9, cows, count = 1, ans, zero = 0;
    
    cout<<"Enter the number of cows: ";
    cin>> cows;
    while(start<=end){
        int mid = (start + end)/2;
        for(int i = 1; i<size; i++){
            int pos = arr[0];
            if(pos+mid <= arr[i]){
                count++;
                pos = arr[i];
            }
        }
            if(count<cows){
                end = mid - 1;
            }else{
                ans = mid;
                start = mid + 1;
            }
    }
}
