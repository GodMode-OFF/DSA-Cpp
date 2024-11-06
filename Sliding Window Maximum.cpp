#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;  // Stores indices of useful elements

    for (int i = 0; i < nums.size(); i++) {
        // Remove elements out of the current window from the front of deque
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Maintain decreasing order in deque by removing elements smaller than the current one
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add current element at the back of deque
        dq.push_back(i);

        // If we have traversed at least 'k' elements, the front of deque is the maximum for the window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);

    // Output the result
    cout << "Sliding Window Maximum: ";
    for (int max_val : result) {
        cout << max_val << " ";
    }

    return 0;
}
