vector<int>PreOrder(Node *root){
    stack<Node*>s;
    vector<int>ans;
    s.push(root);
    while(!s.empty()){
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if(temp->right){
            s.push(temp-right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
    return ans;
}
