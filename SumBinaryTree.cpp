#include<iostream>
using namespace std;

int SumBT(Node *root){
    if(root==NULL){
        return 0;
    }
    return (root->data + SumBT(root->left) + SumBT(root->right));
}
    
int main(){ 
}
