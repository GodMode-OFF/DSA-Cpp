#include<iostream>
using namespace std;

int main(){
    int arr[8] = { 3, 4, -2, 5, 8, 20, -10, 8};
    int prefix = 0, ans;
    int total_sum = 36;
    for(int i = 0; i < 8; i++){
        prefix += arr[i];
        ans = total_sum - prefix;
        if(ans == prefix){
            cout<<"Equal Sub Array is possible.";
        }
    }
}
