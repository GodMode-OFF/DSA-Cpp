#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int Find(int* in, int target, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (in[i] == target) {
            return i;
        }
    }
    return -1;
}

Node* Tree(int* in, int* pre, int InStart, int InEnd, int& index) {
    if (InStart > InEnd) {
        return NULL;
    }
    Node* root = new Node(pre[index]);
    int pos = Find(in, pre[index], InStart, InEnd);
    index++;
    root->left = Tree(in, pre, InStart, pos - 1, index);
    root->right = Tree(in, pre, pos + 1, InEnd, index);
    return root;
}

void InOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main() {
    int in[] = {4, 2, 5, 1, 6, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int n = sizeof(in) / sizeof(in[0]);
    int index = 0;
    Node* root = Tree(in, pre, 0, n - 1, index);
    cout << "In-Order Traversal: ";
    InOrder(root);
    return 0;
}
