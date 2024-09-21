#include<iostream>
#include<vector>
using namespace std;

int trapRainwater(vector<int>& height) {
    int n = height.size();
    if(n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i-1], height[i]);
    }

    rightMax[n-1] = height[n-1];
    for(int i = n-2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], height[i]);
    }

    int waterTrapped = 0;
    for(int i = 0; i < n; i++) {
        waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
    }

    return waterTrapped;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Water trapped: " << trapRainwater(height) << endl;
    return 0;
}
