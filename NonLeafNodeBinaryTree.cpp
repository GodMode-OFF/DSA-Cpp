#include<iostream>
using namespace std;

int SumBT(Node *root){
    if(root==NULL){
        return 0;
    }
    if(!root->left&&!root->right){
        return 0;
    }
        return (1+SumBT(root->left)+SumBT(root->right));
}
    
int main(){ 
}
