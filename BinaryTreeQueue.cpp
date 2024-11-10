#include <iostream>
using namespace std;
int main() {
    int x, first, second;
    cout<<"Enter the value of x: ";
    cin>>x;
    queue<Node*>q;
    Node* root = new Node(x);
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cin>>first;
        if(first !=-1){
            temp->left = new Node(first);
            q.push(temp->left);
        }
        cin>>second;
        if(second != -1){
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
    return 0;
}
