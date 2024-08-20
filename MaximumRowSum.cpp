#include <iostream>
using namespace std;

int main() {
    int arr[4][3] = {4,2,0,5,2,6,2,3,12,15,25,12};
    int sum = 0, maxi = 0, index;
    
    for(int i = 0; i<4; i++){
        for(int j = 0; j<3; j++){
            maxi += arr[i][j];
            if(maxi > sum){
                index = i;
            }maxi = 0;
        }
    }
    cout<<"Maximum row elements are: "<<index;
}
