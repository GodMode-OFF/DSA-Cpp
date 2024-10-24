#include <iostream>
#include <vector>
using namespace std;

// Function to build the Segment Tree
void buildTree(vector<int>& arr, vector<int>& segTree, int start, int end, int node) {
    if (start == end) {
        // Leaf node will have a single element
        segTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    // Build left and right subtree
    buildTree(arr, segTree, start, mid, 2 * node + 1);
    buildTree(arr, segTree, mid + 1, end, 2 * node + 2);
    // Internal node will have the sum of both of its children
    segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
}

// Function to update a value in the Segment Tree
void updateTree(vector<int>& segTree, int start, int end, int idx, int value, int node) {
    if (start == end) {
        // Update the leaf node
        segTree[node] = value;
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid) {
        // If idx is in the left child
        updateTree(segTree, start, mid, idx, value, 2 * node + 1);
    } else {
        // If idx is in the right child
        updateTree(segTree, mid + 1, end, idx, value, 2 * node + 2);
    }

    // Update the internal node after updating the child
    segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
}

// Function to query the sum in a given range
int queryTree(vector<int>& segTree, int start, int end, int l, int r, int node) {
    // If the range represented by this node is completely outside the given range
    if (start > r || end < l) {
        return 0;
    }

    // If the range represented by this node is completely inside the given range
    if (start >= l && end <= r) {
        return segTree[node];
    }

    // Otherwise, the range overlaps with the left and right child
    int mid = (start + end) / 2;
    int leftSum = queryTree(segTree, start, mid, l, r, 2 * node + 1);
    int rightSum = queryTree(segTree, mid + 1, end, l, r, 2 * node + 2);
    return leftSum + rightSum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Build the segment tree
    vector<int> segTree(4 * n);
    buildTree(arr, segTree, 0, n - 1, 0);

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    while (q--) {
        int type;
        cout << "Enter query type (1 for update, 2 for sum query): ";
        cin >> type;

        if (type == 1) {
            int idx, value;
            cout << "Enter index and new value: ";
            cin >> idx >> value;
            updateTree(segTree, 0, n - 1, idx, value, 0);
        } else if (type == 2) {
            int l, r;
            cout << "Enter range [l, r]: ";
            cin >> l >> r;
            int sum = queryTree(segTree, 0, n - 1, l, r, 0);
            cout << "Sum of range [" << l << ", " << r << "] is: " << sum << endl;
        }
    }

    return 0;
}
