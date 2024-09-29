#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    vector<int> arr(5, -1);
    vector<int> data = {1, 3, 2, 4, 5};
    stack<int> s;
    
    for(int i = 4; i >= 0; i--){
        while(!s.empty() && data[s.top()] > data[i]){
            arr[s.top()] = data[i];
            s.pop();
        }
        s.push(i);
    }

    cout << arr[1] << endl;
    return 0;
}
