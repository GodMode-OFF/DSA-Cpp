#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> SpiralLevelOrder(Node* root) {
    if (root == NULL) return {};  // Handle empty tree

    stack<Node*> s1, s2;
    s1.push(root);
    vector<int> ans;

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node *temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);
            if (temp->left) s2.push(temp->left);
            if (temp->right) s2.push(temp->right);
        }
        while (!s2.empty()) {
            Node *temp = s2.top();
            s2.pop();
            ans.push_back(temp->data);
            if (temp->right) s1.push(temp->right);  // Right first for zigzag
            if (temp->left) s1.push(temp->left);    // Left second for zigzag
        }
    }
    return ans;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = SpiralLevelOrder(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
