#include <iostream>
#include <vector>
using namespace std;

// Define the structure of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform in-order traversal and store the elements in a vector
void inorderTraversal(TreeNode* root, vector<int>& elements) {
    if (!root) return;
    inorderTraversal(root->left, elements);
    elements.push_back(root->val);
    inorderTraversal(root->right, elements);
}

// Function to merge two sorted arrays into a single sorted array
vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    // Add remaining elements
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }
    return merged;
}

// Function to convert a sorted array into a balanced BST
TreeNode* sortedArrayToBST(const vector<int>& sortedArray, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(sortedArray[mid]);
    root->left = sortedArrayToBST(sortedArray, start, mid - 1);
    root->right = sortedArrayToBST(sortedArray, mid + 1, end);
    return root;
}

// Function to merge two BSTs into a single balanced BST
TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
    vector<int> elements1, elements2;
    // Get sorted elements from both trees using in-order traversal
    inorderTraversal(root1, elements1);
    inorderTraversal(root2, elements2);
    // Merge the sorted arrays
    vector<int> mergedElements = mergeSortedArrays(elements1, elements2);
    // Convert the merged sorted array into a balanced BST
    return sortedArrayToBST(mergedElements, 0, mergedElements.size() - 1);
}

// Function to print the in-order traversal of a BST
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Create two sample BSTs
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);

    // Merge the BSTs
    TreeNode* mergedRoot = mergeBSTs(root1, root2);

    // Print the in-order traversal of the merged BST
    cout << "In-order traversal of the merged BST:\n";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}
