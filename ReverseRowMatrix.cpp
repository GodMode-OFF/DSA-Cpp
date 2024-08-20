#include <iostream>
using namespace std;

int main() {
        int arr[4][3] = {
        {4 , 2 , 0 },
        {5 , 2 , 6 },
        {2 , 3 , 12},
        {15, 25, 12}
    };
    int sum = 0, maxi = 0, index;
    
    for(int i = 0; i<4; i++){
        for(int j = 2; j>=0; j--){
                cout<< arr[i][j]<< "\t";
            }cout<<"\n";
        }
    }
