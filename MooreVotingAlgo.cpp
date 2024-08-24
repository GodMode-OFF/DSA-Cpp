#include<iostream>
using namespace std;


int main(){
    int candidate = 0, count = 0;
    int arr[11] = {2,2,3,4,2,3,2,3,2,3,2};
    
    for(int i = 0; i < 11; i++){
        if(count == 0){
            count = 1;
            candidate = arr[i];
        }else{
            if(candidate == arr[i]){
                count++;
            }else{
                count--; 
            }
        }
    }cout<<"The candidate is: "<< candidate;
}
