#include<iostream>
using namespace std;


int main(){
    int start = 66, end = 231, count = 1, M, pages = 0, n=6, ans;
    int arr[6] = {44,11,22,55,33,66};
    
    cout<<"How many Students: ";
    cin>>M;
    while(start<=end){
        int mid = (start+end)/2;
        for(int i=0; i<n; i++){
            pages += arr[i];
            if(pages>mid){
                count++;
                pages = 0;
                pages += arr[i];
            }
            if(count<=M){
                ans = end;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
    }
    cout<<"Distribution: "<< ans;
}
