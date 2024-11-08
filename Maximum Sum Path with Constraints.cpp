#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxSumPath(TreeNode* root, int &maxSum) {
        if (!root) return 0;
        int left = max(0, maxSumPath(root->left, maxSum));
        int right = max(0, maxSumPath(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxSumPath(root, maxSum);
        return maxSum;
    }
};

int main() {
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;
    return 0;
}
