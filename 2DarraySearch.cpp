#include <iostream>
using namespace std;

int main() {
    int arr[4][3] = {4,2,0,5,2,6,2,3,12,15,25,12};
    int search;
    cout<<"Which element do you want to search: ";
    cin>>search;
    
    for(int i = 0; i<4; i++){
        for(int j = 0; j<3; j++){
            if(arr[i][j] == search){
                cout<<"Element found at index - "<< i << " , "<<j<< "\n";
            }
        }
    }
}
