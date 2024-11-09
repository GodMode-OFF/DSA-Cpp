#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node *BinaryTree(){
    int x;
    cout<<"Enter the value of x: ";
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node *temp = new Node(x);
    temp->left = BinaryTree();
    temp->right = BinaryTree();
    return temp;
}





int main(){
    
}
