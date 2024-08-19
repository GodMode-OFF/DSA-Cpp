#include<iostream>
#include <climits>
using namespace std;

int main(){
    int arr[8] = {3, 4, -5, 8, -12, 7, 6, 2};
    int maxi = INT_MIN, ans=0;
    
    for(int i = 0; i < 8; i++){
        ans += arr[i];
        maxi = max(maxi, ans);
        if(ans<0){
            ans = 0;
        }
    }
    cout<<"Answer is: "<<ans;
}
